#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Dice
{
private:
	sf::RectangleShape dice;
	sf::RenderWindow* window;

	// Flag indicating whether the die is currently rolling
	bool rolling = false;
	// Clock for controlling animation duration
	sf::Clock animationClock;

public:
	Dice(sf::RenderWindow* window);
	sf::Vector2f initialPosition;
	int result;
	Dice();
	void draw();

	sf::Font font;
	void roll();

	bool isRolling();

	void updateRolling();

	/*void displayDice();*/

	int getResult();
	void setColor(sf::Color color);
};

