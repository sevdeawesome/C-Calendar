#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <utility>
#include <fstream>
#include "header/FileIO.hpp"
#include "header/customEvent.hpp"
#include "header/Event.hpp"
#include "header/Quiz.hpp"
#include "header/Plan.hpp"
#include "header/Class.hpp"
#include "header/priorityDecorator.hpp"
#include "header/timeConverter.hpp"
#include "header/colorDecorator.hpp"

using namespace std;
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
   Plan * thePlan = new Plan("PlannerA");
   string quarterYear = "";
    int userIn=0;
    cout << "\nEnter a quarter and year to start, example: \"winter2020\"\n";
    cin >> quarterYear;
	  fstream fs;
    fs.open(quarterYear);
    if(fs.fail()){

    }else {
		//file does exist, read data from file
		FileIO::GetInstance()->readFromFile(quarterYear);
		//
		string inText = FileIO::GetInstance()->showAllData();
		//inText has a chunk of text to be processed into the event object.
		if (inText.length() == 0) {
			//file is empty
		}else {

			//auto plode = explode(inText, "\n");
			//for (string chunk : plode){
			//split text line by line function/idea copied from 
			//https://stackoverflow.com/questions/5059049/read-a-string-line-by-line-using-c												
			//by Martin Stone
			//reason: the previous explode function only accepts char, we need to split text string by the newline character \n.
		istringstream f(inText);
            string line; 
            while (std::getline(f, line)) {
                auto linePlode = explode(line, '|');
                for (string item : linePlode){

		  //item[0] = event name
		  //item[1] = event type
		  //item[2] = event time
		  //event type c = "Class"
		  //event type q = "Quiz"
		  //event type e = "customEvent"
		      switch(item[1]){
                        case 'c':
                        {
                            Event * theClass = new Class(item[0], item[1], item[2]);
                            thePlan->addEvent(theClass);
                            delete theClass;
                        }
                            break;
                        
                        case 'q':
                        {
                            Event * theQuiz = new Quiz(item[0], item[1], item[2]);
                            thePlan->addEvent(theQuiz);
                            delete theQuiz;
                        }
                            break;

                        case 'u':
                        {
                            Event * aCustomEvent = new customEvent(item[0], item[1], item[2]);
                            thePlan->addEvent(aCustomEvent);
                            delete aCustomEvent;
                        }
                            break;
                        default :
                            cout << "Event Type Error" << endl;
				    }		
				}
			}
		    }
		}
	}
	
    string type;
    string name;
    string color;
    int ti;
    int priority;
    //Event * newClass; 
   // Event * newQuiz;

    do
    {
        cout << "\n1. Create Class Schedule\"\n2. Create Quiz Schedule\n3. Create Custom Events\n4. View Class Schedule\n5. View Upcoming Events\n6. View Calendar\n7. Save & Exit\n";
	 cin >> userIn;

        switch (userIn)
        {
        case 1:
            
	//Create Class Schedule
            break;
        case 2:
            //Create Quiz Schedule
            break;
        case 3:

	type = "customEvent";
	name = "";
	color ="";
	priority =0;
	cout<<"Enter a name for your custom event." << endl;
	cin >> name;
	cout << "Enter a time (in unix) for your custom event." << endl;
	cin >> ti;
	Event *custom = new customEvent(name,type,ti);
	cout << "Enter a color for your custom event."<<endl;
	cin >> color;
	custom = new colorDecorator(new customEvent( name, type, ti));
	cout << "Enter a number of priority for your custom event." << endl;
	cin >> priority;
	thePlan->addEvent(custom);
	cout << "The custom event has been added." << endl;
	cout << custom <<endl;
	delete custom;
		
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
	case 7:
		cout<<"The program will now exit.\n";
		exit(1);
        default:
            cout << "\nInvalid input, please try again.\n";
            break;
        }
    } 
    
    while (userIn <= 0 || userIn > 6);
    //save & exit.
    return 0;
}
