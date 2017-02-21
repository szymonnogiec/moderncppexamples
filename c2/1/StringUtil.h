#ifndef INC_1_STRINGUTIL_H
#define INC_1_STRINGUTIL_H

#include <string>

namespace stringutil
{
    std::string zeroPad (const std::string& word, size_t maxCodeLength)
    {
        auto zerosNeeded = maxCodeLength - word.length();
        return word + std::string (zerosNeeded, '0');
    }

    std::string head (const std::string& word)
    {
        return word.substr(0, 1);
    }

    std::string tail (const std::string& word)
    {
        return word.substr(1);
    }

    std::string upperFront (const std::string& word)
    {
        return std::string (1,
                            std::toupper(static_cast<unsigned char>(word.front())));
    }

}

#endif