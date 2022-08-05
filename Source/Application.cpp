#include<iostream>
#include<string>
#include"glfw3.h"
#include"UI.h"
#define STB_IMAGE_IMPLEMENTATION
#include"Image.h"

constexpr auto WIDTH = 800;
constexpr auto HEIGHT = 600;

int main()
{
#pragma region GLFW_INIT
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Image Viewer", NULL, NULL);
	glfwSwapInterval(1);
	glfwMakeContextCurrent(window);

	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
#pragma endregion

	CoreUI coreUI(window);
	coreUI.OnAttach();

	Image pain;
	pain.Open("Images\\Image.png");

	float scale = 1.0f;

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.1f, 0.15f, 0.15f, 1.0f);

		coreUI.Begin();

		ImGui::BeginMainMenuBar();
		if (ImGui::BeginMenu("File"))
		{
			ImGui::MenuItem("Open");
			if (ImGui::MenuItem("Exit"))
			{
				exit(0);
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();

		ImGui::Begin("Image");
		scale = ImGui::GetWindowWidth() / mode->width;
		/// - (float)pain.GetHeight())
		std::cout << pain.GetHeight() << std::endl;
		ImGui::SetCursorPos(ImVec2{ 0.0f, (ImGui::GetWindowHeight()) * 0.5f });
		ImGui::Image((void*)pain.GetRendererID(), ImVec2{ (float)pain.GetWidth() * scale ,(float)pain.GetHeight() * scale });
		ImGui::End();

		ImGui::Begin("Image Browser");
		for (int i = 1; i < 15; i++)
		{
			int cellSize = 70;
			int cell = ImGui::GetWindowWidth() / (cellSize + 20);
			ImGui::ImageButton((void*)pain.GetRendererID(), ImVec2{ (float)cellSize,(float)cellSize });
			if (i % cell != 0)
				ImGui::SameLine();
		}
		ImGui::End();

		coreUI.End();
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	coreUI.OnDetach();
	glfwTerminate();
}