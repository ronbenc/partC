#ifndef EX3_EXCEPTION_H
#define EX3_EXCEPTION_H

#include <iostream>
#include "Auxiliaries.h"

namespace mtm
{
    class Exception : public std::exception {};

    class GameException : public Exception
    {
        public:  
            virtual const char* what() const noexcept = 0;
    };   

   //a general exception thrown in case of an illegal argument
    class IllegalArgument : public GameException
    {
       public:
          const char* what() const noexcept;
    };

   // thrown when accessing an illegal cell, cell is not board bound
    class IllegalCell : public GameException
    {
       public:
          const char* what() const noexcept;
    };

   //thrown when attemting to command an empty cell
    class CellEmpty : public GameException
    {
       public:
          const char* what() const noexcept;
    };

   //thrown when character cannot move that far
    class MoveTooFar : public GameException
    {
       public:
          const char* what() const noexcept;
    };

   //thrown when accessing an occupied cell
    class CellOccupied : public GameException
    {
       public:
          const char* what() const noexcept;
    };

   //thrown when taget is not in attacker range limitation
    class OutOfRange : public GameException
    {
       public:
          const char* what() const noexcept;
    };

   //thrown when commanding a character witout sufficient ammo to attack
    class OutOfAmmo : public GameException
    {
       public:
          const char* what() const noexcept;
    };

   //thrown when commanding a character to attack an illegal target
    class IllegalTarget : public GameException
    {
       public:
          const char* what() const noexcept;
    };
}


#endif //EX3_EXCEPTION_H