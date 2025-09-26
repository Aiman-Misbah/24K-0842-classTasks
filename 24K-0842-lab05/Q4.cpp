#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

void solveNQueens(vector<string> &board, int row, int n, int &count, vector<string> &firstSolution, bool &foundFirst)
{
    if (row == n)
    {
        count++;
        if (!foundFirst)
        {
            firstSolution = board;
            foundFirst = true;
        }
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';
            solveNQueens(board, row + 1, n, count, firstSolution, foundFirst);
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n;
    cout << endl
         << "Enter value of N (size of chessboard): ";
    cin >> n;

    vector<string> board(n, string(n, '.'));
    int count = 0;
    vector<string> firstSolution;
    bool foundFirst = false;

    solveNQueens(board, 0, n, count, firstSolution, foundFirst);

    if (count == 0)
    {
        cout << "No solution exists for N = " << n << endl
             << endl;
    }
    else
    {
        cout << "One valid solution for N = " << n << ":" << endl
             << endl;
        for (string row : firstSolution)
        {
            cout << row << endl;
        }
        cout << "Total number of distinct solutions: " << count << endl
             << endl;
    }

    return 0;
}
