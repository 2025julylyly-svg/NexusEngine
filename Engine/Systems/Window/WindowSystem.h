#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class WindowSystem final : public sf::RenderWindow
{
private:
    sf::RenderWindow window;
public:
    explicit WindowSystem();
};
