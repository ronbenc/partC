#include "Exceptions.h"
#include <typeinfo>

namespace mtm
{
    const char* GameException::what() const noexcept
    {
        std::string strGameError= "A game related error has occurred: " ;
        strGameError+=(typeid(*this).name());

        std::cout<<(typeid(*this).name())<<std::endl;

        return strGameError.std::string::c_str();
    }
}