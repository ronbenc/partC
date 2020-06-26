#include "Game.h"

namespace mtm
{

    //**********private functions*************

    std::string Game::setToPrint() const
    {
        std::string toPrint;
        for(std::shared_ptr<Character> character: game_board)
        {
            if(character == NULL)
            {
                 toPrint += (EMPTY_CELL_LABEL);
            }
            else
            {
                toPrint += (character->label);
            }
        }

        assert(toPrint.size() == game_board.size());

        return toPrint;
    }


    //**********class methods***************
    Game::Game(const Game& other): Game(Game(other.dim.getRow(), other.dim.getCol()))
    {
        assert(dim == other.dim);

        for (int i = 0; i < dim.getRow(); i++)
        {
            for (int j = 0; j < dim.getCol(); j++)
            {
                if(other.game_board(i,j) != NULL)
                {
                    game_board(i,j) = std::shared_ptr<Character>(other.game_board(i,j)->clone());
                }
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
                if(other.game_board(i,j) != NULL)
                {
                    game_board(i,j) = std::shared_ptr<Character>(other.game_board(i,j)->clone());
                }
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

        //character->position = coordinates;
    }

    std::shared_ptr<Character> Game::makeCharacter(CharacterType type, Team team,units_t health, units_t ammo, units_t range, units_t power)
    {
        std::shared_ptr<Character> new_character;

        switch (type)
        {
            case SOLDIER:
                new_character = (std::shared_ptr<Character>)(new Soldier(health, ammo, range, power, team));
                new_character->label = (team == PYTHON ? PYTHON_SOLDIER_LABEL : CPP_SOLDIER_LABEL);
            default:
                break;
        }

        return new_character;
    }

    void Game::move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates)
    {
        //handle exceptions....
        assert(game_board(dst_coordinates.row, dst_coordinates.col) == NULL);
        game_board(dst_coordinates.row, dst_coordinates.col) = game_board(src_coordinates.row, src_coordinates.col);
        game_board(src_coordinates.row, src_coordinates.col) = NULL;
    }

    void Game::attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates)
    {
        //handle attack board exceptions....
        assert(game_board(src_coordinates.row, src_coordinates.col) != NULL && game_board(dst_coordinates.row, dst_coordinates.col) != NULL);

        //attack target
        game_board(src_coordinates.row, src_coordinates.col)->attack(src_coordinates, dst_coordinates, *game_board(dst_coordinates.row, dst_coordinates.col));

        //check for dead
        if(game_board(dst_coordinates.row, dst_coordinates.col)->isCharacterDead())
        {
            game_board(dst_coordinates.row, dst_coordinates.col) = NULL;
        }

    }

    void Game::reload(const GridPoint & coordinates)
    {
        //handle exceptions....

        assert(game_board(coordinates.row, coordinates.col) != NULL);
        game_board(coordinates.row, coordinates.col)->reload();
    }

    std::ostream& operator<<(std::ostream& os, const Game& game)
    {
        const std::string toPrint = game.setToPrint();\
        return printGameBoard(os, &toPrint.front(), &toPrint.back() + 1, (unsigned)game.dim.getCol());
    }
}