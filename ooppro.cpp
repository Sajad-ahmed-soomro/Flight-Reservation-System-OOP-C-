
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <conio.h>

#include <string>

#define PASSWORD_LENGTH 8

using namespace std;
const int MAX_SCHEDULES = 10;
const int MAX_SEATS = 50;
const int MAX_CITIES = 5;
const int MAX_AIRPORTS_PER_CITY = 2;
const int MAX_PLANES_PER_CITY = 10;
const int MAX_SEATS_PER_PLANE_ECO = 50;
const int MAX_SEATS_PER_PLANE_BUS = 10;
const int MAX_FLIGHTS_PER_AIRPORT_LOCAL = 10;
const int MAX_FLIGHTS_PER_AIRPORT_INTL = 5;
const int MAX_PASSENGERS = 50000;
const int MAX_BOOKINGS = MAX_PASSENGERS * 2; // Maximum 2 bookings per passenger
int ticket = 0;
int ticket_local = 0;

struct Register
{
    string name;
    string cnic;
    char password[9];
    int age;
};

class Registration
{
protected:
    string name;
    string cnic;
    char password[8];
    Register obj[2];
    int optionbooking;
    int age;
    int count;

public:
    Registration() {}
    Registration(string name, string cnic, char password[8], int age)
    {
        this->name = name;
        this->cnic = cnic;
        strcpy(this->password, password);
        this->age = age;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setCnic(string cnic)
    {
        this->cnic = cnic;
    }
    void setPassword(char password[8])
    {
        strcpy(this->password, password);
    }
    void setAge(int age)
    {
        this->age = age;
    }
    string getName()
    {
        return name;
    }
    string getCnic()
    {
        return cnic;
    }
    char getPassword()
    {
        return password[8];
    }
    int getAge()
    {
        return age;
    }
     int users = sizeof(obj) / sizeof(obj[0]);
    void Accountopening();
    void Registers(string name, string cnic, char password[8], int age);
     bool Accountcheck(string cnic, char password[8], int users);
    bool FindingAccount(string cnic, char password[8], int users);
    void ResetAccount();
    //  virtual int book();
};
void  Registration::Registers(string name, string cnic, char password[8], int age)
{
    this->name = name;
    this->cnic = cnic;
    strcpy(password, password);
    this->age = age;
    Accountopening();
}
void Registration::Accountopening()
{
    obj[count].name = name;
    obj[count].cnic = cnic;
    strcpy(obj[count].password, password);
    obj[count].age = age;
    count++;
    cout << "Your account has been sucessfully opened:" << endl;
}
bool Registration::Accountcheck(string cnic, char password[8], int users)
{
    bool found = false;

    for (int i = 0; i < users; i++)
    {
        if (cnic == obj[i].cnic)
        {
            found = true;
            password[8] = obj[i].password[8];
            break;
        }
    }
    if (found)
    {
        cout << "You have successfully logged in with the login ID " << cnic << endl;
        return true;
    }
    else
    {
        cout << "Login ID not found." << endl;
        return false;
    }
}
void Registration::ResetAccount()
{
    if (FindingAccount(cnic, password, users) == true)
    {
        cout << "Enter the name to reset:" << endl;
        getline(cin, name);
        cout << "Enter the password to reset:" << endl;
        cin >> password;
        obj[count].name = name;
        obj[count].cnic = cnic;
        strcpy(obj[count].password, password);
        count++;
    }
}
bool Registration::FindingAccount(string cnic, char password[8], int users)
{
    bool found = false;

    for (int i = 0; i < users; i++)
    {
        if (cnic == obj[i].cnic)
        {
            found = true;
            password[8] = obj[i].password[8];
            break;
        }
    }
    if (found)
    {
        return true;
    }
    else
    {
        return false;
    }
}
class Airplane
{
private:
    string id;
    bool is_international;
    string schedules[MAX_SCHEDULES][3]; // {departure_time, arrival_time, destination}
    int available_seats[MAX_SCHEDULES][MAX_SEATS];

public:
    // Airplane(){}
    Airplane()
    {
        for (int i = 0; i < MAX_SCHEDULES; i++)
        {
            for (int j = 0; j < MAX_SEATS; j++)
            {
                available_seats[i][j] = MAX_SEATS;
            }
        }
    }
    void set_id(string id)
    {
        this->id = id;
    }
    void set_type(bool is_international)
    {
        this->is_international = is_international;
    }

    string get_id()
    {
        return id;
    }

