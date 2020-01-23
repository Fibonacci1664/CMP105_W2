#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();
	void drawLine();
	void calulateDistance();
	void drawCircle(Input* input);
	void drawTriangle(Input* input);

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	sf::CircleShape m_circle;
	sf::RectangleShape m_textBox;
	sf::RectangleShape m_line;
	sf::Vertex m_line_2[2];
	sf::VertexArray m_triangles;
	sf::Font m_font;
	sf::Text m_text_1;
	sf::Text m_text_2;
	std::string m_dragDistance;
	int m_mouseX;
	int m_mouseY;
	int newMouseX;
	int newMouseY;
	bool m_flag;
	bool m_circleLast;

	// Add your object here

};