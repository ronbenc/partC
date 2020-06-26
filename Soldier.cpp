#include "Soldier.h"

namespace mtm
{
    //**********private functions*************

    //**********class methods***************
    Character* Soldier::clone() const
    {
        return new Soldier(*this);
    }

    void Soldier::attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, Character& target)
    {
        //handle Soldier attack exceptions
        assert(src_coordinates.row == dst_coordinates.row || src_coordinates.col == dst_coordinates.col);
        assert(GridPoint::distance(src_coordinates, dst_coordinates) <= range);
        assert(ammo > 0);
        ammo-= SOLDIER_ATTACK_AMMO_COST;

        //handeling specific target
        if(team != target.team)
        {
            target.applyDamage(power);
        }            
    }


    void Soldier::reload()
    {
        ammo+=SOLDIER_RELOAD_VALUE;
    }
}