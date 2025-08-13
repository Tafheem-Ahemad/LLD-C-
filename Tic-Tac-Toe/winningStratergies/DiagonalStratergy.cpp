#include "DiagonalStratergy.hpp"

bool DiagonalStratergy::checkStratergy(const Board* board, const Symbol symbol, const int &x, const int &y) {
	int boardSize=board->getSize();
	if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) {
		return false;
	}

	if(x != y &&  x != boardSize-y-1) return false;

	int check1 =1 ,check2=1;
	if( x==y ){
		int i=0,j=0;
		while(i<boardSize){
			if(board[i][j]->getCell(i,j) != symbol){
				check1=0;
				break;
			}
			i++;
			j++;
		}
	}
	if( x != boardSize-y-1 ){
		int i=0,j=boardSize-1;
		while(i<boardSize){
			if(board[i][j]->getCell(i,j) != symbol){
				check2=0;
				break;
			}
			i++;
			j--;
		}
	}
	
	return (check1 || check2);
}