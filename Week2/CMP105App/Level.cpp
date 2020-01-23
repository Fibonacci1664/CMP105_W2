#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	m_dragDistance = "";
	m_mouseX = 0;
	m_mouseY = 0;
	input->setMouseLDown(false);
	m_flag = false;	

	// initialise game objects
	m_textBox.setSize(sf::Vector2f(400, 100));
	m_textBox.setOrigin(m_textBox.getSize().x / 2, m_textBox.getSize().y / 2);
	m_textBox.setFillColor(sf::Color(126, 126, 126, 126));
	m_textBox.setPosition(sf::Vector2f(window->getSize().x / 2, 75));

	if (!m_font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	std::string mouseXPos = std::to_string(input->getMouseX());
	std::string mouseYPos = std::to_string(input->getMouseY());

	m_text_1.setFont(m_font);
	m_text_1.setString("Mouse X co-ord: " + mouseXPos + " Mouse Y co-ord: " + mouseYPos);
	m_text_1.setCharacterSize(16);
	m_text_1.setOrigin(sf::Vector2f(m_text_1.getLocalBounds().width / 2, m_text_1.getLocalBounds().height / 2));
	m_text_1.setPosition(sf::Vector2f(m_textBox.getPosition().x, m_textBox.getPosition().y - 30));
	m_text_1.setFillColor(sf::Color::Red);

	m_text_2.setFont(m_font);
	m_text_2.setString("Drag distance by Pythagoreum theorem: " + m_dragDistance);
	m_text_2.setCharacterSize(16);
	m_text_2.setOrigin(sf::Vector2f(m_text_1.getLocalBounds().width / 2, m_text_1.getLocalBounds().height / 2));
	m_text_2.setPosition(sf::Vector2f(m_textBox.getPosition().x, m_textBox.getPosition().y + 20));
	m_text_2.setFillColor(sf::Color::Red);
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	//// Works only when window is in focus.
	//if (input->isKeyDown(sf::Keyboard::W))
	//{
	//	std::cout << "The 'W' key has been pressed.\n";
	//}

	//if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	//{
	//	std::cout << "Keys 'J', 'K' and 'L' are all being pressed together.\n";
	//}

	//if (input->isKeyDown(sf::Keyboard::Escape))
	//{
	//	window->close();
	//}

	// If we've clicked the left mouse button.
	if (input->isMouseLDown() && !m_flag)
	{
		m_flag = true;
		m_mouseX = input->getMouseX();
		m_mouseY = input->getMouseY();
	}

	// If we've lifted off of the left mouse button.
	if (!(input->isMouseLDown()) && m_flag)
	{
		int newMouseX = input->getMouseX();
		int newMouseY = input->getMouseY();

		int deltaX = newMouseX - m_mouseX;
		int deltaY = newMouseY - m_mouseY;

		int distance = sqrt((deltaX * deltaX) + (deltaY * deltaY));
		m_dragDistance = std::to_string(distance);
		
		m_flag = false;
	}

	if (input->isMouseRDown())
	{
		input->setMouseRDown(false);

		circle.setRadius(30);
		circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));
		circle.setFillColor(sf::Color::Blue);
		circle.setOutlineColor(sf::Color::Red);
		circle.setOutlineThickness(5.0f);
		circle.setPosition(sf::Vector2f(input->getMouseX(), input->getMouseY()));
	}
}

// Update game objects
void Level::update()
{
	std::string mouseXPos = std::to_string(input->getMouseX());
	std::string mouseYPos = std::to_string(input->getMouseY());

	m_text_1.setString("Mouse X co-ord: " + mouseXPos + " Mouse Y co-ord: " + mouseYPos);
	m_text_1.setOrigin(sf::Vector2f(m_text_1.getLocalBounds().width / 2, m_text_1.getLocalBounds().height / 2));
	m_text_1.setPosition(sf::Vector2f(m_textBox.getPosition().x, m_textBox.getPosition().y - 30));

	m_text_2.setString("Drag distance by Pythagoreum theorem: " + m_dragDistance);
	m_text_2.setOrigin(sf::Vector2f(m_text_1.getLocalBounds().width / 2, m_text_1.getLocalBounds().height / 2));
	m_text_2.setPosition(sf::Vector2f(m_textBox.getPosition().x, m_textBox.getPosition().y + 20));

	m_textBox.setPosition(sf::Vector2f(window->getSize().x / 2, 75));
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(m_textBox);
	window->draw(m_text_1);
	window->draw(m_text_2);
	window->draw(circle);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}