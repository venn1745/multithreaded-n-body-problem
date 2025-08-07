#include <iostream>
#include <SFML/Graphics.hpp>

#include "global.hpp"

class Body {

    private:

        sf::Vector2f vel;
        sf::Vector2f acc;
        int size;
    
    public:

        sf::Vector2f pos;

        Body(sf::Vector2f pos, int size) : pos(pos), size(size) {};

        void update(float dt, const std::vector<Body>& bodies);
        void render(sf::RenderWindow* window);

        sf::Vector2f getGravity(const std::vector<Body>& bodies);

        void edges();

};