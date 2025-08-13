#include "TicTacToeService.hpp"

TicTacToeService& TicTacToeService::getIntance(){
	static TicTacToeService instance;
	return instance;
}

Game* TicTacToeService::createNewGame(const string &player1Name,const string &player2Name, const int size=3) {
	string gameId = createGameId();
	Player* player1 = new Player(player1Name, Symbol::X);
	Player* player2 = new Player(player2Name, Symbol::O);
	Game* newGame = new Game(gameId, player1, player2, size);
	gameRegistry[gameId] = newGame;
	return newGame;
}

void TicTacToeService::makeMove(const string &gameId,Player* player, const int &x, const int &y){
	Game* game = getGame(gameId);
	game->makeMove(player, x, y);
}


void TicTacToeService::printBoard(const string &gameId) const{
	Game* game = getGame(gameId);
	game->getBoard()->printBoard();
}

Game* TicTacToeService::getGame(const string &gameId) const{
	if(gameRegistry.find(gameId) != gameRegistry.end()) {
		return gameRegistry.at(gameId);
	}else {
		throw runtime_error("Game with ID " + gameId + " does not exist.");
	}
}


string TicTacToeService::createGameId(){
	return "GAME" + randomString(8);
}


string TicTacToeService::randomString(const int length) {
    const string chars =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";

    random_device rd;       
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, chars.size() - 1);

    string result;
    result.reserve(length);
    for (int i = 0; i < length; ++i) {
        result += chars[distrib(gen)];
    }
    return result;
}