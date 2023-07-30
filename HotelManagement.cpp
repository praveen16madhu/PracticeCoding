#include <bits/stdc++.h>
using namespace std;
// Requirements
// 1. Employee details
// 2. Customer details 
// 3. Room details - List of room, availability status 
// 4. Hotel 

enum DESIGNATION {
    MANAGER=1,
    SECURITY,
    RECEPTIONIST,
    SERVER
};

class Employee { 
private:
    int employeeId;
    string name;
    // int salary;
    DESIGNATION designation;
public:
    Employee() {
        cout<<"Enter name\n";
        cin >> name;
        cout << "Enter ID\n";
        cin >> employeeId;
        cout<< "Enter Designation number\n. 1.MANAGER 2.SECURITY 3.RECEPTIONIST 4.SERVER";
        int input;
        cin >> input;
        if (input >= 1 && input <= 4) {
            designation = static_cast<DESIGNATION>(input);
        } else {
            cout << "Invalid input" << endl;
            
        }
    }
    Employee(int id, string name, DESIGNATION desig) {
        this->employeeId = id;
        this->name = name;
        this->designation = desig;
    }
};

enum ROOM_TYPE {
    AC,
    Non_AC
};

class Customer {
private:
    string name;
    string id;
public:
    Customer(string n, string i) {
        this->name = n;
        this->id = i;
    }
    Customer(){
        
    }

};


class Room {
private:
    int roomNumber;
    ROOM_TYPE type;
    bool isAvailable;
    Customer customer;
    
public:
    Room(ROOM_TYPE type, int num) {
        this->type = type;
        this->roomNumber = num;
        this->isAvailable = 1; //default value
    }
    void printdetails()
    {
        cout<<isAvailable << "\n";
        cout<<roomNumber<< "\n";
        cout<<type<< "\n";
    }

    void checkIn(Customer cust) {
        isAvailable = 0;
        customer = cust;
    }
    
    void checkOut(int roomNum) {
        isAvailable = 1;
        customer = Customer();
    }

    bool checkAvailability() {
        if (isAvailable == 0) {
            return 0;
        } else {
            return 1;
        }
    }

    int getRoomNumber() {
        return roomNumber;
    }
};





class Hotel {
private:
    string name; 
    string address;
    int rating;
    vector<Employee> employees;
    vector<Room> rooms;
public:
    Hotel() {
        cout<< "Enter Hotel Details\n";
        cout << "Enter name\n";
        cin >> name;
        cout << "Enter Addreess\n";
        cin >> address;
        cout << "Enter Rating(1-5)\n";
        cin >> rating;
    }
    Hotel(string name, string address, int rating) {
        this->name = name;
        this->address = address;
        this->rating = rating;
    }
    
    void addEmployee(Employee e) {
        employees.push_back(e);
    };
    void deleteEmployee(int id) {
        // delete employeee by comparing the id 

    }
    void addRoom(Room r){
        rooms.push_back(r);
    };

    void displayRooms(){
        for(Room &room: rooms) {
                if( room.checkAvailability() != 0)
                {
                    cout<<"the room" << room.getRoomNumber() << " is available" << "\n";
                }
                else
                {
                    cout<<"the room" << room.getRoomNumber() <<" is not available\n";
                }
            }
    }

    void checkin(int roomNum, Customer cust){
        int flag = 0;
        
        for(Room &room: rooms) {
            cout<< room.getRoomNumber();
            if(room.getRoomNumber() == roomNum && room.checkAvailability())
            {
                cout << "calling checkin \n";
                room.checkIn(cust);
                cout << "Checkin Room details:\n";
                room.printdetails();
                flag = 1; 
            }
        }
        if (flag == 0) {
            cout << "Enter valid room number";
        }

    }

    void checkout(int roomNum){
        int flag = 0;
        for(Room &room: rooms) {
            cout<< room.getRoomNumber();
            if(room.getRoomNumber() == roomNum && !room.checkAvailability())
            {
                cout << "Calling checkout \n";
                room.checkOut(roomNum);
                cout << "Checkout Room details:\n";
                room.printdetails();
                flag = 1; 
            }
        }
        if (flag == 0) {
            cout << "Enter valid room number or Room is already available";
        }
    }
};



int main() {
    // Create Hotel 
    Hotel hotel = Hotel("Praveen Hotel", "12,Church street, Chittoor", 5);

    hotel.addRoom(Room(AC, 101));
    hotel.addRoom(Room(AC, 102));
    hotel.addRoom(Room(Non_AC, 103));
    hotel.addRoom(Room(Non_AC, 104));
    hotel.addRoom(Room(AC, 105));
    
    // Hotel hotel = Hotel();
    // create main menu
    // cout<<"Create Hotel";
    // cout<<"Add employee";
    // cout<<"Add room";
    while (1) {
        cout << "Select one of the below options:\n";
        cout<<"1. Room availability\n";
        cout<<"2. Customer Check-in\n";
        cout<<"3. Customer check-out\n";
        int option;
        cin >> option;

        switch (option) {
        case 1: {
            hotel.displayRooms();
            break;
        }

        case 2: {
            int roomNum;
            string name, id;
            cout << "Enter room number\n";
            cin >> roomNum;
            cout << "Enter customer name\n";
            cin >> name;
            cout << "Enter any Id number";
            cin >> id;
            // vector<Room> &rooms=hotel.getRooms();
            hotel.checkin(roomNum, Customer(name, id));
            break;

        }

        // Checkout
        case 3: {
            int roomNum;
            string name, id;
            cout << "Enter room number\n";
            cin >> roomNum;
            hotel.checkout(roomNum);
            break;
        }
        default:
            break;
        }
    }

    // Add employee

}



