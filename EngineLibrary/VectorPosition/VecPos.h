#pragma once
class VecPos
{
public:
    float* x;
    float* y;
    explicit VecPos();
    explicit VecPos(float, float);
    void Set_XY(float new_x, float new_y);
    void Set_Null();
    ~VecPos();
};