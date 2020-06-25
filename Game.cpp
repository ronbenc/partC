#include "Game.h"

namespace mtm
{

    //**********private functions*************

    std::string Game::setToPrint(const Game& game)
    {
        std::string toPrint;
        for(std::shared_ptr<Character> character: game.game_board)
        {

        }

        return toPrint;
    }


    //**********class methods***************
    Game::Game(const Game& other): Game(Game(other.dim.getRow(), other.dim.getCol())) // more efficeirt way?
    {
        assert(dim == other.dim);

        for (int i = 0; i < dim.getRow(); i++)
        {
            for (int j = 0; j < dim.getCol(); j++)
            {
                game_board(i,j) = std::shared_ptr<Character>(other.game_board(i,j)->clone()); //is this okay?
            }
        }
    }

    Game& Game::operator=(const Game& other)
    {
        if(this == &other)
        {
            return *this;
        }

        dim = other.dim;

        for (int i = 0; i < dim.getRow(); i++)
        {
            for (int j = 0; j < dim.getCol(); j++)
            {
                game_board(i,j) = std::shared_ptr<Character>(other.game_board(i,j)->clone()); //is this okay?
            }
        }

        return *this;
    }


    void Game::addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character)
    {
        //handle exceptions...
        assert(game_board(coordinates.row, coordinates.col) == NULL);
        game_board(coordinates.row, coordinates.col) = character;
        assert(game_board(coordinates.row, coordinates.col) != NULL);

        character->position = coordinates;
    }

 std::shared_ptr<Character> Game::makeCharacter(CharacterType type, Team team,units_t health, units_t ammo, units_t range, units_t power)
    {
        std::shared_ptr<Character> new_character;

        switch (type)
        {
        case SOLDIER:
            new_character = (std::shared_ptr<Character>)(new Soldier(health, ammo, range, power));
        }

        new_character->team = team;

        return new_character;
    }




    
    
}