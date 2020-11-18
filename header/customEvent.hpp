using namespace std;
class customEvent : public Event
{
  public:
        string name;
        string info;
        int time;
        array event* events;
    
        void printSchedule(); //print class schedule
        void printUpcomingEvents();
        void printCalendar();
        void printDate();
        void printTime();
        bool checkifToday();   
    
}
