#include "Character.h"

namespace mtm
{
    const units_t SOLDIER_MOVE_RANGE = 3;
    const units_t SOLDIER_RELOAD_VALUE = 3;
    const units_t SOLDIER_ATTACK_AMMO_COST = 1;

    class Soldier : public Character
    {
    private:
        const units_t move_range = SOLDIER_MOVE_RANGE;
    public:
        
        Soldier(units_t health, units_t ammo, units_t range, units_t power, Team team): Character(health, ammo, range, power, team)
        {};
        ~Soldier() = default;
        Character* clone() const override;
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, Character& target) override;
        void reload() override;
    };
}
