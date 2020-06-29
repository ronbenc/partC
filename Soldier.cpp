#include "Soldier.h"

namespace mtm
{
    //**********private functions*************
    void Soldier::isIllegalTarget(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target) const
    {
        if(src_coordinates.row != dst_coordinates.row && src_coordinates.col != dst_coordinates.col)
        {
            throw IllegalTarget();
        }
    }

    //**********class methods***************
    Soldier::Soldier(units_t health, units_t ammo, units_t range, units_t power, Team team)
    : Character(health, ammo, range, power, SOLDIER_ATTACK_AMMO_COST, SOLDIER_RELOAD_VALUE, SOLDIER_MOVE_RANGE, team)
    {
        label = (team == PYTHON ? PYTHON_SOLDIER_LABEL : CPP_SOLDIER_LABEL);
        attackAreaOfEffectRange = (units_t)ceil((double)range/SOLDIER_ATTACK_AREA_OF_EFFECT_RANGE_FACTOR);
    }

    Character* Soldier::clone() const
    {
        return new Soldier(*this);
    }

    void Soldier::attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target, units_t damage_factor)
    {
        //handle Soldier attack exceptions
        isOutOfRange(src_coordinates, dst_coordinates);
        isOutOfAmmo();
        isIllegalTarget(src_coordinates, dst_coordinates, target);

        assert(target != nullptr);
        
        if(team != target->team)
        {
            target->applyDamage((units_t)ceil(((double)power/damage_factor)));
        }
    }
}