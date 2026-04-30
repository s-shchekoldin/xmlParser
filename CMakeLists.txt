cmake_minimum_required(VERSION 3.10)
project(example LANGUAGES CXX)
include(CTest)
add_compile_options(-g -O3 -march=native -Wall -Wextra -Werror -Werror=pedantic)

file(GLOB_RECURSE vprotoList *.vproto)
foreach(vproto ${vprotoList})
    get_filename_component(vName "${vproto}" NAME_WE)
    get_filename_component(vPath "${vproto}" PATH)
    add_library(${vName} "${vPath}/${vName}.cc")
    target_include_directories(${vName} PUBLIC "${vPath}")

    install(TARGETS ${vName} DESTINATION lib)
    install(FILES ${vPath}/${vName}.h DESTINATION include)

    add_executable("${vName}Parser" "${vPath}/main.cc")
    target_link_libraries("${vName}Parser" PUBLIC ${vName})

    set(testSource "${vPath}/tests/${vName}_behavior_tests.cc")
    if(BUILD_TESTING AND EXISTS "${testSource}")
        add_executable("${vName}BehaviorTests" "${testSource}")
        target_link_libraries("${vName}BehaviorTests" PRIVATE ${vName})
        add_test(NAME "${vName}.behavior" COMMAND "${vName}BehaviorTests")
        set_tests_properties("${vName}.behavior" PROPERTIES WORKING_DIRECTORY "${vPath}")
    endif()
endforeach()

add_custom_target(uninstall
    COMMAND cat "${CMAKE_BINARY_DIR}/install_manifest.txt" | xargs rm -vf
    COMMENT "Uninstalling installed files"
)
