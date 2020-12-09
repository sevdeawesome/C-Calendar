
#include "../header/Event.hpp"
#include "../header/Class.hpp"
#include "../header/Plan.hpp"
#include "../header/Quiz.hpp"

//Plan* thePlan = new Event("the plan", "plan", 0);
TEST(EventTests, event)
{

	Plan * thePlan = new Plan("the plan");

	Event * newQuiz = new Quiz("Quiz in CS", "Quiz", 0);
	thePlan->addEvent(newQuiz);
	string a = "abc";
	EXPECT_EQ(thePlan->printCalendar(), a);


}
