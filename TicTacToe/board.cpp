#include<set>
#include<vector>
#include<iostream>
#include "board.h"
using namespace std;


    Board::Board(){

    }

    Board::Board(int size){
        this->size = size;
        board.resize(size, vector<Piece>(size));
    }

    int Board::getSize(){
        return this->size;
    }

    set<pair<int, int> > Board::getEmptyCells(){
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

    void Board::setPiece(int x, int y, Piece p){
        this->board[x][y] = p;
    }

    bool Board::checkWinner() {
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

    void Board::printBoard(){
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