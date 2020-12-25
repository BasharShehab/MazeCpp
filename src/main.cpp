#include <iostream>
using namespace std;
const int n = 4;
int sol[n][n] = {0};

int startX = 0, startY = 0, endX = 3, endY = 2;
int maze[n][n] = {
    {0, 0, 1, 0},
    {0, 0, 0, 1},
    {1, 0, 0, 0},
    {0, 1, 0, 1}};
bool isSafe(int maze[n][n], int x, int y) {
    if (maze[x][y] == 0 && x < n && y < n)
        return true;
    else
        return false;
}

void print() {
    for (int i = startX; i < n; i++) {
        for (int j = startY; j < n; j++) {
            cout << sol[i][j] << "   ";
        }
        cout << endl;
    }
}
int tryPath(int maze[n][n], int x, int y) {
    if (x == endX && y == endY) {
        return 1;
    }

    if (isSafe(maze, x + 1, y)) {
        sol[x + 1][y] = 1;
        if (tryPath(maze, x + 1, y)) {
            return 1;
        }
        sol[x + 1][y] = 0;
    }
    if (isSafe(maze, x, y + 1)) {
        sol[x][y + 1] = 1;
        if (tryPath(maze, x, y + 1)) {
            return 1;
        }
        sol[x][y + 1] = 0;
    }
    return 0;
}
int main() {
    if (tryPath(maze, startX, startY)) {
        sol[startX][startY] = 1;
        print();
    } else
        cout << "no solution";

    system("pause");
    return 0;
}