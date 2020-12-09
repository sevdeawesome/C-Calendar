#ifndef __QUIZ_H__
#define __QUIZ_H__

#include "timeConverter.hpp"

using namespace std;
class Quiz : public Event
{
     public:
    	
	string printSchedule()
	{
		timeConverter t = timeConverter(time, false);
		return	t.getSchedule();		
	};

//print class schedule
        string printUpcomingEvents()
	{	
		if(checkifToday(time))
		{
			timeConverter t = timeConverter(time, false);
        	        t.getSchedule();
		}
	};
        string printCalendar()
	{
		string calendar;
		calendar += name;
		calendar += "Quiz";
                calendar += "null";
                calendar += "|";
                calendar += time;
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
