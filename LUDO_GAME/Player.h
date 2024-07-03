#pragma once
#include "Token.h"
#include "Dice.h"
#include<vector>

class Player
{
private:

    int tokensAtHome;

public:

    std::vector<Token> tokens;
    sf::Color color;
    Token token;
    int index, steps;

    Player(sf::Color color, int startX, int startY);

    bool moveToken(int tokenNum, int result);

    void drawTokens(sf::RenderWindow& window);

    bool moveTokenOut();

    int getTokensAtHome() const;

    int getNumberOfTokens() {
        return tokens.size();
    }

    Token& operator[](int index) {
        /*vector<vector2i> movset = {
            sf::Vector2i(i, j),
            sf::Vector2i(i, j),
            sf::Vector2i(i, j),
            sf::Vector2i(i, j),
        };*/
        return tokens[index];
    }

    bool allAtHome();
    bool allatEnd();
};

