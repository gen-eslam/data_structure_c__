cmake_minimum_required(VERSION 3.21)
project(data_structure_c__)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structure_c__ main.cpp Vector/Vector.cpp Vector/Vector.h singly_linkend_list/SingleLinkedList.cpp singly_linkend_list/SingleLinkedList.h)
