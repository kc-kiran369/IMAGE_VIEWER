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
	//style.FramePadding = ImVec2{ 0.0f,0.0f };
	//style.CellPadding = ImVec2{ 0.0f,0.0f };
	//style.WindowPadding = ImVec2{ 0.0f,0.0f };
	style.TabRounding = 2;
	style.ItemInnerSpacing = { 2,10 };
}