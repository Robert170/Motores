
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

TEST(xcUtilities, Vector2_Math) {
  Vector2 x(4.0f, 4.0f);
  Vector2 y(2.0f, 2.0f);
  Vector2 z = x + y;

  EXPECT_FLOAT_EQ(z.m_x, 6.0f);
  EXPECT_FLOAT_EQ(z.m_y, 6.0f);

  z = x - y;
  EXPECT_FLOAT_EQ(z.m_x, 2.0f);
  EXPECT_FLOAT_EQ(z.m_y, 2.0f);

  z = x * y;
  EXPECT_FLOAT_EQ(z.m_x, 8.0f);
  EXPECT_FLOAT_EQ(z.m_y, 8.0f);

  z = x / y;
  EXPECT_FLOAT_EQ(z.m_x, 2.0f);
  EXPECT_FLOAT_EQ(z.m_y, 2.0f);

  z = x;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);

  EXPECT_TRUE(z == x);


  z = z + 2;
  EXPECT_FLOAT_EQ(z.m_x, 6.0f);
  EXPECT_FLOAT_EQ(z.m_y, 6.0f);

  z = z - 2;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);

  z = z * 2;
  EXPECT_FLOAT_EQ(z.m_x, 8.0f);
  EXPECT_FLOAT_EQ(z.m_y, 8.0f);

  z = z / 2;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);

  z += x;
  EXPECT_FLOAT_EQ(z.m_x, 8.0f);
  EXPECT_FLOAT_EQ(z.m_y, 8.0f);

  z -= x;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);

  z *= x;
  EXPECT_FLOAT_EQ(z.m_x, 16.0f);
  EXPECT_FLOAT_EQ(z.m_y, 16.0f);

  z /= x;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);
}

TEST(xcUtilities, Vector3_Math) {
  Vector3 x(4.0f, 4.0f, 4.0f);
  Vector3 y(2.0f, 2.0f, 2.0f);
  Vector3 z = x + y;

  EXPECT_FLOAT_EQ(z.m_x, 6.0f);
  EXPECT_FLOAT_EQ(z.m_y, 6.0f);
  EXPECT_FLOAT_EQ(z.m_z, 6.0f);

  z = x - y;
  EXPECT_FLOAT_EQ(z.m_x, 2.0f);
  EXPECT_FLOAT_EQ(z.m_y, 2.0f);
  EXPECT_FLOAT_EQ(z.m_z, 2.0f);

  z = x * y;
  EXPECT_FLOAT_EQ(z.m_x, 8.0f);
  EXPECT_FLOAT_EQ(z.m_y, 8.0f);
  EXPECT_FLOAT_EQ(z.m_z, 8.0f);

  z = x / y;
  EXPECT_FLOAT_EQ(z.m_x, 2.0f);
  EXPECT_FLOAT_EQ(z.m_y, 2.0f);
  EXPECT_FLOAT_EQ(z.m_z, 2.0f);

  z = x;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);
  EXPECT_FLOAT_EQ(z.m_z, 4.0f);

  EXPECT_TRUE(z == x);


  z = z + 2;
  EXPECT_FLOAT_EQ(z.m_x, 6.0f);
  EXPECT_FLOAT_EQ(z.m_y, 6.0f);
  EXPECT_FLOAT_EQ(z.m_z, 6.0f);

  z = z - 2;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);
  EXPECT_FLOAT_EQ(z.m_z, 4.0f);

  z = z * 2;
  EXPECT_FLOAT_EQ(z.m_x, 8.0f);
  EXPECT_FLOAT_EQ(z.m_y, 8.0f);
  EXPECT_FLOAT_EQ(z.m_z, 8.0f);

  z = z / 2;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);
  EXPECT_FLOAT_EQ(z.m_z, 4.0f);

  z += x;
  EXPECT_FLOAT_EQ(z.m_x, 8.0f);
  EXPECT_FLOAT_EQ(z.m_y, 8.0f);
  EXPECT_FLOAT_EQ(z.m_z, 8.0f);

  z -= x;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);
  EXPECT_FLOAT_EQ(z.m_z, 4.0f);

  z *= x;
  EXPECT_FLOAT_EQ(z.m_x, 16.0f);
  EXPECT_FLOAT_EQ(z.m_y, 16.0f);
  EXPECT_FLOAT_EQ(z.m_z, 16.0f);

  z /= x;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);
  EXPECT_FLOAT_EQ(z.m_z, 4.0f);
}

