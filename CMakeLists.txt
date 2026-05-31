cmake_minimum_required(VERSION 3.23)

project(pong_game)

add_executable(main)

target_sources(main
  PRIVATE
    ./src/main.c
)