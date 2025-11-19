// Write a C++ program to Video Duration Merger 
// Create a class VideoDuration to represent the duration of a video in hours, minutes, and seconds. 
// Requirements: 
// • Provide default and parameterized constructors. 
// • Write a friend function mergeDuration(VideoDuration v1, VideoDuration v2) that combines the 
// lengths of two videos and returns a new VideoDuration object. 
// • Handle proper carry-over (60 seconds = 1 minute, 60 minutes = 1 hour). 
// • Use a const member function display() to show the result in hh:mm:ss format. 
// Sample Input :  
// Video 1: 1:45:20   
// Video 2: 0:35:50 
// Sample Output :  
// Total Duration: 2:21:10  


#include <iostream>
using namespace std;

class VideoDuration {
	int hours, minutes, seconds;
public:
	
	VideoDuration() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

	
	VideoDuration(int h, int m, int s) {
		hours = h;
		minutes = m;
		seconds = s;
	}

	
	friend VideoDuration mergeDuration(VideoDuration v1, VideoDuration v2);

	
	void display() const {
		cout << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << endl;
	}
};

VideoDuration mergeDuration(VideoDuration v1, VideoDuration v2) {
	int h = v1.hours + v2.hours;
	int m = v1.minutes + v2.minutes;
	int s = v1.seconds + v2.seconds;
	
	if (s >= 60) {
		m += s / 60;
		s = s % 60;
	}
	if (m >= 60) {
		h += m / 60;
		m = m % 60;
	}
	return VideoDuration(h, m, s);
}

int main() {
	
	VideoDuration v1(1, 45, 20);
	VideoDuration v2(0, 35, 50);

	VideoDuration total = mergeDuration(v1, v2);
	cout << "Total Duration: ";
	total.display();
	return 0;
}

