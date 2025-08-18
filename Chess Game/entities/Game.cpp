#include "Game.hpp"

Game::Game(Player* player1, Player* player2, int boardSize, Color color1, Color color2)
	: player1(player1), player2(player2), color1(color1), color2(color2), status(GameStatus::ONGOING) {
	board = new Board(boardSize, color1, color2);
	currentPlayer = player1;
	winner = nullptr;
	status= GameStatus::NOT_STARTED;
}

Game::~Game() {
	delete board;
	delete player1;
	delete player2;
}

void Game::start() {
	board->initializeBoard();
	status = GameStatus::IN_PROGRESS;
	currentPlayer = player1;
}

void Game::switchPlayer() {
	if (currentPlayer == player1) {
		currentPlayer = player2;
	} else {
		currentPlayer = player1;
	}
}

void Game::makeMove(Position source, Position destination) {
	if(isGameOver()) {
		throw runtime_error("Game is already over.");
	}
	if (!isValidMove(source, destination)) {
		throw runtime_error("Invalid move: Move not allowed.");
	}

	board->makeMove(source, destination);
	addMove(Move(source, destination, currentPlayer));
	
	if(board->isCheckMate()) {
		status = GameStatus::CHECKMATE;
		winner = currentPlayer;
	} else if (board->isDrawn()) {
		status = GameStatus::DRAW;
	}

	switchPlayer();

}

bool Game::isValidMove(Position source, Position destination) const {
	return board->isvalidMove(source, destination);
}

vector<Position> Game::getAllValidPositions(const Position source) const {
	return board->getAllValidPosiotion(source);
}

bool Game::isGameOver() const {
	return status == GameStatus::CHECKMATE || status == GameStatus::DRAW;
}

void Game::makeDraw() {
	status = GameStatus::DRAW;
}

void Game::resetGame() {
	delete board;
	board = new Board(board->getSize(), color1, color2);
	status = GameStatus::NOT_STARTED;
	currentPlayer = player1;
	winner = nullptr;
	moves.clear();
}

GameStatus Game::getStatus() const {
	return status;
}

Player* Game::getCurrentPlayer() const {
	return currentPlayer;
}

Player* Game::getWinner() const {
	if(status != GameStatus::CHECKMATE) {
		throw runtime_error("Game is not over yet, no winner.");
	}
	return winner;
}

Board* Game::getBoard() const {
	return board;
}

vector<Move> Game::getMoves() const {
	return moves;
}

vector<Move> Game::getMovesByPlayer(const Player* player) const {
	vector<Move> playerMoves;
	for (const auto& move : moves) {
		if (move.getPlayer() == player) {
			playerMoves.push_back(move);
		}
	}
	return playerMoves;
}

void Game::addMove(const Move& move) {
	moves.push_back(move);
}
void Game::setStatus(GameStatus newStatus) {
	status = newStatus;
}