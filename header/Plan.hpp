#ifndef __PLAN_H__
#define __PLAN_H__


#include "Event.hpp"
#include <vector>


using namespace std;
class Plan {
    
 public:
	string name;
        Plan(string n){
		name = n;
	};

	//composition of events are stored in Plan
       	vector<Event*> events;
    

	//prints all info about all events
        string printSchedule(){
		string output;
		for(int i = 0; i < events.size(); i++)
		{
			output = output + events[i]->printSchedule()+ "\n";
		}	
		return output;

	}


	//only prints events that are today
        string printUpcomingEvents()
	{
		string output;
		for(int i = 0; i < events.size(); i++)
                {
                	output+=      events[i]->printUpcomingEvents();
                }
		
		return output;
	}


	//prints all events in calendar format
	//**FOR FILEIO**
        string printCalendar()
	{
		string output;	
		for(int i = 0; i < events.size(); i++)
                {
                 	output = output +      events[i]->printCalendar() + "\n";
                }

		return output;
	}
        string printDate()
	{
		return "";	
	//no necessary implementation
	}
        string printTime()
	{
		return "";
		//no necessarry implementation
	}

	void addEvent(Event* addThis)
	{
		events.push_back(addThis);
	}
};

#endif
