#include <iostream>
#include <string>
#include "Player.h"
#include "Settings.h"

int main() {
    Player p1;
    Player p2;

    welcome();

    p1.typeName();
    p2.typeName();

    MOVE = m_O;

    while (true) {
        Round1(p1, p2);
        if (p1.checkWin()) {
            std::cout << "Win: " << p1.getName() << '\n';
            break;
        }
        if (p2.checkWin()) {
            std::cout << "Win: " << p2.getName() << '\n';
            break;
        }
        if (checkDraw()) {
            std::cout << "Draw!" << '\n';
            std::cin.get();
            break;
        }
        drawBoard();
        inputField();
        checkWinCondition(p1);
        checkWinCondition(p2);
        MOVE = (MOVE == m_O) ? m_X : m_O;
    }

    std::cin.get();
}
