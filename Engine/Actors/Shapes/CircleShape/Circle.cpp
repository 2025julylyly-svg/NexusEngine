#include "Circle.h"

Circle::Circle() :
    Radius(5), Speed(1.0f), MaxPosX(-1.f), MaxPosY(-1.f), MinPosX(-1.f), MinPosY(-1.f) {
}

Circle::Circle(const float& x, const float& y, const float& r = 5) :
    Speed(1.0f), MaxPosX(-1.f), MaxPosY(-1.f), MinPosX(-1.f), MinPosY(-1.f), Radius(r) {
    circle.setPosition({ x, y });
}

Circle::Circle(const float& x, const float& y, const float& max_pos_x, const float& max_pos_y, const float& min_pos_x, const float& min_pos_y) :
    Radius(5), Speed(1.0f), MaxPosX(-1.f), MaxPosY(-1.f), MinPosX(-1.f), MinPosY(-1.f) {
    circle.setPosition({ x, y });
    this->SetMaxPosX(max_pos_x);
    this->SetMaxPosY(max_pos_y);
    this->SetMinPosX(min_pos_x);
    this->SetMinPosY(min_pos_y);
}

void Circle::SetRadius(const float& r) {
    Radius = r;
    circle.setRadius(r);
}

float Circle::GetRadius() const {
    return Radius;
}

void Circle::SetPointCount(const std::size_t& point_count) {
    circle.setPointCount(point_count);
}

sf::Vector2f Circle::GetGeometricCenter() const {
    return circle.getGeometricCenter();
}

Circle::ULI Circle::GetPointCount() const {
    return static_cast<ULI>(circle.getPointCount());
}

sf::Vector2f Circle::GetPoint(const std::size_t& point_index) const {
    return circle.getPoint(point_index);
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
        if (circle.getRadius() - circle.getPosition().y >= MinPosY) {
            this->circle.setPosition({ this->circle.getPosition().x, this->circle.getPosition().y - this->Speed });
        }
    } else {
        this->circle.setPosition({ this->circle.getPosition().x, this->circle.getPosition().y - this->Speed });
    }
}

void Circle::MoveDown() {
    if (MaxPosY != -1) {
        if (circle.getRadius() + circle.getPosition().x <= MaxPosY) {
            this->circle.setPosition({ this->circle.getPosition().x, this->circle.getPosition().y + this->Speed });
        }
    } else {
        this->circle.setPosition({ this->circle.getPosition().x, this->circle.getPosition().y + this->Speed });
    }
}

void Circle::MoveLeft() {
    if (MinPosX != -1) {
        if (circle.getRadius() - circle.getPosition().x >= MaxPosX) {
            this->circle.setPosition({ this->circle.getPosition().x - this->Speed, this->circle.getPosition().y });
        }
    } else {
        this->circle.setPosition({ this->circle.getPosition().x - this->Speed, this->circle.getPosition().y });
    }
}

void Circle::MoveRight() {
    if (MaxPosX != -1) {
        if (circle.getRadius() + circle.getPosition().x <= MaxPosX) {
            this->circle.setPosition({ this->circle.getPosition().x + this->Speed, this->circle.getPosition().y });
        }
    } else {
        this->circle.setPosition({ this->circle.getPosition().x + this->Speed, this->circle.getPosition().y });
    }
}

bool Circle::operator==(sf::Shape* shape) const {
    if (!shape || typeid(*shape) != typeid(Circle)) {
        return false;
    }
    return this == shape;
}
