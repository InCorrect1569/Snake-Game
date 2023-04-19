#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 50;
const int height = 20;
int x,y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls");
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "Q";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                        cout <<" ";
            }


            if (j == width-1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width+2 ; i++)
        cout << "#";
    cout << endl;
    cout << " Every time you eat the fruit, your tail grows and the score increases by 5." << endl;
    cout << " The fruit looks like:- F ," << endl;
    cout << " Note:- The game flickers and please maximize the screen. " << endl;
    cout << endl;
    cout << " Functions; " << endl;
    cout << "   a for left \n";
    cout << "   d for right \n";
    cout << "   w for up \n";
    cout << "   s for down \n";
    cout << "   x for quit \n";
    cout << " Score: " << score << endl;
    if ( score == 100 )
    {
        cout << "You Won! Game Over!";
    }
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            cout << endl << " Game over -- ( You pressed X) ! " << endl;
            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x > width || x < 0 || y > height || y < 0)
        gameOver = true;
        if (x >= width) x = 0; else if (x < 0) x = width - 1;
        if (y >= height) x = 0; else if (y < 0) x = height - 1;
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
            cout << "You Lost by hitting the wall! Game Over!";
    if (x == fruitX && y == fruitY)
    {
        score += 5;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
int main()
{
    //instruction and details;
    cout << endl << " Hi! This is a snake game." <<endl;
    cout << " Every time you eat the fruit, your tail grows and the score increases by 5." << endl;
    cout << " The fruit looks like:- F ," << endl;
    cout << " Note:- The game flickers and please maximize the screen. " << endl;
    cout << endl;
    cout << " Movements; " << endl;
    cout << "   a for left \n";
    cout << "   d for right \n";
    cout << "   w for up \n";
    cout << "   s for down \n";
    cout << endl <<" Quit: \n   x for quit \n";
    Sleep (10000);
    //program;
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
    return 0;
}
