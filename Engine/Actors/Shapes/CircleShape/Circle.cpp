#include "Circle.h"

Circle::Circle(float x, float y) : Speed( 1.f ) {
    circle.setPosition( { x, y } );
}

void Circle::SetSpeed(float speed) {
    Speed = speed;
}

float Circle::GetSpeed() const {
    return Speed;
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
