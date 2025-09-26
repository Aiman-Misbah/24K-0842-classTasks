#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playTurn(int player, int secretNumber)
{
    int guess;
    cout << "Player " << player << ", enter your guess (1-100): ";
    cin >> guess;

    if (guess == secretNumber)
    {
        cout << "Congratulations! Player " << player << " wins!" << endl;
        return;
    }
    else if (guess < secretNumber)
    {
        cout << "Too low!" << endl;
    }
    else
    {
        cout << "Too high!" << endl;
    }

    int nextPlayer = (player == 1) ? 2 : 1;
    playTurn(nextPlayer, secretNumber);
}

int main()
{
    srand(time(0));
    int secretNumber = rand() % 100 + 1;

    cout << endl
         << "Welcome to the Number Guessing Game!" << endl;
    cout << "We have chosen a number between 1 and 100." << endl;
    cout << "Players take turns guessing. Let's begin!" << endl;

    playTurn(1, secretNumber);

    return 0;
}

