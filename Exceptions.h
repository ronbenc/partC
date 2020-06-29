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

    class IllegalArgument : public GameException
    {
       public:
          const char* what() const noexcept;
    };

    class IllegalCell : public GameException
    {
       public:
          const char* what() const noexcept;
    };

    class CellEmpty : public GameException
    {
       public:
          const char* what() const noexcept;
    };

    class MoveTooFar : public GameException
    {
       public:
          const char* what() const noexcept;
    };

    class CellOccupied : public GameException
    {
       public:
          const char* what() const noexcept;
    };

    class OutOfRange : public GameException
    {
       public:
          const char* what() const noexcept;
    };

    class OutOfAmmo : public GameException
    {
       public:
          const char* what() const noexcept;
    };

    class IllegalTarget : public GameException
    {
       public:
          const char* what() const noexcept;
    };
}


#endif //EX3_EXCEPTION_H