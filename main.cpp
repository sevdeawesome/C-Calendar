#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <utility>

#include "../header/FileIO.hpp"
#include <fstream>

using namespace std;

/*
explode functionality copied from 
https://stackoverflow.com/questions/12966957/is-there-an-equivalent-in-c-of-phps-explode-function
by Kerrek SB
*/
vector<string> explode(string const & s, char delim)
{
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim); )
    {
        result.push_back(move(token));
    }

    return result;
}


int main(){
    
    Plan * thePlan = new Plan();
    // Event * exampleClass = new Class("CS100", "Class", 861203123);
    // Event * exampleCustom = new customEvent("CS100", "customEvent", 861203123 , "red");
    // Event * colorDecorator = customEvent();
    
    // Event * exampleQuiz = new Quiz("CS100", "Quiz", 861203123);
    // thePlan->addEvent(exampleEvent);
    
    string quarterYear = "";
    cout << "\nEnter a quarter and year to start, example: \"winter2020\"\n";
    cin >> quarterYear;
    
    fstream fs;
    fs.open(quarterYear);
    if(fs.fail()){
        //file doesn't exist, move on and save it as a new file when we're done.
    }else{
        //file does exist, read data from file
        FileIO::GetInstance()->readFromFile(quarterYear);
        
        string inText = FileIO::GetInstance()->showAllData(); 
        //inText has a chunk of text to be processed into the event object.
        
        if(inText.length()==0){
            //file is empty
        }else{
            
            auto plode = explode(inText, "\n");

            for (string chunk : plode){
                auto chunkPlode = explode(chunk, "|");
                for (string item : chunkPlode){
                    //item[0] = event name
                    //item[1] = event type
                    //item[2] = event time
                    switch(item[1]){
                        case "Class" :
                            Event * theClass = new Class(item[0], item[1], item[2]);
                            thePlan->addEvent(theClass);
                            delete theClass;
                            break;

                        case "Quiz" :
                            Event * theQuiz = new Quiz(item[0], item[1], item[2]);
                            thePlan->addEvent(theQuiz);
                            delete theQuiz;
                            break;

                        case "customEvent":
                            Event * aCustomEvent = new customEvent(item[0], item[1], item[2],item[3],item[4]);
                            thePlan->addEvent(aCustomEvent);
                            delete aCustomEvent;
                            break;
                    }//end of switch

                }//end of for item

            }//end of for chunk
            
        }//end of if inTest length check.
        
    }//end of processing for read data.
    
    
    
    
    //data is either loaded right now, or an empty instance of FileIO is there for us to use.
    
    
     
     

    

    int userIn = 0;
    do
    {
        cout << "\n1. Create Class Schedule\"\n2. Create Quiz Schedule\n3. Create Custom Events\n4. View Class Schedule\n5. View Upcoming Events\n6. View Calendar\n7. Save & Exit"; 
        cin >> userIn;
        
        switch (userIn)
        {
        case 1:
            //Create Class Schedule
            string type = "Class";
            string name;
            int time;
            
            cout << "Enter the name of the class: " << endl;
            cin >> name;
            cout << endl;
            cout << "Enter the time of the first class (in unix time): " << endl;
            cin >> time;
            cout << endl;
            
            Event * newClass = new Class(name, type, time);
            thePlan->addEvent(newClass);
      

            //class schedule: CS100 | class | MWF | 16002101010 
            //quiz: CS100 Test | quiz | null | 156001010
            //CS100 assignment due | custom | null | 11650651651
            
            
            //Water polo practice || custom || null || 15123123123 || blue || 1
            
             //Event eventA = Event(10000, "blah blah", "blah blah");
            
            //FileIO::GetInstance()->addData(eventA.printCalendar());//
            break;
        case 2:
            //Create Quiz Schedule
            
            
            string type = "Quiz";
            string name;
            int time;
            
            cout << "Enter the name of the class the quiz is in: " << endl;
            cin >> name;
            cout << endl;
            cout << "Enter the time of the quiz (in unix time): " << endl;
            cin >> time;
            cout << endl;
            
            Event * newQuiz = new Quiz(name, type, time);
            thePlan->addEvent(newQuiz);
            
            break;
        case 3:
            //Create Custom Events
            //REQUIRES IMPLEMENTATION
            //allows for creating custom events then customizing with decorators
            string type = "customEvent";
            string color = " ";
	        string name = " ";
	        string info = " ";
	        int time = 0;
	        int priority = 0;
            
            cout << "Enter a color for your custom event."<<endl;
			cin >> color;
			cout<<"Enter a name for your custom event." << endl;
			cin >> name;
			cout << "Enter a  for your custom event." << endl;
			cin >> info;
			cout << "Enter a time (in unix) for your custom event." << endl;
			cin >> time;
			cout << "Enter a number of priority for your custom event." << endl;
			cin >> priority;
			Event *custom = new customEvent(color,name,info,time,priority);
			thePlan->addEvent(custom);
			cout << "The custom event has been added." << endl;
            cout << "implementation here -- Alex";
            break;
        case 4:
            //View Class Schedule
            cout << thePlan->printSchedule();
            break;
        case 5:
            //View Upcoming Events
            cout << thePlan->printUpComingEvents();
            break;
        case 6:
            //View Calendar
            cout << thePlan->printCalendar();
            //this is deprocated and will only show you whats in the file
            
            break;
        default:
            cout << "\nInvalid input, please try again.\n";
            break;
        }

    } 
    
    while (userIn <= 0 || userIn > 6);
    FileIO::GetInstance()->addData(thePlan->printCalendar());//
     //class schedule: CS100 | class | MWF | 16002101010 
     //quiz: CS100 Test | quiz | null | 156001010
     //CS100 assignment due | custom | null | 11650651651
    FileIO::GetInstance()->writeToFile(quarterYear); //save & exit.

    return 0;
}