// Model a Smart IOT Device and develop a core firmware for centralized IoT platform that manages data from 
// various smart devices (e.g. Watch, Camera, ...) uniformly, with each different type of device having unique 
// functionality. Developing the system by demonstrating the inheritance concepts with the following 
// requirements, 
// a. Create a base class with common features and behaviours for smart devices. (e.g, SmartIoTDevice 
// class with data member deviceId, isConnected, and member function connect() and displayStatus()) 
// b. Create a derived class with unique features according to the type of device. (e.g. - SmartWatch class 
// with heartRate and CCTV class with isRecording features) 
// i. SmartWatch - showcase connection through Wi-Fi 
// ii. CCTV - showcase connection through Bluetooth 
// iii. Add a behaviour (processData()) that processes the data relevant to the unique features 
// added to the class and displays the status of each feature. 
// c. Add one more smart device of your choice and implement its feature with appropriate behaviour. 
// (similar to the SmartWatch and CCTV) 
// d. Store the objects of all the different types of devices as a heterogeneous collection to manage them 
// as a single unified type (base class). Iterate through each device from the collection and display the 
// status of its features

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class for all smart IoT devices
class SmartIoTDevice {
protected:
    string deviceId;
    bool isConnected;
    string deviceType;

public:
    SmartIoTDevice(string id, string type) 
        : deviceId(id), isConnected(false), deviceType(type) {}

    virtual ~SmartIoTDevice() {}

    virtual void connect() {
        isConnected = true;
        cout << deviceType << " [" << deviceId << "] connected successfully." << endl;
    }

    virtual void disconnect() {
        isConnected = false;
        cout << deviceType << " [" << deviceId << "] disconnected." << endl;
    }

    virtual void displayStatus() {
        cout << "\n--- " << deviceType << " Status ---" << endl;
        cout << "Device ID: " << deviceId << endl;
        cout << "Connection Status: " << (isConnected ? "Connected" : "Disconnected") << endl;
    }

    virtual void processData() = 0; // Pure virtual function
};

// SmartWatch - connects via Wi-Fi
class SmartWatch : public SmartIoTDevice {
private:
    int heartRate;
    int steps;

public:
    SmartWatch(string id) 
        : SmartIoTDevice(id, "SmartWatch"), heartRate(0), steps(0) {}

    void connect() override {
        cout << "Connecting SmartWatch via Wi-Fi..." << endl;
        SmartIoTDevice::connect();
    }

    void processData() override {
        if (isConnected) {
            heartRate = 72 + rand() % 30; // Simulate heart rate
            steps = 5000 + rand() % 5000;  // Simulate steps
            cout << "Processing SmartWatch data..." << endl;
            cout << "Heart Rate: " << heartRate << " bpm" << endl;
            cout << "Steps: " << steps << endl;
        } else {
            cout << "SmartWatch not connected. Cannot process data." << endl;
        }
    }

    void displayStatus() override {
        SmartIoTDevice::displayStatus();
        cout << "Connection Type: Wi-Fi" << endl;
        if (isConnected) {
            cout << "Heart Rate: " << heartRate << " bpm" << endl;
            cout << "Steps Count: " << steps << endl;
        }
    }
};

// CCTV - connects via Bluetooth
class CCTV : public SmartIoTDevice {
private:
    bool isRecording;
    int videoQuality; // 720p, 1080p, etc.

public:
    CCTV(string id) 
        : SmartIoTDevice(id, "CCTV Camera"), isRecording(false), videoQuality(1080) {}

    void connect() override {
        cout << "Connecting CCTV via Bluetooth..." << endl;
        SmartIoTDevice::connect();
    }

    void processData() override {
        if (isConnected) {
            isRecording = true;
            cout << "Processing CCTV data..." << endl;
            cout << "Recording Status: " << (isRecording ? "Recording" : "Stopped") << endl;
            cout << "Video Quality: " << videoQuality << "p" << endl;
            cout << "Storage Used: " << (rand() % 50 + 10) << "%" << endl;
        } else {
            cout << "CCTV not connected. Cannot process data." << endl;
        }
    }

    void displayStatus() override {
        SmartIoTDevice::displayStatus();
        cout << "Connection Type: Bluetooth" << endl;
        if (isConnected) {
            cout << "Recording: " << (isRecording ? "Yes" : "No") << endl;
            cout << "Video Quality: " << videoQuality << "p" << endl;
        }
    }
};

// SmartThermostat - connects via Wi-Fi (our custom device)
class SmartThermostat : public SmartIoTDevice {
private:
    float currentTemp;
    float targetTemp;
    string mode; // heating, cooling, auto

public:
    SmartThermostat(string id) 
        : SmartIoTDevice(id, "Smart Thermostat"), 
          currentTemp(22.0), targetTemp(24.0), mode("auto") {}

    void connect() override {
        cout << "Connecting Smart Thermostat via Wi-Fi..." << endl;
        SmartIoTDevice::connect();
    }

    void processData() override {
        if (isConnected) {
            currentTemp = 18.0 + (rand() % 15);
            cout << "Processing Thermostat data..." << endl;
            cout << "Current Temperature: " << currentTemp << "°C" << endl;
            cout << "Target Temperature: " << targetTemp << "°C" << endl;
            cout << "Mode: " << mode << endl;
            
            if (currentTemp < targetTemp) {
                cout << "Status: Heating" << endl;
            } else if (currentTemp > targetTemp) {
                cout << "Status: Cooling" << endl;
            } else {
                cout << "Status: Temperature Optimal" << endl;
            }
        } else {
            cout << "Thermostat not connected. Cannot process data." << endl;
        }
    }

    void displayStatus() override {
        SmartIoTDevice::displayStatus();
        cout << "Connection Type: Wi-Fi" << endl;
        if (isConnected) {
            cout << "Current Temp: " << currentTemp << "°C" << endl;
            cout << "Target Temp: " << targetTemp << "°C" << endl;
            cout << "Mode: " << mode << endl;
        }
    }
};

int main() {
    cout << "=== Smart IoT Device Management System ===" << endl;
    cout << "==========================================\n" << endl;

    // Create heterogeneous collection of IoT devices
    vector<SmartIoTDevice*> devices;

    // Add different types of devices
    devices.push_back(new SmartWatch("SW-001"));
    devices.push_back(new CCTV("CCTV-001"));
    devices.push_back(new SmartThermostat("THERMO-001"));
    devices.push_back(new SmartWatch("SW-002"));

    // Connect all devices
    cout << "=== Connecting Devices ===" << endl;
    for (auto device : devices) {
        device->connect();
    }

    cout << "\n=== Processing Data from All Devices ===" << endl;
    for (auto device : devices) {
        cout << "\n";
        device->processData();
    }

    cout << "\n=== Displaying Status of All Devices ===" << endl;
    for (auto device : devices) {
        device->displayStatus();
    }

    // Cleanup
    cout << "\n=== Disconnecting Devices ===" << endl;
    for (auto device : devices) {
        device->disconnect();
        delete device;
    }

    return 0;
}
