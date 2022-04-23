#include <iostream>
#include <iomanip>
using namespace std;

const int mazeWidth = 15;
const int mazeHeight = 15;

const char maze[mazeWidth][mazeHeight] = {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                                            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
                                            {'#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
                                            {'#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
                                            {'#', ' ', '#', ' ', '#', 'F', ' ', ' ', ' ', '#', '#', ' ', '#', ' ', '#'},
                                            {'#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#'},
                                            {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
                                            {'#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
                                            {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
                                            {'#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#'},
                                            {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', ' ', ' ', '#'},
                                            {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#'},
                                            {'#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
                                            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
                                            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

char nextSymb(int coordX, int coordY)
{
    return maze[coordX][coordY];
}

void Move(int *playerPos, int distance)
{
    *playerPos += distance;
}

void MoveLogic(char enteredSymbol, int *playerX, int *playerY)
{
    if(enteredSymbol == 'w' || enteredSymbol == 'W')
    {
        if(nextSymb(*playerX - 1, *playerY) != '#')
        {
            Move(playerX, -1);
        }
    }
    else if(enteredSymbol == 'a' || enteredSymbol == 'A')
    {
        if(nextSymb(*playerX, *playerY - 1) != '#')
        {
            Move(playerY, -1);
        }
    }
    else if(enteredSymbol == 's' || enteredSymbol == 'S')
    {
        if(nextSymb(*playerX + 1, *playerY) != '#')
        {
            Move(playerX, 1);
        }
    }
    else if(enteredSymbol == 'd' || enteredSymbol == 'D')
    {
        if(nextSymb(*playerX, *playerY + 1) != '#')
        {
            Move(playerY, 1);
        }
    }
}

void Draw(int playerX, int playerY, char player, int mazeX, int mazeY, int visionRange)
{
    for(int i = playerX - visionRange; i <= playerX + visionRange; i++)
    {
        for (int j = playerY - visionRange; j <= playerY + visionRange; j++)
        {
            if(i + mazeX == playerX && j + mazeY == playerY)
            {
                cout << player;
            }
            else
            {
                cout << maze[i + mazeX][j + mazeY];
            }
        }
        cout << endl;
    }
}

int mazeCoordStabilizer(int playerCoord, int visionRange, int mazeMax)
{
    if(playerCoord - visionRange < 0)
    {
        return 1;
    }
    if(playerCoord + visionRange >= mazeMax)
    {
        return -1;
    }
    return 0;
}

void StabilizedDraw(int playerX, int playerY, char player, int visionRange)
{
    int mazeX, mazeY;
    mazeX = mazeCoordStabilizer(playerX, visionRange, mazeWidth);
    mazeY = mazeCoordStabilizer(playerY, visionRange, mazeHeight);
    Draw(playerX, playerY, player, mazeX, mazeY, visionRange);
}

void SayHello() 
{
    cout << "Hi!" << endl;
    cout << "This mini blind maze game." << endl;
    cout << "Controls are:" << endl;
    cout << "Just type one of the following letters w / a / s / d," << endl;
    cout << "and your avatar moves that way by one unit." << endl;
    cout << "Note yourself that only first letter be read and move your character." << endl;
    system("pause");
}

int main()
{
    const int startX = 1;
    const int startY = 1;

    const char player = '@';
    int playerX = startX;
    int playerY = startY;

    int visionRange = 2;

    string playerInput;

    SayHello();

    while(nextSymb(playerX, playerY) != 'F')
    {
        system("CLS");
        StabilizedDraw(playerX, playerY, player, visionRange);
        cin >> playerInput;
        MoveLogic(playerInput[0], &playerX, &playerY);
    }
    
    system("CLS");

    cout << "Congratulations!" << endl;

    system("pause");
    return 0;
}