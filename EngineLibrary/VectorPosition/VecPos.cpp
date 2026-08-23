#include "VecPos.h"
void VecPos::Set(const float& target) {
    static int counter = 0;
    if (counter == 0) {
        this->x = new float(target);
    } else {
        this->y = new float(target);
    }
    counter = (counter + 1) % 2;
}
VecPos::VecPos() {
    x = nullptr, y = nullptr;
}

VecPos::VecPos(const float X, const float Y) : x(nullptr), y(nullptr) {
    this->Set_XY(X, Y);
}
VecPos::VecPos(const std::initializer_list<float>& list) : x(nullptr), y(nullptr) {
    for (const auto& pos : list) {
        this->Set(pos);
    }
}
void VecPos::Set_XY(const float new_x, const float new_y) {
    delete x;
    delete y;
    x = new float(new_x);
    y = new float(new_y);
}

void VecPos::Set_Null() {
}

VecPos::~VecPos() {
    delete x;
    delete y;
}
