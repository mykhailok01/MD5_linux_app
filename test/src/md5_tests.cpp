//
// Created by Konstantin Gredeskoul on 5/16/17.
//
#include <MD5.hpp>
#include "gtest/gtest.h"
#include <string>

class MD5Test : public ::testing::Test
{
protected:
    void SetUp() override { };
    void TearDown() override { };
};

TEST_F(MD5Test, Empty)
{
    EXPECT_EQ(toString(generateMD5Hash("")), "D41D8CD98F00B204E9800998ECF8427E");
}

TEST_F(MD5Test, 1char)
{
    EXPECT_EQ(toString(generateMD5Hash("a")), "0CC175B9C0F1B6A831C399E269772661");
}

TEST_F(MD5Test, 3_Chars)
{
    EXPECT_EQ(toString(generateMD5Hash("abc")), "900150983CD24FB0D6963F7D28E17F72");
}

TEST_F(MD5Test, WithSpace)
{
    EXPECT_EQ(toString(generateMD5Hash("message digest")), "F96B697D7CB7938D525A2F31AAF161D0");
}

