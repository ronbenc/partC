#include "Soldier.h"

namespace mtm
{
    //**********private functions*************

    //**********class methods***************
    Character* Soldier::clone() const
    {
        return new Soldier(*this);
    }

    void Soldier::attack(Character& target, units_t damage_factor)
    {
        //handle Soldier attack exceptions
        assert(ammo > 0);

        ammo-= SOLDIER_ATTACK_AMMO_COST;

        if(team != target.team)
        {
            target.applyDamage(power/damage_factor);
        }            
    }


    void Soldier::reload()
    {
        ammo+=SOLDIER_RELOAD_VALUE;
    }
}