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
	int getPriorityFunc() { 
		return priority; 
	}
	void setPriorityFunc(int p) { 
		priority = p; 
	}
	
	priorityDecorator(Event* customEvent) :p_Priority(customEvent) { cout << "created"<<endl; }
	~priorityDecorator() { cout << "destroyed"<< endl; }
	string printCalendar() {
		return p_Priority->printCalendar() + convert + " "; 
	};
	string printSchedule() { 
		return p_Priority->printSchedule() + convert + " ";
	};
	string printUpcomingEvents() { 
		return p_Priority->printUpcomingEvents() + convert + " ";
	};
	string printDate() {
		return p_Priority->printDate();
	}
	string printTime() {
		return p_Priority->printTime();
	}
	
};
