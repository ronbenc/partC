#include "Game.h"

namespace mtm
{
    Game::Game(const Game& other): Game(Game(other.dim.getRow(), other.dim.getCol())) // more efficeirt way?
    {
        for (int i = 0; i < dim.getRow(); i++)
        {
            for (int j = 0; j < dim.getCol(); j++)
            {
                game_board(i,j) = (std::shared_ptr<Character>)other.game_board(i,j)->clone(); //is this okay?
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
                game_board(i,j) = (std::shared_ptr<Character>)other.game_board(i,j)->clone(); //is this okay?
            }
        }

        return *this;
    }

    
    
}