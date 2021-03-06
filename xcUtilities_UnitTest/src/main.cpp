
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
#include "xcMatrix3x3.h"
#include "xcMatrix4x4.h"
#include "xcDegrees.h"
#include "xcRadians.h"
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

   EXPECT_NEAR(Math::PI, 3.141592f, Math::SMALL_NUMBER);
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
  EXPECT_FLOAT_EQ(Math::log(1.0f), 0.0f);
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
}


TEST(xcUtilities, Matrix3x3_Math) {
  
  Matrix3x3 A(1.0f, 4.0f, 7.0f,
              2.0f, 5.0f, 8.0f,
              3.0f, 6.0f, 9.0f);
                     
  Matrix3x3 B(1.0f, 4.0f, 7.0f,
              2.0f, 5.0f, 8.0f,
              3.0f, 6.0f, 9.0f);

  EXPECT_TRUE(A == B);

  Matrix3x3 C = A + B;

  EXPECT_FLOAT_EQ(C.m_matrix[0].m_x, 2.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_y, 4.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_z, 6.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_x, 8.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_y, 10.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_z, 12.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_x, 14.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_y, 16.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_z, 18.0f);

  C = A - B;
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_x, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_y, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_z, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_x, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_y, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_z, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_x, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_y, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_z, 0.0f);

  C = A;
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_x, 1.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_y, 2.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_z, 3.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_x, 4.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_y, 5.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_z, 6.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_x, 7.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_y, 8.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_z, 9.0f);

  C += A;
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_x, 2.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_y, 4.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_z, 6.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_x, 8.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_y, 10.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_z, 12.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_x, 14.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_y, 16.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_z, 18.0f);

  C -= A;
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_x, 1.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_y, 2.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_z, 3.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_x, 4.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_y, 5.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_z, 6.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_x, 7.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_y, 8.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_z, 9.0f);

  C = A * B;
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_x, 30.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_y, 36.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_z, 42.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_x, 66.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_y, 81.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_z, 96.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_x, 102.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_y, 126.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_z, 150.0f);



}

TEST(xcUtilities, Matrix4x4_Math) {

  Matrix4x4 A(1.0f, 5.0f, 9.0f, 13.0f,
              2.0f, 6.0f, 10.0f, 14.0f,
              3.0f, 7.0f, 11.0f, 15.0f,
              4.0f, 8.0f, 12.0f, 16.0f);
   
  Matrix4x4 B(1.0f, 5.0f, 9.0f, 13.0f,
              2.0f, 6.0f, 10.0f, 14.0f,
              3.0f, 7.0f, 11.0f, 15.0f,
              4.0f, 8.0f, 12.0f, 16.0f);

  EXPECT_TRUE(A == B);

  Matrix4x4 C = A + B;

  EXPECT_FLOAT_EQ(C.m_matrix[0].m_x, 2.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_y, 4.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_z, 6.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_w, 8.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_x, 10.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_y, 12.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_z, 14.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_w, 16.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_x, 18.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_y, 20.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_z, 22.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_w, 24.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_x, 26.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_y, 28.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_z, 30.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_w, 32.0f);

  C = A - B;
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_x, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_y, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_z, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_w, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_x, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_y, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_z, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_w, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_x, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_y, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_z, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_w, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_x, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_y, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_z, 0.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_w, 0.0f);

  C = A;
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_x, 1.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_y, 2.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_z, 3.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_w, 4.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_x, 5.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_y, 6.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_z, 7.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_w, 8.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_x, 9.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_y, 10.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_z, 11.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_w, 12.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_x, 13.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_y, 14.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_z, 15.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_w, 16.0f);

  C += A;
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_x, 2.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_y, 4.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_z, 6.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_w, 8.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_x, 10.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_y, 12.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_z, 14.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_w, 16.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_x, 18.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_y, 20.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_z, 22.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_w, 24.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_x, 26.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_y, 28.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_z, 30.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_w, 32.0f);

  C -= A;
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_x, 1.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_y, 2.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_z, 3.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_w, 4.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_x, 5.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_y, 6.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_z, 7.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_w, 8.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_x, 9.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_y, 10.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_z, 11.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_w, 12.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_x, 13.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_y, 14.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_z, 15.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_w, 16.0f);
  
  C = A * B;
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_x, 90.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_y, 100.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_z, 110.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[0].m_w, 120.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_x, 202.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_y, 228.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_z, 254.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[1].m_w, 280.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_x, 314.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_y, 356.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_z, 398.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[2].m_w, 440.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_x, 426.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_y, 484.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_z, 542.0f);
  EXPECT_FLOAT_EQ(C.m_matrix[3].m_w, 600.0f);
}


TEST(xcUtilities, Degrees_Math) {

  Degrees D = 10.0f;
  Degrees D2 = 20.0f;
 
  Degrees D3 = D + D2;

  
  //EXPECT_NEAR(D3.getDegreesIntoRadians(), 30.0f * Math::DEG2RAD, Math::SMALL_NUMBER);
  //EXPECT_FLOAT_EQ(D3.getDegreesIntoRadians(), 0.523599f);
  EXPECT_FLOAT_EQ(D3.getDegrees(), 30.0f);

  D3 = D - D2;
  EXPECT_FLOAT_EQ(D3.getDegrees(), -10.0f);

  D3 = D * D2;
  EXPECT_FLOAT_EQ(D3.getDegrees(), 200.0f);

  D3 = D / D2;
  EXPECT_FLOAT_EQ(D3.getDegrees(), 0.5f);


}