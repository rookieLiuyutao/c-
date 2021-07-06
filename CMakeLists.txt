cmake_minimum_required(VERSION 3.19)
project(cppCode)

set(CMAKE_CXX_STANDARD 14)

file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()


add_executable(Acwung282_MergingOfStones Acwung282_MergingOfStones.cpp)
add_executable(ExponentialEnumeration ExponentialEnumeration.cpp)
add_executable(Acwing897_LongestCommonSubsequence  "Acwing897_LongestCommonSubsequence .cpp")
add_executable(Acwing95 Acwing95.cpp)
add_executable(Acwing172 Acwing172.cpp)
add_executable(dijkstraClass dijkstraClass.cpp)
add_executable(FIFO FIFO.cpp)
add_executable(PushTheThreeDimensionalBox PushTheThreeDimensionalBox.cpp)
add_executable(o1Bag o1Bag.cpp)
add_executable(MyAtoi MyAtoi.cpp)
add_executable(lut lut.cpp)
add_executable(LongestAscendingSubsequence LongestAscendingSubsequence.cpp)
add_executable(leetcode957PrisonAfterNDays leetcode957PrisonAfterNDays.cpp)
add_executable(leetcode10 leetcode10.cpp)
add_executable(Acwing482_ChorusFormation Acwing482_ChorusFormation.cpp)
add_executable(Acwing1012_SisterCity Acwing1012_SisterCity.cpp )
add_executable(leetcode15_ThreeSum leetcode15_ThreeSum.cpp)
add_executable(BitOperationTest  "BitOperationTest .cpp")


add_executable(Acwing_3483PowerOfTwo Acwing_3483PowerOfTwo.cpp)
add_executable(Acwing_1225RegularProblem Acwing_1225RegularProblem.cpp)