TEST(xcUtilities, Vector4_Math) {
  Vector4 x(4.0f, 4.0f, 4.0f, 4.0f);
  Vector4 y(2.0f, 2.0f, 2.0f, 2.0f);
  Vector4 z = x + y;

  EXPECT_FLOAT_EQ(z.m_x, 6.0f);
  EXPECT_FLOAT_EQ(z.m_y, 6.0f);
  EXPECT_FLOAT_EQ(z.m_z, 6.0f);
  EXPECT_FLOAT_EQ(z.m_w, 6.0f);

  z = x - y;
  EXPECT_FLOAT_EQ(z.m_x, 2.0f);
  EXPECT_FLOAT_EQ(z.m_y, 2.0f);
  EXPECT_FLOAT_EQ(z.m_z, 2.0f);
  EXPECT_FLOAT_EQ(z.m_w, 2.0f);

  z = x * y;
  EXPECT_FLOAT_EQ(z.m_x, 8.0f);
  EXPECT_FLOAT_EQ(z.m_y, 8.0f);
  EXPECT_FLOAT_EQ(z.m_z, 8.0f);
  EXPECT_FLOAT_EQ(z.m_w, 8.0f);

  z = x / y;
  EXPECT_FLOAT_EQ(z.m_x, 2.0f);
  EXPECT_FLOAT_EQ(z.m_y, 2.0f);
  EXPECT_FLOAT_EQ(z.m_z, 2.0f);
  EXPECT_FLOAT_EQ(z.m_w, 2.0f);

  z = x;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);
  EXPECT_FLOAT_EQ(z.m_z, 4.0f);
  EXPECT_FLOAT_EQ(z.m_w, 4.0f);

  EXPECT_TRUE(z == x);


  z = z + 2;
  EXPECT_FLOAT_EQ(z.m_x, 6.0f);
  EXPECT_FLOAT_EQ(z.m_y, 6.0f);
  EXPECT_FLOAT_EQ(z.m_z, 6.0f);
  EXPECT_FLOAT_EQ(z.m_w, 6.0f);

  z = z - 2;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);
  EXPECT_FLOAT_EQ(z.m_z, 4.0f);
  EXPECT_FLOAT_EQ(z.m_w, 4.0f);

  z = z * 2;
  EXPECT_FLOAT_EQ(z.m_x, 8.0f);
  EXPECT_FLOAT_EQ(z.m_y, 8.0f);
  EXPECT_FLOAT_EQ(z.m_z, 8.0f);
  EXPECT_FLOAT_EQ(z.m_w, 8.0f);

  z = z / 2;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);
  EXPECT_FLOAT_EQ(z.m_z, 4.0f);
  EXPECT_FLOAT_EQ(z.m_w, 4.0f);

  z += x;
  EXPECT_FLOAT_EQ(z.m_x, 8.0f);
  EXPECT_FLOAT_EQ(z.m_y, 8.0f);
  EXPECT_FLOAT_EQ(z.m_z, 8.0f);
  EXPECT_FLOAT_EQ(z.m_w, 8.0f);

  z -= x;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);
  EXPECT_FLOAT_EQ(z.m_z, 4.0f);
  EXPECT_FLOAT_EQ(z.m_w, 4.0f);

  z *= x;
  EXPECT_FLOAT_EQ(z.m_x, 16.0f);
  EXPECT_FLOAT_EQ(z.m_y, 16.0f);
  EXPECT_FLOAT_EQ(z.m_z, 16.0f);
  EXPECT_FLOAT_EQ(z.m_w, 16.0f);

  z /= x;
  EXPECT_FLOAT_EQ(z.m_x, 4.0f);
  EXPECT_FLOAT_EQ(z.m_y, 4.0f);
  EXPECT_FLOAT_EQ(z.m_z, 4.0f);
  EXPECT_FLOAT_EQ(z.m_w, 4.0f);
}

