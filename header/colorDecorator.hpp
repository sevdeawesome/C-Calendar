#pragma once
#include <iostream>
#include "customEvent.hpp"
#include "Event.hpp"
using namespace std;
class colorDecorator : public Event
{	protected:
	string color;
	Event * p_Color;
public:
	colorDecorator(Event* cEvent,string c) : p_Color(cEvent)
	{
	p_Color = cEvent;
	color = c; 
	}
	~colorDecorator() { delete p_Color; }
	string getColor(){
		return color;
	}
	
	void setColor(string &c) { 
		
	 	return  p_Color->setColor(c); 
	};
	string printCalendar() { 
		return p_Color->printCalendar() + p_Color->getColor(); 
		 
	};
	string printSchedule() { 
		return p_Color->printSchedule() + p_Color->getColor();
	};
	string printUpcomingEvents() { 
		return p_Color->printUpcomingEvents() + p_Color->getColor();
	};
	string printDate() {
		return p_Color->printDate();
	}
	string printTime() {
		return p_Color->printTime();
	}

};
