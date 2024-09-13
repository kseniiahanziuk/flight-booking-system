#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Seat {
private:
    int seatNum;
    char seatChar;
    int price;
    bool seatAvailable;

public:
    Seat(const int seatNum, const char seatChar, const int price) :
        seatNum(seatNum), seatChar(seatChar), price(price), seatAvailable(true) {}

    int getSeatNum() const {
        return seatNum;
    }

    char getSeatChar() const {
        return seatChar;
    }

    int getPrice() const {
        return price;
    }

    bool getAvailability() const {
        return seatAvailable;
    }

    void seatBooked() {
        seatAvailable = false;
    }
};


class Airplane {
private:
    int numOfSeats;
    string flightDate;
    string flightNum;
    vector<Seat> availableSeats;
public:
    Airplane(const int &numOfSeats, const string &flightDate, const string &flightNum, vector<Seat> &availableSeats) :
        numOfSeats(numOfSeats), flightDate(flightDate), flightNum(flightNum), availableSeats(availableSeats) {}

    int getNumOfSeats() const {
        return numOfSeats;
    }

    string getFlightDate() const {
        return flightDate;
    }

    string getFlightNum() const {
        return flightNum;
    }

    vector<Seat>& getAvailableSeats() {
        return availableSeats;
    }
};


class Ticket {
private:
    int ticketID;
    string flightNumber;
    Seat seat;
    string date;
    string passengerName;
public:
    Ticket(int ticketID, const string &flightNumber, const Seat &seat,
        const string &date, const string &passengerName) :
            ticketID(ticketID), flightNumber(flightNumber),
            seat(seat), date(date), passengerName(passengerName) {}


    int getTicketID() const {
        return ticketID;
    }

    string getFlightNumber() const {
        return flightNumber;
    }

    int getSeatNumber() const {
        return seat.getSeatNum();
    }

    char getSeatLetter() const {
        return seat.getSeatChar();
    }

    string getDate() const {
        return date;
    }

    string getPassengerName() const {
        return passengerName;
    }

    void showTicket() const {
        cout << "Information about the ticket: \n";
        cout << "Ticket ID: " << ticketID << "\n";
        cout << "Flight number: " << flightNumber << "\n";
        cout << "Seat: " << getSeatNumber() << getSeatLetter() << "\n";
        cout << "Date: " << date << "\n";
        cout << "Passenger name: " << passengerName << "\n";
    }
};

class Passenger {
    string passengerName;
    vector<Ticket> tickets;
public:
    Passenger(const string passengerName) : passengerName(passengerName) {}

    string getPassengerName() {
        return passengerName;
    }

    void addTicket(const Ticket &ticket) {
        tickets.push_back(ticket);
    }

    vector<Ticket> getTickets() const {
        return this->tickets;
    }
};

class Commands {
public:
    void checkFreeSeats() {

    }

    void bookTicket() {

    }

    void returnTicket() {

    }

    void viewByID() {

    }

    void viewByName() {

    }

    void viewByFlight() {

    }

    void help() {
        cout << "\nHere's the list of commands: \n\n";
        cout << "~ check - check available places for the flight.\n";
        cout << "~ book - book a ticket for a flight.\n";
        cout << "~ return - return ticket with refund.\n";
        cout << "~ view id - view the booking info by ticket ID.\n";
        cout << "~ view name - view all tickets booked under a passenger name.\n";
        cout << "~ view flight - view all booked tickets for a flight.\n";
        cout << "~ help - view command prompt.\n";
        cout << "~ exit - exit the program.\n";
    }
};

class UserInput {
private:
    Commands commands;
public:
    void userInterface() {
        string command;
        cout << "Welcome to the Airplane Ticket Booking System.\n";
        do {
            cout << "\nEnter the command you want to perform: ";
            cin >> command;

            if (command == "check") {
                commands.checkFreeSeats();
            }
            else if (command == "book") {
                commands.bookTicket();
            }
            else if (command == "return") {
                commands.returnTicket();
            }
            else if (command == "view id") {
                commands.viewByID();
            }
            else if (command == "view name") {
                commands.viewByName();
            }
            else if (command == "view flight") {
                commands.viewByFlight();
            }
            else if (command == "help") {
                commands.help();
            }
            else if (command == "exit") {
                cout << "Thanks for using the program. Bye!\n";
            }
            else {
                cout << "Invalid input. Try using 'help' to see commands.";
            }
        } while (command != "exit");
    }
};

int main() {
    UserInput ui;
    ui.userInterface();
    return 0;
}