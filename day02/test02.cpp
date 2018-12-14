#include "gtest/gtest.h"
#include "day02.h"


TEST(Day02, countLetters) {
	auto counts = aoc2018_02::countLetters("zzaazzbzz");
	EXPECT_EQ(2, counts[0]);
	EXPECT_EQ(6, counts['z'-'a']);
	EXPECT_EQ(0, counts[3]);
	EXPECT_EQ(1, counts[1]);
}

TEST(Day02, Day02_A_1) {
	std::istringstream ss(
		"abcdef\n"
		"bababc\n"
		"abbcde\n"
		"abcccd\n"
		"aabcdd\n"
		"abcdee\n"
		"ababab\n");
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(12, aoc2018_02::checksum(input));
}

TEST(Day02, checkIfOffByOne) {
	EXPECT_TRUE(aoc2018_02::checkIfOffByOne("aaaa", "aaab"));
	EXPECT_TRUE(aoc2018_02::checkIfOffByOne("aaba", "aaaa"));
	EXPECT_FALSE(aoc2018_02::checkIfOffByOne("aaaa", "bbbb"));
	EXPECT_FALSE(aoc2018_02::checkIfOffByOne("aaaa", "bbb"));
	EXPECT_FALSE(aoc2018_02::checkIfOffByOne("aaaa", "aaaa"));
}
TEST(Day02, removeMismatchLetter) {
	EXPECT_EQ("abcde", aoc2018_02::removeMismatchLetter("abcXde", "abcYde"));
	EXPECT_EQ("abcde", aoc2018_02::removeMismatchLetter("Xabcde", "Yabcde"));
	EXPECT_EQ("abcde", aoc2018_02::removeMismatchLetter("abcdeX", "abcdeY"));
}
TEST(Day02, Day02_B_1) {
	std::istringstream ss(
		"abcde\n"
		"fghij\n"
		"klmno\n"
		"pqrst\n"
		"fguij\n"
		"axcye\n"
		"wvxyz\n");
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ("fgij", aoc2018_02::find_boxes(input));
}