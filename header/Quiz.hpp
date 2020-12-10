#ifndef __QUIZ_H__
#define __QUIZ_H__
#include "timeConverter.hpp"

using namespace std;
class Quiz : public Event
{
     public:
    	

	Quiz(string n, string i, int t) : Event(n, i, t){};

	string printSchedule()
	{
		timeConverter t = timeConverter(time, false);
		return	t.getSchedule();		
	};
        string printUpcomingEvents()
	{
		return "";	
	}
        string printCalendar()
	{
		string calendar;
		calendar += name;
		calendar += "|q|"; // q for quiz
                calendar += "0"; //no recurrence - recurrence term
                calendar += "|";
                calendar += to_string(time); //saves as string
		return calendar;
	};
        string printDate()
	{
		timeConverter t = timeConverter(time, false);
	        return t.getDate();

	};
        string printTime()
	{
		timeConverter t = timeConverter(time, false);
                return  t.getTime();

	};
    
};


#endif
