cmake_minimum_required(VERSION 3.10)
project(example LANGUAGES CXX)
include(CTest)

set(XML_PGO_MODE "OFF" CACHE STRING "PGO mode for xml targets: OFF, GENERATE, or USE")
set_property(CACHE XML_PGO_MODE PROPERTY STRINGS OFF GENERATE USE)
set(XML_PGO_DIR "${CMAKE_BINARY_DIR}/pgo" CACHE PATH "Directory used for GCC PGO profile data")
string(TOUPPER "${XML_PGO_MODE}" XML_PGO_MODE)

if(NOT XML_PGO_MODE MATCHES "^(OFF|GENERATE|USE)$")
    message(FATAL_ERROR "XML_PGO_MODE must be OFF, GENERATE, or USE")
endif()

add_compile_options(-g -O3 -march=native -Wall -Wextra -Werror -Werror=pedantic)

function(apply_xml_pgo target)
    if(XML_PGO_MODE STREQUAL "OFF")
        return()
    endif()

    if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        message(FATAL_ERROR "XML_PGO_MODE requires GNU C++ because it uses GCC-style profile flags")
    endif()

    if(XML_PGO_MODE STREQUAL "GENERATE")
        target_compile_options(${target} PRIVATE "-fprofile-generate=${XML_PGO_DIR}")
        target_link_libraries(${target} PRIVATE "-fprofile-generate=${XML_PGO_DIR}")
    elseif(XML_PGO_MODE STREQUAL "USE")
        target_compile_options(${target} PRIVATE "-fprofile-use=${XML_PGO_DIR}" -fprofile-correction -Wno-error=missing-profile)
        target_link_libraries(${target} PRIVATE "-fprofile-use=${XML_PGO_DIR}" -fprofile-correction)
    endif()
endfunction()

file(GLOB_RECURSE vprotoList *.vproto)
foreach(vproto ${vprotoList})
    get_filename_component(vName "${vproto}" NAME_WE)
    get_filename_component(vPath "${vproto}" PATH)
    add_library(${vName} "${vPath}/${vName}.cc")
    target_include_directories(${vName} PUBLIC "${vPath}")
    apply_xml_pgo(${vName})

    install(TARGETS ${vName} DESTINATION lib)
    install(FILES ${vPath}/${vName}.h DESTINATION include)

    add_executable("${vName}Parser" "${vPath}/main.cc")
    target_link_libraries("${vName}Parser" PUBLIC ${vName})
    apply_xml_pgo("${vName}Parser")

    set(benchSource "${vPath}/${vName}_bench.cc")
    if(EXISTS "${benchSource}")
        add_executable("${vName}Benchmark" "${benchSource}")
        target_link_libraries("${vName}Benchmark" PRIVATE ${vName})
        apply_xml_pgo("${vName}Benchmark")
    endif()

    set(testSource "${vPath}/tests/${vName}_behavior_tests.cc")
    if(BUILD_TESTING AND EXISTS "${testSource}")
        add_executable("${vName}BehaviorTests" "${testSource}")
        target_link_libraries("${vName}BehaviorTests" PRIVATE ${vName})
        apply_xml_pgo("${vName}BehaviorTests")
        add_test(NAME "${vName}.behavior" COMMAND "${vName}BehaviorTests")
        set_tests_properties("${vName}.behavior" PROPERTIES WORKING_DIRECTORY "${vPath}")
    endif()
endforeach()

add_custom_target(uninstall
    COMMAND cat "${CMAKE_BINARY_DIR}/install_manifest.txt" | xargs rm -vf
    COMMENT "Uninstalling installed files"
)
