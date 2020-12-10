

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    tests/test.cpp
    src/FileIO.cpp
    src/Event.cpp
)

ADD_EXECUTABLE(main
	main.cpp
    src/FileIO.cpp
    src/Event.cpp
)
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)


