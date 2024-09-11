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