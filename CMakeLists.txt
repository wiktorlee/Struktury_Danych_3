cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled
        main.cpp
        Badanie.cpp
        TablicaDynamiczna.cpp
        KubelkiJednokierunkowe.cpp
        ListaJednokierunkowa.cpp
        DaneGenerator.cpp
        HashTableAVL.cpp
        AVLTree.cpp
)

