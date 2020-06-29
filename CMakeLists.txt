cmake_minimum_required(VERSION 3.0.0)
project(partC VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(partC test_partC.cpp Auxiliaries.cpp Game.cpp Character.cpp Soldier.cpp Medic.cpp Sniper.cpp Matrix.h Exception.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
