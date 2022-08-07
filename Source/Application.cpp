#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include"glfw3.h"
#include"UI.h"
#include"ImGuiFileDialog.h"
#define STB_IMAGE_IMPLEMENTATION
#include"Image.h"

constexpr auto WIDTH = 800;
constexpr auto HEIGHT = 600;

bool isDialogOpen = false;

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

	Image icon("Images//AddIcon.png");
	std::vector<Image*> images;
	Image activeImage;

	float imageScale = 1.0f;

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.1f, 0.15f, 0.15f, 1.0f);

		coreUI.Begin();

		ImGui::BeginMainMenuBar();
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				exit(0);
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();

		ImGui::Begin("Image");
		if (images.size() != 0)
		{
			imageScale = ImGui::GetWindowWidth() / mode->width;
			ImGui::SetCursorPos(ImVec2{ 0.0f, (ImGui::GetWindowHeight() - (activeImage.GetHeight() * imageScale)) * 0.5f });
			ImGui::Image((void*)activeImage.GetRendererID(), ImVec2{ (float)activeImage.GetWidth() * imageScale ,(float)activeImage.GetHeight() * imageScale });
		}
		ImGui::End();

		ImGui::Begin("Image Browser");
		int cellSize = 50;
		for (int i = 1; i <= images.size(); i++)
		{
			int noOfCellPerRow = ImGui::GetWindowWidth() / (cellSize + 20);
			if (noOfCellPerRow == 0)
				noOfCellPerRow = 1;
			if (ImGui::ImageButton((void*)(*images[i-1]).GetRendererID(), ImVec2{ (float)cellSize,(float)cellSize }))
			{
				activeImage = *images[i-1];
			}
			if (i % noOfCellPerRow != 0)
				ImGui::SameLine();
		}
		if (ImGui::ImageButton((void*)icon.GetRendererID(), ImVec2{ (float)cellSize,(float)cellSize }))
		{
			ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose Image", ".jpg,.png,", ".");
		}
		ImGui::End();

		if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey", ImGuiWindowFlags_NoDocking, ImVec2{ 300.0f,100.0f }))
		{
			if (ImGuiFileDialog::Instance()->IsOk())
			{
				std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
				std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();

				images.push_back(new Image(filePathName.c_str()));			//Image Insertion
			}
			ImGuiFileDialog::Instance()->Close();
		}

		coreUI.End();
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	coreUI.OnDetach();
	glfwTerminate();
	return 0;
}