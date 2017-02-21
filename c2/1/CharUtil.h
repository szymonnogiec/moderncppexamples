#ifndef INC_1_CHARUTIL_H
#define INC_1_CHARUTIL_H

#include <string>

namespace charutil
{
    char lower (char c)
    {
        return std::tolower (static_cast<unsigned char>(c));
    }

    bool isVowel (char letter)
    {
        return std::string ("aeiouy").find (charutil::lower (letter)) != std::string::npos;
    }

}

#endif