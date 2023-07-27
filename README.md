# csv-visualizer
A c++ project I built as the final project for my Object Oriented Programming (OOP) C++ course.
<img width="1011" alt="image" src="https://github.com/IJustWantAJob/csv-visualizer/assets/100003303/082a9a88-4638-4a8b-8e01-ad6225a7b90d">

This project is a data visualization tool that reads energy usage data from a CSV file and displays it in a line graph. The x-axis represents time (in hours), and the y-axis represents energy usage. The tool is designed to be interactive, allowing users to select a CSV file and view the corresponding graph. This tool could be useful in a variety of contexts, such as monitoring energy usage in a building over time, or analyzing patterns in energy consumption for energy conservation efforts.


This is a C++ program that utilizes the ImGui and GLFW libraries to:
A) Create a simple gui for the user to interact with
B) Allow the user to select their .csv (currently hardcoded to the name energy_usage.csv)
C) Read, prase, and store the data from the .csv file in a vector class container
D) Take in the stored data and graph it to the gui.

--------------------------------------------------------------------------------------------------------------------------------------------

I used two libraries in this program for visualization, I had some issues with running it so I'll cover my compile command below:
GLFW: GLFW is an open-source library for creating windows with OpenGL contexts and managing input. It's used in this application to create the window and handle the main event loop.

Dear ImGui: ImGui is a bloat-free graphical user interface library for C++. It's used in this application to create the GUI elements such as the window, button, and line graph.

GLFW: This is an open-source library for creating windows with OpenGL contexts and managing input. It's used to create the window and handle the main event loop.

ImGui and GLFW work to create the window, the gui, buttons, and the graph (based on the data stored earlier).


--------------------------------------------------------------------------------------------------------------------------------------------


The folders required are ImGui and GLFW, but I had some issues with that so here is the command I ran to actually compile the code:

g++ -std=c++11 -DGL_SILENCE_DEPRECATION -I /Users/<YOUR_USERNAME>/cis25final/imgui -I /Users/<YOUR_USERNAME>/cis25final/imgui/backends -I /usr/local/include -L /usr/local/lib main.cpp /Users/<YOUR_USERNAME>/cis25final/imgui/imgui.cpp /Users/<YOUR_USERNAME>/cis25final/imgui/imgui_draw.cpp /Users/<YOUR_USERNAME>/cis25final/imgui/imgui_widgets.cpp /Users/<YOUR_USERNAME>/cis25final/imgui/imgui_tables.cpp /Users/<YOUR_USERNAME>/cis25final/imgui/backends/imgui_impl_glfw.cpp /Users/<YOUR_USERNAME>/cis25final/imgui/backends/imgui_impl_opengl3.cpp -lglfw -framework OpenGL -ldl -o main 


A break down of this long and complex command that you might think would hack you is this:

g++: This is the command to invoke the GCC C++ compiler.

-std=c++11: This option sets the language standard to C++11. This means the compiler will accept code that adheres to the C++11 standard.

-DGL_SILENCE_DEPRECATION: This is a preprocessor directive that defines the GL_SILENCE_DEPRECATION macro. This is typically used to silence deprecation warnings in the OpenGL library.

-I /Users/<YOUR_USERNAME>/cis25final/imgui -I /Users/<YOUR_USERNAME>/cis25final/imgui/backends -I /usr/local/include: These -I options tell the compiler where to look for header files. In this case, it's instructed to look in the imgui and imgui/backends directories in your project, and in the /usr/local/include directory.

-L /usr/local/lib: This -L option tells the linker where to look for library files. In this case, it's instructed to look in the /usr/local/lib directory.

main.cpp /Users/<YOUR_USERNAME>/cis25final/imgui/imgui.cpp /Users/<YOUR_USERNAME>/cis25final/imgui/imgui_draw.cpp /Users/<YOUR_USERNAME>/cis25final/imgui/imgui_widgets.cpp /Users/<YOUR_USERNAME>/cis25final/imgui/imgui_tables.cpp /Users/<YOUR_USERNAME>/cis25final/imgui/backends/imgui_impl_glfw.cpp /Users/<YOUR_USERNAME>/cis25final/imgui/backends/imgui_impl_opengl3.cpp: These are the source files to be compiled.

-lglfw: This option tells the linker to link against the GLFW library.

-framework OpenGL: This option is specific to macOS and tells the linker to link against the OpenGL framework.

-ldl: This option tells the linker to link against the dl library, which provides functions for dynamic linking.

-o main: This option specifies the name of the output file. In this case, the output executable will be named main.



This is specifically for me because I'm really bad at organizing my files, but if you're any better than this won't (hopefully) be an issue.


--------------------------------------------------------------------------------------------------------------------------------------------

The .csv file is named energy_usage.csv and it has one column for time (in hours) and another for energy usage (in any units). This structure is important, because the code will grab the file named energy_usage.csv (also needs to be in the same folder as the main.cpp file), parse through it line by line, and store it in a dynamic container using the vector class.


The program ends with some basic clean-up code that helps with memory management and preventing memory leaks.