    bool get_is_international()
    {
        return is_international;
    }

    bool add_schedule(string departure_time, string arrival_time, string destination, int num_seats)
    {
        for (int i = 0; i < MAX_SCHEDULES; i++)
        {
            if (schedules[i][0] == "")
            {
                schedules[i][0] = departure_time;
                schedules[i][1] = arrival_time;
                schedules[i][2] = destination;
                for (int j = 0; j < num_seats; j++)
                {
                    available_seats[i][j] = 1;
                }
                return true;
            }
        }
        return false;
    }

    void display_schedule()
    {
        cout << "Schedule for airplane " << id << ":" << endl;
        for (int i = 0; i < MAX_SCHEDULES; i++)
        {
            if (schedules[i][0] != "")
            {
                cout << "  Departure time: " << schedules[i][0] << endl;
                cout << "  Arrival time: " << schedules[i][1] << endl;
                cout << "  Destination: " << schedules[i][2] << endl;
                cout << "  Available seats: " << get_num_available_seats(i) << "/" << MAX_SEATS << endl;
            }
        }
    }

    int get_num_available_seats(int schedule_index)
    {
        int count = 0;
        for (int i = 0; i < MAX_SEATS; i++)
        {
            if (available_seats[schedule_index][i] == 1)
            {
                count++;
            }
        }
        return count;
    }

    bool book_seat(int schedule_index)
    {
        for (int i = 0; i < MAX_SEATS; i++)
        {
            if (available_seats[schedule_index][i] == 1)
            {
                available_seats[schedule_index][i] = 0;
                return true;
            }
        }
        return false;
    }
};
class flight : public Airplane
{
protected:
    string flight_Name;
    int flight_number;
    bool Is_international;
    string dep_date;
    string Arr_date;
    int seats;
    string country_det;

public:
    Airplane airplane1[10];
    Airplane airplane2[5];

    flight()
    {
    }

    void flightbook_National();
    void flightbook_International();
    void putdata()
    {
        cout << "Enter the flight name:" << endl;
        getline(cin, flight_Name);
        cout << "Is International true/false" << endl;
        cin >> Is_international;
        if (Is_international == true)
        {
            flightbook_International();
        }
        else
        {
            flightbook_National();
        }
    }
};
void flight::flightbook_National()
{
    while (flight_number < 11)
    {
        cout << "Enter the no of flight you want to book  Enter less than 11" << endl;
        cin >> flight_number;
        if (flight_number < 11)
        {
            break;
        }
        else
        {
            cout << "Please enter less than 11" << endl;
            cin >> flight_number;
        }
    }

    for (int i = 0; i < flight_number; i++)
    {

        airplane1[i].set_id(flight_Name);
        airplane1[i].set_type(Is_international);
        cout << "Enter the departure date in format year/month/day and time format  " << endl;
        getline(cin, dep_date);
        cout << "Enter the Arrival date in format year/month/day and time format  " << endl;
        getline(cin, Arr_date);
        cout << "Enter the seats maximum can 10" << endl;
        cin >> seats;
        airplane2[i].add_schedule(dep_date, Arr_date, country_det, seats);
    }
}
void flight::flightbook_International()
{

    while (flight_number < 6)
    {
        cout << "Enter the no of flight you want to book  Enter less than 6" << endl;
        cin >> flight_number;
        if (flight_number < 6)
        {
            break;
        }
        else
        {
            cout << "Please enter less than 6" << endl;
            cin >> flight_number;
        }
    }

    for (int i = 0; i < flight_number; i++)
    {
        airplane2[i].set_id(flight_Name);
        airplane2[i].set_type(Is_international);
        cout << "Enter the departure date in format year/month/day and time format  " << endl;
        getline(cin, dep_date);
        cout << "Enter the Arrival date in format year/month/day and time format  " << endl;
        getline(cin, country_det);
        cout << "Enter the country destination" << endl;
        getline(cin, Arr_date);
        cout << "Enter the seats maximum can 10" << endl;
        cin >> seats;
        airplane2[i].add_schedule(dep_date, Arr_date, country_det, seats);
    }
}
struct Passengers
{
    string cnic;
    string name;
    string address;
    string phone;
    string email;
    string passportNum;
    string isLocalPassport;
    string hasVisa;
};
class passenger : virtual public Registration, virtual public Airplane
{
protected:
    Passengers Persons[MAX_PASSENGERS];

public:
    passenger() {}
    passenger(string address, string phone, string email, string passprtNum, bool isLocalPassport, bool hasVisa, int numBookings)
    {
        this->Persons[count].cnic = cnic;
        this->Persons[count].name = name;
        this->Persons[count].address = address;
        this->Persons[count].phone = phone;
        this->Persons[count].email = email;
        this->Persons[count].passportNum = passprtNum;
        this->Persons[count].isLocalPassport = isLocalPassport;
        this->Persons[count].hasVisa = hasVisa;
        count++;
    }
};

class BookingSeats : virtual public passenger, virtual public Airplane
{
public:
    int option;
    int flight_option;
    int chosen;
    string chosenCountry;
    int ticket;
    double hours;
    double ticketprice;
    string date;
    int country_option;
    int city_dep;
    int Routeoption;
    bool is_International;
    double cost_local_economy;          //= 10000;
    double cost_local_buisness;         // = 15000;
    double cost_International_economy;  // = 20000;
    double cost_International_buisness; // = 40000;
    // static const
    double tax1;                 //= 0.5;
                                 // static const
    double tax2;                 //= 0.10;
                                 //
    static const double penalty; // = 0.25;
    double netprice;
    int classoption;
    int cityoption;
    double price;
    int airportoption;
    flight Islamabad_North;
    flight Islamabad_South;
    flight Karachi_North;
    flight Karachi_South;
    flight Lahore_North;
    flight Lahore_South;
    flight Peshaware_North;
    flight Peshaware_South;
    flight Quetta_North;
    flight Quetta_South;

