#include "Character.h"

namespace mtm
{
    const units_t MEDIC_MOVE_RANGE = 5;
    const units_t MEDIC_RELOAD_VALUE = 5;
    const units_t MEDIC_ATTACK_AMMO_COST = 1;

    class Medic : public Character
    {
    private:
        void isIllegalTarget(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, Character& target) const override;

    public:
        Medic(units_t health, units_t ammo, units_t range, units_t power, Team team);
        ~Medic() = default;
        Character* clone() const override;
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target, units_t damage_factor) override;
    };
}
