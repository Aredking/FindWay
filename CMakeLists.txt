cmake_minimum_required(VERSION 4.0.1)
project(FindWay)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SFML_DIR "F:/Program Files (x86)/SFML-3.0.0/lib/cmake/SFML")

# Ищем SFML
find_package(SFML 3 COMPONENTS Graphics REQUIRED)

# Добавление исполняемого файла
add_executable(FindWay
				src/main.cpp
				src/Engine.cpp
				src/Engine.h
				src/Game.cpp
				src/Game.h
				src/Map.cpp
				src/Map.h
				src/SFMLRenderer.cpp
				src/SFMLRenderer.h)

# Связывание с библиотеками SFML
target_link_libraries(FindWay PRIVATE SFML::Graphics)
