#include <iostream>
#include <conio.h>
#include <stdlib.h> 
#include <Windows.h>
#include <string>

using namespace std;

int ROWS = 5;
int COLS = 5;
char board[20][20];
int moveCounter = 0; // переменная для ходов
int maxMoves = ROWS * COLS; // максимум ходов
int gameMode = 1;
string p1;
string p2;

void startMenu() {

    if (gameMode == 1) {
         p1 = "Player 1";
         p2 = "Player 2";
    }
    else {
         p1 = "Player 1";
         p2 = "Computer";
    }
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
    cout << "******  *  ******  " << "****** ******  ******  " << "****** ******  ******  " << endl;
    cout << "  **   *** *       " << "  **   **  **  *       " << "  **   **  **  *       " << endl;
    cout << "  **   *** *       " << "  **   ******  *       " << "  **   **  **  ******  " << endl;
    cout << "  **   *** *       " << "  **   **  **  *       " << "  **   **  **  *       " << endl;
    cout << "  **   *** ******  " << "  **   **  **  ******  " << "  **   ******  ******  " << endl;
    SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    cout << "———————————————————" << "———————————————————————" << "———————————————————————" << endl;
    cout << "||                 |" << "|                    |" << "|                     ||" << endl;
    cout << "||      PLAY       |" << "|        MODE        |" << "|     BOARD SIZE      ||" << endl;
    cout << "||                 |" << "|" << p1 << " vs " << p2 << "|" << "|        "<<ROWS<<"x"<<COLS<<"          ||" << endl;
    cout << "||    press 1      |" << "|      press 2       |" << "|      press 3        ||" << endl;
    cout << "||                 |" << "|                    |" << "|                     ||" << endl;
    cout << "———————————————————" << "———————————————————————" << "———————————————————————" << endl;
    SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << "******  *  ******  " << "****** ******  ******  " << "****** ******  ******  " << endl;
    cout << "  **   *** *       " << "  **   **  **  *       " << "  **   **  **  *       " << endl;
    cout << "  **   *** *       " << "  **   ******  *       " << "  **   **  **  ******  " << endl;
    cout << "  **   *** *       " << "  **   **  **  *       " << "  **   **  **  *       " << endl;
    cout << "  **   *** ******  " << "  **   **  **  ******  " << "  **   ******  ******  " << endl;
    SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

}

void initiateBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << "******  *  ******  " << "****** ******  ******  " << "****** ******  ******  " << endl;
    cout << "  **   *** *       " << "  **   **  **  *       " << "  **   **  **  *       " << endl;
    cout << "  **   *** *       " << "  **   ******  *       " << "  **   **  **  ******  " << endl;
    cout << "  **   *** *       " << "  **   **  **  *       " << "  **   **  **  *       " << endl;
    cout << "  **   *** ******  " << "  **   **  **  ******  " << "  **   ******  ******  " << endl;

    SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    cout << "    "; 
    cout << "                ";
    for (int i = 0; i < COLS; i++) {
        cout << "  " << i << " ";
    }
    cout << endl;

    for (int i = 0; i < ROWS; i++) {
        cout << "                ";
        cout << "  " << i << " ";
        for (int j = 0; j < COLS; j++) {
            cout << "| " << board[i][j] << " ";
        }

        cout << "|" << endl;

    }
}

bool makeMove(int row, int col, char player) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '-') {
        board[row][col] = player;
        moveCounter++; // увеличение счетчика ходов
        return true;
    }
    return false;
}

bool checkWin(char player) {
    // проверка рядков
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player) {
                count++;
            }
        }
        if (count == ROWS) {
            return true;
        }
    }

    // проверка столбиков
    for (int j = 0; j < COLS; j++) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (board[i][j] == player) {
                count++;
            }
        }
        if (count == COLS) {
            return true;
        }
    }
    // проверка диагоналей
    for (int i = 0; i < ROWS; i++) {
        int count1 = 0, count2 = 0;
        if (board[i][i] == player) {
            count1++;
        }
        if (board[i][(ROWS - 1) - i] == player) {
            count2++;
        }
        if (count1 == ROWS || count2 == ROWS) {
            return true;
        }
    }
    return false;
}

void computerMove(char player) {
    int row, col;
    do {
        row = rand() % ROWS;
        col = rand() % COLS;
    } while (!makeMove(row, col, player));
    system("cls");
    printBoard();
    cout << "\n            Computer played at row " << row << " and column " << col << endl;
    _getch();
}

int mainGame() {
    initiateBoard();
    char currentPlayer = 'X';

    while (true) {
        system("cls");
        printBoard();
        if (moveCounter == maxMoves) {
            cout << "\n                 It's draw!" << endl;
            _getch();
            break;
        }
        if (gameMode == 2 && currentPlayer == 'O') {
            computerMove(currentPlayer);
        }
        else {
            int row, col;
            cout << "\n                    Player " << currentPlayer << ", enter row: ";
            cin >> row;
            cout << "                   Player " << currentPlayer << ", enter column: ";
            cin >> col;
            if (!makeMove(row, col, currentPlayer)) {
                cout << "\n                You cant move there, try again." << endl << "         Press Q to quit the game, press Enter to continue." << endl;
                char input = _getch();
                if (input == 'q') {
                    break;

                }
                continue;
            }
        }
        if (checkWin(currentPlayer)) {
            system("cls");
            printBoard();
            cout << "                    Player " << currentPlayer << " wins!" << endl;
            _getch();
            break;
        }
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        }
        else {
            currentPlayer = 'X';
        }
    }
    return 0;
}

int main() {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT srWindowRect;
    srWindowRect.Top = 0;
    srWindowRect.Left = 0;
    srWindowRect.Bottom = 25;
    srWindowRect.Right = 65;
    SetConsoleWindowInfo(hConsole, TRUE, &srWindowRect);

    while (true) {
        startMenu();
        char input = _getch();
        if (input == '1') {
            mainGame();
            system("cls");
        }
        else if (input == '3') {
            cout << "                  Enter the size of the board: ";
            cin >> ROWS;
            COLS = ROWS;
            maxMoves = ROWS * COLS;
            system("cls");
        }
        else if (input == '2') {
            cout << "                        SELECT GAME MODE " << endl << endl << "                     1 for player vs player" << endl << "                     2 for player vs computer" << endl << endl;

            char mode = _getch();
            if (mode == '1') {
                gameMode = 1;
            }
            else if (mode == '2') {
                gameMode = 2;
            }
            else {  
                cout << "                    Invalid input. Please try again." << endl;
                _getch();
                system("cls");
            }
            
            system("cls");
        }
        else if (input == '4') {
            break;
        }
        else {
            cout << "                        Invalid input. Please try again." << endl;
            _getch();
            system("cls");
        }
    }
}
