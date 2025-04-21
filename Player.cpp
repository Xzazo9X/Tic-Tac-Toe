#include "Player.h"
#include <iostream>

void Player::typeName() {
    std::cout << "Enter Player name: ";
    std::getline(std::cin, name);
}

std::string Player::getName() const {
    return name;
}

void Player::setWin(bool x) {
    win = x;
}

bool Player::checkWin() const {
    return win;
}