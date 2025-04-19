#include <iostream>
#include <string>

namespace TicTacToe {
    enum state {
        Free,
        X,
        O
    };

    enum move {
        m_X,
        m_O
    };

    move MOVE = m_O;

    int board[3][3] = { {Free, Free, Free},
                        {Free, Free, Free},
                        {Free, Free, Free} }; 

    class Player {
        std::string name;
        bool win = false;

    public:
        void typeName() {
            std::cout << "Enter Player name: ";
            std::getline(std::cin, name);
        }

        std::string getName() const {
            return name;
        }

        void setWin(bool x) {
            win = x;
        }

        bool checkWin() const {
            return win;
        }
    };

    void welcome() {
        std::cout << "Tic Tac Toe" << "\n\n";
    }

    void Round1(const Player& name1, const Player& name2) {
        if (MOVE == m_O)
            std::cout << "Player O: " << name1.getName() << '\n';
        else
            std::cout << "Player X: " << name2.getName() << '\n';
    }

    void drawBoard() {
        std::cout << "-----" << '\n';

        int temp = 1;
        for (int i = 0; i < 3; ++i) {
            std::cout << "|";

            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == Free)
                    std::cout << temp; 
                else if (board[i][j] == X)
                    std::cout << "X";
                else if (board[i][j] == O)
                    std::cout << "O";

                ++temp;
            }

            std::cout << "|" << '\n';
        }

        std::cout << "-----" << '\n';
    }

    void inputField() {
        int number;

        std::cout << "Enter field: ";
        std::cin >> number; 
        --number;

        int column = number % 3; 
        int row = number / 3;

        while (board[row][column] != Free) {
            std::cout << "This field is occupied" << '\n';
            std::cout << "Enter field: ";
            std::cin >> number; 
            --number;
            column = number % 3; 
            row = number / 3;
        }

        if (MOVE == m_O)
            board[row][column] = O;
        else
            board[row][column] = X;  
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == Free)
                    return false;
            }
        }

        return true;
    }

    void checkWinCondition(Player& player) {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != Free) {
                player.setWin(true);
                return;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != Free) {
                player.setWin(true);
                return;
            }
            if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != Free) {
                player.setWin(true);
                return;
            }
            if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != Free) {
                player.setWin(true);
                return;
            }
        }
    }
}

int main() {
    using namespace TicTacToe;
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
