#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#include <vector>
#include "Token.h"
#include "Dice.h"
#include "Board.h"

#define N 15

bool is_colliding(sf::CircleShape shape, sf::Vector2i mouse_pos) {
	sf::Vector2f shapePosition = shape.getPosition();
	if (shapePosition.x < mouse_pos.x && shapePosition.y < mouse_pos.y
		&& shapePosition.x + 2 * shape.getRadius() > mouse_pos.x && shapePosition.y + 2 * shape.getRadius() > mouse_pos.y) {
		return true;
	}
	return false;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	// Seed the random number generator with the current time
	std::srand(62704);

	window.setFramerateLimit(60);
	Board board = Board(&window);
	board.createBoard();
	Dice dice(&window);

	int turn = 0;
	int othersturn = 0;
	int x = 58, y = 58;
	Player players[4] =
	{
		Player(sf::Color::Red, 1 * x + 17, 1 * y + 17),
		Player(sf::Color::Green, 11.4 * x - 35, 1 * y + 15),
		Player(sf::Color::Yellow, 11.4 * x - 36, 11.4 * y - 36),
		Player(sf::Color::Blue, 1 * x + 17, 11.4 * y - 37)
	};

	bool hasRolled = false;
	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				if (!hasRolled) {
					dice.roll();
					hasRolled = true;
				}
			}
		}
		window.clear();
		board.displayBoard();
		for (int i = 0; i < 4; i++)
		{
			if (i == turn) {
				continue;
			}
			players[i].drawTokens(window);
		}
		players[turn].drawTokens(window);
		if (turn == 0) {
			dice.setColor(sf::Color::Red);
		}
		else if (turn == 1) {
			dice.setColor(sf::Color::Green);
		}
		else if (turn == 2) {
			dice.setColor(sf::Color::Yellow);
		}
		else if (turn == 3) {
			dice.setColor(sf::Color::Blue);
		}

		if (hasRolled && !dice.isRolling()) {
			if (players[turn].allAtHome()) {
				if (dice.result != 6) {
					turn = (turn + 1) % 4;
					hasRolled = false;
				}
				else {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						std::cout << turn << "\n";
						auto pos = sf::Mouse::getPosition(window);
						for (int i = 0; i < 4; i++) {
							if (is_colliding(players[turn].tokens[i].token, pos)) {
								if (!players[turn].moveToken(i, dice.result)) {
									continue;
								}
								for (othersturn = 0; othersturn < 4; othersturn++) {
									if (othersturn == turn) {
										continue;
									}
									for (int j = 0; j < 4; j++) {
										if (players[turn].tokens[i].prev == players[othersturn].tokens[j].prev) {
											if (!board.isStop(players[othersturn].tokens[j].prev)) {
												players[othersturn].tokens[j].goHome();
											}
										}
									}
								}
								turn = (turn + 1) % 4;
								hasRolled = false;
								break;
							}
						}
					}
				}
			}
			else {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					std::cout << turn << "\n";
					auto pos = sf::Mouse::getPosition(window);
					for (int i = 0; i < 4; i++) {
						if (is_colliding(players[turn].tokens[i].token, pos)) {
							if (!players[turn].moveToken(i, dice.result)) {
								continue;
							}
							for (othersturn = 0; othersturn < 4; othersturn++) {
								if (othersturn == turn) {
									continue;
								}
								for (int j = 0; j < 4; j++) {
									if (players[turn].tokens[i].prev == players[othersturn].tokens[j].prev) {
										if (!board.isStop(players[othersturn].tokens[j].prev)) {
											players[othersturn].tokens[j].goHome();
										}
									}
								}
							}
							turn = (turn + 1) % 4;
							hasRolled = false;
							break;
						}
					}
				}
			}
		}

		dice.updateRolling();
		dice.draw();
		window.display();	//Will Dsiplay Whole Loop
		/*if (players[(turn - 1) % 4].allatEnd()) {
			break;
		}*/
	}
	//while (window.isOpen()) {
	//	sf::Font font;
	//	sf::Text text;
	//	if (!font.loadFromFile("arial.ttf"))
	//	{
	//		std::cout << "Error in loading the font";
	//	}
	//	text.setFont(font);
	//	text.setCharacterSize(80);
	//	text.setStyle(sf::Text::Bold);
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed) {
	//			window.close();
	//		}

	//	}
	//	switch ((turn - 1) % 4) {
	//	case 0:
	//		text.setFillColor(sf::Color::Red);
	//		text.setString("Red Wins");
	//		break;
	//	case 1:
	//		text.setFillColor(sf::Color::Green);
	//		text.setString("Green Wins");
	//		break;
	//	case 2:
	//		text.setFillColor(sf::Color::Yellow);
	//		text.setString("Yellow Wins");
	//		break;
	//	case 3:
	//		text.setFillColor(sf::Color::Blue);
	//		text.setString("Blue Wins");
	//		break;
	//	}
	//	window.clear();
	//	window.draw(text);
	//	//window.display();
	//}

	return 0;
}
