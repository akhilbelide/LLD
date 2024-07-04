#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include "piece.h"
#include "board.h"
using namespace std;

class PlayingPiece{
    public:
    Piece piece;
    PlayingPiece(){

    }
    PlayingPiece(Piece piece){
        this->piece = piece;
    }
};

class PlayingPieceX : public PlayingPiece{
    public: 
    PlayingPieceX() : PlayingPiece(X){

    }
};

class PlayingPieceO : public PlayingPiece{
    public: 
    PlayingPieceO() : PlayingPiece(O){

    }
};

class Player{
    public:
    string name;
    PlayingPiece *playing_piece;

    Player(string name, PlayingPiece *p){
        this->name = name;
        this->playing_piece = p;
    }
};

class Game{
    public:

    Player *p1;
    Player *p2;
    Board *b;

    void startGame(){
        bool isfinished = false;
        queue<Player*> d;
        d.push(p1);
        d.push(p2);

        while(!isfinished){
            b->printBoard();

            Player *curr_player = d.front();
            string player_name;
            string player_type;
            int m,n;

            player_name = curr_player->name;
            player_type = curr_player->playing_piece->piece == X? "X" : "O";

            cout<<player_name<<"'s turn. Enter the row and column number to place "<<player_type<<" : ";
            cin>>m>>n;

            if(m<0 || n<0 || m>=b->getSize() || n>=b->getSize()){
                cout<<endl<<"Invalid row/column number"<<endl;
            }
            else{
                set<pair<int, int> > emptycells = b->getEmptyCells();
                if(emptycells.find(make_pair(m,n))==emptycells.end()){
                    cout<<endl<<"Enter the row, column of empty cell"<<endl;
                }
                else{
                    d.pop();
                    d.push(curr_player);

                    b->setPiece(m,n,curr_player->playing_piece->piece);

                    if(b->checkWinner()){
                        isfinished = true;
                        b->printBoard();
                        cout<< "Winner is : "<<player_name<<" - "<<player_type<<endl;
                    }
                    else{
                        cout<<endl<<" Game is drawn - No Winner "<<endl;
                        return;
                    }      
                }
            }
        }
    }

    void initializeGame(){
        int size;
        string player1, player2;
        string player1_piece;

        cout<<"Enter the boards size"<<endl;
        cin>>size;

        cout<<"Enter player1 name : ";
        cin>>player1;

        bool isvalid = false;

        while(!isvalid){
            cout<<"Enter the Piece type - X or O : ";
            cin>>player1_piece;

            if(player1_piece=="X" || player1_piece=="O")
                isvalid = true;
            else cout<<"Invalid option"<<endl;
        }   
        
        cout<<"Enter player2 name : ";
        cin>>player2;


        p1 = new Player(player1, player1_piece == "O" 
                                                ? static_cast<PlayingPiece*>(new PlayingPieceO()) 
                                                : static_cast<PlayingPiece*>(new PlayingPieceX()));
        p2 = new Player(player2, player1_piece == "O" 
                                                ? static_cast<PlayingPiece*>(new PlayingPieceX()) 
                                                : static_cast<PlayingPiece*>(new PlayingPieceO()));
        b = new Board(size);
        startGame();
    }
};

int main(){
    Game *game = new Game();
    game->initializeGame();
    return 0;
}