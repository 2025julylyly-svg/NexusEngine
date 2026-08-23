#include "Polygon.h"

Polygon::Polygon() :
    Speed(1.f), MaxPosX(-1.f), MaxPosY(-1.f), MinPosX(-1.f), MinPosY(-1.f) {
}

Polygon::Polygon(const std::size_t& point_count) :
    Speed(1.f), MaxPosX(-1.f), MaxPosY(-1.f), MinPosX(-1.f), MinPosY(-1.f) {
    CVX.setPointCount(point_count);
}

Polygon::Polygon(const std::size_t& point_count, const float& speed) :
    Speed(1.f), MaxPosX(-1.f), MaxPosY(-1.f), MinPosX(-1.f), MinPosY(-1.f) {
    CVX.setPointCount(point_count);
    Speed = speed;
}

void Polygon::SetSpeed(const float& speed) {
    Speed = speed;
}

float Polygon::GetSpeed() const {
    return Speed;
}

bool Polygon::CanMoveUp() const {
    const std::size_t& PointCount = CVX.getPointCount();
    for (std::size_t point = 0; point < PointCount; ++point) {
        if (CVX.getPoint(point).y - this->Speed < this->MinPosY) {
            return false;
        }
    }
    return true;
}

bool Polygon::CanMoveDown() const {
    const std::size_t& PointCount = CVX.getPointCount();
    for (std::size_t point = 0; point < PointCount; ++point) {
        if (CVX.getPoint(point).y + this->Speed > this->MaxPosY) {
            return false;
        }
    }
    return true;
}

bool Polygon::CanMoveLeft() const {
    const std::size_t& PointCount = CVX.getPointCount();
    for (std::size_t point = 0; point < PointCount; ++point) {
        if (CVX.getPoint(point).x - this->Speed < this->MinPosX) {
            return false;
        }
    }
    return true;
}

bool Polygon::CanMoveRight() const {
    const std::size_t& PointCount = CVX.getPointCount();
    for (std::size_t point = 0; point < PointCount; ++point) {
        if (CVX.getPoint(point).x + this->Speed > this->MaxPosX) {
            return false;
        }
    }
    return true;
}

void Polygon::MoveUp() {
    if (CanMoveUp()) {
        const std::size_t& PointCount = CVX.getPointCount();
        for (std::size_t point = 0; point < PointCount; ++point) {
            CVX.setPoint(point, { CVX.getPoint(point).x, CVX.getPoint(point).y - this->Speed });
        }
    }
}

void Polygon::MoveDown() {
    if (CanMoveDown()) {
        const std::size_t& PointCount = CVX.getPointCount();
        for (std::size_t point = 0; point < PointCount; ++point) {
            CVX.setPoint(point, { CVX.getPoint(point).x, CVX.getPoint(point).y + this->Speed });
        }
    }
}

void Polygon::MoveLeft() {
    if (CanMoveLeft()) {
        const std::size_t& PointCount = CVX.getPointCount();
        for (std::size_t point = 0; point < PointCount; ++point) {
            CVX.setPoint(point, { CVX.getPoint(point).x - this->Speed, CVX.getPoint(point).y });
        }
    }
}

void Polygon::MoveRight() {
    if (CanMoveRight()) {
        const std::size_t& PointCount = CVX.getPointCount();
        for (std::size_t point = 0; point < PointCount; ++point) {
            CVX.setPoint(point, { CVX.getPoint(point).x + this->Speed, CVX.getPoint(point).y });
        }
    }
}