    string passport_No, city, Route, country_destination;
    // public:
    BookingSeats()
    {
    }
    void country_flight();
    void seat_book();
    void searchCountry();
    void Display();
    void country(flight obj, int country_option);
    void City(flight obj, int country_option);
    void TicketInformation_local(flight obj, int city);
    void TicketInformation_Inter(flight obj, int city);
};
void BookingSeats::country_flight()
{   
    cout << "Enter the city to schedual" << endl;
    Islamabad_North.add_schedule("2/3/23 8:00", "2/3/23 9:00", "New York", 2);
}
void BookingSeats::seat_book()
{
    cout << "Enter the date" << endl;
    getline(cin, date);
    cout << "1) Isalmabad 2) Karachi 3) Lahore 4) Peshaware 5) Quetta \n"
         << endl;
    cout << "Enter the departure city " << endl;
    cin >> city_dep;
    cout << "Enter the deparure route 1) North 2) South " << endl;
    cin >> Routeoption;
    cout << "Enter the flight type 1) International 2) local  " << endl;
    cin >> option;
    cout << "1) Economic 2) Business" << endl;
    cin >> flight_option;
    if (option == 1)
    {
        cout << "1 to 5" << endl;
        cout << "Enter the above option for country airport" << endl;

        cin >> country_option;
        is_International == true;
        switch (city_dep)
        {
        case 1:
            switch (Routeoption)
            {
            case 1:
                for (int i = 0; i < 6; i++)
                {
                    Islamabad_North.airplane2[i].display_schedule();
                }
                country(Islamabad_North, country_option);
                break;

            case 2:
                for (int i = 0; i < 6; i++)
                {
                    Islamabad_South.airplane2[i].display_schedule();
                }
                country(Islamabad_South, country_option);
                break;
            }
            break;
        case 2:
            switch (Routeoption)
            {
            case 1:
                for (int i = 0; i < 6; i++)
                {
                    Karachi_North.airplane2[i].display_schedule();
                }
                country(Karachi_North, country_option);
                break;

            case 2:
                for (int i = 0; i < 6; i++)
                {
                    Karachi_South.airplane2[i].display_schedule();
                }
                country(Karachi_South, country_option);
                break;
            }
            break;

        case 3:
            switch (Routeoption)
            {
            case 1:
                for (int i = 0; i < 6; i++)
                {
                    Lahore_North.airplane2[i].display_schedule();
                }
                country(Lahore_North, country_option);
                break;

            case 2:
                for (int i = 0; i < 6; i++)
                {
                    Lahore_South.airplane2[i].display_schedule();
                }
                country(Lahore_South, country_option);
                break;
            }
            break;
        case 4:
            switch (Routeoption)
            {
            case 1:
                for (int i = 0; i < 6; i++)
                {
                    Peshaware_North.airplane2[i].display_schedule();
                }
                country(Peshaware_North, country_option);
                break;

            case 2:
                for (int i = 0; i < 6; i++)
                {
                    Peshaware_South.airplane2[i].display_schedule();
                }
                country(Peshaware_South, country_option);
                break;
            }
            break;
        case 5:
            switch (Routeoption)
            {
            case 1:
                for (int i = 0; i < 6; i++)
                {
                    Quetta_North.airplane2[i].display_schedule();
                }
                country(Quetta_North, country_option);
                break;

            case 2:
                for (int i = 0; i < 6; i++)
                {
                    Quetta_South.airplane2[i].display_schedule();
                }
                country(Quetta_South, country_option);
                break;
            }
            break;
        default:
            break;
        }
    }
    else
    {
        cout << "1 to 5" << endl;
        cout << "Enter the above option city airport" << endl;
        getline(cin, chosenCountry);
        is_International = false;
        switch (city_dep)
        {
        case 1:
            switch (Routeoption)
            {
            case 1:
                for (int i = 0; i < 11; i++)
                {
                    Islamabad_North.airplane1[i].display_schedule();
                }
                City(Islamabad_North, country_option);
                break;

            case 2:
                for (int i = 0; i < 11; i++)
                {
                    Islamabad_South.airplane1[i].display_schedule();
                }
                City(Islamabad_South, country_option);
                break;
            }
            break;
        case 2:
            switch (Routeoption)
            {
            case 1:
                for (int i = 0; i < 11; i++)
                {
                    Karachi_North.airplane1[i].display_schedule();
                }
                City(Karachi_North, country_option);
                break;

            case 2:
                for (int i = 0; i < 11; i++)
                {
                    Karachi_South.airplane1[i].display_schedule();
                }
                City(Karachi_South, country_option);
                break;
            }
            break;

        case 3:
            switch (Routeoption)
            {
            case 1:
                for (int i = 0; i < 11; i++)
                {
                    Lahore_North.airplane1[i].display_schedule();
                }
                City(Lahore_North, country_option);
                break;

            case 2:
                for (int i = 0; i < 11; i++)
                {
                    Lahore_South.airplane1[i].display_schedule();
                }
                City(Lahore_South, country_option);
                break;
            }
            break;
        case 4:
            switch (Routeoption)
            {
            case 1:
                for (int i = 0; i < 11; i++)
                {
                    Peshaware_North.airplane1[i].display_schedule();
                }
                City(Peshaware_North, country_option);
                break;

            case 2:
                for (int i = 0; i < 11; i++)
                {
                    Peshaware_South.airplane1[i].display_schedule();
                }
                City(Peshaware_South, country_option);
                break;
            }
            break;
        case 5:
            switch (Routeoption)
            {
            case 1:
                for (int i = 0; i < 11; i++)
                {
                    Quetta_North.airplane1[i].display_schedule();
                }
                City(Quetta_North, country_option);
                break;

            case 2:
                for (int i = 0; i < 11; i++)
                {
                    Quetta_South.airplane1[i].display_schedule();
                }
                City(Quetta_South, country_option);
                break;
            }
            break;
        default:
            break;
        }
    }
}
void BookingSeats::country(flight obj, int country_option)
{
    bool success = obj.airplane2[country_option].book_seat(ticket);
    if (success)
    {
        cout << "Seat booked successfully!" << endl;

        TicketInformation_Inter(obj, country_option);
    }
    else
    {
        cout << "Failed to book seat." << endl;
    }
    ticket + 1;
}
void BookingSeats::City(flight obj, int country_option)
{
    bool success = obj.airplane1[country_option].book_seat(ticket_local);
    if (success)
    {
        cout << "Seat booked successfully!" << endl;
        TicketInformation_local(obj, country_option);
    }
    else
    {
        cout << "Failed to book seat." << endl;
    }
    ticket_local + 1;
}
void BookingSeats::TicketInformation_local(flight obj, int city)
{
    cout << "Name:" << name;
    cout << "Passport number" << passport_No;
    cout << "Ticket no" << ticket;
    cout << "class:" << classoption;
    cout << "Departure city" << city_dep;
    // cout<<"Arrival city"<<obj.airplane1[city].Arrival_city;
    // cout<<"Departure time"<<obj.airplane1[city].deparure_time;
    // cout<<"Arrival time"<<obj.airplane1[city].Arr_time;
    if (classoption == 1)
    {
        cout << "Ticket price" << cost_local_economy;
        cout << " ticket tax" << tax1;
        price = cost_local_economy * tax1;
        netprice = price + cost_local_economy;
        cout << "Net price" << netprice;
    }
    else
    {
        cout << "Ticket price" << cost_local_buisness;
        cout << " ticket tax" << tax1;
        price = cost_local_buisness * tax1;
        netprice = price + cost_local_buisness;
        cout << "Net price" << netprice;
    }
}
void BookingSeats::TicketInformation_Inter(flight obj, int city)
{
    cout << "Name:" << name;
    cout << "Passport number" << passport_No;
    cout << "Ticket no" << ticket;
    cout << "class :" << classoption;
    cout << "Departure city" << city_dep;
    // cout << "Arrival Country city " <<obj.airplane2[city].Arrival_city;
    // cout << "Departure time" <<obj.airplane2[city].Dep_time;
    // cout << "Arrival time" <<obj.airplane2[city].Arr_time;
    if (classoption == 1)
    {
        cout << "Ticket price" << cost_International_economy;
        cout << " ticket tax" << tax2;
        price = cost_International_buisness * tax2;
        netprice = price + cost_International_economy;
        cout << "Net price" << netprice;
    }
    else
    {
        cout << "Ticket price" << cost_International_buisness;
        cout << " ticket tax" << tax2;
        price = cost_International_buisness * tax2;
        netprice = price + cost_International_buisness;
        cout << "Net price" << netprice;
    }
}
// Global bvariables string name;
bool verifyPassword(char *password);
void Registration_Information();
string cnic, name;
int age;
char password[PASSWORD_LENGTH + 1], confirmPassword[PASSWORD_LENGTH + 1];
void Registration_Information()
{
    cout << "Enter the Name:" << endl;
    getline(cin, name);
    cout << "Enter the CNIC:" << endl;
    getline(cin, cnic);
    cout<<"enter the age"<<endl;
    cin>>age;
    cout << "Enter the password it should be 8 chracters use of minimum one special character, uppercase, lowercase, and numeric digit is must. : " << endl;

    // Get username

    // Get password
    cout << "Enter password (must be  characters long and contain at least one special character, uppercase, lowercase, and numeric digit): " << PASSWORD_LENGTH;
    char c;
    int i = 0;
    while (i < PASSWORD_LENGTH || !verifyPassword(password))
    {
        password[i] = '\0';
        while (c = getch())
        {
            if (c == '\r') // Enter key pressed
            {
                cout << endl;
                break;
            }
            else if (c == '\b') // Backspace key pressed
            {
                if (i > 0)
                {
                    i--;
                    password[i] = '\0';
                    cout << "\n \n"; // Erase the last asterisk and move the cursor back
                }
            }
            else if (isprint(c) && i < PASSWORD_LENGTH)
            {
                password[i] = c;
                i++;
                cout << "*"; // Mask the entered character with an asterisk
            }
        }
        if (!verifyPassword(password))
        {
            cout << "\nPassword is not strong enough. Please try again.\n";
            i = 0;
        }
    }

    // Verify password
    while (true)
    {
        cout << "Confirm password: ";
        i = 0;
        confirmPassword[i] = '\0';
        while (c = getch())
        {
            if (c == '\r') // Enter key pressed
            {
                cout << endl;
                break;
            }
            else if (c == '\b') // Backspace key pressed
            {
                if (i > 0)
                {
                    i--;
                    confirmPassword[i] = '\0';
                    cout << "\b \b"; // Erase the last asterisk and move the cursor back
                }
            }
            else if (isprint(c) && i < PASSWORD_LENGTH)
            {
                confirmPassword[i] = c;
                i++;
                cout << "*"; // Mask the entered character with an asterisk
            }
        }
        if (strcmp(confirmPassword, password) == 0)
        {
            break;
        }
        cout << "\nPasswords do not match. Please try again.\n";
    }
}
bool verifyPassword(char *password)
{
    bool hasSpecial = false, hasUppercase = false, hasLowercase = false, hasDigit = false;
    for (int i = 0; i < strlen(password); i++)
    {
        if (ispunct(password[i]))
        {
            hasSpecial = true;
        }
        else if (isupper(password[i]))
        {
            hasUppercase = true;
        }
        else if (islower(password[i]))
        {
            hasLowercase = true;
        }
        else if (isdigit(password[i]))
        {
            hasDigit = true;
        }
    }
    return strlen(password) >= PASSWORD_LENGTH && hasSpecial && hasUppercase && hasLowercase && hasDigit;
}
void BookingSeats::country_flight()
{
    string departure_date;
    string arrival_date;
    string city_country;
    int schedulasflight;
    int air_option;
    int flightsno;
    cout<<"1)Isalmabd North ariport 2) Islamabad south airport 3) karachi North airport 4) Karachi south airport 5) Lahore north airport 6) lahore south airport 7) Peshaware North airport 8) Peshaware south airport 9) Quetta South airport 10) Quetta North airport"<<endl;
    cout<<"Enter the Airport to flight book"<<endl;
    cin>>air_option;
    cout<<"Enetr the date departure with time "<<endl;
    getline(cin,departure_date);
    cin.ignore();
    cout << "Enetr the date Arrival with time " << endl;
    getline(cin, arrival_date);
    cin.ignore();
    cout << "Enetr the city /country airport " << endl;
    getline(cin, city_country);
    cin.ignore();
    cout<<"enter the flights no"<<endl;
    cin>>flightsno;
    switch (air_option)
    {
    case 1:
        Islamabad_North.add_schedule(departure_date,arrival_date,city_country,flightsno);
        cout<<"The flight has been scheduled"<<endl;
        break;

    case 2:    Islamabad_South.add_schedule(departure_date, arrival_date, city_country, flightsno);
        cout << "The flight has been scheduled" << endl;
        break;
    case 3:
        Karachi_North.add_schedule(departure_date, arrival_date, city_country, flightsno);
        cout << "The flight has been scheduled" << endl;
        break;
    case 4:
        Karachi_South.add_schedule(departure_date, arrival_date, city_country, flightsno);
        cout << "The flight has been scheduled" << endl;
        break;
    case 5:
        Lahore_North.add_schedule(departure_date, arrival_date, city_country, flightsno);
        cout << "The flight has been scheduled" << endl;
        break;
    case 6:
        Lahore_South.add_schedule(departure_date, arrival_date, city_country, flightsno);
        cout << "The flight has been scheduled" << endl;
        break;
    case 7:
        Peshaware_North.add_schedule(departure_date, arrival_date, city_country, flightsno);
        cout << "The flight has been scheduled" << endl;
        break;
    case 8:
        Peshaware_South.add_schedule(departure_date, arrival_date, city_country, flightsno);
        cout << "The flight has been scheduled" << endl;
        break;
    case 9:
        Quetta_North.add_schedule(departure_date, arrival_date, city_country, flightsno);
        cout << "The flight has been scheduled" << endl;
        break;
    case 10:
        Quetta_South.add_schedule(departure_date, arrival_date, city_country, flightsno);
        cout << "The flight has been scheduled" << endl;
        break;
    default:
        break;
    }


    
}
void PassengerDetail(){
    string address,phone,email,passprtNum;
    bool isLocalPassport,hasVisa;
    cout<<"Enter the address"<<endl;
    getline(cin,address);
    cin.ignore();
    cout << "Enter the email" << endl;
    getline(cin, email);
    cin.ignore();
    cout << "Enter the islocal Passport true/false " << endl;
    cin>>isLocalPassport;
    cout << "Enter the has visa" << endl;
    cin>>hasVisa;

    passenger pobj( address,phone, email,passprtNum,isLocalPassport, hasVisa,1);
}
int main(void){
    cout<<"Welcome to Nucess "<<endl;
    int option;
    int reoption;
    while(1){
        cout<<"for Admin 2)customer seat book 3) Registration 4) exit"<<endl;
        cin>>option;
        if(option==1){
            BookingSeats Bobj;
            Bobj.country_flight();
            break;
        }else if(option==2){
            PassengerDetail();
            BookingSeats obj;
            passenger pobj;
            obj.seat_book();
            break;
        }
        else if(option==3){
            cout<<"1)Register account 2) check account 3) Reset Account"<<endl;
            cin>>reoption;
            if(reoption==1)
            {
            
                Registration_Information();
                Registration obj1,
                obj1(name, cnic, confirmPassword, age);
                obj1.Registers(name,cnic,confirmPassword,age);
                break;
            }else if(reoption==2){
                Registration_Information();
                Registration obj2(name, cnic, confirmPassword, age);
                obj2.Accountcheck(cnic,confirmPassword,50000);
            }
          else if (reoption == 3)
         {
            Registration_Information();
            Registration obj3(name, cnic, confirmPassword, age);
            obj3.ResetAccount();
            break;
         }else{
            break;
         }
    }




}