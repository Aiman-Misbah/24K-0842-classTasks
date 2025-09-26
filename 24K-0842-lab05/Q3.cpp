#include <iostream>
using namespace std;

const int N = 7;

int maze[N][N] = {
    {1, 0, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 1},
    {0, 1, 0, 1, 0, 1, 0},
    {1, 1, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 0, 1},
    {0, 0, 1, 1, 1, 1, 1}};

int solution[N][N];

bool isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && solution[x][y] == 0);
}

bool solveMaze(int x, int y)
{
    if (x == N - 1 && y == N - 1)
    {
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(x, y))
    {
        solution[x][y] = 1;

        if (solveMaze(x + 1, y))
            return true;
        if (solveMaze(x, y + 1))
            return true;
        if (solveMaze(x - 1, y))
            return true;
        if (solveMaze(x, y - 1))
            return true;

        solution[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            solution[i][j] = 0;

    if (solveMaze(0, 0))
    {
        cout << endl
             << "Path to Ice Cream Shop (Karachi to Lahore street maze):" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No path found!" << endl;
    }
    cout << endl;
    return 0;
}
