#include "Rectangle.h"

Rectangle::Rectangle(
    float x, float y,
    float Width, float Height,
    const float Max_X = -1.f, const float Max_Y = -1.f, const float Min_X = -1.f, const float Min_Y = -1.f) :
    Speed( 0.0f ),
    MaxPosX( Max_X ), MaxPosY( Max_Y ),
    MinPosX( Min_X ), MinPosY( Min_Y ) {

    shape.setPosition( { x, y } );
    shape.setSize( { Width, Height } );
    shape.setFillColor( sf::Color::White );
}

void Rectangle::MoveUp() {
    if (shape.getPosition().y - this->Speed >= this->MinPosY) {
        shape.setPosition( { shape.getPosition().x, shape.getPosition().y - this->Speed } );
    }
}

void Rectangle::MoveDown() {
    if (shape.getPosition().y + this->Speed <= this->MaxPosY) {
        shape.setPosition( { shape.getPosition().x, shape.getPosition().y + this->Speed } );
    }
}

void Rectangle::MoveLeft() {
    if (shape.getPosition().x - this->Speed >= this->MinPosX) {
        shape.setPosition( { shape.getPosition().x - this->Speed, shape.getPosition().y } );
    }
}

void Rectangle::MoveRight() {
    if (shape.getPosition().x + this->Speed <= this->MaxPosX) {
        shape.setPosition( { shape.getPosition().x + this->Speed, shape.getPosition().y } );
    }
}
