cmake_minimum_required(VERSION 3.19)
project(Biblioteca)

set(CMAKE_CXX_STANDARD 14)

add_executable(Biblioteca main.cpp Informatii.cpp Informatii.h Text.cpp Text.h Numeric.cpp Numeric.h Matematic.cpp Matematic.h Adresa.cpp Adresa.h Biblioteca.cpp Biblioteca.h Client.cpp Client.h)