#include "Exceptions.h"

namespace mtm
{
    const char* GameException::what() const noexcept
    {
        std::string strGameError= "A game related error has occurred: " ;
        strGameError+=(typeid(*this).name());

        std::cout<<strGameError<<std::endl;

        return strGameError.std::string::c_str();
    }
}