cmake_minimum_required(VERSION 3.10)
project(gh_code)

set(CMAKE_CXX_STANDARD 14)

add_executable(gh_code main.cpp ghlib/gh.cpp ghlib/gh.h SwordToOffer/Interview.cpp SwordToOffer/Interview.h)