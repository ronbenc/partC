#include "Soldier.h"

namespace mtm
{
    //**********private functions*************

    //**********class methods***************
    Character* Soldier::clone() const
    {
        return new Soldier(*this);
    }

    void Soldier::reload()
    {
        ammo+=3;
    }
}