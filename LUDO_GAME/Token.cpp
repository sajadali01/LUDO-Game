#include "Token.h"
#define N 15
Token::Token() {}

Token::Token(sf::Color color, int x, int y)
{
    this->color = color;
    token.setRadius(20);
    token.setFillColor(color);
    atHome = true;
    atEnd = false;
    token.setOutlineThickness(4);
    token.setOutlineColor(sf::Color::White);
    token.setPosition(x, y);
    starting.x = x;
    starting.y = y;

    redposition.push_back(sf::Vector2i(6, 1));
    redposition.push_back(sf::Vector2i(6, 2));
    redposition.push_back(sf::Vector2i(6, 3));
    redposition.push_back(sf::Vector2i(6, 4));
    redposition.push_back(sf::Vector2i(6, 5));
    redposition.push_back(sf::Vector2i(5, 6));
    redposition.push_back(sf::Vector2i(4, 6));
    redposition.push_back(sf::Vector2i(3, 6));
    redposition.push_back(sf::Vector2i(2, 6));
    redposition.push_back(sf::Vector2i(1, 6));
    redposition.push_back(sf::Vector2i(0, 6));
    redposition.push_back(sf::Vector2i(0, 7));
    redposition.push_back(sf::Vector2i(0, 8));
    redposition.push_back(sf::Vector2i(1, 8));
    redposition.push_back(sf::Vector2i(2, 8));
    redposition.push_back(sf::Vector2i(3, 8));
    redposition.push_back(sf::Vector2i(4, 8));
    redposition.push_back(sf::Vector2i(5, 8));
    redposition.push_back(sf::Vector2i(6, 9));
    redposition.push_back(sf::Vector2i(6, 10));
    redposition.push_back(sf::Vector2i(6, 11));
    redposition.push_back(sf::Vector2i(6, 12));
    redposition.push_back(sf::Vector2i(6, 13));
    redposition.push_back(sf::Vector2i(6, 14));
    redposition.push_back(sf::Vector2i(7, 14));
    redposition.push_back(sf::Vector2i(8, 14));
    redposition.push_back(sf::Vector2i(8, 13));
    redposition.push_back(sf::Vector2i(8, 12));
    redposition.push_back(sf::Vector2i(8, 11));
    redposition.push_back(sf::Vector2i(8, 10));
    redposition.push_back(sf::Vector2i(8, 9));
    redposition.push_back(sf::Vector2i(9, 8));
    redposition.push_back(sf::Vector2i(10, 8));
    redposition.push_back(sf::Vector2i(11, 8));
    redposition.push_back(sf::Vector2i(12, 8));
    redposition.push_back(sf::Vector2i(13, 8));
    redposition.push_back(sf::Vector2i(14, 8));
    redposition.push_back(sf::Vector2i(14, 7));
    redposition.push_back(sf::Vector2i(14, 6));
    redposition.push_back(sf::Vector2i(13, 6));
    redposition.push_back(sf::Vector2i(12, 6));
    redposition.push_back(sf::Vector2i(11, 6));
    redposition.push_back(sf::Vector2i(10, 6));
    redposition.push_back(sf::Vector2i(9, 6));
    redposition.push_back(sf::Vector2i(8, 5));
    redposition.push_back(sf::Vector2i(8, 4));
    redposition.push_back(sf::Vector2i(8, 3));
    redposition.push_back(sf::Vector2i(8, 2));
    redposition.push_back(sf::Vector2i(8, 1));
    redposition.push_back(sf::Vector2i(8, 0));
    redposition.push_back(sf::Vector2i(7, 0));
    redposition.push_back(sf::Vector2i(7, 1));
    redposition.push_back(sf::Vector2i(7, 2));
    redposition.push_back(sf::Vector2i(7, 3));
    redposition.push_back(sf::Vector2i(7, 4));
    redposition.push_back(sf::Vector2i(7, 5));
    redposition.push_back(sf::Vector2i(7, 6));



    greenposition.push_back(sf::Vector2i(1, 8));
    greenposition.push_back(sf::Vector2i(2, 8));
    greenposition.push_back(sf::Vector2i(3, 8));
    greenposition.push_back(sf::Vector2i(4, 8));
    greenposition.push_back(sf::Vector2i(5, 8));
    greenposition.push_back(sf::Vector2i(6, 9));
    greenposition.push_back(sf::Vector2i(6, 10));
    greenposition.push_back(sf::Vector2i(6, 11));
    greenposition.push_back(sf::Vector2i(6, 12));
    greenposition.push_back(sf::Vector2i(6, 13));
    greenposition.push_back(sf::Vector2i(6, 14));
    greenposition.push_back(sf::Vector2i(7, 14));
    greenposition.push_back(sf::Vector2i(8, 14));
    greenposition.push_back(sf::Vector2i(8, 13));
    greenposition.push_back(sf::Vector2i(8, 12));
    greenposition.push_back(sf::Vector2i(8, 11));
    greenposition.push_back(sf::Vector2i(8, 10));
    greenposition.push_back(sf::Vector2i(8, 9));
    greenposition.push_back(sf::Vector2i(9, 8));
    greenposition.push_back(sf::Vector2i(10, 8));
    greenposition.push_back(sf::Vector2i(11, 8));
    greenposition.push_back(sf::Vector2i(12, 8));
    greenposition.push_back(sf::Vector2i(13, 8));
    greenposition.push_back(sf::Vector2i(14, 8));
    greenposition.push_back(sf::Vector2i(14, 7));
    greenposition.push_back(sf::Vector2i(14, 6));
    greenposition.push_back(sf::Vector2i(13, 6));
    greenposition.push_back(sf::Vector2i(12, 6));
    greenposition.push_back(sf::Vector2i(11, 6));
    greenposition.push_back(sf::Vector2i(10, 6));
    greenposition.push_back(sf::Vector2i(9, 6));
    greenposition.push_back(sf::Vector2i(8, 5));
    greenposition.push_back(sf::Vector2i(8, 4));
    greenposition.push_back(sf::Vector2i(8, 3));
    greenposition.push_back(sf::Vector2i(8, 2));
    greenposition.push_back(sf::Vector2i(8, 1));
    greenposition.push_back(sf::Vector2i(8, 0));
    greenposition.push_back(sf::Vector2i(7, 0));
    greenposition.push_back(sf::Vector2i(6, 0));
    greenposition.push_back(sf::Vector2i(6, 1));
    greenposition.push_back(sf::Vector2i(6, 2));
    greenposition.push_back(sf::Vector2i(6, 3));
    greenposition.push_back(sf::Vector2i(6, 4));
    greenposition.push_back(sf::Vector2i(6, 5));
    greenposition.push_back(sf::Vector2i(5, 6));
    greenposition.push_back(sf::Vector2i(4, 6));
    greenposition.push_back(sf::Vector2i(3, 6));
    greenposition.push_back(sf::Vector2i(2, 6));
    greenposition.push_back(sf::Vector2i(1, 6));
    greenposition.push_back(sf::Vector2i(0, 6));
    greenposition.push_back(sf::Vector2i(0, 7));
    greenposition.push_back(sf::Vector2i(1, 7));
    greenposition.push_back(sf::Vector2i(2, 7));
    greenposition.push_back(sf::Vector2i(3, 7));
    greenposition.push_back(sf::Vector2i(4, 7));
    greenposition.push_back(sf::Vector2i(5, 7));
    greenposition.push_back(sf::Vector2i(6, 7));





    yellowposition.push_back(sf::Vector2i(8, 13));
    yellowposition.push_back(sf::Vector2i(8, 12));
    yellowposition.push_back(sf::Vector2i(8, 11));
    yellowposition.push_back(sf::Vector2i(8, 10));
    yellowposition.push_back(sf::Vector2i(8, 9));
    yellowposition.push_back(sf::Vector2i(9, 8));
    yellowposition.push_back(sf::Vector2i(10, 8));
    yellowposition.push_back(sf::Vector2i(11, 8));
    yellowposition.push_back(sf::Vector2i(12, 8));
    yellowposition.push_back(sf::Vector2i(13, 8));
    yellowposition.push_back(sf::Vector2i(14, 8));
    yellowposition.push_back(sf::Vector2i(14, 7));
    yellowposition.push_back(sf::Vector2i(14, 6));
    yellowposition.push_back(sf::Vector2i(13, 6));
    yellowposition.push_back(sf::Vector2i(12, 6));
    yellowposition.push_back(sf::Vector2i(11, 6));
    yellowposition.push_back(sf::Vector2i(10, 6));
    yellowposition.push_back(sf::Vector2i(9, 6));
    yellowposition.push_back(sf::Vector2i(8, 5));
    yellowposition.push_back(sf::Vector2i(8, 4));
    yellowposition.push_back(sf::Vector2i(8, 3));
    yellowposition.push_back(sf::Vector2i(8, 2));
    yellowposition.push_back(sf::Vector2i(8, 1));
    yellowposition.push_back(sf::Vector2i(8, 0));
    yellowposition.push_back(sf::Vector2i(7, 0));
    yellowposition.push_back(sf::Vector2i(6, 0));
    yellowposition.push_back(sf::Vector2i(6, 1));
    yellowposition.push_back(sf::Vector2i(6, 2));
    yellowposition.push_back(sf::Vector2i(6, 3));
    yellowposition.push_back(sf::Vector2i(6, 4));
    yellowposition.push_back(sf::Vector2i(6, 5));
    yellowposition.push_back(sf::Vector2i(5, 6));
    yellowposition.push_back(sf::Vector2i(4, 6));
    yellowposition.push_back(sf::Vector2i(3, 6));
    yellowposition.push_back(sf::Vector2i(2, 6));
    yellowposition.push_back(sf::Vector2i(1, 6));
    yellowposition.push_back(sf::Vector2i(0, 6));
    yellowposition.push_back(sf::Vector2i(0, 7));
    yellowposition.push_back(sf::Vector2i(0, 8));
    yellowposition.push_back(sf::Vector2i(1, 8));
    yellowposition.push_back(sf::Vector2i(2, 8));
    yellowposition.push_back(sf::Vector2i(3, 8));
    yellowposition.push_back(sf::Vector2i(4, 8));
    yellowposition.push_back(sf::Vector2i(5, 8));
    yellowposition.push_back(sf::Vector2i(6, 9));
    yellowposition.push_back(sf::Vector2i(6, 10));
    yellowposition.push_back(sf::Vector2i(6, 11));
    yellowposition.push_back(sf::Vector2i(6, 12));
    yellowposition.push_back(sf::Vector2i(6, 13));
    yellowposition.push_back(sf::Vector2i(6, 14));
    yellowposition.push_back(sf::Vector2i(7, 14));
    yellowposition.push_back(sf::Vector2i(7, 13));
    yellowposition.push_back(sf::Vector2i(7, 12));
    yellowposition.push_back(sf::Vector2i(7, 11));
    yellowposition.push_back(sf::Vector2i(7, 10));
    yellowposition.push_back(sf::Vector2i(7, 9));
    yellowposition.push_back(sf::Vector2i(7, 8));





    blueposition.push_back(sf::Vector2i(13, 6));
    blueposition.push_back(sf::Vector2i(12, 6));
    blueposition.push_back(sf::Vector2i(11, 6));
    blueposition.push_back(sf::Vector2i(10, 6));
    blueposition.push_back(sf::Vector2i(9, 6));
    blueposition.push_back(sf::Vector2i(8, 5));
    blueposition.push_back(sf::Vector2i(8, 4));
    blueposition.push_back(sf::Vector2i(8, 3));
    blueposition.push_back(sf::Vector2i(8, 2));
    blueposition.push_back(sf::Vector2i(8, 1));
    blueposition.push_back(sf::Vector2i(8, 0));
    blueposition.push_back(sf::Vector2i(7, 0));
    blueposition.push_back(sf::Vector2i(6, 0));
    blueposition.push_back(sf::Vector2i(6, 1));
    blueposition.push_back(sf::Vector2i(6, 2));
    blueposition.push_back(sf::Vector2i(6, 3));
    blueposition.push_back(sf::Vector2i(6, 4));
    blueposition.push_back(sf::Vector2i(6, 5));
    blueposition.push_back(sf::Vector2i(5, 6));
    blueposition.push_back(sf::Vector2i(4, 6));
    blueposition.push_back(sf::Vector2i(3, 6));
    blueposition.push_back(sf::Vector2i(2, 6));
    blueposition.push_back(sf::Vector2i(1, 6));
    blueposition.push_back(sf::Vector2i(0, 6));
    blueposition.push_back(sf::Vector2i(0, 7));
    blueposition.push_back(sf::Vector2i(0, 8));
    blueposition.push_back(sf::Vector2i(1, 8));
    blueposition.push_back(sf::Vector2i(2, 8));
    blueposition.push_back(sf::Vector2i(3, 8));
    blueposition.push_back(sf::Vector2i(4, 8));
    blueposition.push_back(sf::Vector2i(5, 8));
    blueposition.push_back(sf::Vector2i(6, 9));
    blueposition.push_back(sf::Vector2i(6, 10));
    blueposition.push_back(sf::Vector2i(6, 11));
    blueposition.push_back(sf::Vector2i(6, 12));
    blueposition.push_back(sf::Vector2i(6, 13));
    blueposition.push_back(sf::Vector2i(6, 14));
    blueposition.push_back(sf::Vector2i(7, 14));
    blueposition.push_back(sf::Vector2i(8, 14));
    blueposition.push_back(sf::Vector2i(8, 13));
    blueposition.push_back(sf::Vector2i(8, 12));
    blueposition.push_back(sf::Vector2i(8, 11));
    blueposition.push_back(sf::Vector2i(8, 10));
    blueposition.push_back(sf::Vector2i(8, 9));
    blueposition.push_back(sf::Vector2i(9, 8));
    blueposition.push_back(sf::Vector2i(10, 8));
    blueposition.push_back(sf::Vector2i(11, 8));
    blueposition.push_back(sf::Vector2i(12, 8));
    blueposition.push_back(sf::Vector2i(13, 8));
    blueposition.push_back(sf::Vector2i(14, 8));
    blueposition.push_back(sf::Vector2i(14, 7));
    blueposition.push_back(sf::Vector2i(13, 7));
    blueposition.push_back(sf::Vector2i(12, 7));
    blueposition.push_back(sf::Vector2i(11, 7));
    blueposition.push_back(sf::Vector2i(10, 7));
    blueposition.push_back(sf::Vector2i(9, 7));
    blueposition.push_back(sf::Vector2i(8, 7));
}

