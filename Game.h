#ifndef EX3_GAME_H
#define EX3_GAME_H

#include <assert.h>
#include "Matrix.h"
#include "Auxiliaries.h"
#include "Character.h"
#include "Soldier.h" 
#include <memory>
#include <map>

namespace mtm
{
    class Game
    {
    private:
        Dimensions dim;
        Matrix<std::shared_ptr<Character>> game_board;

        std::string setToPrint() const;
        //std::map<GridPoint, units_t> GetAreaOfAttack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);


    public:
        Game(int height, int width): dim(Dimensions(height, width)), game_board(Matrix<std::shared_ptr<Character>>(dim, NULL)){};
        ~Game() = default;

        Game(const Game& other);
        Game& operator=(const Game& other);
        void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);
        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team, units_t health, units_t ammo, units_t range, units_t power);
        void move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
        void reload(const GridPoint & coordinates);
        bool isOver(Team* winningTeam=NULL) const;
        friend std::ostream& operator<<(std::ostream& os, const Game& game);
    };


}

#endif //EX3_GAME_H
