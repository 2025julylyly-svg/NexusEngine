#include "VecCol.h"
VecCol::VecCol() = default;

void VecCol::SetGreen(const float g) {
    this->G = g;
    this->B = 0;
    this->R = 0;
}

void VecCol::SetBlue(const float b) {
    this->B = b;
    this->R = 0;
    this->G = 0;
}

void VecCol::SetRed(const float r) {
    this->R = r;
    this->G = 0;
    this->B = 0;
}

void VecCol::SetColor(const float r, const float g, const float b) {
    this->R = r;
    this->G = g;
    this->B = b;
}

void VecCol::ResetColor() {
    this->R = 0;
    this->G = 0;
    this->B = 0;
}
