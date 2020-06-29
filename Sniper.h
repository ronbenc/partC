#include "Character.h"

//Sniper class. derives from Character class

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
        //double attack damage when reaches 3
        units_t sniperDamageBoost = 1;
        
        //throws OutOfRange exception if target is too close to sniper position
        void isOutOfRangeSniper(const GridPoint & src_coordinates, const GridPoint & dst_coordinates) const;

        //throws IllegalTarget exception if target is illegal according to sniper defenitions
        void isIllegalTarget(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target) const override;

    public:
        //Sniper constructor
        Sniper(units_t health, units_t ammo, units_t range, units_t power, Team team);

        //Sniper destructor
        ~Sniper() = default;

        //Sniper cloning function
        Character* clone() const override;

        //Sniper attack function. according to sniper defenitions
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target, units_t damage_factor) override;
    };
}
