#include "Character.h"

namespace mtm
{
    const units_t SNIPER_MOVE_RANGE = 4;
    const units_t SNIPER_RELOAD_VALUE = 2;
    const units_t SNIPER_ATTACK_AMMO_COST = 1;
    const units_t SNIPER_DAMAGAE_BOOST_LIMIT = 3;
    const units_t SNIPER_MINIMUM_RANGE_FACTOR = 2;

    class Sniper : public Character
    {
    private:
        units_t sniperDamageBoost = 1;

        void isIllegalTarget(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target) const override;

    public:
        Sniper(units_t health, units_t ammo, units_t range, units_t power, Team team);
        ~Sniper() = default;
        Character* clone() const override;
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target, units_t damage_factor) override;
    };
}
