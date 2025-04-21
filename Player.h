#pragma once
#include <iostream>

class Player {
    std::string name;
    bool win = false;

public:
    void typeName();
    std::string getName() const;
    void setWin(bool x);
    bool checkWin() const;
};