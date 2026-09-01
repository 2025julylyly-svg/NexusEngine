#pragma once
#include <Vector.h>

class VecPos
{
private:
    float x;
    float y;

public:
    VecPos();
    VecPos(float, float);
    VecPos(const Vector<float>&);
    void Set_XY(float new_x, float new_y);
    void Set_X(float new_x);
    void Set_Y(float new_y);
    [[nodiscard]] float get_x() const;
    [[nodiscard]] float get_y() const;
    VecPos operator -(const VecPos&) const;
    VecPos operator +(const VecPos&) const;
    bool operator >(const VecPos&) const;
    bool operator <(const VecPos&) const;
    VecPos& operator= (const VecPos&);
    ~VecPos();
};
