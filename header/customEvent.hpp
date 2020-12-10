#ifndef __CUSTOMEVENT_H__
#define __CUSTOMEVENT_H__
#include <iostream>
#include <string>
#include "timeConverter.hpp"
using namespace std;
class customEvent : public Event
{
  private:
	timeConverter t =timeConverter(time,false);
	int priority;
	string color;

  public:

 	customEvent(string n,string i, int ti):Event(n,i,ti)
	{
	   t = timeConverter(time, true);
	};
	customEvent(string n, string i, int ti, string rec) : Event(n, i, ti)
	{
		t = timeConverter(time, rec);

	};
 	string printSchedule() {
		return t.getSchedule();
	
	}; //print class schedule
	string printUpcomingEvents(){
		if (checkifToday(time))
		{
			return t.getSchedule();
		}
		return "";
	};
	string printCalendar() {
		string calendar;
		calendar += name;
		calendar += "|ce|";
		calendar += t.getRec();
		calendar += "|";
		calendar += time;
		calender += "|"
		calender += color;
		calender += "|";
		calender += priority;
		return calendar;
	};
	string printDate() {
		return	t.getDate();
	};
	 string printTime(){
		return t.getTime();
	};
};
#endif
