cmake_minimum_required(VERSION 3.10)
project(example LANGUAGES CXX)
add_compile_options(-g -O3 -march=native -Wall -Wextra -Werror -Werror=pedantic)

file(GLOB_RECURSE vprotoList *.vproto)
foreach(vproto ${vprotoList})
    get_filename_component(vName "${vproto}" NAME_WE)
    get_filename_component(vPath "${vproto}" PATH)
    add_library(${vName} "${vPath}/${vName}.cc")

    install(TARGETS ${vName} DESTINATION lib)
    install(FILES ${vPath}/${vName}.h DESTINATION include)

    add_executable("${vName}Parser" "${vPath}/main.cc")
    target_link_libraries("${vName}Parser" PUBLIC ${vName})
endforeach()

add_custom_target(uninstall
    COMMAND cat "${CMAKE_BINARY_DIR}/install_manifest.txt" | xargs rm -vf
    COMMENT "Uninstalling installed files"
)
