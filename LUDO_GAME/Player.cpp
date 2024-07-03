
#include "Player.h"

#define x2 50
#define y2 50

Player::Player(sf::Color color, int startX, int startY) : color(color)
{
    // Initialize four tokens for the player

    float xOffset = 52.5f;
    float yOffset = 52.5f;


    for (int i = 0; i < 4; ++i)
    {
        tokens.emplace_back(color, startX + i % 2 * xOffset, startY + i / 2 * yOffset);
    }
}

bool Player::moveToken(int tokenNum, int result)
{
    return tokens[tokenNum].move(result);
    
}

void Player::drawTokens(sf::RenderWindow& window)
{
    // Drawing all tokens of the player

    // for (auto& token : tokens) 
    // {
    //     token.draw(window);
    // }

    for (int i = 0; i < tokens.size(); i++) {
        tokens[i].draw(window);
    }

}

bool Player::moveTokenOut()
{
    if (tokensAtHome > 0)
    {
        tokensAtHome--;
        return true;
    }
    return false; // No tokens left At Home
}


bool Player::allAtHome()
{
    for (int i = 0; i < tokens.size(); i++) {
        if (!tokens[i].atHome) {
            return false;
        }
    }
    return true;
}

bool Player::allatEnd()
{
    for (int i = 0; i < tokens.size(); i++) {
        if (!tokens[i].atEnd) {
            return false;
        }
    }
    return true;
}

int Player::getTokensAtHome() const {
    return tokensAtHome;
}


