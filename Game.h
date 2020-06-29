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

//A Game class to create a stradegy board game

/*developers comment: that main priority of the implemantation was polymorpism and making it easier for the user to add 
a new charcter type without changing the program and to edit an existing character attributes. for example, this comes to practise by 
adding a general area of effect feature to the game and not specifically for the Soldier class. the only sepertation to class types is done
in makeCharacter accoeding to the given enum values. some functions could have been implemented more efficiently (GetVectorOfTargets for example) 
but assuming that the game board dimensions are relativly small we decided to choose the simpler and more comprehendable implementation..*/

namespace mtm
{
    class Game
    {
    private:
        //game board dimensions (number of rows and columns)
        Dimensions dim;
        //a game board utilising part b template matrix
        Matrix<std::shared_ptr<Character>> game_board;

        //a helper functions sets the game boad to printable format required by PrintGameBoard function
        std::string setToPrint() const;

        //a helper function makes a vector of potential targets to attack
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
        //Game constructor creates a game with (height) rows and (with) cols. each set is initialized to nullptr
        Game(int height, int width);

        //Game default destructor
        ~Game() = default;

        //Game copy constructor
        Game(const Game& other);

        //Game assign operator
        Game& operator=(const Game& other);

        //places pointed character to given coordinates
        void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);

        //creates a new charcter with given parameters
        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team, units_t health, units_t ammo, units_t range, units_t power);

        //move a charcter from source to destination
        void move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);

        //command a charactor positioned in source to atack destination
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);

        //command a charactor positioned in source to reload
        void reload(const GridPoint & coordinates);

        //true whether a team won (only member from its team are positioned on board) and updates "winning team" (if is not null) to the winnig team. returns false otherwise
        bool isOver(Team* winningTeam=NULL) const;

        //print opertor. prints the game board in its current state
        friend std::ostream& operator<<(std::ostream& os, const Game& game);
    };
}

#endif //EX3_GAME_H
