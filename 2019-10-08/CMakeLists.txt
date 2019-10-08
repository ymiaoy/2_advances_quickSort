cmake_minimum_required(VERSION 3.14)
project(2019_10_08)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp SortTestHelper.h MergeSort.h InsertionSort.h QuickSort.h)
add_executable(quick_advance  ${SOURCE_FILES})