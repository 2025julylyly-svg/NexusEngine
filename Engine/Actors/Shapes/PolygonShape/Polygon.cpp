#include "Polygon.h"

Polygon::Polygon() : Speed( 1.f ), MaxPosX( -1.f ), MaxPosY( -1.f ), MinPosX( -1.f ), MinPosY( -1.f ) {}

Polygon::Polygon(const std::size_t& point_count)
    : Speed( 1.f ), MaxPosX( -1.f ), MaxPosY( -1.f ), MinPosX( -1.f ), MinPosY( -1.f ) {
    setPointCount( point_count );
}

Polygon::Polygon(const std::size_t& point_count, const float& speed)
    : Speed( 1.f ), MaxPosX( -1.f ), MaxPosY( -1.f ), MinPosX( -1.f ), MinPosY( -1.f ) {
    setPointCount( point_count );
    Speed = speed;
}

void Polygon::SetSpeed(const float& speed) {
    Speed = speed;
}

float Polygon::GetSpeed() const {
    return Speed;
}

bool Polygon::CanMoveUp() const {
    if (this->MinPosY == -1) return true;
    const std::size_t& PointCount = getPointCount();
    for (std::size_t point = 0; point < PointCount; ++point) {
        if (getPoint( point ).y - this->Speed < this->MinPosY) {
            return false;
        }
    }
    return true;
}

bool Polygon::CanMoveDown() const {
    if (this->MaxPosY == -1) return true;
    const std::size_t& PointCount = getPointCount();
    for (std::size_t point = 0; point < PointCount; ++point) {
        if (getPoint( point ).y + this->Speed > this->MaxPosY) {
            return false;
        }
    }
    return true;
}

bool Polygon::CanMoveLeft() const {
    if (this->MinPosX == -1) return true;
    const std::size_t& PointCount = getPointCount();
    for (std::size_t point = 0; point < PointCount; ++point) {
        if (getPoint( point ).x - this->Speed < this->MinPosX) {
            return false;
        }
    }
    return true;
}

bool Polygon::CanMoveRight() const {
    if (this->MaxPosX == -1) return true;
    const std::size_t& PointCount = getPointCount();
    for (std::size_t point = 0; point < PointCount; ++point) {
        if (getPoint( point ).x + this->Speed > this->MaxPosX) {
            return false;
        }
    }
    return true;
}

void Polygon::MoveUp() {
    if (CanMoveUp()) {
        const std::size_t& PointCount = getPointCount();
        for (std::size_t point = 0; point < PointCount; ++point) {
            setPoint( point, { getPoint( point ).x, getPoint( point ).y - this->Speed } );
        }
    }
}

void Polygon::MoveDown() {
    if (CanMoveDown()) {
        const std::size_t& PointCount = getPointCount();
        for (std::size_t point = 0; point < PointCount; ++point) {
            setPoint( point, { getPoint( point ).x, getPoint( point ).y + this->Speed } );
        }
    }
}

void Polygon::MoveLeft() {
    if (CanMoveLeft()) {
        const std::size_t& PointCount = getPointCount();
        for (std::size_t point = 0; point < PointCount; ++point) {
            setPoint( point, { getPoint( point ).x - this->Speed, getPoint( point ).y } );
        }
    }
}

void Polygon::MoveRight() {
    if (CanMoveRight()) {
        const std::size_t& PointCount = getPointCount();
        for (std::size_t point = 0; point < PointCount; ++point) {
            setPoint( point, { getPoint( point ).x + this->Speed, getPoint( point ).y } );
        }
    }
}

void Polygon::SetMinPosY(const float& min_pos) {
    MinPosY = min_pos;
}

void Polygon::SetMinPosX(const float& min_pos) {
    MinPosX = min_pos;
}

void Polygon::SetMaxPosY(const float& max_pos) {
    MaxPosY = max_pos;
}

void Polygon::SetMaxPosX(const float& max_pos) {
    MaxPosX = max_pos;
}
