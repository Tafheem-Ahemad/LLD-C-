#pragma once
#include <bits/stdc++.h>
using namespace std;

enum class GameStatus {
    WINNER_X,
    WINNER_Y,
    IN_PROGRESS,
    DRAW
};

inline std::ostream& operator<<(std::ostream& os, const GameStatus& status) {
    return os << toString(status);
}
string toString(GameStatus status) {
    switch (status) {
        case GameStatus::WINNER_X: return "Win by first player";
        case GameStatus::WINNER_Y: return "Win by second player";
        case GameStatus::IN_PROGRESS: return "In_Progress";
        case GameStatus::DRAW: return "Draw";
    }
    return {};
}