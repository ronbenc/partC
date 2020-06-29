#include "Sniper.h"

namespace mtm
{
    //**********private functions*************
     void Sniper::isOutOfRangeSniper(const GridPoint & src_coordinates, const GridPoint & dst_coordinates) const
     {
        if(GridPoint::distance(src_coordinates, dst_coordinates) < (units_t)ceil(((double)range)/SNIPER_MINIMUM_RANGE_FACTOR)) //target is too close
        {
            throw OutOfRange();
        }
     }

    void Sniper::isIllegalTarget(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target) const
    {
        if(target == nullptr || team == target->team) //target is empty or a teammate
        {
            throw IllegalTarget();
        }
    }

    //**********class methods***************
    Sniper::Sniper(units_t health, units_t ammo, units_t range, units_t power, Team team)
    : Character(health, ammo, range, power,SNIPER_ATTACK_AMMO_COST, SNIPER_RELOAD_VALUE, SNIPER_MOVE_RANGE, team)
    {
        label = (team == PYTHON ? PYTHON_SNIPER_LABEL : CPP_SNIPER_LABEL);
    }
       
    Character* Sniper::clone() const
    {
        return new Sniper(*this);
    }

    void Sniper::attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target, units_t damage_factor)
    {
        //handle Medic attack exceptions
        isOutOfRange(src_coordinates, dst_coordinates);
        isOutOfRangeSniper(src_coordinates, dst_coordinates);
        isOutOfAmmo();
        isIllegalTarget(src_coordinates, dst_coordinates, target);

        int currAttackBoost = 1;
        if(sniperDamageBoost % 3 == 0)
        {
            currAttackBoost = 2;
            sniperDamageBoost = 0;
        }

        target->applyDamage(power * currAttackBoost);
        sniperDamageBoost++;
    }
    
}