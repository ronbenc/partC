#include "Soldier.h"

namespace mtm
{
    //**********private functions*************
    char Soldier::getLetter() const
    {
        if(team == CPP)
            return 'S';
        
        return 's';
    }


    //**********class methods***************
    Character* Soldier::clone() const
    {
        return new Soldier(*this);
    }

}