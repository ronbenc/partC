#include "Character.h"

//Soldier class. derives from Character class

namespace mtm
{
    const units_t SOLDIER_MOVE_RANGE = 3;
    const units_t SOLDIER_RELOAD_VALUE = 3;
    const units_t SOLDIER_ATTACK_AMMO_COST = 1;
    const units_t SOLDIER_ATTACK_AREA_OF_EFFECT_RANGE_FACTOR = 3;

    class Soldier : public Character
    {
    private:

        //throws IllegalTarget exception if target is illegal according to soldier defenitions
        void isIllegalTarget(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target) const override;

    public:
        //Soldier constructor
        Soldier(units_t health, units_t ammo, units_t range, units_t power, Team team);

        //Soldier destructor 
        ~Soldier() = default;

        //Soldier cloning function
        Character* clone() const override;

        //Sedic attack function. according to soldier defenitions
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target, units_t damage_factor) override;
    };
}
