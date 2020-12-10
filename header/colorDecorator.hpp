#pragma once
#include <iostream>
#include "customEvent.hpp"
using namespace std;
class colorDecorator : public Event
{	protected:
	string color;
	Event * p_Color;;
public:
	colorDecorator(Event* customEvent) : p_Color(customEvent) { cout << "created"<<endl; }
	~colorDecorator() { cout << "destroyed"<<endl; }
	string getColorFunc() { 
		return color; 
	};
	void setColorFunc(string c) { 
		color = c; 
	};
	string printCalendar() { 
		return p_Color->printCalendar() + color; 
		 
	};
	string printSchedule() { 
		return p_Color->printSchedule() + color;
	};
	string printUpcomingEvents() { 
		return p_Color->printUpcomingEvents() + color;
	};
	string printDate() {
		return p_Color->printDate();
	}
	string printTime() {
		return p_Color->printTime();
	}
};
