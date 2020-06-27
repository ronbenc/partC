#ifndef EX3_EXCEPTION_H
#define EX3_EXCEPTION_H

#include <iostream>
#include "Auxiliaries.h"

namespace mtm
{
    //class Exception : public std::exception {}; //already in Auxiliaries.h

    class GameException : public Exception
    {
        public:
        const char* what() const noexcept;
    };   

    class IllegalArgument : public GameException {};

    class IllegalCell : public GameException {}; 

    class CellEmpty : public GameException {};

    class MoveToFar : public GameException {};

    class CellOccupied : public GameException {};

    class OutOfRange : public GameException {};

    class OutOfAmmo : public GameException {};

    class IllegalTarget : public GameException {};


    

    

}


#endif //EX3_EXCEPTION_H