#include "Game.h"

namespace mtm
{

    //**********private functions*************

    std::string Game::setToPrint() const
    {
        std::string toPrint;
        for(std::shared_ptr<Character> character: game_board)
        {
            if(character == nullptr)
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

    //Creates a vector of potential targets to attack depending on the attacker's area of effect range and target location
    std::vector<GridPoint> Game::GetVectorOfTargets(std::shared_ptr<Character> attacking_character, const GridPoint & target_coordinates) const
    {
        std::vector<GridPoint> targets;

        for(int i = 0; i < dim.getRow(); i++) //there are more efficient ways. implemented this way for simplicity
        {
            for(int j =0; j < dim.getCol(); j++)
            {
                if((GridPoint::distance(GridPoint(i,j), target_coordinates) <= attacking_character->attackAreaOfEffectRange) && (game_board(i,j) != nullptr))
                {
                    targets.push_back(GridPoint(i, j));
                }
            }
        }

        return targets;
    }

    void Game::isInBoard(const GridPoint& coordinates) const
    {
        if(coordinates.row >= dim.getRow() || coordinates.row >= dim.getCol())
        {
            throw IllegalCell();
        }
    }

    void Game::isCellEmpty(const GridPoint& coordinates) const
    {
        if(game_board(coordinates.row, coordinates.col) == nullptr)
        {
            throw CellEmpty();
        }
    }

    void Game::isCellOccupied(const GridPoint& coordinates) const
    {
        if(game_board(coordinates.row, coordinates.col) == nullptr)
        {
            throw CellOccupied();
        }
    }

    void Game::isMoveTooFar(const GridPoint & src_coordinates, const GridPoint & dst_coordinates) const
    {
        if(GridPoint::distance(src_coordinates, dst_coordinates) > game_board(src_coordinates.row, src_coordinates.col)->move_range)
        {
            throw MoveToFar();
        }
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
        isInBoard(coordinates);

        if(game_board(coordinates.row, coordinates.col) != nullptr)
        {
            throw CellOccupied();
        }

        assert(game_board(coordinates.row, coordinates.col) == nullptr);
        game_board(coordinates.row, coordinates.col) = character;
        assert(game_board(coordinates.row, coordinates.col) != nullptr);
    }

    std::shared_ptr<Character> Game::makeCharacter(CharacterType type, Team team,units_t health, units_t ammo, units_t range, units_t power)
    {
        if(health <= 0)
        {
            throw IllegalArgument();
        }

        std::shared_ptr<Character> new_character;

        switch (type) // map of CharacterType/ typeinfo?
        {
            case SOLDIER:
                new_character = (std::shared_ptr<Character>)(new Soldier(health, ammo, range, power, team));

            default:
                break;
        }

        return new_character;
    }

    void Game::move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates)
    {
        //handle exceptions....
        isInBoard(src_coordinates);
        isInBoard(dst_coordinates);
        isCellEmpty(src_coordinates);
        isMoveTooFar(src_coordinates, dst_coordinates);
        isCellOccupied(dst_coordinates);

        assert(game_board(dst_coordinates.row, dst_coordinates.col) == NULL);
        game_board(dst_coordinates.row, dst_coordinates.col) = game_board(src_coordinates.row, src_coordinates.col);
        game_board(src_coordinates.row, src_coordinates.col) = NULL;
    }

    void Game::attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates)
    {
        //handle exceptions....
        isInBoard(src_coordinates);
        isInBoard(dst_coordinates);
        isCellEmpty(src_coordinates);

        std::shared_ptr<Character> attacking_character = game_board(src_coordinates.row, src_coordinates.col);
        std::shared_ptr<Character> attacked_character = game_board(dst_coordinates.row, dst_coordinates.col);
        assert(attacking_character != NULL);

        //make vector of targets coordinates
        std::vector<GridPoint> targets = GetVectorOfTargets(attacking_character, dst_coordinates);

        //attack targets
        for(GridPoint target: targets)
        {
            //attack target. character exceptions are checked in attack
            attacking_character->attack(src_coordinates, dst_coordinates, game_board(target.row, target.col), (target == dst_coordinates ? 1 : 2));

            //check for dead
            if(game_board(target.row, target.col)->isCharacterDead())
            {
                game_board(target.row, target.col)=nullptr;
            }
        }
    }

    void Game::reload(const GridPoint & coordinates)
    {
        //handle exceptions....
        isInBoard(coordinates);
        isCellEmpty(coordinates);

        assert(game_board(coordinates.row, coordinates.col) != NULL);
        game_board(coordinates.row, coordinates.col)->reload();
    }

    bool Game::isOver(Team* winningTeam) const
    {
        bool teamPhytonSurvivors = false;
        bool teamCppSurvivors = false;

        for(std::shared_ptr<Character> character: game_board)
        {
            if(character == nullptr)
            {
                continue;
            }

            if(character->team == PYTHON)
            {
                teamPhytonSurvivors = true;
            }

            if(character->team == CPP)
            {
                teamCppSurvivors = true;
            }
        }

        //if no team member is left or there are team members from both teams
        if((teamPhytonSurvivors && teamCppSurvivors) || (!teamPhytonSurvivors && !teamCppSurvivors))
        {
            return false;
        }

        //if winningTeam is not NULL change it to the winnig team name
        if(winningTeam && teamPhytonSurvivors)
        {
            *winningTeam = PYTHON;
        }

        if(winningTeam && teamCppSurvivors)
        {
            *winningTeam = CPP;
        }

        return true;
    }

    std::ostream& operator<<(std::ostream& os, const Game& game)
    {
        const std::string toPrint = game.setToPrint();\
        return printGameBoard(os, &toPrint.front(), &toPrint.back() + 1, (unsigned)game.dim.getCol());
    }
}