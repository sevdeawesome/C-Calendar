#ifndef __EVENT_H__
#define __EVENT_H__



#include <iostream>
#include <string>
#include <array>
#include <ctime>
using namespace std;

class Event {
        protected:
        string name;
        string info;
        int time;

	public:
	//constructor
	Event(string n, string i, int t)
	{
		name = n;
		info = i;
		time = t;	

	}
       

	//getters
        int getTime();
	string getInfo();
	string getName();
	
	   
	//setters
	void setTime(int t);
	void setInfo(string i);
	void setName(string n);


	//members (virtual)
	//
	//prints out all info about the event
        virtual string printSchedule() = 0; //print class schedule
       
	 virtual string printUpcomingEvents() = 0;
		//prints out a class schedule of recurring class events
        virtual string printCalendar() = 0; 
		//returns string of all of an events info in a format viable for writing to the file
		


        virtual string printDate () =0 ;
		//prints the date of an event        

	virtual string printTime() = 0;
		//prints the time of an event (ex 12:00:00)
	


	//members defined here
        bool checkifToday(int timeInput);
	//checks if an event is within 24hrs of the current epoch time
 	
	bool checkifToday()
	{
		  time_t t = std::time(0);


        	long int currTime = static_cast<long int>(t);


   	     if(abs(currTime - time) <= 86400)
   	     {
        	        return true;
	
  	      }
	        return false;

	};       
};



#endif