TEST(xcUtilities, VectorI2_Math) {
  VectorI2 x(4, 4);
  VectorI2 y(2, 2);
  VectorI2 z = x + y;

  EXPECT_FLOAT_EQ(z.m_x, 6);
  EXPECT_FLOAT_EQ(z.m_y, 6);

  z = x - y;
  EXPECT_FLOAT_EQ(z.m_x, 2);
  EXPECT_FLOAT_EQ(z.m_y, 2);

  z = x * y;
  EXPECT_FLOAT_EQ(z.m_x, 8);
  EXPECT_FLOAT_EQ(z.m_y, 8);

  z = x / y;
  EXPECT_FLOAT_EQ(z.m_x, 2);
  EXPECT_FLOAT_EQ(z.m_y, 2);

  z = x;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);

  EXPECT_TRUE(z == x);


  z = z + 2;
  EXPECT_FLOAT_EQ(z.m_x, 6);
  EXPECT_FLOAT_EQ(z.m_y, 6);

  z = z - 2;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);

  z = z * 2;
  EXPECT_FLOAT_EQ(z.m_x, 8);
  EXPECT_FLOAT_EQ(z.m_y, 8);

  z = z / 2;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);

  z += x;
  EXPECT_FLOAT_EQ(z.m_x, 8);
  EXPECT_FLOAT_EQ(z.m_y, 8);

  z -= x;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);

  z *= x;
  EXPECT_FLOAT_EQ(z.m_x, 16);
  EXPECT_FLOAT_EQ(z.m_y, 16);

  z /= x;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);
}


TEST(xcUtilities, VectorI3_Math) {
  VectorI3 x(4, 4, 4);
  VectorI3 y(2, 2, 2);
  VectorI3 z = x + y;

  EXPECT_FLOAT_EQ(z.m_x, 6);
  EXPECT_FLOAT_EQ(z.m_y, 6);
  EXPECT_FLOAT_EQ(z.m_z, 6);

  z = x - y;
  EXPECT_FLOAT_EQ(z.m_x, 2);
  EXPECT_FLOAT_EQ(z.m_y, 2);
  EXPECT_FLOAT_EQ(z.m_z, 2);

  z = x * y;
  EXPECT_FLOAT_EQ(z.m_x, 8);
  EXPECT_FLOAT_EQ(z.m_y, 8);
  EXPECT_FLOAT_EQ(z.m_z, 8);

  z = x / y;
  EXPECT_FLOAT_EQ(z.m_x, 2);
  EXPECT_FLOAT_EQ(z.m_y, 2);
  EXPECT_FLOAT_EQ(z.m_z, 2);

  z = x;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);
  EXPECT_FLOAT_EQ(z.m_z, 4);

  EXPECT_TRUE(z == x);


  z = z + 2;
  EXPECT_FLOAT_EQ(z.m_x, 6);
  EXPECT_FLOAT_EQ(z.m_y, 6);
  EXPECT_FLOAT_EQ(z.m_z, 6);

  z = z - 2;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);
  EXPECT_FLOAT_EQ(z.m_z, 4);

  z = z * 2;
  EXPECT_FLOAT_EQ(z.m_x, 8);
  EXPECT_FLOAT_EQ(z.m_y, 8);
  EXPECT_FLOAT_EQ(z.m_z, 8);

  z = z / 2;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);
  EXPECT_FLOAT_EQ(z.m_z, 4);

  z += x;
  EXPECT_FLOAT_EQ(z.m_x, 8);
  EXPECT_FLOAT_EQ(z.m_y, 8);
  EXPECT_FLOAT_EQ(z.m_z, 8);

  z -= x;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);
  EXPECT_FLOAT_EQ(z.m_z, 4);

  z *= x;
  EXPECT_FLOAT_EQ(z.m_x, 16);
  EXPECT_FLOAT_EQ(z.m_y, 16);
  EXPECT_FLOAT_EQ(z.m_z, 16);

  z /= x;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);
  EXPECT_FLOAT_EQ(z.m_z, 4);
}

