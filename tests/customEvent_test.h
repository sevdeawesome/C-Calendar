#include "../header/Event.hpp"
#include "../header/Plan.hpp"
#include "../header/customEvent.hpp"
#include "../header/colorDecorator.hpp"
#include "../header/priorityDecorator.hpp"
#include "../header/Class.hpp"
#include <iostream>
#include <string>
using namespace std;


TEST(EventTests, classTest)
{
	Plan * thePlan = new Plan("planA");
	
	
	Event * newClass = new customEvent("Party", "customEvent", 0);
	//Event * newClass2 = new customEvent("Homework", "customEvent", 1607505416, "M");
	
	thePlan->addEvent(newClass);
	//thePlan->addEvent(newClass2);
	
	cout<< &newClass<<" event 1"<<endl;
	//cout<< &newClass2<<" event2"<<endl;
	string color ="red";
	Event * newClass3 = new colorDecorator(new customEvent("Party","customEvent",0),"red");

	thePlan->addEvent(newClass);
	//cout<< &newClass<<" new event 1"<<endl;
	string a = "01:16:56 PST M";
	string b = "16:00:00 PST every T\n01:16:56 PST every M\n";
	string c = "";
	string d = "16:00:00 PST red";
	EXPECT_EQ(newClass3->printSchedule(),d);
	int priority =1;
	string convert = to_string(priority);
	 Event * newClass4 = new priorityDecorator( new colorDecorator(new customEvent("Party","CE",0),color),priority);

	string e= "16:00:00 PST red 1";
	string f= "Party | CE | 0 | red | 1";
	EXPECT_EQ(newClass4->printSchedule(),e);
	EXPECT_EQ(newClass4->printUpcomingEvents(),f);

	//newClass = new colorDecorator(new

	//EXPECT_EQ(newClass2->printSchedule(), a);	
	//EXPECT_EQ(thePlan->printSchedule(), b);
	//EXPECT_EQ(newClass->checkifToday(), false);
	//EXPECT_EQ(thePlan->printUpcomingEvents(), a);
	delete newClass4;
	delete newClass3;
	delete newClass;

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
