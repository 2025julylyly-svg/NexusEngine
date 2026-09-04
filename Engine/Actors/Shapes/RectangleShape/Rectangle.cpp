#include "Rectangle.h"

Rectangle::Rectangle() {
    this->Speed = 1.f;
    this->MinPosX = -1;
    this->MinPosY = -1;
    this->MaxPosX = -1;
    this->MaxPosY = -1;
}

Rectangle::Rectangle(float x, float y, float Width, float Height, const float Max_X = -1.f,
                     const float Max_Y = -1.f,
                     const float Min_X = -1.f, const float Min_Y = -1.f)
    : Speed( 0.0f ), MaxPosX( Max_X ), MaxPosY( Max_Y ), MinPosX( Min_X ), MinPosY( Min_Y ) {
    this->setPosition( { x, y } );
    this->setSize( { Width, Height } );
    this->setFillColor( sf::Color::White );
}

Rectangle::Rectangle(const Rectangle& other) : RectangleShape( other ) {}

void Rectangle::SetSpeed(const float speed) {
    Speed = speed;
}

void Rectangle::MoveUp() {
    if (MinPosY != -1) {
        if (this->getPosition().y - this->Speed >= this->MinPosY) {
            this->setPosition( { this->getPosition().x, this->getPosition().y - this->Speed } );
        }
        return;
    }
    this->setPosition( { this->getPosition().x, this->getPosition().y - this->Speed } );
}

void Rectangle::MoveDown() {
    if (MaxPosY != -1) {
        if (this->getSize().y + this->getPosition().y + this->Speed <= this->MaxPosY) {
            this->setPosition( { this->getPosition().x, this->getPosition().y + this->Speed } );
        }
        return;
    }
    this->setPosition( { this->getPosition().x, this->getPosition().y + this->Speed } );
}

void Rectangle::MoveLeft() {
    if (MinPosX != -1) {
        if (this->getPosition().x - this->Speed >= this->MinPosX) {
            this->setPosition( { this->getPosition().x - this->Speed, this->getPosition().y } );
        }
        return;
    }
    this->setPosition( { this->getPosition().x - this->Speed, this->getPosition().y } );
}

void Rectangle::MoveRight() {
    if (MaxPosX != -1) {
        if (this->getSize().x + this->getPosition().x + this->Speed <= this->MaxPosX) {
            this->setPosition( { this->getPosition().x + this->Speed, this->getPosition().y } );
        }
        return;
    }
    this->setPosition( { this->getPosition().x + this->Speed, this->getPosition().y } );
}
