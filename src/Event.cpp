#include "../header/Event.hpp"

using namespace std;
int Event::getTime()
{
	return time;

}

string Event::getInfo()
{
	return info;
}

string Event::getName()
{
	return name;
}


//setters

void Event::setTime(int t)
{
	time = t;
}

void Event::setInfo(string i)
{
	info = i;
}
void Event::setName(string n)
{
	name = n;
}



bool checkifToday()
{
return true;
cout << "NEEDS IMPLEMENTATION ON CHECKIFTODAY IN EVENT";


}









//.Event(string n, string i, int t);


        //getters
        //        int getTime();
        //                string getInfo();
        //                        string getName();
        //
        //
        //                                //setters
        //                                        void setTime(int t);
        //                                                void setInfo(string i);
        //                                                        void setName(string n);
        //
        //
        //                                                                //members (virtual)
        //                                                                        virtual void printSchedule() = 0; //print class schedule
        //                                                                                virtual void printUpcomingEvents() = 0;
        //                                                                                        virtual void printCalendar() = 0;
        //                                                                                                virtual void printDate () =0 ;
        //                                                                                                        virtual void printTime() = 0;
        //
        //                                                                                                                //members defined here
        //                                                                                                                        bool checkIfToday()
