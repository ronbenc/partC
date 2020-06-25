#include "Character.h"

namespace mtm
{
    class Soldier : public Character
    {
    private:
        unsigned int move_range = 3;
    public:
        
        Soldier(units_t health, units_t ammo, units_t range, units_t power, Team team): Character(health, ammo, range, power, team)
        {};
        ~Soldier() = default;
        Character* clone() const override;

        void reload();
    };
}
