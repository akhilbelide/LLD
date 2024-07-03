#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;

enum Piece{
    Empty,
    O,
    X
};

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

class Board{
    int size;

    public:
    vector<vector<Piece> > board;
    Board(){

    }

    Board(int size){
        this->size = size;
        board.resize(size, vector<Piece>(size));
    }

    int getSize(){
        return this->size;
    }

    set<pair<int, int> > getEmptyCells(){
        // returns the empty cells 
        set<pair<int, int> > cells;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(this->board[i][j]==Empty)
                    cells.insert(make_pair(i, j));
            }
        }
        return cells;
    }

    void setPiece(int x, int y, Piece p){
        this->board[x][y] = p;
    }

    bool checkWinner() {
        // Check rows
        for (int i = 0; i < size; i++) {
            if (board[i][0] != Empty) {
                bool win = true;
                for (int j = 1; j < size; j++) {
                    if (board[i][j] != board[i][0]) {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }
        }

        // Check columns
        for (int j = 0; j < size; j++) {
            if (board[0][j] != Empty) {
                bool win = true;
                for (int i = 1; i < size; i++) {
                    if (board[i][j] != board[0][j]) {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }
        }

        // Check main diagonal
        if (board[0][0] != Empty) {
            bool win = true;
            for (int i = 1; i < size; i++) {
                if (board[i][i] != board[0][0]) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }

        // Check anti-diagonal
        if (board[0][size-1] != Empty) {
            bool win = true;
            for (int i = 1; i < size; i++) {
                if (board[i][size-1-i] != board[0][size-1]) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }

        return false;
    }

    void printBoard(){
        for(int i=0;i<this->size;i++){
            for(int j=0;j<this->size;j++){
                if(board[i][j]==X)
                    cout<<" X |";
                else if(board[i][j]==O)
                    cout<<" O |";
                else cout<<"  |";
            }
            cout<<endl;
            cout<<"------------"<<endl;
        }
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