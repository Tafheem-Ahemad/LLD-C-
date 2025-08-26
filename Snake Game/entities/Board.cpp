
#include "Board.hpp"
#include "Cell/Cell.hpp"
#include "Cell/Dot.hpp"
#include "Cell/Snake.hpp"
#include "Cell/Ladder.hpp"

Board::Board(const int size): size(size){	
}

Board::~Board(){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			delete board[i][j];
		}
	}
}

void Board::InitBoard(){
	board.resize(size,vector<Cell*>(size));
	// init all cell with dot
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			Position pos={i,j};
			board[i][j] = new Dot(pos,pos,i*size+j+1);
		}
	}

	// add some snake
	Position s1s={3,4},s1d={1,4};
	board[3][4] = new Snake(s1s,s1d,16);

	Position s2s={2,2},s2d={0,1};
	board[2][2] = new Snake(s2s,s2d,7);

	Position s3s={4,2},s3d={3,0};
	board[4][2] = new Snake(s3s,s3d,13);

	// add some ladder
	Position l1s={1,1},l1d={3,1};
	board[1][1] = new Ladder(l1s,l1d,11);

	Position l2s={0,3},l2d={2,3};
	board[0][3] = new Ladder(l2s,l2d,9);

	Position l3s={3,0},l3d={4,0};
	board[3][0] = new Ladder(l3s,l3d,16);

	// may be more snake and ladder, or any other logic
}

void Board::makeMove(int playerIndex,int value){
	// get current position of player
	// calculate new position of player
	// check if new position is valid or not
	// if valid then move player to new position
	// if not valid then do nothing
	// check if player is winner or not
}

bool Board::isWinner(Player* player){
	// check if player is winner or not , by checjking his position
	return false;
}

void Board::printBoard() const{
	for(int i=size-1;i>=0;i--){
		for(int j=0;j<size;j++){
			cout<<board[i][j]->getPlaceValue()<<" ";
		}
		cout<<endl;
	}
}

// getter setter
int Board::getSize() const{
	return this->size;
}

vector<vector<Cell*>> Board::getBoard() const{
	return this->board;
}

vector<Position> Board::getPlayerPositions() const{
	return this->playerPositions;
}
