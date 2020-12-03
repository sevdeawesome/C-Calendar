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
        virtual void printSchedule() = 0; //print class schedule
        virtual void printUpcomingEvents() = 0;
        virtual void printCalendar() = 0; 
        virtual void printDate () =0 ;
        

	virtual void printTime() = 0;

	//members defined here
        bool checkifToday(int timeInput);
        
};



#endif
