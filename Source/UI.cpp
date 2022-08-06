#include"UI.h"


CoreUI::CoreUI(GLFWwindow* window)
{
	m_Window = window;
}

CoreUI::~CoreUI()
{

}

void CoreUI::OnAttach()
{
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_ViewportsEnable;
	io.ConfigFlags = ImGuiConfigFlags_DockingEnable;
	io.IniFilename = "AppConfiguration.ini";
	Style();
}

void CoreUI::OnDetach()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void CoreUI::Begin()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	ImGui::DockSpaceOverViewport();
}

void CoreUI::End()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void CoreUI::Style()
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowMenuButtonPosition = ImGuiDir_None;
	style.Colors[ImGuiCol_TitleBg] = ImVec4{ 39.0f / 255.0f, 46.0f / 255.0f, 57.0f / 255.0f,1.0f };
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4{ 39.0f / 255.0f, 46.0f / 255.0f, 57.0f / 255.0f,1.0f };
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 39.0f / 255.0f, 46.0f / 255.0f, 57.0f / 255.0f,1.0f };
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4{ 39.0f / 255.0f, 46.0f / 255.0f, 57.0f / 255.0f,1.0f };
	////rgb(66, 203, 169)
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4{ 66.0f / 255.0f, 203.0f / 255.0f, 169.0f / 255.0f,1.0f };
	style.Colors[ImGuiCol_DockingPreview] = ImVec4{ 66.0f / 255.0f, 203.0f / 255.0f, 169.0f / 255.0f,1.0f };
	style.Colors[ImGuiCol_Header] = ImVec4{ 66.0f / 255.0f, 203.0f / 255.0f, 169.0f / 255.0f,1.0f };
	style.Colors[ImGuiCol_Border] = ImVec4{ 66.0f / 255.0f, 203.0f / 255.0f, 169.0f / 255.0f,1.0f };
	style.Colors[ImGuiCol_WindowBg] = ImVec4{ 1.0f / 255.0f, 10.0f / 255.0f, 24.0f / 255.0f,1.0f };
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4{ 1.0f / 255.0f, 10.0f / 255.0f, 24.0f / 255.0f,1.0f };
	style.Colors[ImGuiCol_DockingEmptyBg] = ImVec4{ 10.0f / 255.0f, 10.0f / 255.0f, 10.0f / 255.0f,1.0f };
	//style.FramePadding = ImVec2{ 2,2 };
	style.FrameBorderSize = 0.0f;
	style.TabBorderSize = 0.0f;
	style.WindowBorderSize = 0.0f;
	style.TabRounding = 0;
}