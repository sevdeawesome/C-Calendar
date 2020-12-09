#ifndef CLASS_H
#define CLASS_H


#include <iostream>
#include <string>

using namespace std;
class Class : public Event
{

	private:
		timeConverter t = timeConverter(time, false);
 	 public:
 //       string name;
   //     string info;
     //   int time;
     //   array event* events;
    	//timeConverter t;
	
	Class(string a, string b, int c) : Event(a, b, c) 
	{
		t = timeConverter(time, true);	
	
	};
        string  printSchedule()
	{
	//	timeConverter t = timeConverter(time, true);
               return  t.getSchedule();

	}; //print class schedule
        string printUpcomingEvents()
	{
		if(checkifToday(time))
		{
			return t.getSchedule();
		}	
		return "";
	};

        string printCalendar()
	{
	
		string calendar;
		calendar += name;
		calendar += "|Class|";
		calendar += t.getRec();
		calendar += "|";
		calendar += time;


		return calendar;
	//needs implementation - what do you want me to do for this?
	};
        string printDate()
	{	
		return	t.getDate();
	};
        string printTime()
	{
		return t.getTime();
	};
};


#endif
