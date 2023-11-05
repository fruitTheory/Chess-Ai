#pragma once

#include "SFML/Graphics.hpp"
#include "chess_board.hpp"

enum class Pieces { None = 0, P, B, N, R, Q, K };
extern const std::map<char, Pieces> piece_notation_map;
std::ostream& operator<<(std::ostream& os, const Pieces& value);

enum class Letters { a = 1, b, c, d, e, f, g, h };
extern const std::map<char, Letters> letter_notation_map;

extern int piece_map[8][8];

class Chessboard;

// Class for all chess pieces - uses shapes for now
class ChessPieces{
    
private:

    // Piece shapes

    sf::CircleShape null_shape;
    sf::CircleShape pawn_shape;
    sf::CircleShape bishop_shape;
    sf::CircleShape knight_shape;
    sf::CircleShape rook_shape; 
    sf::CircleShape king_shape; 
    sf::CircleShape queen_shape;

    // Piece data 

    int object_id; // generally linked with piece_id
    int object_value; // value of piece
    int color_id; // 0:black 1:white
    bool has_moved; // if piece has moved

public:

    // Construction
    ChessPieces():
    null_shape(0.f, 0),
    pawn_shape(48.f, 3),
    bishop_shape(48.f, 4),
    knight_shape(48.f, 5),
    rook_shape(48.f, 6),
    king_shape(48.f, 8),
    queen_shape(48.f, 100){}
    
    // General data for active moving pieces
    struct Move_data {
        Pieces piece_type;
        int letter;
        int number;
        int color;
        int piece_id;
    };

    // Completed move containing move data
    struct Move {
        Move_data start;
        Move_data end;
    };

    // Piece creation

    void create_chess_pieces(std::vector<ChessPieces>& pieces);
    void set_piece_colors(std::vector<ChessPieces>& pieces);
    void place_pieces(std::vector<ChessPieces>& pieces);
    void draw_pieces(sf::RenderWindow& window, std::vector<ChessPieces>& pieces);
    void update_pieces(sf::RenderWindow& window, Chessboard& board, std::vector<ChessPieces>& pieces);

 
    // Piece moving

    Move_data convert_move(const Move_data& move, std::vector<ChessPieces>& pieces);
    bool move_piece(sf::RenderWindow& window, Chessboard& board, 
                    ChessPieces& chess_pieces, std::vector<ChessPieces>& pieces, 
                    ChessPieces::Move& move);


    // Getters and setters

    void Set_Piece_ID(int ID);
    int Get_Piece_ID();
    void Set_Color_ID(int ID);
    int Get_Color_ID();
    void Set_Has_Moved(int ID);
    bool Get_Has_Moved();
    Pieces get_piece_type();
    std::string get_piece_type_str(Pieces type);


    // Checkers 

    void check_valid_squares(const Move_data& move_start, const Move_data& move_end);
    bool check_attack(const Move_data& move_start, const Move_data& move_end);
    bool check_move_validity(const Move_data& move_start, const Move_data& move_end, 
                             std::vector<ChessPieces>& pieces);
                             
};

class Pawn : public ChessPieces{

    private:
        bool double_step;

    public:
        bool valid_move(const Move_data& move_start, const Move_data& move_end, std::vector<ChessPieces>& pieces);
};

class Bishop : public ChessPieces{

    private:

    public:
        bool valid_move(const Move_data& move_start, const Move_data& move_end, std::vector<ChessPieces>& pieces);
};

/*
Piece value:
Pawn	1
Knight	3
Bishop	3
Rook	5
Queen	9
*/