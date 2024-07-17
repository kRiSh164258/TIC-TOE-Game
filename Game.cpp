#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void layout(char *space);
void player(char *space, char user);
void compue(char *space, char com);
bool check_winner(char *space, char user, char com);
bool check_draw(char *space);

int main()
{
    char space[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char user = 'O';
    char com = 'X';
    bool running = true;
    layout(space);

    while (running)
    {
        player(space, user);
        layout(space);
        if (check_winner(space, user, com) || check_draw(space))
            break;

        compue(space, com);
        layout(space);
        if (check_winner(space, user, com) || check_draw(space))
            break;
    }

    return 0;
}

void layout(char *space)
{
    cout << " _____ _____ _____" << "\n";
    cout << "|     |     |     |" << "\n";
    cout << "|  " << space[0] << "  |  " << space[1] << "  |  " << space[2] << "  |" << "\n";
    cout << "|_____|_____|_____|" << "\n";
    cout << "|     |     |     |" << "\n";
    cout << "|  " << space[3] << "  |  " << space[4] << "  |  " << space[5] << "  |" << "\n";
    cout << "|_____|_____|_____|" << "\n";
    cout << "|     |     |     |" << "\n";
    cout << "|  " << space[6] << "  |  " << space[7] << "  |  " << space[8] << "  |" << "\n";
    cout << "|_____|_____|_____|" << "\n";
}

void player(char *space, char user)
{
    int number;
    do
    {
        cout << "Enter your position (1-9): ";
        cin >> number;
        number--;
        if (number >= 0 && number < 9 && space[number] == ' ')
        {
            space[number] = user;
            break;
        }
        else
        {
            cout << "Invalid move. Try again.\n";
        }
    } while (true);
}

void compue(char *space, char com)
{
    int number;
    srand(time(0));

    while (true)
    {
        number = rand() % 9;
        if (space[number] == ' ')
        {
            space[number] = com;
            break;
        }
    }
}

bool check_winner(char *space, char user, char com)
{

    int win[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    for (int i = 0; i < 8; i++)
    {
        if (space[win[i][0]] != ' ' && space[win[i][0]] == space[win[i][1]] && space[win[i][1]] == space[win[i][2]])
        {
            if (space[win[i][0]] == user)
            {
                cout << "You win!\n";
                return true;
            }
            else if (space[win[i][0]] == com)
            {
                cout << "You lose!\n";
                return true;
            }
        }
    }
    return false;
}

bool check_draw(char *space)
{
    for (int i = 0; i < 9; i++)
    {
        if (space[i] == ' ')
        {
            return false;
        }
    }
    cout << "It's a draw!\n";
    return true;
}
