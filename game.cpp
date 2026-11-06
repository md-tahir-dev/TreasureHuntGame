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
    int position;

public:
    Player()
    {
        this->bag = nullptr;
        this->bagsize = 0;
        this->totalpoints = 0;
        this->capacity=0;
        this->name = "";
        this->position=0;// for saving current position
    }

    Player(string name,int capacity)
    {
        this->capacity = capacity;
        this->bagsize=0;
        this->totalpoints=0;
        this->name=name;
        this->bag = new Treasure *[capacity];
        this->position=0;//again
    }
    string getName()//for name like player1,player2, soon on... 
    {
        return name;
    }
    int getPosition()
    {
        return position;
    }
    int  getTotalPoints()
    {
        return totalpoints;
    }

    void move(int dice, int lastIndex)
    {
        position+=dice;

        if(position>lastIndex)
        {
            this->position=lastIndex;
        }
    }

    void addTreasure(Treasure* t)
    {
        if(bagsize<capacity)
        {
            bag[bagsize++]=t;
        }
        totalpoints+= t->value;//adding points
    }

    void showResult()
    {
        cout<<name<<" total points: "<<totalpoints<<endl;
        cout<<"treasure collected: "<<endl;
        for(int i = 0; i<bagsize;i++)
        {
            cout<<bag[i]->description<<"("<<bag[i]->value<<")";
        }
        cout<<endl;
    }
    ~Player()
    {
        if(bag!=nullptr)
        {
            delete [] bag;
            bag=nullptr;
        }
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
                // int value = rand() % 100 + 1;
                string descripitions[] = {"Gold coin", "Diamond", "Ruby", "Silver", "Emerald"};
                int values[]={20,50,30,10,40};
                int idx =rand() % 5;
                board[i][j]  = new Treasure{values[idx], descripitions[idx]};
            }
        }

        players = new Player*[playerCount];
        for(int i =0; i< playCount; i++)
        {
            players[i]=new Player("player" + to_string(i+1),5);
        }
    }

    void playGame()//main loop
    {
        int lastIndex=rows*cols-1;//11
        bool gameOver=false;
        while (!gameOver)
        {
            gameOver=true;
            for(int i = 0; i<playerCount; i++)
            {
                Player* p = players[i];
                if(p->getPosition()<lastIndex)
                {
                    int dice = rand()%6+1;  //dice 1:6
                    p->move(dice,lastIndex);

                    int pos= p->getPosition();
                    int r=pos/cols;
                    int c=pos%cols;

                    Treasure* t=board[r][c];
                    p->addTreasure(t);

                    cout<<p->getName()<<" roll "<<dice<<" got "<<t->description<<"("<<t->value<<")"<<endl;//print statment everytime when dice roll 
                    if(p->getPosition()<lastIndex)
                    {
                        gameOver=false;
                    }
                }
            }
            cout<<endl;
        }
        cout<<"Final result:"<<endl;
        for(int i =0; i<playerCount;i++)
        {
            players[i]->showResult();
            cout<<endl;
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
    ~TreaureHunt()    
    {
        if(board!=nullptr)
        {
            for(int i = 0; i < rows; i++)
            {
                if(board[i]!=nullptr)
                {
                    for(int j=0; j<cols;j++)
                    {
                        delete[] board[i][j];//free every cell
                    }
                    delete[] board[i];//free every row
                }
            }
            delete[] board;//free board array
        }

        //free players
        if(players!=nullptr)
        {
            for(int i=0;i<playerCount; i++)
            {
                delete players[i];
            }
            delete[] players;
        }
    }
};

int main()
{    
    srand(time(0)); //for random number
    int Players;
    cout<<"Enter the number of players: ";
    cin>>Players;
    TreaureHunt game(4,3,Players);// first 4 is total rows, second 3 is total columns, third three is total player
    // game.printBoard();
    game.playGame();
}