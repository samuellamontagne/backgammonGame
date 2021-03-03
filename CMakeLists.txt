cmake_minimum_required(VERSION 3.17)
project(gameCopy)

set(CMAKE_CXX_STANDARD 14)

add_executable(gameCopy src/backgammonGame.cpp  src/Board.h src/Board.cpp src/Case.h src/Case.cpp src/Players.h src/Players.cpp  )