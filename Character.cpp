#include "Character.h"

namespace mtm
{

    Character::Character(units_t health, units_t ammo, units_t range, units_t power, units_t move_range, Team team)
    : health(health), ammo(ammo), range(range), power(power), move_range(move_range), team(team){};

    void Character::applyDamage(units_t damage)
    {
        health-=damage;
    }

    bool Character::isCharacterDead()
    {
        return (health < 0);
    }
}