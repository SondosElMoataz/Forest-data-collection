
#get_filename_component(PARENT_DIR Tests DIRECTORY)

#include_directories(${PARENT_DIR}/client2)

#file(GLOB_RECURSE SOURCE_FILES client2/*.cpp)

#add_executable(clientFunTesting "clientFunTesting.cpp"
					#C:\Users\HP\source\repos\client2\client2\client2.cpp)
#add_test(NAME clientFunTesting COMMAND clientFunTesting)

cmake_minimum_required (VERSION 3.8)

#target_include_directories( clientFunTesting PRIVATE "../client2/client2.cpp")

#set(SOURCES clientFunTesting.cpp client2/client2.cpp client2/client2.h )

#add_executable(clientFunTesting ${SOURCES})

set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})