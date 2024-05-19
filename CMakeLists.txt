cmake_minimum_required(VERSION 3.10)
project(CW2)
enable_testing()
#option(BUILD_EXAMPLES "Build examples" OFF)
#option(BUILD_TESTS "Build tests" OFF)

# Указываем, что используем C++11
set(CMAKE_CXX_STANDARD 11)

# Добавляем исходные файлы проекта
add_executable(CW2
    Flyweight.cpp
    Flyweight.h
    FlyweightPattern.cpp
)

# Добавляем подкаталог с тестами
add_subdirectory(tests)

add_subdirectory(extern/googletest)

# Подключаем googletest к нашему проекту
target_link_libraries(CW2 gtest gtest_main)
