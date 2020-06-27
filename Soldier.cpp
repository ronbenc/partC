#include "Soldier.h"

namespace mtm
{
    //**********private functions*************

    //**********class methods***************
    Soldier::Soldier(units_t health, units_t ammo, units_t range, units_t power, Team team)
    : Character(health, ammo, range, power, SOLDIER_MOVE_RANGE, team)
    {
        label = (team == PYTHON ? PYTHON_SOLDIER_LABEL : CPP_SOLDIER_LABEL);
        attackAreaOfEffectRange = (units_t)ceil(double(range)/SOLDIER_ATTACK_AREA_OF_EFFECT_RANGE_FACTOR);
    }

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