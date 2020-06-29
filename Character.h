#ifndef EX3_CHARACTER_H
#define EX3_CHARACTER_H


#include "Auxiliaries.h"
#include "Exceptions.h"
#include <memory>
#include <assert.h>

namespace mtm 
{
    //const values for each character represntation on the board
    const char EMPTY_CELL_LABEL = ' ';
    const char CPP_SOLDIER_LABEL = 'S';
    const char PYTHON_SOLDIER_LABEL = 's';
    const char CPP_MEDIC_LABEL = 'M';
    const char PYTHON_MEDIC_LABEL = 'm';
    const char CPP_SNIPER_LABEL = 'N';
    const char PYTHON_SNIPER_LABEL = 'n';


    //Character class. in order to add another charcter "child" implement its clone, attack function, and its character specific attributes
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
        virtual void isIllegalTarget(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target) const = 0;


    public:

        const units_t move_range;
        const Team team; //PHYTON/CPP
        char label; //a character representing character's team (upper / lower) and type
        units_t attackAreaOfEffectRange = 0; //initianalized to zero by default. relevent only to characters with AOE attribute

        // Character constructor. specific character attributes are initialized in their constructor
        Character(units_t health, units_t ammo, units_t range, units_t power, units_t attack_ammo_cost, units_t reload_value, units_t move_range, Team team);

        //defaul destructor
        virtual ~Character() = default;

        //cloning function required for copying a charcter
        virtual Character* clone() const = 0;

        //damgage is subtracted from this characted health. (added if damage is negative)
        void applyDamage(units_t damage);

        //returns true if character health is equal or lower than zero. false otherwise
        bool isCharacterDead() const;

        //attack another character. attack validness is checked before excecuting.
        virtual void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates, std::shared_ptr<Character> target, units_t damage_factor) = 0;

        //add characters reload value to ammo
        void reload();

        //consume ammo depending on attack ammo cost
        void consumeAmmo();
    };  
}

#endif //EX3_CHARACTER_H