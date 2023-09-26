# CMakeList.txt : projet CMake pour selection_sort, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

# Ajoutez une source à l'exécutable de ce projet.
add_executable (selection_sort "selection_sort.cpp" "selection_sort.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET selection_sort PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
