#pragma once

#include "chess_pieces.hpp"
#include <vector>
#include <array>

extern std::vector<std::array<std::array<int, 8>, 8>> game_history;
extern std::vector<ChessPieces::Move> stored_moves;

void store_board_state();