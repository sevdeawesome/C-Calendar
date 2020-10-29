# \<Epic Calendar\>
 
 > Authors: \<[Carl Che](https://github.com/pureche)\>, \<[Severin Field](https://github.com/sevdeawesome)\>, \<[Alex Nguyen](https://github.com/Anguy600)\>
 

## Project Description
Our calendar will give you a daily rundown of what assignments are due, what classes you have, and any other events that you have at the beginning of each day. We will store information for each day using the singleton pattern to save configuration files. We will also handle recurring events with the visitor design pattern, which will visit each day and see if it is applicable for a given change and we will use this design pattern for modifying day objects. Lastly, we will use the abstract factory design pattern to handle types of events such as quizzes, homework due dates, class schedules, etc. We will incorporate it all into either a simple daily message delivered with http requests to a php backend system or if we have enough time an interactive web app with html and css. The back end of our program will be written in C++ and store yearly information in text files. 

- Why it’s important
 - It helps students manage their school schedule and quiz/exam times for students to be successful.
 - Provides a simple way for students to enter their schedule of classes for a quarter and reads it back
 - Provides better time management for students.
 - We are in need of a calendar program or app that is customized for school work.

- Technologies used: 
 - C++
 - We will use PHP, HTML, and CSS to make a simple web calendar GUI if we have enough time and have already completed a planner which incorporates all 3 of our design patterns. 


* Input / output of project:
- Input: Students’ schedule, daily specific tasks.
- Output: Text based configuration file.



* Design Patterns:
- Visitor:
For starters, all the years, months, days are their own objects. By using the Visitor design pattern, we can do operations, such as adding quiz and exam days, with each individual day without modifying its attributes or class structures. For the most part, any kind of operations related to scheduling or items would be implemented with the Visitor design pattern.
- Abstract Factory: 
The Abstract Factory design pattern can be used for a number of different features of our calendar. Firstly, different types of events, such as quizzes, homework due dates, and classes will all inherit from an event class that can be repeated day by day / week by week in the calendar. Because of this, we will use the Abstract Factory design pattern to handle all events. One of the benefits of this design pattern is that it makes exchanging product families easy since the class of a concrete factory is only defined once in an application - this will provide an easy way to edit all event subclasses, regardless of what they are. It will also promote consistency within these different event classes. One drawback is that it will be difficult to support and create new events/ event types.

- Singleton: 
Singleton is a design pattern that fits perfectly with our needs of reading and writing to a configuration file for the needs of saving calendar items. The singleton instance can also be used as a global object. All of the operations that relate to adding/removing/modifying calendar items can be operated on this single object, as well as being saved to storage/write to file when needed. 




 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
11
