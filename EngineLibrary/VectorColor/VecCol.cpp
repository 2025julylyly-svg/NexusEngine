#include "VecCol.h"
VecCol::VecCol() = default;

VecCol::VecCol(const unsigned char r, const unsigned char g, const unsigned char b) {
    this->SetColor( r, g, b );
}

void VecCol::SetGreen(const unsigned char g) {
    this->G = g;
    this->B = 0;
    this->R = 0;
}

void VecCol::SetBlue(const unsigned char b) {
    this->B = b;
    this->R = 0;
    this->G = 0;
}

void VecCol::SetRed(const unsigned char r) {
    this->R = r;
    this->G = 0;
    this->B = 0;
}

void VecCol::SetColor(const unsigned char r, const unsigned char g, const unsigned char b) {
    this->R = r;
    this->G = g;
    this->B = b;
}

void VecCol::ResetColor() {
    this->R = 0;
    this->G = 0;
    this->B = 0;
}
