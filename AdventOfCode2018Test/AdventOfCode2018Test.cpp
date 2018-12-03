#include "gtest/gtest.h"
#include "../common/inputReader.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TokenizerTest, OneToken)
{
	std::string s("Test");
	auto tokens = aoc2018::Tokenize(s);
	ASSERT_EQ(1, tokens.size());
	EXPECT_EQ("Test", tokens[0]);
}
TEST(TokenizerTest, TwoTokens)
{
	std::string s("Test this");
	auto tokens = aoc2018::Tokenize(s);
	ASSERT_EQ(2, tokens.size());
	EXPECT_EQ("this", tokens[1]);
}

TEST(ReadInputTest, ReadInputOneLine)
{
	std::istringstream	iss("This is a Test");
	auto result = aoc2018::ReadInput(iss);
	ASSERT_EQ(1, result.size());
	ASSERT_EQ(4, result[0].size());
	EXPECT_EQ("This", result[0][0]);
	EXPECT_EQ("a", result[0][2]);
	EXPECT_EQ("Test", result[0][3]);
}
TEST(ReadInputTest, ReadInputTwoLine)
{
	std::istringstream	iss("This is a Test\r\nAnd now line 2");
	auto result = aoc2018::ReadInput(iss);
	ASSERT_EQ(2, result.size());
	ASSERT_EQ(4, result[1].size());
	EXPECT_EQ("And", result[1][0]);
	EXPECT_EQ("2", result[1][3]);
}
TEST(ReadInputTest, ReadInputOneLineWithLineBreak)
{
	std::istringstream	iss("This is a Test\r\n");
	auto result = aoc2018::ReadInput(iss);
	ASSERT_EQ(1, result.size());
}

TEST(OpenInputFile, OpenFileAndRead)
{
	auto file = aoc2018::OpenInputFile("test.txt");
	auto result = aoc2018::ReadInput(*file);
	ASSERT_EQ(2, result.size());
	ASSERT_EQ(4, result[1].size());
	EXPECT_EQ("And", result[1][0]);
	EXPECT_EQ("2", result[1][3]);
}