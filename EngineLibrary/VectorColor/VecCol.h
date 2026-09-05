#pragma once
class VecCol
{
public:
    float R{};
    float G{};
    float B{};
    explicit VecCol();
    void SetColor(float r, float g, float b);
    void SetRed(float r);
    void SetGreen(float g);
    void SetBlue(float g);
    void ResetColor();
};
