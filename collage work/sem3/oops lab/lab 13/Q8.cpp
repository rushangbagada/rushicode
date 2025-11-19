// Q8: Date and Time Table with User-Defined Manipulator
// Demonstrates: Custom manipulators, date formatting, table display

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

// User-defined manipulator for date formatting
ostream& formatDate(ostream& os) {
    // This is a simple manipulator that can be extended
    // For real date formatting, you'd pass date strings through
    return os;
}

struct Event {
    string name;
    string date; // Format: YYYY-MM-DD
};

// Function to validate and format date
string validateDate(const string& date) {
    // Basic validation - assumes format YYYY-MM-DD or variations
    if(date.length() >= 8) {
        // Extract components
        stringstream ss(date);
        string year, month, day;
        char delim;
        
        if(date.find('-') != string::npos) {
            getline(ss, year, '-');
            getline(ss, month, '-');
            getline(ss, day, '-');
        } else if(date.find('/') != string::npos) {
            getline(ss, year, '/');
            getline(ss, month, '/');
            getline(ss, day, '/');
        } else {
            return date;
        }
        
        // Ensure proper formatting
        if(month.length() == 1) month = "0" + month;
        if(day.length() == 1) day = "0" + day;
        
        return year + "-" + month + "-" + day;
    }
    return date;
}

// Custom manipulator function that formats dates
class DateFormatter {
private:
    string date;
public:
    DateFormatter(const string& d) : date(d) {}
    
    friend ostream& operator<<(ostream& os, const DateFormatter& df) {
        os << validateDate(df.date);
        return os;
    }
};

DateFormatter formatDateString(const string& date) {
    return DateFormatter(date);
}

int main() {
    int n;
    cout << "Enter number of events: ";
    cin >> n;
    cin.ignore();
    
    Event events[n];
    
    // Input event details
    for(int i = 0; i < n; i++) {
        cout << "\n--- Event " << (i+1) << " ---\n";
        
        cout << "Enter Event Name: ";
        getline(cin, events[i].name);
        
        cout << "Enter Date (YYYY-MM-DD): ";
        getline(cin, events[i].date);
        
        // Validate and format date
        events[i].date = validateDate(events[i].date);
    }
    
    // Display Events Table
    cout << "\n\n";
    cout << string(80, '=') << endl;
    cout << setw(45) << "EVENT SCHEDULE" << endl;
    cout << string(80, '=') << endl;
    
    // Table Header
    cout << left << setw(10) << "Sr. No."
         << setw(45) << "Event Name"
         << right << setw(25) << "Date (YYYY-MM-DD)" <<endl;
    cout << string(80, '-') << endl;
    
    // Display events
    for(int i = 0; i < n; i++) {
        cout << left << setw(10) << (i+1)
             << setw(45) << events[i].name
             << right << setw(25) << formatDateString(events[i].date) << endl;
    }
    
    cout << string(80, '=') << endl;
    
    // Display in alternative format
    cout << "\n\n";
    cout << string(80, '=') << endl;
    cout << setw(50) << "DETAILED EVENT LIST" << endl;
    cout << string(80, '=') << endl;
    
    for(int i = 0; i < n; i++) {
        cout << "\n";
        cout << right << setw(15) << "Event #" << (i+1) << endl;
        cout << string(80, '-') << endl;
        
        cout << left << setw(20) << "Event Name:" 
             << setw(60) << events[i].name << endl;
        
        cout << left << setw(20) << "Scheduled Date:" 
             << right << formatDateString(events[i].date) << endl;
        
        // Parse and display date components
        stringstream ss(events[i].date);
        string year, month, day;
        getline(ss, year, '-');
        getline(ss, month, '-');
        getline(ss, day, '-');
        
        cout << left << setw(20) << "  Year:" << year << endl;
        cout << left << setw(20) << "  Month:" << month << endl;
        cout << left << setw(20) << "  Day:" << day << endl;
    }
    
    cout << "\n" << string(80, '=') << endl;
    
    // Calendar view
    cout << "\n\n";
    cout << string(80, '=') << endl;
    cout << setw(45) << "CALENDAR VIEW" << endl;
    cout << string(80, '=') << endl;
    
    cout << right << setw(25) << "Date"
         << setw(55) << "Event" << endl;
    cout << string(80, '-') << endl;
    
    // Sort events by date (simple bubble sort)
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(events[j].date > events[j+1].date) {
                Event temp = events[j];
                events[j] = events[j+1];
                events[j+1] = temp;
            }
        }
    }
    
    // Display sorted events
    for(int i = 0; i < n; i++) {
        cout << right << setw(25) << formatDateString(events[i].date)
             << "  →  " << left << events[i].name << endl;
    }
    
    cout << string(80, '=') << endl;
    
    return 0;
}
