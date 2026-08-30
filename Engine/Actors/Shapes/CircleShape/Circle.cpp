#include "Circle.h"

Circle::Circle() : Radius(5), Speed(1.0f), MaxPosX(-1.f), MaxPosY(-1.f), MinPosX(-1.f), MinPosY(-1.f) {}

Circle::Circle(const float& x, const float& y, const float& r = 5)
    : Radius(r), Speed(1.0f), MaxPosX(-1.f), MaxPosY(-1.f), MinPosX(-1.f), MinPosY(-1.f) {
    this->setPosition({x, y});
}

Circle::Circle(const float& x, const float& y, const float& max_pos_x, const float& max_pos_y, const float& min_pos_x,
    const float& min_pos_y)
    : Radius(5), Speed(1.0f), MaxPosX(-1.f), MaxPosY(-1.f), MinPosX(-1.f), MinPosY(-1.f) {
    this->setPosition({x, y});
    this->SetMaxPosX(max_pos_x);
    this->SetMaxPosY(max_pos_y);
    this->SetMinPosX(min_pos_x);
    this->SetMinPosY(min_pos_y);
}
Circle::Circle(const Circle* target_circle) : Radius(5) {
    this->Speed = target_circle->Speed;
    this->setRadius(target_circle->getRadius());
    this->MaxPosX = target_circle->MaxPosX;
    this->MaxPosY = target_circle->MaxPosY;
    this->MinPosX = target_circle->MinPosX;
    this->MinPosY = target_circle->MinPosY;
}

void Circle::SetMaxPosX(const float& max_pos) {
    MaxPosX = max_pos;
}

void Circle::SetMaxPosY(const float& max_pos) {
    MaxPosY = max_pos;
}

void Circle::SetMinPosX(const float& min_pos) {
    MinPosX = min_pos;
}

void Circle::SetMinPosY(const float& min_pos) {
    MinPosY = min_pos;
}

void Circle::SetSpeed(const float speed) {
    Speed = speed;
}

float Circle::GetSpeed() const {
    return Speed;
}

void Circle::MoveUp() {
    if (MinPosY != -1) {
        if (this->getRadius() - this->getPosition().y >= MinPosY) {
            this->setPosition({this->getPosition().x, this->getPosition().y - this->Speed});
        }
    } else {
        this->setPosition({this->getPosition().x, this->getPosition().y - this->Speed});
    }
}

void Circle::MoveDown() {
    if (MaxPosY != -1) {
        if (this->getRadius() + this->getPosition().x <= MaxPosY) {
            this->setPosition({this->getPosition().x, this->getPosition().y + this->Speed});
        }
    } else {
        this->setPosition({this->getPosition().x, this->getPosition().y + this->Speed});
    }
}

void Circle::MoveLeft() {
    if (MinPosX != -1) {
        if (getRadius() - getPosition().x >= MaxPosX) {
            this->setPosition({this->getPosition().x - this->Speed, this->getPosition().y});
        }
    } else {
        this->setPosition({this->getPosition().x - this->Speed, this->getPosition().y});
    }
}

void Circle::MoveRight() {
    if (MaxPosX != -1) {
        if (this->getRadius() + this->getPosition().x <= MaxPosX) {
            this->setPosition({this->getPosition().x + this->Speed, this->getPosition().y});
        }
    } else {
        this->setPosition({this->getPosition().x + this->Speed, this->getPosition().y});
    }
}
bool Circle::operator==(sf::Shape* shape) const {
    if (!shape || typeid(*shape) != typeid(Circle)) {
        return false;
    }
    return this == shape;
}
