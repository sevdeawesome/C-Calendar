#include <iostream>
#include "customEvent.hpp"
using namespace std;
class priorityDecorator : public Event
{
protected:
	int priority;
	Event* p_Priority;
	string convert = to_string(priority);
public:
	
	priorityDecorator(Event* cEvent,int p) : p_Priority(cEvent) 
	{
	p_Priority = cEvent;
	priority =p; 
	}
	~priorityDecorator() { delete p_Priority; }
	 void setPriority(int &p) {
              return p_Priority ->setPriority(p);
        }
	string getPriority()
	{
	      return convert;
	}
	string printCalendar() {
		return p_Priority->printCalendar() + p_Priority->getPriority(); 
	};
	string printSchedule() { 
		return p_Priority->printSchedule() + p_Priority->getPriority();
	};
	string printUpcomingEvents() { 
		return p_Priority->printUpcomingEvents() + p_Priority->getPriority();
	};
	string printDate() {
		return p_Priority->printDate();
	}
	string printTime() {
		return p_Priority->printTime();
	}
	
};
