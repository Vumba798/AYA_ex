# CMakeList.txt: проект CMake для ekz; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (ekz "ekz.cpp" "dot.h" "dot.cpp" "except.cpp" "except.h" "dot_space.h" "dot_space.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
