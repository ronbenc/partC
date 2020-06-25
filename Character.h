#ifndef EX3_CHARACTER_H
#define EX3_CHARACTER_H


#include "Auxiliaries.h"

namespace mtm 
{
    const char EMPTY_CELL_LABEL = ' ';
    const char CPP_SOLDIER_LABEL = 'S';
    const char PYTHON_SOLDIER_LABEL = 's';


    class Character
    {
    protected: //private with access functions or protected?
        //GridPoint position(); //should be a field in Character?
        //Team team; //should be a field in Character?
        units_t health;
        units_t ammo;
        units_t range;
        units_t power;
        //unsigned int move_range;//moveset?

    public:
        //GridPoint position;
        Team team;
        char label;

        Character(units_t health, units_t ammo, units_t range, units_t power, Team team): health(health), ammo(ammo), range(range), power(power), team(team){};
        virtual ~Character() = default;
        virtual Character* clone() const = 0;
    };
    
}

#endif //EX3_CHARACTER_H