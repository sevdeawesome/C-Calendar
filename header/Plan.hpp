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
       	vector<Event*> events;
    
        string printSchedule(){
		string output;
		for(int i = 0; i < events.size(); i++)
		{
			output = output + events[i]->printSchedule()+ "\n";
		}	
		return output;

	}
        string printUpcomingEvents()
	{
		string output;
		for(int i = 0; i < events.size(); i++)
                {
                	output+=      events[i]->printUpcomingEvents();
                }
		
		return output;
	}
        string printCalendar()
	{
		string output;	
		for(int i = 0; i < events.size(); i++)
                {
                 	output+=       events[i]->printCalendar();
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
