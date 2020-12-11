# \<Epic Calendar\>
 
 > Authors: \<[Carl Che](https://github.com/pureche)\>, \<[Severin Field](https://github.com/sevdeawesome)\>, \<[Alex Nguyen](https://github.com/Anguy600)\>
 

## Project Description
Our calendar will give you a daily rundown of what assignments are due, what classes you have, and any other events that you have at the beginning of each day. We will store information for each day using the singleton pattern to save configuration files. We will also handle recurring events with the visitor design pattern, which will visit each day and see if it is applicable for a given change and we will use this design pattern for modifying day objects. Lastly, we will use the abstract factory design pattern to handle types of events such as quizzes, homework due dates, class schedules, etc. We will incorporate it all into either a simple daily message delivered with http requests to a php backend system or if we have enough time an interactive web app with html and css. The back end of our program will be written in C++ and store yearly information in text files. 


## Functionalities:
Create a class schedule
Create events
View of upcoming events
View of class schedule
reminder(email)
Visualization of the calendar (either in console or HTML web app if enough time)
Knows when there's a federal holiday coming up


## Epics:
As a user, I should be able to create a class schedule for a quarter.
As a user, I should be able to create events such as quizzes and exams.
As a user, I should be able to see a calendar of upcoming events
As a user, I should be able to see my full class schedule for the quarter.
As a user, I should receive a reminder / email when an event is coming up.
As a user, i should be able to visually see the calendar
As a user, I should be informed when a holiday is coming up

### Why it’s important
 - It helps students manage their school schedule and quiz/exam times for students to be successful.
 - Provides a simple way for students to enter their schedule of classes for a quarter and reads it back
 - Provides better time management for students.
 - We are in need of a calendar program or app that is customized for school work.

### Technologies used: 
 - C++
 - We will use PHP, HTML, and CSS to make a simple web calendar GUI if we have enough time and have already completed a planner which incorporates all 3 of our design patterns. 


### Input / output of project:
- Input: Students’ schedule, daily specific tasks.
- Output: Text based configuration file.




### Design Patterns:
- Composite: 
We chose the composite pattern because it allows us to have a composition of similar objects inside of one object. These are going to be events inside of a day (inside of a the planner / plan class). The leafs are going to be quizzes, tests and custom events and the composite is going to be the plan. Lastly, the event class is going to be the component of the composite. This will make handling of various type of events easier and we don’t see any major drawbacks with this pattern.  


- Singleton: 
Singleton is a design pattern that fits perfectly with our needs of reading and writing to a configuration file for the needs of saving calendar items. The singleton instance can also be used as a global object. All of the operations that relate to adding/removing/modifying calendar items can be operated on this single object, as well as being saved to storage/write to file when needed. 


- Decorator: We chose this design pattern to allow the users to create custom events that can be differentiated by color to allow the user to see the importance of one event to another. It is  giving the user the freedom to add  events that are not specific to school work. One drawback is having too many events would clutter the calendar with bright visuals making it difficult to know what is prioritized.



## Class Diagram

 ![OMT Diagram](https://github.com/cs100/final-project-cche003-anguy600-sfiel003/blob/master/project%20(2).png)
 This is our current class diagram. We use the singleton pattern in writing to and from files. We will have a text file when necessary for events like quizzes or custom events that need long descriptions. Our plan class is a composition of events such as quizzes or class that someone has, and here we use the composite pattern where event is the composite. Lastly, we use the decorator pattern to decorate custom events and give them attributes like the color (they will show as a different color in a GUI) or priority (how important or urgent is this event). 
 
 
 ## Screenshots
 ![OMT Diagram](https://github.com/cs100/final-project-cche003-anguy600-sfiel003/blob/master/1.png)
  ![OMT Diagram](https://github.com/cs100/final-project-cche003-anguy600-sfiel003/blob/master/2.png)
   ![OMT Diagram](https://github.com/cs100/final-project-cche003-anguy600-sfiel003/blob/master/3.png)
    ![OMT Diagram](https://github.com/cs100/final-project-cche003-anguy600-sfiel003/blob/master/4.png)
     ![OMT Diagram](https://github.com/cs100/final-project-cche003-anguy600-sfiel003/blob/master/5.png)
 
 ## Installation/Usage
 Usage is through CLI, we did not have time to write a script that emails you when an event is coming up, however, implementation would be simple given the code we've built.
 
 ## Testing
 We used Googletest and were each responsible for testing our own classes and methods. 
 
