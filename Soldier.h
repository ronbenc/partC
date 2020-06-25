#include "Character.h"

namespace mtm
{
    class Soldier : public Character
    {
    private:
        unsigned int move_range = 3;

        char getLetter() const override;
    public:
        Soldier(units_t health, units_t ammo, units_t range, units_t power): Character(health, ammo, range, power){};
        ~Soldier() = default;
        Character* clone() const override;
    };
}
