#pragma once
class GameLogic
{
public:
    explicit GameLogic();
    virtual void Main() = 0;
    ~GameLogic();
};
