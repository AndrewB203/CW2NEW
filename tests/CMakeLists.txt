cmake_minimum_required(VERSION 3.10)
project(tests) 
 
 # Enable testing
enable_testing()
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/..")
# Add your test files
add_executable(FlyweightTests
    FlyweightTest.cpp
    ConcreteFlyweightTest.cpp
    FlyweightFactoryTest.cpp
    ../Flyweight.cpp  # Включаем исходный файл для Flyweight
)


# Link Google Test to your tests
target_include_directories(FlyweightTests PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../")

target_link_libraries(FlyweightTests gtest gtest_main)

# Add the tests to CTest
add_test(NAME FlyweightTests COMMAND FlyweightTests)
