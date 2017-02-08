#ifndef INC_1_SOUNDEX_H
#define INC_1_SOUNDEX_H

#include <string>

class Soundex
{
public:
	std::string encode (const std::string& word) const
	{
		auto encoded = word.substr(0, 1);
		if (word.length() > 1)
			encoded += "1";

		return zeroPad (encoded);
	}

private:
	std::string head (const std::string& word) const
	{
		return word.substr(0, 1);
	}
	std::string encodedDigits (const std::string& word) const
	{
		if (word.length() > 1)
		{
			return "1";
		}
		return "";
	}
	std::string zeroPad (const std::string& word) const
	{
		auto zerosNeeded = 4 - word.length();
		return word + std::string (zerosNeeded, '0');
	}

};

#endif
