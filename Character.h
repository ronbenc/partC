#ifndef EX3_CHARACTER_H
#define EX3_CHARACTER_H


#include "Auxiliaries.h"

namespace mtm 
{
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

        virtual char getLetter() const;

    public:
        GridPoint position;
        Team team;

        Character(units_t health, units_t ammo, units_t range, units_t power): health(health), ammo(ammo), range(range), power(power), position(position){};
        virtual ~Character() = default;
        virtual Character* clone() const = 0;
    };
    
}

#endif //EX3_CHARACTER_H