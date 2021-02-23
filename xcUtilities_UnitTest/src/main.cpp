
#define GTEST_HAS_TR1_TUPLE 0
#define GTEST_USE_OWN_TR1_TUPLE 0
#include <gtest/gtest.h>
#include "xcMath.h"
#include "xcPrerequisitesUtilities.h"


using namespace xcEngineSDK;

int
main(int argc, char** argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


TEST(xcUtilities, Basic_Type_Size) {

   EXPECT_EQ(sizeof(unsigned char), 1U);
   EXPECT_EQ(sizeof(uint8), 1U);
   EXPECT_EQ(sizeof(uint16), 2U);
   EXPECT_EQ(sizeof(uint32), 4U);
   EXPECT_EQ(sizeof(uint64), 8U);

   EXPECT_EQ(sizeof(char), 1);
   EXPECT_EQ(sizeof(int8), 1);
   EXPECT_EQ(sizeof(int16), 2);
   EXPECT_EQ(sizeof(int32), 4);
   EXPECT_EQ(sizeof(int64), 8);

   EXPECT_EQ(sizeof(float), 4);
   EXPECT_EQ(sizeof(double), 8);

   //EXPECT_FLOAT_EQ(Math::PI, 3.141592f);
}


TEST(xcUtilities, Trigonometrics) {

  EXPECT_FLOAT_EQ(Math::cos(0.0f), 1.0f);
  EXPECT_FLOAT_EQ(Math::cos(90.0f), -0.4480f);
}

