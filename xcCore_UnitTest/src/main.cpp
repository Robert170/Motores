#define GTEST_HAS_TR1_TUPLE 0
#define GTEST_USE_OWN_TR1_TUPLE 0
#include <gtest/gtest.h>

#include <iostream>
#include <xcPrerequisitesCore.h>
#include "xcGameAppUnitTest.h"

using namespace xcEngineSDK;

GameAppUnitTest g_App;

int32
main() {

  return g_App.run();
}