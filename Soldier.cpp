#include "Soldier.h"

namespace mtm
{

    Character* Soldier::clone() const
    {
        return new Soldier(*this);
    }

}