#include "Dice.h"

Dice::Dice(sf::RenderWindow* window)
{
    // Initialize the die shape
    this->window = window;
    dice.setSize(sf::Vector2f(70, 70));
    dice.setFillColor(sf::Color::White);
    dice.setOutlineThickness(2);
    dice.setOutlineColor(sf::Color::Black);
    dice.setPosition(358, 358);     //Set the initial position of the die in the window
    initialPosition = dice.getPosition();
    result = 0;
}
Dice::Dice() {}

void Dice::roll()
{
    if (!rolling)
    {
        rolling = true;
        animationClock.restart();
        dice.setPosition(initialPosition);
    }
}

void Dice::setColor(sf::Color color) {
    dice.setFillColor(color);
}
bool Dice::isRolling() {
    return rolling;
}

void Dice::updateRolling()
{
    if (rolling)
    {
        // Simulate rolling animation for 1 second
        sf::Time elapsed = animationClock.getElapsedTime();

        if (elapsed.asSeconds() < 1.0f)
        {
            dice.rotate(180 * elapsed.asSeconds());
        }
        else
        {
            // Finish rolling animation
            rolling = false;
            animationClock.restart();
            result = rand() % 6 + 1;
            std::cout << "Result: " << result << std::endl;
            dice.setRotation(0);

        }
    }

    //auto pos = sf::Mouse::getPosition(*window);
    //dice.setPosition(static_cast<float>(pos.x), static_cast<float>(pos.y));
}

void Dice::draw()
{
    window->draw(dice);

    if (rolling)
    {
        // Display the rolling result (temporary)
        sf::Font font;
        if (font.loadFromFile("wTmfJo.ttf"))
        {
            sf::Text text;
            text.setFont(font);
            text.setString(std::to_string(result));
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::White);
            text.setPosition(dice.getPosition().x + 20, dice.getPosition().y + 20);
            window->draw(text);
        }
        else
        {
            std::cerr << "Error loading font!" << std::endl;
        }
    }
    else
    {
        sf::Font font;
        if (font.loadFromFile("wTmfJo.ttf"))
            
        {
            sf::Text text;
            text.setFont(font);
            text.setString(std::to_string(result));
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::Black);
            text.setPosition(dice.getPosition().x + 25, dice.getPosition().y + 20);
            window->draw(text);
        }
    }
}

int Dice::getResult()
{
    return result;
}
