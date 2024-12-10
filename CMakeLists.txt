project(example)
cmake_minimum_required(VERSION 3.10)
add_compile_options(-g -O3 -march=native -Wall -Wextra -Werror -Werror=pedantic)

file(GLOB_RECURSE vprotoList *.vproto)
foreach(vproto ${vprotoList})
    get_filename_component(vName "${vproto}" NAME_WE)
    get_filename_component(vPath "${vproto}" PATH)
    add_library(${vName} "${vPath}/${vName}.cc" "${vPath}/${vName}.h")

    add_executable("${vName}Parser" "${vPath}/main.cc")
    target_link_libraries("${vName}Parser" PRIVATE ${vName})
endforeach()
