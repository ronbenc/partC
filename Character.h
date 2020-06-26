#ifndef EX3_CHARACTER_H
#define EX3_CHARACTER_H


#include "Auxiliaries.h"
#include <assert.h>

namespace mtm 
{
    const char EMPTY_CELL_LABEL = ' ';
    const char CPP_SOLDIER_LABEL = 'S';
    const char PYTHON_SOLDIER_LABEL = 's';
    const char CPP_MEDIC_LABEL = 'M';
    const char PYTHON_MEDIC_LABEL = 'm';
    const char CPP_SNIPER_LABEL = 'N';
    const char PYTHON_SNIPER_LABEL = 'n';


    class Character
    {
    protected: //private with access functions or protected?
        units_t health;
        units_t ammo;
        units_t range;
        units_t power;

    public:
        Team team;
        char label;
        units_t attackAreaOfEffectRange = 0; //initianalized to zero by default.

        Character(units_t health, units_t ammo, units_t range, units_t power, Team team): health(health), ammo(ammo), range(range), power(power), team(team){};
        virtual ~Character() = default;
        virtual Character* clone() const = 0;

        void applyDamage(units_t damage);
        bool isCharacterDead();
        virtual void attack(Character& target, units_t damage_factor) = 0; //this character attacks
        virtual void reload() = 0;

    };
    
}

#endif //EX3_CHARACTER_H