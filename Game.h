#ifndef EX3_GAME_H
#define EX3_GAME_H

#include <assert.h>
#include "Matrix.h"
#include "Auxiliaries.h"
#include "Exceptions.h"
#include "Character.h"
#include "Soldier.h" 
#include "Medic.h"
#include "Sniper.h"  
#include <memory>
#include <vector>

namespace mtm
{
    class Game
    {
    private:
        Dimensions dim;
        Matrix<std::shared_ptr<Character>> game_board;

        std::string setToPrint() const;
        std::vector<GridPoint> GetVectorOfTargets(std::shared_ptr<Character> attacking_character, const GridPoint & target_coordinates) const;

        //**********exception functions*************

        //throw an exception if coordinates are not in the game board
        void isInBoard(const GridPoint& coordinates) const; 

        //throw an exception if no character is in coordinates
        void isCellEmpty(const GridPoint& coordinates) const;

        //throw an exception if destination coordinates are not in the charactaer move range
        void isMoveTooFar(const GridPoint & src_coordinates, const GridPoint & dst_coordinates) const;
        
        //throw an exception if a character is in coordinates
        void isCellOccupied(const GridPoint& coordinates) const;




    public:
        Game(int height, int width);
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
