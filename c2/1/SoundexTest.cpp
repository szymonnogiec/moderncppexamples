#include "gmock/gmock.h"
#include "Soundex.h"

using testing::Eq;

class SoundexEncoding : public testing::Test
{
public:
	Soundex soundex;
};

TEST_F(SoundexEncoding, RetainSoleLetterOfOneLetterWord)
{
	ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}
TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
	ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}
TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropiateDigits)
{
    ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}
TEST_F(SoundexEncoding, IgnoresNonAlphabetics)
{
    ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}
TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits)
{
    ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}
TEST_F(SoundexEncoding, LimitsLengthToFourCharacters)
{
    ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}
TEST_F(SoundexEncoding, IgnoresVowelLikeLetters)
{
    ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHyYcdl"), Eq("B234"));
}
TEST_F(SoundexEncoding, CombinesDuplicateEncoding)
{
    ASSERT_THAT(soundex.encodedDigit('b'), Eq(soundex.encodedDigit('f')));
    ASSERT_THAT(soundex.encodedDigit('c'), Eq(soundex.encodedDigit('g')));
    ASSERT_THAT(soundex.encodedDigit('d'), Eq(soundex.encodedDigit('t')));

    ASSERT_THAT(soundex.encode("Abfcgt"), Eq("A123"));
}
TEST_F(SoundexEncoding, UppercasesFirstLetter)
{
    ASSERT_THAT(soundex.encode("abcd"), testing::StartsWith("A"));
}
TEST_F(SoundexEncoding, IgnoresCaseWhenEncodingConsonants)
{
    ASSERT_THAT(soundex.encode("BCDL"), Eq(soundex.encode("Bcdl")));
}