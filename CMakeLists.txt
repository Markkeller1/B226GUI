cmake_minimum_required(VERSION 3.17)
project(greenhouse-sim)

set(BUILD_SHARED_LIBS FALSE CACHE BOOL "Setting SFML to build static libraries" FORCE)
set(SFML_USE_STATIC_STD_LIBS TRUE CACHE BOOL "Use static versions of the C++ std libs" FORCE)
add_subdirectory(libs/SFML)

set(IMGUI_SFML_FIND_SFML OFF CACHE BOOL "Do not use find_package to find SFML." FORCE)
set(IMGUI_DIR ${PROJECT_SOURCE_DIR}/libs/imgui CACHE PATH "imgui top-level directory." FORCE)
set(IMGUI_SFML_IMGUI_DEMO ON CACHE BOOL "make the demo window" FORCE)

add_subdirectory(libs/imgui-sfml)

add_executable(greenhouse-sim src/greenhouse-sim.cpp)
add_dependencies(greenhouse-sim sfml-graphics ImGui-SFML)
target_include_directories(greenhouse-sim PUBLIC libs/SFML/include)
target_link_libraries(greenhouse-sim sfml-graphics ImGui-SFML)

add_executable(imgui-example src/imgui-example.cpp)
add_dependencies(imgui-example sfml-graphics ImGui-SFML)
target_include_directories(imgui-example PUBLIC libs/SFML/include libs/imgui libs/imgui-sfml)
target_link_libraries(imgui-example sfml-graphics sfml-system sfml-window ImGui-SFML)

add_executable(imgui-example2 src/imgui-example2.cpp)
add_dependencies(imgui-example2 sfml-graphics ImGui-SFML)
target_include_directories(imgui-example2 PUBLIC libs/SFML/include libs/imgui libs/imgui-sfml)
target_link_libraries(imgui-example2 sfml-graphics sfml-system sfml-window ImGui-SFML)

add_executable(mini-project src/mini-project.cpp)
add_dependencies(mini-project sfml-graphics ImGui-SFML)
target_include_directories(mini-project PUBLIC libs/SFML/include libs/imgui libs/imgui-sfml libs/headers)
target_link_libraries(mini-project sfml-graphics ImGui-SFML)

add_executable(RPG-UI src/RPG-UI.cpp)
add_dependencies(RPG-UI sfml-graphics ImGui-SFML)
target_include_directories(RPG-UI PUBLIC libs/SFML/include libs/imgui libs/imgui-sfml libs/headers)
target_link_libraries(RPG-UI sfml-graphics ImGui-SFML)

add_executable(Dummyphone-UI src/Dummyphone-UI.cpp)
add_dependencies(Dummyphone-UI sfml-graphics ImGui-SFML)
target_include_directories(Dummyphone-UI PUBLIC libs/SFML/include libs/imgui libs/imgui-sfml libs/headers)
target_link_libraries(Dummyphone-UI sfml-graphics ImGui-SFML)

add_executable(Dummyphone-UI2 src/Dummyphone-UI2.cpp)
add_dependencies(Dummyphone-UI2 sfml-graphics ImGui-SFML)
target_include_directories(Dummyphone-UI2 PUBLIC libs/SFML/include libs/imgui libs/imgui-sfml libs/headers)
target_link_libraries(Dummyphone-UI2 sfml-graphics ImGui-SFML)