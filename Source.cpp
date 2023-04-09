/*
Elliot Putnam
CS210

This program is designed to dispay two clock formats simultaneously (12H and 24H)
*/

#include <iostream>
#include <ctime>

using namespace std;

int hours, minutes, seconds;  // Vars to hold clock values
int option;                   // Var to hold user input
string ampm;                  // Var to hold 'AM' or 'PM' 

// Function to add hours to clock, resets at 24
void AddHour() {
    if (hours == 24) {
        hours = 1;

    }
    else {
        hours += 1;
    }
}

// Function to add minutes, calls hour function at 59
void AddMinute() { 
	if (minutes == 59) {
		AddHour();
        minutes = 0;
	}
    else {
        minutes += 1;
    }
}

// Function to add seconds, calls minute function at 59
void AddSecond() { 

	if (seconds == 59) {
		AddMinute();
        seconds = 0;
	}
    else {
        seconds += 1;
    }
}

// Funtion to check & correct if parameters are valid for Format12Hour and Format24Hour functions
void ClockChecker(int hour, int minute, int second) {
    if (hour > 24) { // sets hour if out of clock range 
        hours = 24;
    }
    if (minute > 59) { // sets minute in range
        minutes = 59;
    }
    if (second > 59) { // sets second in range
        seconds = 59;
    }
}

// Formats hours into 12 Hour intervals
void Format12Hour(int hour, int minute, int second) { 
    
    ClockChecker(hour, minute, second); // Checks if clock parameters are valid

    int twelveHour = hours; // Set for clearer understanding

    if (twelveHour == 24) { //24 is 12 AM
        twelveHour -= 12;
        ampm = "AM";
    }
    else if (twelveHour == 12) { // noon PM
        ampm = "PM";
    }
    else if (twelveHour > 12) { // above noon is PM
        twelveHour -= 12;
        ampm = "PM";
    }
    else if (twelveHour <= 11) { // 1-11 is AM
        ampm = "AM";
    }
    if (twelveHour < 10) {
        cout << "0" << twelveHour << ":";
    }
    else {
        cout << twelveHour << ":";
    }
    if (minutes < 10) {
        cout << "0" << minutes << ":";
    }
    else {
        cout << minutes << ":";
    }
    if (seconds < 10) {
        cout << "0" << seconds;
    }
    else {
        cout << seconds;
    }
    cout << " " << ampm;
}

// Formats hours into 24 hour intervals
void Format24Hour(int hour, int minute, int second) {
    
    ClockChecker(hour, minute, second); // Checks for valid parameters
    
    int twoFourHours = hours;

    if (twoFourHours == 24 && seconds != 0) {
        twoFourHours = 0;
    }

    if (twoFourHours < 10) {
        cout << "0" << twoFourHours << ":";
    }
    else {
        cout << twoFourHours << ":";
    }
    if (minutes < 10) {
        cout << "0" << minutes << ":";
    }
    else {
        cout << minutes << ":";
    }
    if (seconds < 10) {
        cout << "0" << seconds;
    }
    else {
        cout << seconds;
    }


}

// Displays user menu in ASCI border
void DisplayMenu() {
    cout << endl;
	cout << "         ************************" << endl;
	cout << "         * 1 - Add one hour     *" << endl;
	cout << "         * 2 - Add one minute   *" << endl;
	cout << "         * 3 - Add one second   *" << endl;
	cout << "         * 4 - Exit program     *" << endl;
    cout << "         ************************" << endl;
}

// Dispays 12Hour and 24Hour Clocks in ASCI border
void DisplayClocks(int hour, int minute, int second) {
    
    
    cout << "********************   ********************" << endl;
    cout << "*  12-Hour Clock   *   *   24-Hour Clock  *" << endl;
    cout << "*   "; 
    
    Format12Hour(hour, minute, second);

    cout << "    *   *     "; // Space between clocks

    Format24Hour(hour, minute, second);

    cout << "     *" << endl;
    cout << "********************   ********************" << endl;
}   

// Function to perform user input selections
void userInput() {

        cin >> option;
        // If user input is 1, AddHour function is called
        if (option == 1) {

            AddHour();
        }
        // If the option is 2, AddMinute function is called
        else if (option == 2) {

            AddMinute();
        }
        // If the option is 3, AddSecond function is called
        else if (option == 3) {

            AddSecond();
        }
        // If the option is 4, exit message prints and application stops running
        else if (option == 4) {

            cout << "You have exited the application.";
            return;
        }
        else {
            cout << "You have entered an invalid input." << endl;
        }
}

// Main function
int main() {

	seconds = 10;
	minutes = 60;
	hours = 3;

    do
    {
        DisplayClocks(hours, minutes, seconds); //DisplayClocks function is called
        
        DisplayMenu(); // DisplayMenu function is called
        
        userInput(); // Handles user input 

    } while (option != 4); // 4 is to quit within userInput function
}

// END
