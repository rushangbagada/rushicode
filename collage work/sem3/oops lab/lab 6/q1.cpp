// Write a programme to implement a Smart Home Management System using the 
// C++ concepts of Static members, Nested member functions and using objects 
// as function arguments. Design a system to manage rooms and smart devices, 
// focusing on tracking shared resources and demonstrating object relationships. 
// Your designed system should implement the following requirements, 
// a.  The House management system contains multiple Room objects. 
// b.  Each Room contains multiple device objects. 
// c.  Track and report on shared resources (Smart Devices) 
// d.  Device  Management:  The  system  must  be  able  to  add  devices  to 
// specific rooms. 
// e.  Power Consumption: Calculate and report the total power consumption 
// for the entire house by summing up the consumption of all devices. 
// f.  Summary:  Your  program  must  display  a  clear,  organised  list  of  all 
// rooms and the devices contained within each, along with their individual 
// power consumption. 


#include<bits/stdc++.h>
using namespace std;

class Device {
    string name;
    int powerConsumption;
    static int totalDevices; // static member to track all devices
public:
    Device(string n, int p) {
        name = n;
        powerConsumption = p;
        totalDevices++;
    }
    int getPowerConsumption() const { return powerConsumption; }
    string getName() const { return name; }
    static int getTotalDevices() { return totalDevices; }
};
int Device::totalDevices = 0;

class Room {
    string name;
    vector<Device> devices;
public:

    Room(string n)  {
        name = n;
    }
    void addDevice(const Device& d) { devices.push_back(d); }
    int getTotalPowerConsumption() const {
        int total = 0;
        for (const auto& d : devices) total += d.getPowerConsumption();
        return total;
    }
    void displayDevices() const {
        cout << "Devices in room " << name << ":\n";
        // Nested member function
        auto showDevice = [](const Device& d) {
            cout << "- " << d.getName() << " (Power: " << d.getPowerConsumption() << "W)\n";
        };
        for (const auto& d : devices) showDevice(d);
    }
    string getName() const { return name; }
    int getDeviceCount() const { return devices.size(); }
};

class House {
    vector<Room> rooms;
public:
    void addRoom(const Room& r) { rooms.push_back(r); }
    void addDeviceToRoom(const Device& d, int roomIndex) {
        if (roomIndex >= 0 && roomIndex < rooms.size())
            rooms[roomIndex].addDevice(d);
    }
    int getTotalPowerConsumption() const {
        int total = 0;
        for (const auto& r : rooms) total += r.getTotalPowerConsumption();
        return total;
    }
    void displaySummary() const {
        cout << "Smart Home Summary:\n";
        for (const auto& r : rooms) {
            cout << "Room: " << r.getName() << " (" << r.getDeviceCount() << " devices, Power: " << r.getTotalPowerConsumption() << "W)\n";
            r.displayDevices();
        }
        cout << "Total devices in house: " << Device::getTotalDevices() << "\n";
        cout << "Total power consumption: " << getTotalPowerConsumption() << "W\n";
    }
};



int main() {
    House myHouse;
    Room living("Living Room"), bed("Bedroom");
    Device tv("TV", 120), lamp("Lamp", 40), ac("AC", 1500);
    myHouse.addRoom(living);
    myHouse.addRoom(bed);
    myHouse.addDeviceToRoom(tv, 0);    
    myHouse.addDeviceToRoom(lamp, 0);  
    myHouse.addDeviceToRoom(ac, 1);  
    myHouse.displaySummary();
    return 0;
}


