cmake_minimum_required(VERSION 3.7)
project(urna)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Sessao.cpp Sessao.h Arquivo.cpp Arquivo.h Secretaria.cpp Secretaria.h Candidato.cpp Candidato.h)
add_executable(urna ${SOURCE_FILES})
