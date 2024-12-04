# TEAM 13 - COMP3004 Project 

## Group members

> Ishan Bhalla : 101256630 <br>
> Alex Gale : 101273250<br>
> John Williams : 101108045 

## Individual Contributions 
- **Ishan Bhalla** - implemented App, Profile, Radotech, MeasureWidget, ProfilesWidget, the bar graph tab of HistoryWidget, and did the two sequence diagrams
- **Alex Gale** - 
- **John Williams** -implemented Recommended, the circle chart tab of HistoryWidget, use cases and its diagram, class diagram and recorded the video demonstration

## Download and run project

```
- git clone https://github.com/IshanB7/COMP3004-Project.git
- If Project.pro.user file exists exists in /Project/ directory, delete it
- Open Project.pro in Qt and run it
```
## Instructions 
- The app comes with a "Demo" profile with an existing reading. You can view the visualized readings by navigating to the History tab and clicking on the only button that will be visible. Upto 10 such buttons can be visible for a user, with top to bottom signifying latest to earliest readings. At most 10 readings are stored for a single user.
- To create another profile (if the current number of profiles is less than 5), navigate to the Profiles tab and click on the button for adding a new profile. There is no error checking for the name text field, the two buttons for gender are in a single button group (one of them will always be selected), the weight and height fields have numeric type checking and some limits for inputs. Weight must be 0 < w < 1000, height must be 0 < h < 300.
- To select a profile for metering, navigate to the Profiles tab, click on the profile name you'd like to select, and check the "Profile for metering" checkbox. Pressing the back button does not deselect the newly selected profile. You cannot deselect a profile by unchecking this checkbox, you must navigate to another profile and select it instead. There is no way to deselect a profile if the number of profiles is 1. If the number of profiles is 0 at any time, the next profile created will automatically be set to the profile for metering. 
- To get a new reading, navigate to the Measure tab. There are a few preconditions, a profile must be selected for metering, and the radotech device must be on. If the device is turned off during a reading (either by pressing the power button, or losing all battery), the reading will not complete and will not be saved in the selected profile's history screen. Additionally, the user must remain on the measure screen to get a complete reading, if the app switched to another tab it will register as an incomplete reading and will not be saved to a profile's history. There are two ways to complete a reading once the measure button has been pressed in the app, the two ways are to simulate skin contact:
 1. Do not have simulate readings checked on the right side of the screen checked, and click on the button that displays the current point name if you would like to see what point is being measured. 
 2. If you'd just like to add a reading to a profile and do not wish to see every point label, check simulate readings button. The simulate button may be checked or unchecked during a reading.
- To turn on the radotech device, click on the power button of the device.png. The power button emits an orange color when turned on, and a red color as a low-power indicator (when device is on and battery is <= 10). To drain the battery to 10%, press the drain button to the left of the device (Note: the power button will only emit a red color once the device is on). To recharge the device to 100%, press the charge button right below the drain button. The progress bar to the right of the device shows the current battery level, the battery drains at a rate of 1% every 2 seconds while the device is on.

## Directory Structure
```
/COMP3004-Project/
+--- README.md 
+--- Team13Project.pdf              # diagrams and written explanations
+--- /diagrams/                     # diagrams as images
|    +--- seq1.png
|    +--- seq2.png
|    +--- classDiagram.png
|    +--- useCaseDiagram.png
+--- /Project/                      # source code
|    +--- .gitignore
|    +--- App.cpp
|    +--- App.h
|    +--- Profile.cpp
|    +--- Profile.h
|    +--- Project.pro
|    +--- Radotech.cpp
|    +--- Radotech.h
|    +--- resources.qrc
|    +--- /ui/                      # .cpp, .h, and .ui for ui widgets
|         +--- historywidget.cpp
|         +--- historywidget.h
|         +--- historywidget.ui
|         +--- main.cpp
|         +--- mainwindow.cpp
|         +--- mainwindow.h
|         +--- mainwindow.ui
|         +--- measurewidget.cpp
|         +--- measurewidget.h
|         +--- measurewidget.ui
|         +--- profileswidget.cpp
|         +--- profileswidget.h
|         +--- profileswidget.ui
|         +--- radotechwidget.cpp
|         +--- radotechwidget.h
|         +--- radotechwidget.ui
|    +--- /images/                  # images used
|         +--- add.png
|         +--- back.png
|         +--- bar.png
|         +--- current.png
|         +--- circleGraph.png
|         +--- device.png
|         +--- edit.png
|         +--- Graph.png
|         +--- organs.png
|         +--- power.png
|         +--- /bodychartimages/
|              +--- bodyoutline.jpg         
|              +--- leftlymphvessel.png     
|              +--- rightlargeintestine.png
|              +--- leftbladder.png         
|              +--- leftpancreas.png        
|              +--- rightliver.png
|              +--- leftgallbladder.png     
|              +--- leftsmallintestine.png  
|              +--- rightlung.png
|              +--- leftheart.png           
|              +--- leftstomach.png         
|              +--- rightlymphvessel.png
|              +--- leftkidney.png          
|              +--- rightbladder.png        
|              +--- rightpancreas.png
|              +--- leftlargeintestine.png  
|              +--- rightgallbladder.png    
|              +--- rightsmallintestine.png
|              +--- leftliver.png           
|              +--- rightheart.png          
|              +--- rightstomach.png
|              +--- leftlung.png            
|              +--- rightkidney.png
```

