#include <iostream>
#include "floodfill.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

TEST(testFlood, example)
{
    vector<int> a = {1,2,3};
    EXPECT_THAT(a, ElementsAre(1,2,3));	
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}