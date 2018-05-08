#ifndef __Library_H__
#define __Library_H__

// #define _release
#ifdef _release
#define preFunc inline
#else
#define preFunc ;
#endif // _release

/* External libraries */
#include <assert.h>
#include <iostream>
#define MyAssert assert

// OpenGL extensions
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <math.h>
#include "../Utilities/MathHelpers.h"
#include "../Utilities/Vector.h"

typedef Vector2 vec2;
typedef Vector3 vec3;
typedef Vector4 vec4;

class MyGLFW
{
public:
	MyGLFW(const char* windowTitle, vec2 windowSize = vec2(1280, 720), vec2 windowPos = vec2(100, 100));
	~MyGLFW();

	/* Event Callbacks */
	// input
	void SetInputMode(); // TODO:: Add functionality
	void SetKeyCallback(GLFWkeyfun key_callback);
	void SetCursorMoveCallback(GLFWcursorposfun key_callback);
	void SetScrollCallback(GLFWscrollfun scroll_callback);
	void SetCharCallback(GLFWcharfun char_callback);
	void SetMouseButtonCallback(GLFWmousebuttonfun mouse_button_callback);
	void SetCharModsCallback(GLFWcharmodsfun char_mods_callback);
	// window
	void SetWindowMoveCallback(GLFWwindowposfun window_position_callback);
	void SetWindowResizeCallback(GLFWwindowsizefun window_resize_callback);
	void SetWindowCloseCallback(GLFWwindowclosefun window_close_callback);
	void SetWindowRefreshCallback(GLFWwindowrefreshfun window_refresh_callback);
	void SetWindowFocusCallback(GLFWwindowfocusfun window_focus_callback);
	void SetWindowIconifyCallback(GLFWwindowiconifyfun window_iconify_callback);
	void SetFrameBufferResizeCallback(GLFWframebuffersizefun frame_buffer_callback);
	// error
	void SetErrorCallback(GLFWerrorfun error_callback);

	void SetCursor() {};

	// Game Loop
	void CheckInput() { glfwPollEvents(); };
	void Clear();
	void SwapBuffers() { glfwSwapBuffers(m_Window); };

	void RequestClose() { glfwSetWindowShouldClose(m_Window, GL_TRUE); };

	int CloseRequested() {return glfwWindowShouldClose(m_Window); }
	GLFWwindow* GetWindow() { return m_Window; };

	void GetWindowPosition(int *x, int *y) { glfwGetWindowPos(m_Window, x, y); };
	void GetWindowSize(int *x, int *y) { glfwGetWindowSize(m_Window, x, y); }

	preFunc double GetTime() { return glfwGetTime(); };

	void SetClearColor(vec4 color) { m_ClearColor = color; };
	void SetWindowPosition(int x, int y);

private:
	GLFWwindow* m_Window = nullptr;
	vec4 m_ClearColor = vec4(0.3f, 0.3f, 0.3f, 1);
};

#endif //!__Library_H__
