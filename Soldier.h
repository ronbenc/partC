#include "Character.h"

namespace mtm
{
    class Soldier : public Character
    {
    private:
        unsigned int move_range = 3;

    public:
        Soldier(int health, int ammo, int range, int power): Character(health, ammo, range, power){};
        ~Soldier() = default;
        Character* clone() const override;
    };
}
