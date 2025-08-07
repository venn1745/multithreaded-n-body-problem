#include "body.hpp"

void Body::update(float dt, const std::vector<Body>& bodies) {

    sf::Vector2f forceDueToGravity = getGravity(bodies);

    acc = forceDueToGravity;
    vel += acc * dt;
    pos += vel * dt;

    edges();

}

void Body::render(sf::RenderWindow* window) {

    sf::CircleShape shape;
    shape.setRadius(size);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(pos);

    window->draw(shape);

}

sf::Vector2f Body::getGravity(const std::vector<Body>& bodies) {

    sf::Vector2f force(0, 0);

    for (auto& other : bodies) {

        if (&other == this) continue;

        float G = 100;
        sf::Vector2f dir = other.pos - pos;
        float distSquared = dir.lengthSquared();
        if (distSquared < 5000) continue;
        
        float mag = G / distSquared;
        force += dir * mag;

    }

    return force;

}

void Body::edges() {

    float coeff = 0.5;

    if (pos.x > WIDTH - size * 2) vel.x *= -coeff;
    if (pos.x < 0 - size) vel.x *= -coeff;
    if (pos.y > HEIGHT - size * 2) vel.y *= -coeff;
    if (pos.y < 0 - size) vel.y *= -coeff;

}