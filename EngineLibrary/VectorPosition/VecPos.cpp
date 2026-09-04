#include "VecPos.h"

#include "Vector.h"


VecPos::VecPos() {
    x = 0, y = 0;
}

VecPos::VecPos(const float X, const float Y) : x( 0 ), y( 0 ) {
    this->Set_XY( X, Y );
}

VecPos::VecPos(const Vector<float>& vec) : x( 0 ), y( 0 ) {
    x = vec[0];
    y = vec[1];
}

void VecPos::Set_XY(const float new_x, const float new_y) {
    x =new_x;
    y = new_y;
}

void VecPos::Set_X(const float new_x) {
    x = new_x;
}

void VecPos::Set_Y(const float new_y) {
    y = new_y;
}

float VecPos::get_x() const {
    return x;
}

float VecPos::get_y() const {
    return y;
}

VecPos VecPos::operator-(const VecPos& other) const {
    return { x - other.x, y - other.y };
}

VecPos VecPos::operator+(const VecPos& other) const {
    return { x + other.x, y + other.y };
}

bool VecPos::operator>(const VecPos& other) const {
    return this->x > other.x && this->y > other.y;
}

bool VecPos::operator<(const VecPos& other) const {
    return this->x < other.x && this->y < other.y;
}

VecPos& VecPos::operator=(const VecPos& other) = default;

VecPos::~VecPos() = default;
