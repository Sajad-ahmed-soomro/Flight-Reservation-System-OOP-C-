Summary
The code implements a flight booking system where users can register, book flights, and manage their accounts. It supports both domestic and international flight bookings with seat availability tracking. The system provides details about flight schedules, booking tickets, and calculating ticket prices based on flight type and class.

Features
User Registration and Authentication:

Users can register with their name, CNIC, password, and age.
Account management includes functions for opening accounts, checking existing accounts, and resetting account details.
Flight Booking:

Supports booking for both domestic and international flights.
Users can choose flights based on city, route, and flight type (domestic/international).
The system displays available flight schedules and allows booking seats based on availability.
Flight Scheduling:

The system manages schedules for different flights, including departure/arrival times, destinations, and seat availability.
Flight schedules are categorized by city and flight route (North/South).
Seat Management:

Keeps track of seat availability for each flight schedule.
Allows users to book available seats and updates the availability status.
Ticket Information and Pricing:

Calculates ticket prices based on the class (economy/business), type (domestic/international), and applicable taxes.
Displays detailed ticket information including passenger details, departure city, and net price after taxes.
Structuring and Extensibility:

The code is organized into classes like Registration, Airplane, Flight, Passenger, and BookingSeats to handle different responsibilities.
The system supports adding more cities, airports, and flights as needed.
Potential Use Cases
This project could be useful as a learning tool for understanding object-oriented programming, inheritance, and class interactions in C++.
It can serve as a foundational template for a larger, more feature-complete airline reservation system.


How to Use
To use the system, compile the code using a C++ compiler and run the executable. Follow the console prompts to register users, book flights, and view ticket information.
