// Demonstrate the Hierarchical and Multiple Inheritance concepts while implementing the Air Condition (AC) 
// system using Sensor, Light and Controller components with the following requirements, 
// a. Create a Base class (Sensor) with a data member (reading) and an appropriate member function to 
// process the reading data. 
// b. Create a Base class (Controller) with a data member (autoMode)  and a member function to enable 
// the auto mode. 
// c. Create a derived class (Light) from the Base class (SmartDevice) with a data member 
// (brightnessLevel) and an appropriate member function to adjust the brightness of the light. 
// d. Derive MotionSensor from the Sensor class to detect motion. Read the data (through inherited 
// readData() from base class) and update the status of motion detected or not. 
// e. Derive SmartVent class from Controller and Light base classes with an additional feature 
// (airFlowRate) and a member function to adjust the air flow rate. 
// f. Demonstrate calls to the function inherited from the parent classes and display appropriate values. 
// (Light - adjust brightness, Controller - adjust auto mode and SmartVent - air flow rate) 
// g. Discuss whether the "Diamond Problem" issues persist in the given AC system or not, with 
// appropriate reasons. 

#include <iostream>
#include <string>
using namespace std;

// Base class: SmartDevice (for Light to inherit from)
class SmartDevice {
protected:
    string deviceName;
    bool isPoweredOn;

public:
    SmartDevice(string name = "Device") : deviceName(name), isPoweredOn(false) {}

    void powerOn() {
        isPoweredOn = true;
        cout << deviceName << " is now ON" << endl;
    }

    void powerOff() {
        isPoweredOn = false;
        cout << deviceName << " is now OFF" << endl;
    }
};

// a. Base class: Sensor
class Sensor {
protected:
    float reading;

public:
    Sensor() : reading(0.0) {}

    void readData() {
        reading = 20.0 + (rand() % 30); // Simulate sensor reading
        cout << "Sensor reading: " << reading << endl;
    }

    void processReading() {
        cout << "Processing sensor data: " << reading << endl;
        if (reading > 30) {
            cout << "High reading detected!" << endl;
        } else if (reading > 15) {
            cout << "Normal reading" << endl;
        } else {
            cout << "Low reading detected" << endl;
        }
    }

    float getReading() { return reading; }
};

// b. Base class: Controller
class Controller {
protected:
    bool autoMode;

public:
    Controller() : autoMode(false) {}

    void enableAutoMode() {
        autoMode = true;
        cout << "Auto mode ENABLED" << endl;
    }

    void disableAutoMode() {
        autoMode = false;
        cout << "Auto mode DISABLED" << endl;
    }

    void displayAutoMode() {
        cout << "Auto Mode Status: " << (autoMode ? "ON" : "OFF") << endl;
    }

    bool isAutoMode() { return autoMode; }
};

// c. Derived class: Light (from SmartDevice)
class Light : public SmartDevice {
protected:
    int brightnessLevel;

public:
    Light(string name = "Smart Light") : SmartDevice(name), brightnessLevel(0) {}

    void adjustBrightness(int level) {
        if (level >= 0 && level <= 100) {
            brightnessLevel = level;
            cout << "Light brightness adjusted to: " << brightnessLevel << "%" << endl;
        } else {
            cout << "Invalid brightness level! Must be 0-100" << endl;
        }
    }

    void displayBrightness() {
        cout << "Current brightness: " << brightnessLevel << "%" << endl;
    }

    int getBrightness() { return brightnessLevel; }
};

// d. Derived class: MotionSensor (from Sensor) - Hierarchical Inheritance
class MotionSensor : public Sensor {
private:
    bool motionDetected;

public:
    MotionSensor() : motionDetected(false) {}

    void detectMotion() {
        readData(); // Inherited from base class
        motionDetected = (reading > 25); // Motion detected if reading > 25
        
        if (motionDetected) {
            cout << "Motion DETECTED!" << endl;
        } else {
            cout << "No motion detected" << endl;
        }
    }

    void displayMotionStatus() {
        cout << "Motion Status: " << (motionDetected ? "DETECTED" : "NOT DETECTED") << endl;
    }
};

// e. Derived class: SmartVent (from Controller and Light) - Multiple Inheritance
class SmartVent : public Controller, public Light {
private:
    float airFlowRate;

public:
    SmartVent() : Controller(), Light("Smart Vent Light"), airFlowRate(0.0) {}

    void adjustAirFlowRate(float rate) {
        if (rate >= 0.0 && rate <= 100.0) {
            airFlowRate = rate;
            cout << "Air flow rate adjusted to: " << airFlowRate << "%" << endl;
        } else {
            cout << "Invalid air flow rate! Must be 0-100" << endl;
        }
    }

    void displayVentStatus() {
        cout << "\n=== Smart Vent Status ===" << endl;
        displayAutoMode();        // From Controller
        displayBrightness();      // From Light
        cout << "Air Flow Rate: " << airFlowRate << "%" << endl;
    }

    void autoAdjust(float temperature) {
        cout << "\n--- Auto Adjustment based on temperature: " << temperature << "°C ---" << endl;
        if (isAutoMode()) {
            if (temperature > 28) {
                adjustAirFlowRate(80);
                adjustBrightness(100);
                cout << "High temperature detected - maximizing cooling" << endl;
            } else if (temperature > 22) {
                adjustAirFlowRate(50);
                adjustBrightness(60);
                cout << "Moderate temperature - normal operation" << endl;
            } else {
                adjustAirFlowRate(20);
                adjustBrightness(30);
                cout << "Low temperature - minimal cooling" << endl;
            }
        } else {
            cout << "Auto mode is OFF - manual control required" << endl;
        }
    }
};

int main() {
    cout << "=== Air Condition (AC) System Demonstration ===" << endl;
    cout << "===============================================\n" << endl;

    // d. Testing MotionSensor (Hierarchical Inheritance from Sensor)
    cout << "--- Motion Sensor Testing ---" << endl;
    MotionSensor motionSensor;
    motionSensor.detectMotion();
    motionSensor.processReading();
    motionSensor.displayMotionStatus();

    cout << "\n--- Testing Again ---" << endl;
    motionSensor.detectMotion();
    motionSensor.displayMotionStatus();

    // e. Testing SmartVent (Multiple Inheritance from Controller and Light)
    cout << "\n\n--- Smart Vent Testing ---" << endl;
    SmartVent smartVent;

    // f. Demonstrate calls to inherited functions
    cout << "\n1. Testing Controller functions:" << endl;
    smartVent.enableAutoMode();

    cout << "\n2. Testing Light functions:" << endl;
    smartVent.powerOn();
    smartVent.adjustBrightness(75);

    cout << "\n3. Testing SmartVent specific functions:" << endl;
    smartVent.adjustAirFlowRate(60);

    cout << "\n4. Display complete status:" << endl;
    smartVent.displayVentStatus();

    cout << "\n5. Testing auto adjustment:" << endl;
    smartVent.autoAdjust(30);
    smartVent.displayVentStatus();

    smartVent.autoAdjust(20);
    smartVent.displayVentStatus();

  

    return 0;
}