TEST(xcUtilities, VectorI4_Math) {
  VectorI4 x(4, 4, 4, 4);
  VectorI4 y(2, 2, 2, 2);
  VectorI4 z = x + y;

  EXPECT_FLOAT_EQ(z.m_x, 6);
  EXPECT_FLOAT_EQ(z.m_y, 6);
  EXPECT_FLOAT_EQ(z.m_z, 6);
  EXPECT_FLOAT_EQ(z.m_w, 6);

  z = x - y;
  EXPECT_FLOAT_EQ(z.m_x, 2);
  EXPECT_FLOAT_EQ(z.m_y, 2);
  EXPECT_FLOAT_EQ(z.m_z, 2);
  EXPECT_FLOAT_EQ(z.m_w, 2);

  z = x * y;
  EXPECT_FLOAT_EQ(z.m_x, 8);
  EXPECT_FLOAT_EQ(z.m_y, 8);
  EXPECT_FLOAT_EQ(z.m_z, 8);
  EXPECT_FLOAT_EQ(z.m_w, 8);

  z = x / y;
  EXPECT_FLOAT_EQ(z.m_x, 2);
  EXPECT_FLOAT_EQ(z.m_y, 2);
  EXPECT_FLOAT_EQ(z.m_z, 2);
  EXPECT_FLOAT_EQ(z.m_w, 2);

  z = x;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);
  EXPECT_FLOAT_EQ(z.m_z, 4);
  EXPECT_FLOAT_EQ(z.m_w, 4);

  EXPECT_TRUE(z == x);


  z = z + 2;
  EXPECT_FLOAT_EQ(z.m_x, 6);
  EXPECT_FLOAT_EQ(z.m_y, 6);
  EXPECT_FLOAT_EQ(z.m_z, 6);
  EXPECT_FLOAT_EQ(z.m_w, 6);

  z = z - 2;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);
  EXPECT_FLOAT_EQ(z.m_z, 4);
  EXPECT_FLOAT_EQ(z.m_w, 4);

  z = z * 2;
  EXPECT_FLOAT_EQ(z.m_x, 8);
  EXPECT_FLOAT_EQ(z.m_y, 8);
  EXPECT_FLOAT_EQ(z.m_z, 8);
  EXPECT_FLOAT_EQ(z.m_w, 8);

  z = z / 2;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);
  EXPECT_FLOAT_EQ(z.m_z, 4);
  EXPECT_FLOAT_EQ(z.m_w, 4);

  z += x;
  EXPECT_FLOAT_EQ(z.m_x, 8);
  EXPECT_FLOAT_EQ(z.m_y, 8);
  EXPECT_FLOAT_EQ(z.m_z, 8);
  EXPECT_FLOAT_EQ(z.m_w, 8);

  z -= x;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);
  EXPECT_FLOAT_EQ(z.m_z, 4);
  EXPECT_FLOAT_EQ(z.m_w, 4);

  z *= x;
  EXPECT_FLOAT_EQ(z.m_x, 16);
  EXPECT_FLOAT_EQ(z.m_y, 16);
  EXPECT_FLOAT_EQ(z.m_z, 16);
  EXPECT_FLOAT_EQ(z.m_w, 16);

  z /= x;
  EXPECT_FLOAT_EQ(z.m_x, 4);
  EXPECT_FLOAT_EQ(z.m_y, 4);
  EXPECT_FLOAT_EQ(z.m_z, 4);
  EXPECT_FLOAT_EQ(z.m_w, 4);
}