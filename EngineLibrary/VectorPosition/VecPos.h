#pragma once
#include <initializer_list>
class VecPos
{
private:
    void Set(const float&);
public:
    float* x;
    float* y;
    explicit VecPos();
    explicit VecPos(float, float);
    VecPos(const std::initializer_list<float>& );
    void Set_XY(float new_x, float new_y);
    void Set_Null();
    VecPos operator- (const VecPos&) const;
    VecPos operator+(const VecPos&) const;
    ~VecPos();
};