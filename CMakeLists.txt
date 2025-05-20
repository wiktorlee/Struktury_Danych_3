cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        Badanie.cpp
        Badanie.hpp
        DaneGenerator.cpp
        DaneGenerator.hpp
        TablicaDynamiczna.cpp
        TablicaDynamiczna.hpp
        ListaJednokierunkowa.cpp
        ListaJednokierunkowa.hpp
        KubelkiJednokierunkowe.cpp
        KubelkiJednokierunkowe.hpp)
