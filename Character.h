#include "Auxiliaries.h"

namespace mtm 
{
    class Character
    {
    private: //private with access functions or protected?
        GridPoint position(); //should be a field in Character?
        unsigned int health;
        unsigned int ammo;
        unsigned int range;
        unsigned int power;
        //unsigned int move_range;//moveset?
        
    public:
        Character(int health, int ammo, int range, int power): health(health), ammo(ammo), range(range), power(power){};
        virtual ~Character() = default;
    };
    
}
