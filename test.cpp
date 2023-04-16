#include <iostream>
#include "floodfill.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

TEST(testFlood, onBounds)
{
    vector<string> a = {
        "*****",
        "*   *",
        "*   *",
        "*   *",
        "*****"
        };
    floodFill(a, make_pair(1,1));
    EXPECT_THAT(a, ElementsAre(
        "*****",
        "*   *",
        "*   *",
        "*   *",
        "*****"
        ));	
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}