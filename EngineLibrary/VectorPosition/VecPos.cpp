#include "VecPos.h"

VecPos::VecPos() {
    x = nullptr, y = nullptr;
}

VecPos::VecPos(const float X, const float Y) : x(nullptr), y(nullptr) {
    this->Set_XY( X, Y );
}

void VecPos::Set_XY(const float new_x, const float new_y) {
    delete x;
    delete y;
    x = new float(new_x);
    y = new float(new_y);
}

void VecPos::Set_Null() {}

VecPos::~VecPos() {
    delete x;
    delete y;
}
