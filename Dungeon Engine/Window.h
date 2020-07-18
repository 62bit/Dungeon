#pragma once
#include "Renderer.h"

struct Vector2
{
	double x;
	double y;
	
	Vector2(double xL, double yL)
	{
		x = xL;
		y = yL;
	}
	
};

class Window
{
public:
	Window(int width, int height, const char* title);
	~Window();

	GLFWwindow* GetWindowInstance() const;

	void Init();
	void Update();
	Vector2* GetMousePos();

	// Test keyboard callback
	
private:
	GLFWwindow* _window;
	const char* _title;
	unsigned int _width;
	unsigned int _height;

	//mouse position
	double _mouseY;
	double _mouseX;

	static void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int m);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	//static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
};
