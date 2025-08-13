#include "Cell.hpp"

Cell::Cell(const Symbol &symbol) : symbol(symbol){}

Symbol Cell::getSymbol() const{
	return symbol;
}
void Cell::setSymbol(Symbol symbol){
	this->symbol=symbol;
}