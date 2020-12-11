#ifndef __CUSTOMEVENT_H__
#define __CUSTOMEVENT_H__
#include <iostream>
#include <string>
#include "timeConverter.hpp"
using namespace std;
class customEvent : public Event
{
  private:
	int priority=0;
	string color="";

  public:
	customEvent(){};
	customEvent(Event*){};
 	customEvent(string n,string i, int ti):Event(n,i,ti)
	{
	  // t = timeConverter(time, true);
	};
	~customEvent(){};
 	string printSchedule() {
		long int unixt = time;
		struct tm ts;
		char buf[80];
		ts = *localtime(&unixt);
		string output;

			strftime(buf, sizeof(buf), "%H:%M:%S %Z", &ts);
			for (int i = 0; i < 40; i++)
			{
				if (buf[i] == '\0')
				{
					break;
				}
				else { output += buf[i]; }
			}
			//output = output+" every ";
	

	return output;
	
	}; //print class schedule
	string printUpcomingEvents(){
		if (checkifToday(time))
		{
			return printSchedule();
		}
		return "";
	};
	string printCalendar() {
		
		setColor(color);
		setPriority(priority);
		string calendar;
		calendar += name;
		calendar += "|ce|";
		//calendar += t.getRec();
		calendar += " | ";
		calendar += time;
		calendar += " | ";
		calendar += getColor();
		calendar += " | ";
		calendar += getPriority();
		return calendar;
	};
	string printDate() {
		long int unixt = time;
		struct tm ts;
		char buf[80];


		ts = *localtime(&unixt);
		strftime(buf, sizeof(buf), "%a %Y-%m-%d", &ts);
		string output;

		for (int i = 0; i < 40; i++)
		{
			output += buf[i];

		}

		string finaloutput;
		int i = 0;
		char check = output.at(i);
		while (check != '\0' && i < 30)
		{
			finaloutput += check;
			i++;
			check = output.at(i);

		}
		return finaloutput;
	};
	 string printTime(){
		long int unixt = time;
		struct tm ts;
		char buf[80];


		ts = *localtime(&unixt);
		strftime(buf, sizeof(buf), "%a %Y-%m-%d", &ts);
		string output;

		for (int i = 0; i < 40; i++)
		{
			output += buf[i];

		}

		string finaloutput;
		int i = 0;
		char check = output.at(i);
		while (check != '\0' && i < 30)
		{
			finaloutput += check;
			i++;
			check = output.at(i);

		}
		return finaloutput;
	};

};
#endif
