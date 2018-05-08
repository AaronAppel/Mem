#ifndef __MYIMGUI_H__
#define __MYIMGUI_H__

/* IMGui window IDs*/
enum eIMGuiWindowID
{
	WindowID_Cameras = 0,
	WindowID_RenderedScene,
	WindowID_Nodes,
	WindowID_Lights,
	WindowID_SceneController,
	WindowID_SceneExplorer,
	WindowID_Max,
	WindowID_Invalid,
};

// Disable Warning
#pragma warning(disable:4996)

#include "MyGLFW\MyGLFW.h"

// system library includes
#include <map>
#include <vector>

// imGUI related
#include "../Libraries/imGUI/imgui.h"
#include "../Libraries/imGUI/imgui_impl_glfw_gl3.h"

// 3rd Party imGUI extension
#include "imguinodegrapheditor.h"
#include "imguidock.h"
#include "imigui_memory_editor.h"

// MyImGUI
#include "ImGUIWindow.h"

#include "IconsFontAwesome.h"
#include "ImGUIStyles.h"
#include "ImGuiUtils.h"

#include "NodeGraph.h"

// external classes
class MyGLFW;

// Window classes
class RenderedScene;
class NodeGraph;
class ImGUIWindow;

class MyImGUI
{
public:
	MyImGUI();
	~MyImGUI();

	void Init(MyGLFW* window, bool setupCallbacks = false);

	void NewFrame();
	void Draw();

	// TODO:: Create eWindow enum for specifying windows without handles
	void ShowWindow(bool visible) {}; // toggle window visibility

	void AddWindow(); // (eWindow) or int windowID
	void RemoveWindow() {}; // (eWindow)

	RenderedScene* GetRenderedScene(eIMGuiWindowID ID) { return (RenderedScene*)m_Windows.at(ID); };

private:
	MyGLFW* m_pWindow = nullptr;

	// other
	bool m_Visible = true;

	ImTextureID test_image = 0;
	ImGuiWindowFlags m_Flags = 0;

	// TODO :: Create Window() base class and have a list of windows.
	// This is nice for multiple instances of the same window.
	// Also consider making SaveWindows() cJSON save functionality.

	/* Functions */
	void CreateWindows();
	void DrawWindowToggle();
	void DrawMainMenuBar();
	void DrawMainWindow();

	void ProcessEvents();

	int m_Event = 0;

	/* Styling */
	const int m_ThemeMax = 5; // number of supported themes
	int m_Theme = 0;
	const float m_GlobalOpacityDefault = 0.95f;
	float m_GlobalOpacity = m_GlobalOpacityDefault;

	void SetTheme(int theme);

	// windows
	std::map<eIMGuiWindowID, ImGUIWindow*> m_Windows;
	bool show_rendered_scene = true;
	bool show_node_graph = true;
	bool show_camera_panel = true;
};

int main();

#endif //__MYIMGUI_H__
