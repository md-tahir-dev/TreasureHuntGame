#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
struct Treasure
{
    int value;
    string description;
};
class Player
{
private:
    Treasure **bag;
    int bagsize;
    int totalpoints;
    int capacity;
    string name;

public:
    Player()
    {
        this->bag = nullptr;
        this->bagsize = 0;
        this->totalpoints = 0;
        this->capacity=0;
        this->name = "";
    }

    Player(string name,int capacity)
    {
        this->capacity = capacity;
        this->bagsize=0;
        this->totalpoints=0;
        this->name=name;
        this->bag = new Treasure *[capacity];
    }
};

class TreaureHunt
{
private:
    Treasure ***board;
    int rows;
    int cols;
    Player **players;
    int playerCount;

public:
    TreaureHunt()
    {
        this->board = nullptr;
        this->rows = 0;
        this->cols = 0;
        this->players = nullptr;
        this->playerCount = 0;
    }
    TreaureHunt(int rows, int cols, int playCount)
    {
        this->rows = rows;
        this->cols = cols;
        this->playerCount = playCount;
        
        board = new Treasure**[rows];
        for (int i = 0; i < rows; i++)
        {
            board[i] = new Treasure *[cols];
            for (int j = 0; j < cols; j++)
            {
                int value = rand() % 100 + 1;
                string descripitions[] = {"Gold coin", "Diamond", "Ruby", "Silver", "Emerald"};
                string desc = descripitions[rand() % 5];
                board[i][j] = new Treasure{value, desc};
            }
        }

        players = new Player*[playerCount];
        for(int i =0; i< playCount; i++)
        {
            players[i]=new Player("player" + to_string(i+1),5);
        }
    }

    void printBoard()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << board[i][j]->description << "(" << board[i][j]->value<< ")  " ;
            }
            cout << endl;
        }
    }
};

int main()
{    
    srand(time(0)); //for random number
    TreaureHunt game(4,3,3);// first 4 is total rows, second 3 is total columns, third three is total player
    game.printBoard();
}