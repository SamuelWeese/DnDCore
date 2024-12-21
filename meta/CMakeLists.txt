cmake_minimum_required(VERSION 3.5)

project(DnDCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DNDCORE_DEPENDENCIES
    combatcharacter.cpp
    dice.cpp
    player.cpp
    weapon.cpp
    item.cpp
    sceneobject.cpp
    damage.cpp
    )

add_executable(DnDCore main.cpp ${DNDCORE_DEPENDENCIES})

target_link_libraries(
 ${PROJECT_NAME}
)

