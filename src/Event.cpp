#include "../header/Event.hpp"
#include <ctime>
#include <iostream>
using namespace std;




int Event::getTime()
{
	return time;

}

string Event::getInfo()
{
	return info;
}

string Event::getName()
{
	return name;
}
string Event::getPriority()
{
	return priority;
}
string Event::getColor()
{
	return color;
}

//setters

void Event::setTime(int t)
{
	time = t;
}

void Event::setInfo(string i)
{
	info = i;
}
void Event::setName(string n)
{
	name = n;
}
void Event::setPriority(int &p)
{
	priority=p;
}
void Event::setColor(string& c) 
{ 
	color = c; 
}


bool Event::checkifToday(int timeInput)
{
//	using namespace std::chrono;

 // 	system_clock::time_point tp = system_clock::now();
 //	 system_clock::duration dtn = tp.time_since_epoch();

//	int currTime = dtn.count() * system_clock::period::num / system_clock::period::den;
	time_t t = std::time(0);
	long int currTime = static_cast<long int>(t);


	if(abs(currTime - timeInput) <= 86400)
	{
		return true; 

		//returns true if within 24 hours
		//
		//else returns false
	}
	return false;

}









//.Event(string n, string i, int t);


        //getters
        //        int getTime();
        //                string getInfo();
        //                        string getName();
        //
        //
        //                                //setters
        //                                        void setTime(int t);
        //                                                void setInfo(string i);
        //                                                        void setName(string n);
        //
        //
        //                                                                //members (virtual)
        //                                                                        virtual void printSchedule() = 0; //print class schedule
        //                                                                                virtual void printUpcomingEvents() = 0;
        //                                                                                        virtual void printCalendar() = 0;
        //                                                                                                virtual void printDate () =0 ;
        //                                                                                                        virtual void printTime() = 0;
        //
        //                                                                                                                //members defined here
        //                                                                                                                        bool checkIfToday()
