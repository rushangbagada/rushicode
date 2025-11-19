// (e.g., Light).
// a. Task:
//  i. Design a Smart Device Class: Implement a C++ class to represent a smart
// device.
//  ii. Define Member Variables and Functions:
// 1. The class should have member variables to store the device's state
// (e.g., status, brightness).
// 2. Implement member functions to manipulate and access the device's
// state.
// b. System Requirements: Your developed system must fulfil the following
// requirements,
//  i. Implement Function Overloading: Use function overloading for one or
// more actions to provide different ways of controlling the device.
//  ii. Display Device Status:
// 1. Your program must display the initial state of the device.
// 2. After applying various settings and actions, the program should display
// the updated state.
// c. For example: Implement a SmartLight device with the following properties,
//  i. Name: A string to identify the light (e.g., "Living Room Light").
//  ii. Status: A boolean or enum to represent its on/off state.
//  iii. Brightness: An integer value ranging from 0 to 100, where 0 means the light
// is off.
//  iv. Functions: togglePower(), changeSetting(int brightness), displayState()
// d. Extend Functionality: After successfully implementing the SmartLight, implement
// the same requirements for a second smart device of your choice.
#include <iostream>
#include <string>
using namespace std;

class SmartLight {
	string name;
	bool status; 
	int brightness;
public:
	SmartLight(string n, bool s = false, int b = 0){
        name = n;
        status = s;
        brightness = b;
    }

	void togglePower() {
		status = !status;
		if (!status) brightness = 0;
	}

		void changeSetting(int b) {
		if (b < 0) b = 0;
		if (b > 100) b = 100;
		brightness = b;
		status = (b > 0);
	}
	void changeSetting(bool s) {
		status = s;
		if (!s) brightness = 0;
		else if (brightness == 0) brightness = 50; 
	}

	void displayState() {
		cout << "Light: " << name << endl;
		cout << "Status: " << (status ? "ON" : "OFF") << endl;
		cout << "Brightness: " << brightness << endl;
		cout << "--------------------------" << endl;
	}
};

class SmartFan {
	string name;
	bool status;
	int speed; 
public:
	SmartFan(string n, bool s = false, int sp = 0) {
        name = n;
        status = s;
        speed = sp;
    }

	void togglePower() {
		status = !status;
		if (!status) speed = 0;
	}

	
	void changeSetting(int sp) {
		if (sp < 0) sp = 0;
		if (sp > 5) sp = 5;
		speed = sp;
		status = (sp > 0);
	}
	void changeSetting(bool s) {
		status = s;
		if (!s) speed = 0;
		else if (speed == 0) speed = 3; 
	}

	void displayState() {
		cout << "Fan: " << name << endl;
		cout << "Status: " << (status ? "ON" : "OFF") << endl;
		cout << "Speed: " << speed << endl;
		cout << "--------------------------" << endl;
	}
};

int main() {
	SmartLight light("Living Room Light");
	SmartFan fan("Bedroom Fan");

	cout << "Initial States:\n";
	light.displayState();
	fan.displayState();

	
	light.changeSetting(75);
	fan.changeSetting(4);   

	light.togglePower();     
	fan.changeSetting(false); 

	light.changeSetting(true); 
	fan.changeSetting(true); 

	cout << "\nUpdated States:\n";
	light.displayState();
	fan.displayState();

	return 0;
}
