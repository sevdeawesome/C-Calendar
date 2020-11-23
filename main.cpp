#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
   string quarterYear = "";
    int userIn = 0;
    cout << "\nEnter a quarter and year to start, example: \"winter2020\"\n" cin >> quarterYear;
    loadConfig(quarterYear + ".txt");
    //loadConfig outputs result. either creating new schedule, or editing current ones.

    do
    {
        cout << "\n1. Create Class Schedule\"\n2. Create Quiz Schedule\n3. Create Custom Events\n4. View Class Schedule\n5. View Upcoming Events\n6. View Calendar\n7. Save & Exit" cin >> userIn;

        switch (userIn)
        {
        case 1:
            //Create Class Schedule
            break;
        case 2:
            //Create Quiz Schedule
            break;
        case 3:
            //Create Custom Events
            break;
        case 4:
            //View Class Schedule
            break;
        case 5:
            //View Upcoming Events
            break;
        case 6:
            //View Calendar
            break;
        default:
            cout << "\nInvalid input, please try again.\n";
            break;
        }

    } 
    
    while (userIn <= 0 || userIn > 6);
    //save & exit.
    return 0;
}