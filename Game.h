#ifndef EX3_GAME_H
#define EX3_GAME_H

#include "Matrix.h"
#include "Auxiliaries.h"
#include "Character.h"
#include <memory>
#include <vector> //perhaps a different data structure?

namespace mtm
{
    const char empty = ' ';

    class Game
    {
    private:
        Dimensions dim;
        Matrix<std::shared_ptr<Character>> game_board;


    public:
        Game(int height, int width): dim(Dimensions(height, width)), game_board(Matrix<std::shared_ptr<Character>>(dim)){};
        ~Game() = default;

        Game(const Game& other);
        Game& operator=(const Game& other);
        void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);
        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,units_t health, units_t ammo, units_t range, units_t power);
        void move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
        void reload(const GridPoint & coordinates);
        std::ostream& printGameBoard(std::ostream& os, const char* begin, const char* end, unsigned int width);
        bool isOver(Team* winningTeam=NULL) const;
    };
}

#endif //EX3_GAME_H
