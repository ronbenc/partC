#include "Character.h"

namespace mtm
{
    //**********exception functions*************
    void Character::isOutOfRange(const GridPoint & src_coordinates, const GridPoint & dst_coordinates) const
    {
        if(GridPoint::distance(src_coordinates, dst_coordinates) > range)
        {
            throw OutOfRange();
        }
    }

    void Character::isOutOfAmmo() const
    {
        if(ammo <attack_ammo_cost)
        {
            throw OutOfAmmo();
        }
    }



    //**********class methods*************
    Character::Character(units_t health, units_t ammo, units_t range, units_t power,units_t attack_ammo_cost, units_t move_range, Team team)
    : health(health), ammo(ammo), range(range), power(power), attack_ammo_cost(attack_ammo_cost), move_range(move_range), team(team){}

    void Character::applyDamage(units_t damage)
    {
        health-=damage;
    }

    bool Character::isCharacterDead()
    {
        return (health < 0);
    }
}