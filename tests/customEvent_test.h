#include "../header/Event.hpp"
#include "../header/Plan.hpp"
#include "../header/customEvent.hpp"
#include "../header/colorDecorator.hpp"
#include "../header/priorityDecorator.hpp"
#include "../header/Class.hpp"
#include <iostream>

using namespace std;


TEST(EventTests, classTest)
{
	Plan * thePlan = new Plan("planA");
	
	
	Event * newClass = new customEvent("Party", "customEvent", 0, "T");
	Event * newClass2 = new customEvent("Homework", "customEvent", 1607505416, "M");
	
	thePlan->addEvent(newClass);
	thePlan->addEvent(newClass2);
	
	cout<< &newClass<<" event 1"<<endl;
	cout<< &newClass2<<" event2"<<endl;
	newClass = new colorDecorator(new customEvent("Party","customEvent",0,"W"),"Red");

	thePlan->addEvent(newClass);
	cout<< &newClass<<" new event 1"<<endl;

	string a = "01:16:56 PST every M";
	string b = "16:00:00 PST every T\n01:16:56 PST every M\n";
	string c = "";


	EXPECT_EQ(newClass2->printSchedule(), a);	
	cout<<newClass2->printSchedule()<<"   classchedule"<<endl;
	EXPECT_EQ(thePlan->printSchedule(), b);
	cout<<thePlan->printSchedule()<<"   planschedule"<<endl;
	EXPECT_EQ(newClass->checkifToday(), false);
	cout<<newClass->checkifToday()<<"   checking"<<endl;
	EXPECT_EQ(thePlan->printUpcomingEvents(), a);
	cout<<thePlan->printUpcomingEvents()<<"   upcoming events"<<endl;
	

}



//TEST(customEvent,customEventTest)
//{
//	Plan * thePlan = new Plan("the plan");
//	Event* custom = new customEvent("party at my house","acustomEvent",1623123123);
	
//	thePlan->addEvent(custom);
	//custom = new colorDecorator(new customEvent( name, info, time));

	//custom = new priorityDecorator(new colorDecorator(new customEvent( name, info, time)));
//	string a = "01:16:56 PST every MWF";
//	string b = "16:00:00 PST every T/TR\n01:16:56 PST every MWF\n";
	
//	string c = "";
	//thePlan->addEvent(custom);
	
//	EXPECT_EQ(custom->printSchedule(),a);
//	EXPECT_EQ(thePlan->printSchedule(),a);
//	EXPECT_EQ(thePlan->printSchedule(),b);
//     	EXPECT_EQ(custom->checkifToday(), false);
//	EXPECT_EQ(thePlan->printUpcomingEvents(), c);


//}
