#ifndef __CUSTOMEVENT_H__
#define __CUSTOMEVENT_H__
#include <iostream>
#include <string>
#include <array>
using namespace std;
class customEvent : public Event
{
  public:
        string name;
        string info;
        int time;
        array event* events;
    
      //getters
      int getTime();
      string getInfo();
      string getName();
      string getColor();
      int getPriority();

      //setters
      void setTime(int time);
      void setInfo(string info);
      void setName(string name);
      void setPriority(int priority);
      void setColor(string color); 
}
#endif
