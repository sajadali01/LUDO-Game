#include "Board.h"

Board::Board(sf::RenderWindow* window) {
	this->window = window;
}
void Board::createBoard() {

	float width = 40, height = 40;
	int x = 50;
	int y = 50;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			sf::RectangleShape shape(sf::Vector2f(width, height));

			shape.setPosition(x * j + 25, y * i + 25);

			if (i == 6 && j == 1 || i < 6 && j < 6 || i == 7 && (j > 0 && j < 6)) {

				shape.setFillColor(sf::Color::Red);

			}

			else if (i == 1 && j == 8 || i < 6 && j > 8 || (i > 0 && i < 6) && j == 7) {

				shape.setFillColor(sf::Color::Green);

			}

			else if (i == 13 && j == 6 || i > 8 && j < 6 || (i < 14 && i>8) && j == 7) {

				shape.setFillColor(sf::Color::Blue);

			}

			else if (i == 8 && j == 13 || i > 8 && j > 8 || i == 7 && (j < 14 && j>8)) {

				shape.setFillColor(sf::Color::Yellow);

			}

			else if ((i < 9 && i>5) && (j > 5 && j < 9)) {

				shape.setFillColor(sf::Color::Black);

			}
			else if ((i == 2 && j == 6)|| (i==8 && j==2) || (i==6 && j==12)||(i==12 && j==8)) {
				shape.setFillColor(sf::Color::Magenta);
			}

			else {

				shape.setFillColor(sf::Color::White);

			}
			grid[i][j] = shape;
		}

	}

}
void Board::displayBoard() {

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			if (grid[i][j].getOutlineColor() != sf::Color::Black) {

				window->draw(grid[i][j]);

			}

		}

	}



	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			if (grid[i][j].getOutlineColor() == sf::Color::Black) {

				window->draw(grid[i][j]);

			}

		}

	}



}

bool Board::isStop(sf::Vector2i position)
{
	int x = 50;
	int y = 50;
	int newposx = position.x;
	int newposy = position.y;
	if ((newposx == 2 && newposy == 6) || (newposx == 8 && newposy == 2) || (newposx == 6 && newposy == 12) || (newposx == 12 && newposy == 8) || (newposx == 6 && newposy == 1) || (newposx == 1 && newposy == 8) || (newposx == 8 && newposy == 13) || (newposx == 13 && newposy == 6)) {
		return true;
	}
	return false; 
}
