#ifndef __EVENT_H__
#define __EVENT_H__



#include <iostream>
#include <string>
#include <array>
using namespace std;

class Event {
        protected:
        string name;
        string info;
        int time;

	public:
	//constructor
	Event(string n, string i, int t);
       

	//getters
        int getTime();
	string getInfo();
	string getName();
	
	   
	//setters
	void setTime(int t);
	void setInfo(string i);
	void setName(string n);


	//members (virtual)
        virtual string printSchedule() = 0; //print class schedule
        virtual string printUpcomingEvents() = 0;
        virtual string printCalendar() = 0; 
        virtual string printDate () =0 ;
        

	virtual string printTime() = 0;

	//members defined here
        bool checkifToday(int timeInput);
        
};



#endif
