#include "Medic.h"

namespace mtm
{
    //**********private functions*************
    void Medic::isIllegalTarget(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target) const
    {
        if(target == nullptr || src_coordinates == dst_coordinates) //neither team mate nor enemy
        {
            throw IllegalTarget();
        }
    }

    //**********class methods***************
    Medic::Medic(units_t health, units_t ammo, units_t range, units_t power, Team team)
    : Character(health, ammo, range, power,MEDIC_ATTACK_AMMO_COST, MEDIC_RELOAD_VALUE, MEDIC_MOVE_RANGE, team)
    {
        label = (team == PYTHON ? PYTHON_MEDIC_LABEL : CPP_MEDIC_LABEL);
    }
       
    Character* Medic::clone() const
    {
        return new Medic(*this);
    }

    void Medic::attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target, units_t damage_factor)
    {
        //handle Medic attack exceptions
        isOutOfRange(src_coordinates, dst_coordinates);
        isOutOfAmmo();
        isIllegalTarget(src_coordinates, dst_coordinates, target);

        assert(target != nullptr);

        if(team != target->team) //target is an enemy. attack
        {
            target->applyDamage(power);
        }

        else //target is a teammate. heal. no ammo usage
        {
            target->applyDamage(-(power));
            ammo += MEDIC_ATTACK_AMMO_COST;
        }               
    }
}