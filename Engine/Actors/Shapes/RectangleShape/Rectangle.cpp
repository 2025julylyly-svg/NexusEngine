#include "Rectangle.h"
Rectangle::Rectangle() = default;
Rectangle::Rectangle(
    float x, float y,
    float Width, float Height,
    const float Max_X = -1.f, const float Max_Y = -1.f, const float Min_X = -1.f, const float Min_Y = -1.f) :
    Speed( 0.0f ),
    MaxPosX( Max_X ), MaxPosY( Max_Y ),
    MinPosX( Min_X ), MinPosY( Min_Y ) {

    WidthRectShape = Width; HeightRectShape = Height;
    shape.setPosition( { x, y } );
    shape.setSize( { Width, Height } );
    shape.setFillColor( sf::Color::White );
}

void Rectangle::SetPointPositions() {
    const float X_posShape = shape.getPosition().x;
    const float Y_posShape = shape.getPosition().y;
    PointPositions.Append( {X_posShape, Y_posShape} );
    PointPositions.Append( {X_posShape + WidthRectShape, Y_posShape} );
    PointPositions.Append( {X_posShape, Y_posShape + HeightRectShape} );
    PointPositions.Append( {X_posShape + WidthRectShape, Y_posShape + HeightRectShape} );
}

const Vector<Rectangle::pos>& Rectangle::GetPointPositions() const {
    return PointPositions;
}
void Rectangle::SetSpeed(const float speed) {
    Speed = speed;
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
bool Rectangle::operator==(ABS_SHAPE* abs_shape) const {
    if (!abs_shape) {
        return false;
    }
    return this == abs_shape;
}
