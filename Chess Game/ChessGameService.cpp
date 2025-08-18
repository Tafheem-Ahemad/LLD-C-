#include "ChessGameService.hpp"

ChessGameService::ChessGameService() {}
ChessGameService::~ChessGameService() {
	for (auto& game : games) {
		delete game.second;
	}
	for (auto& player : players) {
		delete player.second;
	}
}

ChessGameService& ChessGameService::getIntance() {
	static ChessGameService instance;
	return instance;
}

void ChessGameService::addNewGame(Player* player1, Player* player2, Color color1, Color color2) {
	string gameId = getNewGameId();
	Game* newGame = new Game(player1, player2, 8, color1, color2);
	games[gameId] = newGame;
}

Game* ChessGameService::getGame(const string& id) {
	auto it = games.find(id);
	if (it != games.end()) {
		return it->second;
	}else{
		throw runtime_error("Game not found with id: " + id);
	}
}

void ChessGameService::makeMove(const string& id, Position source, Position destination) {
	Game* game = getGame(id);
	game->makeMove(source, destination);
}

vector<Position> ChessGameService::getAllPossibleMoves(const string& id, Position source) {
	Game* game = getGame(id);
	
	return game->getAllValidPositions(source);

}

void ChessGameService::makeGameDraw(const string& id) {
	Game* game = getGame(id);
	game->makeDraw();
}

void ChessGameService::resetGame(const string& id) {
	Game* game = getGame(id);
	game->resetGame();
}

void ChessGameService::addPlayer(const string& id, const string& name, PieceType pieceType) {
	if (players.find(id) != players.end()) {
		throw runtime_error("Player with id " + id + " already exists.");
	}
	Player* newPlayer = new Player(id, name, pieceType);
	players[id] = newPlayer;
}

Player* ChessGameService::getPlayer(const string& id) {
	auto it = players.find(id);
	if (it != players.end()) {
		return it->second;
	} else {
		throw runtime_error("Player not found with id: " + id);
	}
}

vector<Player*> ChessGameService::getAllPlayers() const {
	vector<Player*> allPlayers;
	for (const auto& player : players) {
		allPlayers.push_back(player.second);
	}
	return allPlayers;
}

void ChessGameService::removePlayer(const string& id) {
	auto it = players.find(id);
	if (it != players.end()) {
		delete it->second;
		players.erase(it);
	} else {
		throw runtime_error("Player not found with id: " + id);
	}
}


vector<Move> ChessGameService::getMovesByPlayer(const string& gameId, const string& playerId) const {
	Game* game = getGame(gameId);
	Player* player = getPlayer(playerId);
	return game->getMovesByPlayer(player);
}

vector<Move> ChessGameService::getAllMoves(const string& gameId) const {
	Game* game = getGame(gameId);
	return game->getMoves();
}

string ChessGameService::getNewGameId() const {
	string newId= getRandomId();
	return "GAME_" + newId;
}

string ChessGameService::getNewPlayerId() const {
	static int playerCounter = 0;
	return "PLAYER_" + to_string(playerCounter++);
}

string ChessGameService::getRandomId(int len) const {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 9);
	string id;
	for (int i = 0; i < len; ++i) {
		id += to_string(dis(gen));
	}
	return id;
}