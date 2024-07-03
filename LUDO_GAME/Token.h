#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Token
{
private:

public:
    sf::CircleShape token;
    std::vector<sf::Vector2i> redposition;
    std::vector<sf::Vector2i> greenposition;
    std::vector<sf::Vector2i> yellowposition;
    std::vector<sf::Vector2i> blueposition;
    sf::Color color;
    bool atHome;
    sf::Vector2i prev;
    Token(sf::Color color, int x, int y);
    void draw(sf::RenderWindow& window);
    bool move(int steps);
    sf::Vector2f starting;
    Token();
    void goHome();
    bool atEnd;

};


