#include "gtest/gtest.h"
//#include "time_tests.h"
//#include "event_tests.h"
//include other tests here
#include "../header/Event.hpp"
#include "FileIOTest.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



