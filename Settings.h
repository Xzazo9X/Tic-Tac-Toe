#pragma once
#include <iostream>
#include "Player.h"

enum state {
    Free,
    X,
    O
};

enum move {
    m_X,
    m_O
};

extern move MOVE;

extern int board[3][3]; 

void welcome();
void Round1(const Player& name1, const Player& name2);
void drawBoard();
void inputField();
bool checkDraw();
void checkWinCondition(Player& player);