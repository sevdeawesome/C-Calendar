#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <utility>

#include "header/FileIO.hpp"
#include <fstream>

//NEW INCLUDES
#include "header/Event.hpp"
#include "header/Plan.hpp"
#include "header/Class.hpp"
#include "header/Quiz.hpp"

using namespace std;

/*
explode function copied from 
https://stackoverflow.com/questions/12966957/is-there-an-equivalent-in-c-of-phps-explode-function
by Kerrek SB
*/
vector<string> explode(string const &s, char delim)
{
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim);)
    {
        result.push_back(move(token));
    }

    return result;
}

int main()
{

    Plan *thePlan = new Plan("PlannerA");
    // Event * exampleClass = new Class("CS100", "Class", 861203123);
    // Event * exampleCustom = new customEvent("CS100", "customEvent", 861203123 , "red");
    // Event * colorDecorator = customEvent();

    // Event * exampleQuiz = new Quiz("CS100", "Quiz", 861203123);
    // thePlan->addEvent(exampleEvent);

    string quarterYear = "";
    cout << "\nEnter a quarter and year to start, example: \"winter2020\"\n";
    cin >> quarterYear;

    fstream fs;
    fs.open(quarterYear + ".txt");
    if (fs.fail())
    {
        //file doesn't exist, move on and save it as a new file when we're done.
    }
    else
    {
        //file does exist, read data from file

        FileIO::GetInstance()->readFromFile(quarterYear + ".txt");

        string inText = FileIO::GetInstance()->showAllData();
        //inText has a chunk of text to be processed into the event object.

        if (inText.length() == 0)
        {
            //file is empty
            cout << "\n***Schedule file exists but empty, moving on.***\n";
        }
        else
        {

            //auto plode = explode(inText, "\n");

            //for (string chunk : plode){

            //split text line by line function/idea copied from
            //https://stackoverflow.com/questions/5059049/read-a-string-line-by-line-using-c
            //by Martin Stone
            //reason: the previous explode function only accepts char, we need to split text string by the newline character \n.
            istringstream f(inText);
            string line = "";
            while (getline(f, line))
            {
                if (line.length() == 0)
                {
                    //skipping empty line.
                    break;
                }
                auto item = explode(line, '|');

                //item[0] = event name
                //item[1] = event type
                //item[2] = event time

                //event type c = "Class"
                //event type q = "Quiz"
                //event type e = "customEvent"

                string selectorString = "";
                selectorString = item[1];

                char eventSelector = 'a';
                eventSelector = selectorString[0];

                switch (eventSelector)
                {
                case 'c':
                {
                    string a = "";
                    a += item[0]; //name

                    string b = "";
                    b += item[1]; //type

                    string c = "";
                    c += item[2]; //recurrence

                    string d = "";
                    d += item[3]; //time
                    int cTime = stoi(d);

                    Event *theClass = new Class(a, b, cTime, c);
                    thePlan->addEvent(theClass);
                    break;
                }

                case 'q':
                {
                    string a = "";
                    a += item[0]; //name

                    string b = "";
                    b += item[1]; //type

                    string d = "";
                    d += item[2]; //time
                    int cTime = stoi(d);

                    Event *theQuiz = new Quiz(a, b, cTime);
                    thePlan->addEvent(theQuiz);
                    break;
                }

                /*
                        case 'u':
                        {
                            string d = "";
                            d+= item[3];

                            string e = "";
                            e+= item[4];

                            Event * aCustomEvent = new customEvent(a, item[1], cTime, d, e);
                            thePlan->addEvent(aCustomEvent);
                            delete aCustomEvent;
                        }
                            break;
                        */
                default:
                    cout << "\nEvent Type Error, Try Again.\n";
                } //end of switch

            } //end of while
            //}//end of for chunk

        } //end of if inTest length check.

    } //end of processing for read data.

    //data is either loaded right now, or an empty instance of FileIO is there for us to use.

    string type;
    string name;
    int time;
    Event *newClass;
    Event *newQuiz;

    int userIn = 0;
    do
    {
        cout << "\n1. Create Class Schedule\n2. Create Quiz Schedule\n3. Create Custom Events\n4. View Class Schedule\n5. View Upcoming Events\n6. View Calendar\n7. Save & Exit\n";
        cin >> userIn;

        switch (userIn)
        {
        case 1:
            //Create Class Schedule
            type = "Class";
            name = "";

            cout << "Enter the name of the class: " << endl;
            cin >> name;
            cout << endl;
            cout << "Enter the time of the first class (in unix time): " << endl;
            cin >> time;
            cout << endl;

            newClass = new Class(name, type, time);
            thePlan->addEvent(newClass);
		FileIO::GetInstance()->addData(newClass->printCalendar());
            //class schedule: CS100 | class | MWF | 16002101010
            //quiz: CS100 Test | quiz | null | 156001010
            //CS100 assignment due | custom | null | 11650651651

            //Water polo practice || custom || null || 15123123123 || blue || 1

            //Event eventA = Event(10000, "blah blah", "blah blah");

            //FileIO::GetInstance()->addData(eventA.printCalendar());//
            break;
        case 2:
            //Create Quiz Schedule

            type = "Quiz";
            name = "";

            cout << "Enter the name of the class the quiz is in: " << endl;
            cin >> name;
            cout << endl;
            cout << "Enter the time of the quiz (in unix time): " << endl;
            cin >> time;
            cout << endl;

            newQuiz = new Quiz(name, type, time);
            thePlan->addEvent(newQuiz);
		FileIO::GetInstance()->addData(newQuiz->printCalendar());
            break;
        case 3:
            //Create Custom Events
            //REQUIRES IMPLEMENTATION
            //allows for creating custom events then customizing with decorators

            /* 
            //POSSIBLE OPTION:
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
            
            */

            cout << "The custom event has been added." << endl;
            cout << "implementation here Alex";
            break;
        case 4:
            //View Class Schedule
            cout << thePlan->printSchedule();
            break;
        case 5:
            //View Upcoming Events
            cout << thePlan->printUpcomingEvents();
            break;
        case 6:
            //View Calendar
            cout << thePlan->printCalendar();
            //this is deprocated and will only show you whats in the file

            break;
        case 7:
        {
           // FileIO::GetInstance()->addData(thePlan->printCalendar()); //
                                                                      //class schedule: CS100 | class | MWF | 16002101010
                                                                      //quiz: CS100 Test | quiz | null | 156001010
                                                                      //CS100 assignment due | custom | null | 11650651651

            
            FileIO::GetInstance()->writeToFile(quarterYear + ".txt"); //save & exit.
            return 0;
        }
        default:
            cout << "\nInvalid input, please try again.\n";
            break;
        }

    }

    while (userIn == 1 || userIn == 2 || userIn == 3 || userIn == 4 || userIn == 5 || userIn == 6 || userIn == 7);

    return 0;
}
