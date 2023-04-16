#include <iostream>
#include "floodfill.h"
#include "gtest/gtest.h"

using namespace std;

TEST(testFlood, example)
{
    EXPECT_EQ(1000, 1000);	
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}