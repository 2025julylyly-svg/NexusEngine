#include "Rectangle.h"

Rectangle::Rectangle(float x, float y, float Width, float Height) : Speed( 0.0f ), MaxPosX( -1.f ), MaxPosY( -1.f ), MinPosX( -1.f ), MinPosY( -1.f ) {
    shape.setPosition( { x, y } );
    shape.setSize( { Width, Height } );
    shape.setFillColor( sf::Color::White );
}

void Rectangle::MoveUp() {
    shape.setPosition( { shape.getPosition().x, shape.getPosition().y - this->Speed } );
}

void Rectangle::MoveDown() {
    shape.setPosition( { shape.getPosition().x, shape.getPosition().y + this->Speed } );
}

void Rectangle::MoveLeft() {
    shape.setPosition( { shape.getPosition().x - this->Speed, shape.getPosition().y } );
}

void Rectangle::MoveRight() {
    shape.setPosition( { shape.getPosition().x + this->Speed, shape.getPosition().y } );
}
