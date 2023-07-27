# csv-visualizer
A c++ project i built as the final project for my Object Oriented Programming (OOP) C++ course.

This is a C++ program that utilizes the ImGui and GLFW libraries to:
A) Create a simple gui for the user to interact with
B) Allow the user to select their .csv (currently hardcoded to the name energy_usage.csv)
C) Read, prase, and store the data from the .csv file in a vector class container
D) Take in the stored data and graph it to the gui.


This project requires you to install both ImGui and GLFW; I'll include a command if there are some issues with getting the compiler to read the headerfiles or libraries. 

The .csv file is named energy_usage.csv and it has one column for time (in hours) and another for energy usage (in any units). This structure is important, because the code will grab the file named energy_usage.csv (also needs to be in the same folder as the main.cpp file), parse through it line by line, and store it in a dynamic container using the vector class.

ImGui and GLFW work to create the window, the gui, buttons, and the graph (based on the data stored earlier).

The program ends with some basic clean-up code that helps with memory management and preventing memory leaks.

