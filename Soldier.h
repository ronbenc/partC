#include "Character.h"

namespace mtm
{
    const units_t SOLDIER_MOVE_RANGE = 3;
    const units_t SOLDIER_RELOAD_VALUE = 3;
    const units_t SOLDIER_ATTACK_AMMO_COST = 1;
    const units_t SOLDIER_ATTACK_AREA_OF_EFFECT_RANGE_FACTOR = 3;

    class Soldier : public Character
    {
    private:
        units_t attackAreaOfEffectRange = SOLDIER_ATTACK_AREA_OF_EFFECT_RANGE_FACTOR;

        void isIllegalTarget(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, Character& target) const override;

    public:
        Soldier(units_t health, units_t ammo, units_t range, units_t power, Team team);
        ~Soldier() = default;
        Character* clone() const override;
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target, units_t damage_factor) override;
        void reload() override;
    };
}
