#include "Character.h"

//Medic class. derives from Character class

namespace mtm
{
    const units_t MEDIC_MOVE_RANGE = 5;
    const units_t MEDIC_RELOAD_VALUE = 5;
    const units_t MEDIC_ATTACK_AMMO_COST = 1;

    class Medic : public Character
    {
    private:
        //throws an IllegalTarget exception if target is illegal according to medic defenitions
        void isIllegalTarget(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target) const override;

    public:
        //Medic constructor
        Medic(units_t health, units_t ammo, units_t range, units_t power, Team team);

        //Medic destructor
        ~Medic() = default;

        //Medic cloning function
        Character* clone() const override;

        //Medic attack function. according to medic defenitions
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target, units_t damage_factor) override;
    };
}
