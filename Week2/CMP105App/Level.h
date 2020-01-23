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

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	sf::CircleShape circle;
	sf::RectangleShape m_textBox;
	sf::Font m_font;
	sf::Text m_text_1;
	sf::Text m_text_2;

	std::string m_dragDistance;
	int m_mouseX;
	int m_mouseY;
	bool m_flag;

	// Add your object here

};