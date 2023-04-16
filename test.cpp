#include <iostream>
#include "floodfill.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

TEST(testFlood, outOfBounds)
{
    vector<string> testVec = {
        "*****",
        "*   *",
        "*   *",
        "*   *",
        "*****"
        };
    try
    {
        floodFill(testVec, make_pair(7,8));
    }
    catch(const char* e)
    {
        EXPECT_STREQ("Punkts arpus robezam", e);
    }
}

TEST(testFlood, onBounds)
{
    vector<string> testVec = {
        "*****",
        "*   *",
        "*   *",
        "*   *",
        "*****"
        };
    floodFill(testVec, make_pair(1,1));
    EXPECT_THAT(testVec, ElementsAre(
        "*****",
        "*   *",
        "*   *",
        "*   *",
        "*****"
        ));	
}

TEST(testFlood, inBounds)
{
    vector<string> testVec = {
        "*****",
        "*   *",
        "*   *",
        "*   *",
        "*****"
        };
    floodFill(testVec, make_pair(3,3));
    EXPECT_THAT(testVec, ElementsAre(
        "*****",
        "*###*",
        "*###*",
        "*###*",
        "*****"
        ));	
}

TEST(testFlood, fillLeft)
{
    vector<string> testVec = {
        "****",
        "*  *",
        "****"
        };
    floodFill(testVec, make_pair(2,2));
    EXPECT_THAT(testVec, ElementsAre(
        "****",
        "*##*",
        "****"
        ));	
}

TEST(testFlood, fillRight)
{
    vector<string> testVec = {
        "****",
        "*  *",
        "****"
        };
    floodFill(testVec, make_pair(3,2));
    EXPECT_THAT(testVec, ElementsAre(
        "****",
        "*##*",
        "****"
        ));	
}

TEST(testFlood, fillDown)
{
    vector<string> testVec = {
        "***",
        "* *",
        "* *"
        "***"
        };
    floodFill(testVec, make_pair(2,2));
    EXPECT_THAT(testVec, ElementsAre(
        "***",
        "*#*",
        "*#*"
        "***"
        ));	
}

TEST(testFlood, fillUp)
{
    vector<string> testVec = {
        "***",
        "* *",
        "* *"
        "***"
        };
    floodFill(testVec, make_pair(2,3));
    EXPECT_THAT(testVec, ElementsAre(
        "***",
        "*#*",
        "*#*"
        "***"
        ));	
}


int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}