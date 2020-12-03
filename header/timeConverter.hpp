#include <string>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <time.h>
using namespace std;


class timeConverter
{
	public:
		long int unixt;

		
		bool isRecurring;
		string recurrence = "";
	

		timeConverter(int t, bool r)
		{

			unixt = t;
			if(r = true)
			{
					cout << "Enter recurrence pattern (ex: MWF)" << endl;
					cin >> recurrence;
					cout << "You've entered: " << recurrence << endl;
			}
		};
		timeConverter(int t, string rec)
		{	
			unixt = t;
			isRecurring = true;
			recurrence = rec;
		};
			
		void getFullTime()
		{
			struct tm ts;
			char buf[80];
 
 
			ts = *localtime(&unixt);
			strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
			printf("%s\n", buf);
		};
		
};
