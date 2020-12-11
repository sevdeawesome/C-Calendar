/*
 *This file tests the composite structure and the following classes:
 * Plan
 * Quiz
 * Class
 * Event
 *
 *
 *It also tests the printCalendar
 *printDate
 *and other time checking methods
 *
 *
 *Lastly it tests to make sure the printCalendar in Plan
 *works correctly so that it will function with fileIO
 *
 *NOTE:::
 *
 *DOES NOT CHECK checkifToday() OR
 * printUpComingEvents() since they are in event_time_tests.h
 */

#include "../header/Event.hpp"
#include "../header/Class.hpp"
#include "../header/Plan.hpp"
#include "../header/Quiz.hpp"

//Plan* thePlan = new Event("the plan", "plan", 0);
TEST(EventTests, eventQuizTest1)
{

	Plan * thePlan = new Plan("the plan");


	Event * newQuiz = new Quiz("Quiz in CS", "Quiz", 1623123123);
	thePlan->addEvent(newQuiz);
	string c = "20:32:03 PDT";
	string a = "Quiz in CS|q|0|1623123123";
	string b = "Mon 2021-06-07";
	string d = "";
	string e = a + "\n";
	//MAKES SURE EVERYTHING IN QUIZ PRINTS CORRECTLY
	EXPECT_EQ(newQuiz->printCalendar(), a);
	EXPECT_EQ(newQuiz->printDate(), b );
	EXPECT_EQ(newQuiz->printTime(), c);
	EXPECT_EQ(newQuiz->printUpcomingEvents(),d);
	//will be empty cause there is no recurrence to this event
	//EXPECT_EQ(newQuiz->printCalendar(), d);


	//confirming thePlan calendar print
	EXPECT_EQ(thePlan->printCalendar(), e);
	Event * newClass = new Class("CS100", "Class", 1621231231, "MWF");
	delete newQuiz;
	delete thePlan;
	delete newClass;
}


TEST(EventTests, eventQuizTest2)
{
	//edge case time 0
	//also tests a plan with multiple quiz events
        Plan * thePlan = new Plan("the plan");


        Event * newQuiz = new Quiz("Quiz1", "Quiz", 0); //beginning of epoch
	Event * newQuiz2 = new Quiz("Quiz2", "q", 124123); // in the past
	Event * newQuiz3 = new Quiz("Quiz3", "q", 3602312312); // in ~30 yrs
	Event * newQuiz4 = new Quiz("Quiz4", "q", 1607505416);

        thePlan->addEvent(newQuiz);
	thePlan->addEvent(newQuiz2);
	thePlan->addEvent(newQuiz4);

        string c = "02:28:43 PST";
        string a = "Quiz2|q|0|124123";
        string b = "Fri 1970-01-02";
        string d = "";
        string e = "Quiz1|q|0|0\nQuiz2|q|0|124123\nQuiz4|q|0|1607505416\n";
	string h = "Wed 2020-12-09";
        EXPECT_EQ(newQuiz2->printCalendar(), a);
        EXPECT_EQ(newQuiz2->printDate(), b );
        EXPECT_EQ(newQuiz2->printTime(), c);
        EXPECT_EQ(newQuiz2->printUpcomingEvents(), d);
	EXPECT_EQ(newQuiz4->printDate(), h);
        EXPECT_EQ(thePlan->printCalendar(), e);
        
        delete newQuiz;
        delete thePlan;
	delete newQuiz2;
	delete newQuiz3;
}
TEST(EventTests, eventQuizTest3)
{

        Plan * thePlan = new Plan("the plan");
 	 time_t t = std::time(0);
	 long int currTime = static_cast<long int>(t);


        Event * newQuiz = new Quiz("Quiz in CS", "Quiz", 0);
	Event * newQuiz2 = new Quiz("Quiz2", "abc", currTime);
        thePlan->addEvent(newQuiz);
        
  

        EXPECT_EQ(newQuiz->checkifToday(8640000),false);
	EXPECT_EQ(newQuiz->checkifToday(), false);
	EXPECT_EQ(newQuiz2->checkifToday(), true);
        delete newQuiz;
        delete thePlan;
	delete newQuiz2;	
}
TEST(EventTests, classTest)
{
	Plan * thePlan = new Plan("planA");
	
	
	Event * newClass = new Class("CS100", "class", 0, "T/TR");
	Event * newClass2 = new Class("Phys40C", "class", 1607505416, "MWF");

	thePlan->addEvent(newClass);
	thePlan->addEvent(newClass2);
	

	string a = "Phys40C: 01:16:56 PST every MWF";
	string b = "CS100: 16:00:00 PST every T/TR\nPhys40C: 01:16:56 PST every MWF\n";
	string c = "";


	EXPECT_EQ(newClass2->printSchedule(), a);	
	EXPECT_EQ(thePlan->printSchedule(), b);
	EXPECT_EQ(newClass->checkifToday(), false);
	EXPECT_EQ(thePlan->printUpcomingEvents(), c);
	

}
