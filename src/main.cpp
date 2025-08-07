#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "global.hpp"

int main() {

    std::cout << std::endl;

    // ========== //

    sf::Clock clock;
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WIDTH, HEIGHT}),
        "multithreaded n body problem", 
        sf::Style::Default, 
        sf::State::Windowed,
        settings
    );

    const sf::Font font("fonts/Consolas.ttf");

    sf::Text fpsText(font);
    fpsText.setCharacterSize(20);
    fpsText.setFillColor(sf::Color(255, 255, 255, 100));
    fpsText.setPosition({10, 10});

    sf::Text deltaTimeText(font);
    deltaTimeText.setCharacterSize(20);
    deltaTimeText.setFillColor(sf::Color(255, 255, 255, 100));
    deltaTimeText.setPosition({10, 30});

    int frameCounter = 0;
    const int updateRate = 72;

    while (window.isOpen()) {

        float dt = clock.restart().asSeconds();

        frameCounter++;
        if (frameCounter >= updateRate) {

            frameCounter = 0;

            std::ostringstream ss;
            ss << "fps: " << std::fixed << std::setprecision(0) << 1 / dt;
            fpsText.setString(ss.str());

            ss.str("");
            ss.clear();

            ss << "dt: " << std::fixed << std::setprecision(2) << (dt * 1000) << "ms";
            deltaTimeText.setString(ss.str());

        }

        while (const std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>())
                window.close();

        }

        window.clear(sf::Color(20, 20, 20));
            
            window.draw(fpsText);
            window.draw(deltaTimeText);

        window.display();
    }

    // ========== //

    std::cout << std::endl;
    return 0;

}