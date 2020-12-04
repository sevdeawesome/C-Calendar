#ifndef __QUIZ_H__
#define __QUIZ_H__
#include "timeConverter.hpp"

using namespace std;
class Quiz : public Event
{
     public:
    	
	void printSchedule()
	{
		timeConverter t = timeConverter(time, false);
		t.getSchedule();		
	};

//print class schedule
        void printUpcomingEvents()
	{	
		if(checkifToday(time))
		{
			timeConverter t = timeConverter(time, false);
        	        t.getSchedule();
		}
	};
        void printCalendar()
	{
		//no implementation here
	};
        void printDate()
	{
		timeConverter t = timeConverter(time, false);
	         t.getDate();

	};
        void printTime()
	{
		timeConverter t = timeConverter(time, false);
                t.getTime();

	};
    
};


#endif
