
#define GTEST_HAS_TR1_TUPLE 0
#define GTEST_USE_OWN_TR1_TUPLE 0
#include <gtest/gtest.h>
#include "xcMath.h"
#include "xcVector2.h"
#include "xcVectorI2.h"
#include "xcVector3.h"
#include "xcVectorI3.h"
#include "xcVector4.h"
#include "xcVectorI4.h"
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

  EXPECT_FLOAT_EQ(Math::sin(0.f), 0.0f);
  EXPECT_FLOAT_EQ(Math::cos(0.f), 1.0f);
  EXPECT_FLOAT_EQ(Math::tan(0.f), 0.0f);
 
}


TEST(xcUtilities, Math_Basic) {

  EXPECT_FLOAT_EQ(Math::sqrt(9.0f), 3.0f);
  EXPECT_FLOAT_EQ(Math::pow(2.0f,2), 4.0f);
  EXPECT_FLOAT_EQ(Math::abs(-1.0f), 1.0f);
}

TEST(xcUtilities, Vectors_Math) {
  Vector2 x(1, 1);
  Vector2 y(1, 1);
  Vector2 z(2, 2);

  EXPECT_FLOAT_EQ(x + y, z);

}
