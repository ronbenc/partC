#include "Character.h"

namespace mtm
{
    void Character::applyDamage(units_t damage)
    {
        health-=damage;
    }

    bool Character::isCharacterDead()
    {
        return (health < 0);
    }
}