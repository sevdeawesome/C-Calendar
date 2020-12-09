#include <iostream>
#include <string>
#include <array>

#include "../header/FileIO.hpp"
#include <fstream>

using namespace std;


int main(){
    
    string quarterYear = "";
    cout << "\nEnter a quarter and year to start, example: \"winter2020\"\n" cin >> quarterYear;
    
    fstream fs;
    fs.open(quarterYear);
    if(fs.fail()){
        //file doesn't exist, move on and save it as a new file when we're done.
    }else{
        //file does exist, read data from file
        FileIO::GetInstance()->readFromFile(quarterYear);
    }
    
    //data is either loaded right now, or an empty instance of FileIO is there for us to use.
    

    int userIn = 0;
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
    
    FileIO::GetInstance()->writeToFile(quarterYear); //save & exit.

    return 0;
}
