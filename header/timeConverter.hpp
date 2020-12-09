#ifndef __timeConverter_H__
#define __timeConverter_H__


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
			
		long int getT()
		{
			return unixt;
		};
		string getRec()
		{
			return recurrence;
		}
		
		string getFullTime()
		{
			struct tm ts;
			char buf[80];
 
 
			ts = *localtime(&unixt);
			strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
			//	printf("%s\n", buf);
			//
			//
			string output;

			for(int i = 0; i < 40; i++)
			{
       				 output += buf[i];

			}	

			return output;
		};
		string getSchedule()
		{

			
			struct tm ts;
                        char buf[80];

			
                        ts = *localtime(&unixt);
                       	string output;
	
			if(isRecurring)
			{
				strftime(buf, sizeof(buf), "%H:%M:%S %Z", &ts);
        	                for(int i = 0; i < 40; i++)
				{
					output += buf[i];
				}
				output = output +  " every " +	recurrence;		

			}
			else
			{
				strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M", &ts);
                        	//	printf("%s\n", buf);		
				for(int i = 0; i < 40; i++)
				{
					output += buf[i];

				}
			}

			return output;
		};
		
		string getTime()
		{
			struct tm ts;
                       	char buf[80];


                        ts = *localtime(&unixt);


                      	strftime(buf, sizeof(buf), "%H:%M:%S %Z", &ts);
                 	//       printf("%s\n", buf);
                 	string output;

			for(int i = 0; i < 40; i++)
			{
      				 output += buf[i];

			}

			return output;

		};

		string getDate()
		{	
			struct tm ts;
                        char buf[80];


                        ts = *localtime(&unixt);
                        strftime(buf, sizeof(buf), "%a %Y-%m-%d", &ts);
                       // printf("%s\n", buf);
                        string output;

			for(int i = 0; i < 40; i++)
			{
        			output += buf[i];

			}	

			return output;      			
		};
};

#endif
