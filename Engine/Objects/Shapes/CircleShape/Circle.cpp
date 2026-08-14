#include "Circle.h"

Circle::Circle(float x, float y) : Speed( 1.f ) {
    circle.setPosition( { x, y } );
}

void Circle::SetSpeed(float speed) {
    Speed = speed;
}

void Circle::SetColor(uint8_t r, uint8_t g, uint8_t b, float state) {
    if (state == 0) {
        circle.setFillColor( { r, g, b } );
    } else {
        circle.setFillColor( sf::Color::Transparent );
        circle.setOutlineThickness( state );
        circle.setOutlineColor( { r, g, b } );
    }
}

void Circle::SetRadius(float Radius) {
    circle.setRadius( Radius );
}

void Circle::SetPos(float x, float y) {
    circle.setPosition( { x, y } );
}

void Circle::MoveUp() {
    this->circle.setPosition( { this->circle.getPosition().x, this->circle.getPosition().y - this->Speed } );
}

void Circle::MoveDown() {
    this->circle.setPosition( { this->circle.getPosition().x, this->circle.getPosition().y + this->Speed } );
}

void Circle::MoveLeft() {
    this->circle.setPosition( { this->circle.getPosition().x - this->Speed, this->circle.getPosition().y } );
}

void Circle::MoveRight() {
    this->circle.setPosition( { this->circle.getPosition().x + this->Speed, this->circle.getPosition().y } );
}
