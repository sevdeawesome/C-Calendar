#ifndef CLASS_H
#define CLASS_H


using namespace std;
class Class : public Event
{

	private:
		timeConverter t = timeConverter(time, false);
 	 public:
 //       string name;
   //     string info;
     //   int time;
     //   array event* events;
    	//timeConverter t;
	
	Class(string a, string b, int c) : Event(a, b, c) 
	{
		t = timeConverter(time, true);	
	
	};
        void printSchedule()
	{
	//	timeConverter t = timeConverter(time, true);
                t.getSchedule();

	}; //print class schedule
        void printUpcomingEvents()
	{
		if(checkifToday(time))
		{
			t.getSchedule();
		}	
	};

        void printCalendar()
	{
		//needs implementation - what do you want me to do for this?
	};
        void printDate()
	{
		t.getDate();
	};
        void printTime()
	{
		t.getTime();
	};
};


#endif
