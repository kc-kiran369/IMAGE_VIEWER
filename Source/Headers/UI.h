#ifndef UI_H
#define UI_H

#include"imgui.h"
#include"imgui_impl_glfw.h"
#include"imgui_impl_opengl3.h"

class CoreUI
{
public:
	CoreUI(GLFWwindow* window);
	~CoreUI();

	void OnAttach();
	void OnDetach();

	void Begin();
	void End();

	void Style();

private:
	GLFWwindow* m_Window;
};

#endif