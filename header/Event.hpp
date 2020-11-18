#include <iostream>
#include <string>
#include <array>
using namespace std;

class Event {
        public:
        string name;
        string info;
        int time;
       
    
        virtual void printSchedule() = 0; //print class schedule
        virtual void printUpcomingEvents() = 0;
        virtual void printCalendar() = 0; 
        virtual void printDate () =0 ;
        virtual void printTime() = 0;
        bool checkifToday(int time);
        
}
