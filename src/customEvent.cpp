#include "../header/customEvent.hpp"
using namespace std;
    
customEvent(string color, string name,string info,int time,int priority)
{
	color = " ";
	name = " ";
	info = " ";
	time =  0;
	priority = 0;
	
}
int customEvent:: getTime()
{  
	return time;  
}
string customEvent::getInfo()
{
	return info;
}
string customEvent::getName()
{
	return name;
}
string customEvent::getColor()
{
	return color;
}
int customEvent::getPriority()
{
	return priority;
}
void customEvent::setTime(int time)
{
	this->time = time;
}
void customEvent::setInfo(string info)
{
	this->info = info;
}
void customEvent::setName(string name)
{
	this->name = name;
}
void customEvent::setPriority(int priority)
{
	this->priority = priority;
}
void customEvent::setColor(string color)
{
	this->color = color;
}
