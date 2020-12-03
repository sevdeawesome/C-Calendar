using namespace std;
class Plan: public Event  {
    
 public:
        
       	vector<event*> events;
    
        void printSchedule(){
		for(int i = 0; i < events.length(); i++)
		{
			events[i]->printSchedule();
		}	

	}
        void printUpcomingEvents()
	{
		for(int i = 0; i < events.length(); i++)
                {
                        events[i]->printUpcomingEvents();
                }

	
	}
        void printCalendar()
	{	
		for(int i = 0; i < events.length(); i++)
                {
                        events[i]->printCalendar();
                }


	}
        void printDate()
	{
		//no necessary implementation
	}
        void printTime()
	{
		//no necessarry implementation
	}
}


