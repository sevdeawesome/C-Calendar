#include "../header/timeConverter.hpp"
using namespace std;


/*

These are the tests for the timeConverter class

Plan, event, etc. are not used here

Tests reccurrence within the timeConverter class
Tests the getters
Tests all getTime variants

*/


TEST(time_tests, testGetters)
{

	string a = "MWF";
	timeConverter* t1 = new timeConverter(1607478508, false);
	timeConverter* t2 = new timeConverter(1607478508, a);

	
	EXPECT_EQ(t2->getRec(), "MWF");
	EXPECT_EQ(t1->getT(), 1607478508);
		
	delete t1;
	delete t2;
}


TEST(time_tests, testGetters2)
{

        string a = "Tues / Thursday";
        timeConverter* t1 = new timeConverter(1607481288, false);
        timeConverter* t2 = new timeConverter(1623123508, a);


        EXPECT_EQ(t2->getRec(), "Tues / Thursday");
        EXPECT_EQ(t1->getT(), 1607481288);
	
	delete t1;
	delete t2;

}

TEST(time_tests, testTime)
{
	//Dec 8 2020 4:45:41 PM PST = 1607474741
	string a = "MWF";
	timeConverter * t = new timeConverter(1607474741, false);
	timeConverter *t1 = new timeConverter(1607474741, a);
	EXPECT_EQ(t1->getFullTime(), "Tue 2020-12-08 16:45:41 PST");	
	EXPECT_EQ(t1->getTime(), "16:45:41 PST");
	EXPECT_EQ(t1->getDate(), "Tue 2020-12-08");
	EXPECT_EQ(t1->getSchedule() , "16:45:41 PST every MWF");
	EXPECT_EQ(t->getSchedule(), "");
}


TEST(time_tests, testTime2)
{
        string a = "MWF";
 //       timeConverter * t = new timeConverter(0, false);

	//start of the epoch
        timeConverter *t1 = new timeConverter(0, a);
        EXPECT_EQ(t1->getFullTime(), "Wed 1969-12-31 16:00:00 PST");
	EXPECT_EQ(t1->getTime(), "16:00:00 PST");
    	EXPECT_EQ(t1->getDate(), "Wed 1969-12-31");
    	EXPECT_EQ(t1->getSchedule() , "16:00:00 PST every MWF");	
//	EXPECT_EQ(t1->getDate(),"2020-12-08");
}


TEST(time_tests, testTime3)
{
        string a = "MWF";
 //      TESTS A TIME IN 37 YEARS
                timeConverter *t1 = new timeConverter(2607481941, a);
                EXPECT_EQ(t1->getFullTime(), "Tue 1916-07-11 14:04:05 PST");
		EXPECT_EQ(t1->getTime(), "14:04:05 PST");
   	 	 EXPECT_EQ(t1->getDate(), "Tue 1916-07-11");
   		 EXPECT_EQ(t1->getSchedule() , "14:04:05 PST every MWF");
		
    


}


TEST(time_tests, testTime4)
{
//TESTS THE CURRENT TIME
//
			
			time_t t = std::time(0);
		        long int currTime = static_cast<long int>(t);

			struct tm ts;
                        char buf[80];


                        ts = *localtime(&currTime);
                        strftime(buf, sizeof(buf), "%a %Y-%m-%d", &ts);
			
			string output;

                        for(int i = 0; i < 40; i++)
                        {
                                output += buf[i];

                        }

                        string finaloutput;
                        int i = 0;
                        char check = output.at(i);
                        while(check != '\0' && i < 30)
                        {
                                finaloutput += check;
                                i++;
                               check = output.at(i);

                        }

			timeConverter * ta = new timeConverter(currTime, false);
                        EXPECT_EQ(finaloutput, ta->getDate());

}
