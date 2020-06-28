#ifndef EX3_CHARACTER_H
#define EX3_CHARACTER_H


#include "Auxiliaries.h"
#include "Exceptions.h"
#include <memory>
#include <assert.h>

namespace mtm 
{
    const char EMPTY_CELL_LABEL = ' ';
    const char CPP_SOLDIER_LABEL = 'S';
    const char PYTHON_SOLDIER_LABEL = 's';
    const char CPP_MEDIC_LABEL = 'M';
    const char PYTHON_MEDIC_LABEL = 'm';
    const char CPP_SNIPER_LABEL = 'N';
    const char PYTHON_SNIPER_LABEL = 'n';


    class Character
    {
    protected:
        units_t health;
        units_t ammo;
        const units_t range;
        const units_t power;

        const units_t attack_ammo_cost;
        const units_t reload_value;
        
        //**********exception functions*************
   
        //throw an exception if a an attack target is out of character range
        void isOutOfRange(const GridPoint & src_coordinates, const GridPoint & dst_coordinates) const;

        //throw an exception if the character is out of ammo
        void isOutOfAmmo() const;

        //throw an exception if the specific character target is illegal
        virtual void isIllegalTarget(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, Character& target) const = 0;


    public:
        const Team team;
        char label;
        const units_t move_range = 0; //initianalized to zero by default.
        units_t attackAreaOfEffectRange = 0; //initianalized to zero by default.


        Character(units_t health, units_t ammo, units_t range, units_t power, units_t attack_ammo_cost , units_t reload_value, units_t move_range, Team team);
        virtual ~Character() = default;
        virtual Character* clone() const = 0;

        void applyDamage(units_t damage);
        bool isCharacterDead();
        virtual void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target, units_t damage_factor) = 0; //this character attacks
        void reload();

    };
    
}

#endif //EX3_CHARACTER_H