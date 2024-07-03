#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define N 15
class Board {
private:
	sf::RenderWindow* window;

public:

	std::vector<std::vector<sf::RectangleShape>> grid{ N, std::vector<sf::RectangleShape>(N) };
	Board(sf::RenderWindow* window);


	void createBoard();

	void displayBoard();
	bool isStop(sf::Vector2i position);

};

