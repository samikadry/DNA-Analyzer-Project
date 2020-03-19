cmake_minimum_required(VERSION 3.15)
project(DNA)

set(CMAKE_CXX_STANDARD 98)

add_executable(DNA main.cpp src/Model/DnaSequence.cpp src/Model/DnaSequence.h src/Model/Nucleotides.cpp src/Model/Nucleotides.h src/Model/Codon.cpp src/Model/Codon.h
        src/Model/IndexedDnaSequence.cpp src/Model/IndexedDnaSequence.h src/Controller/Commands.cpp src/Controller/Commands.h src/View/InterfaceCMD.h src/Controller/Controller.cpp src/Controller/Controller.h src/View/Parser.cpp src/View/Parser.h src/View/Print.cpp src/View/Print.h src/Model/DataBase.h)