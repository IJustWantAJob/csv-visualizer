// Include necessary libraries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

// CSV file structure
struct CSV {
    std::vector<float> time;
    std::vector<float> energy;
};

// Function to read CSV file
CSV readCSV(const std::string& filename) {
    CSV csv;
    std::ifstream file(filename);
    std::string line;
    std::getline(file, line); 
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string time, energy;
        std::getline(ss, time, ',');
        std::getline(ss, energy, ',');
        csv.time.push_back(std::stof(time));
        csv.energy.push_back(std::stof(energy));
    }
    return csv;
}

int main() {
    // Setup window
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(1280, 720, "CSV Graph", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enables vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 120");

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Start the ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Create GUI
        ImGui::Begin("CSV Graph");
        static CSV csv;
        if (ImGui::Button("Select CSV")) {
            csv = readCSV("energy_usage.csv"); 
        }
        ImVec2 graph_size(800.0f, 600.0f); // Resize , maybe change from hardcoding?
        ImGui::Text("0"); 
        ImGui::SameLine();
        ImGui::PlotLines("Energy", csv.energy.data(), csv.energy.size(), 0, NULL, FLT_MAX, FLT_MAX, graph_size);
        ImGui::SameLine();
        ImGui::Text("%lu", csv.time.size()); // End of X-axis
        ImGui::End();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