void Token::draw(sf::RenderWindow& window)
{
    window.draw(token);
}

bool Token::move(int steps) {
    int x = 50, y = 50;
    if (color == sf::Color::Red) {

        std::cout << std::endl << "Steps: " << steps;
        if (atHome) {
            if (steps == 6) {
                prev = redposition[0];
                token.setPosition(x * prev.y + 25, y * prev.x + 25);
                atHome = false;
            }
            return true;
        }
        int newPosition = -1;
        for (int i = 0; i < redposition.size(); i++) {
            if (redposition[i].x == prev.x && redposition[i].y == prev.y) {
                newPosition = steps + i;
                break;
            }
        }
        if (newPosition < redposition.size() && newPosition >= 0) {
            prev = redposition[newPosition];
            token.setPosition(x * prev.y + 25, y * prev.x + 25);
            if (newPosition == redposition.size() - 1) {
                atEnd = true;
            }
            return true;
        }
        else {
            return false;
        }
    }
    else if (color == sf::Color::Green) {

        std::cout << std::endl << "Steps: " << steps;
        if (atHome) {
            if (steps == 6) {
                prev = greenposition[0];
                token.setPosition(x * prev.y + 25, y * prev.x + 25);
                atHome = false;
            }
            return true;
        }
        int newPosition = -1;
        for (int i = 0; i < greenposition.size(); i++) {
            if (greenposition[i].x == prev.x && greenposition[i].y == prev.y) {
                newPosition = steps + i;
                break;
            }
        }
        if (newPosition < greenposition.size() && newPosition >= 0) {
            prev = greenposition[newPosition];
            token.setPosition(x * prev.y + 25, y * prev.x + 25);
            if (newPosition == greenposition.size() - 1) {
                atEnd = true;
            }
            return true;
        }
        else {
            return false;
        }
    }
    else  if (color == sf::Color::Yellow) {

        std::cout << std::endl << "Steps: " << steps;
        if (atHome) {
            if (steps == 6) {
                prev = yellowposition[0];
                token.setPosition(x * prev.y + 25, y * prev.x + 25);
                atHome = false;
            }
            return true;
        }
        int newPosition = -1;
        for (int i = 0; i < yellowposition.size(); i++) {
            if (yellowposition[i].x == prev.x && yellowposition[i].y == prev.y) {
                newPosition = steps + i;
                break;
            }
        }
        if (newPosition < yellowposition.size() && newPosition >= 0) {
            prev = yellowposition[newPosition];
            token.setPosition(x * prev.y + 25, y * prev.x + 25);
            if (newPosition == yellowposition.size() - 1) {
                atEnd = true;
            }
            return true;
        }
        else {
            return false;
        }
    }
    else  if (color == sf::Color::Blue) {
        std::cout << std::endl << "Steps: " << steps;
        if (atHome) {
            if (steps == 6) {
                prev = blueposition[0];
                token.setPosition(x * prev.y + 25, y * prev.x + 25);
                atHome = false;
            }
            return true;
        }
        int newPosition = -1;
        for (int i = 0; i < blueposition.size(); i++) {
            if (blueposition[i].x == prev.x && blueposition[i].y == prev.y) {
                newPosition = steps + i;
                break;
            }
        }
        if (newPosition < blueposition.size() && newPosition >= 0) {
            prev = blueposition[newPosition];
            token.setPosition(x * prev.y + 25, y * prev.x + 25);
            if (newPosition == blueposition.size() - 1) {
                atEnd = true;
            }
            return true;
        }
        else {
            return false;
        }

    }
    return false;
}

void Token::goHome()
{
    token.setPosition(starting.x, starting.y);
    atHome = true;
}
