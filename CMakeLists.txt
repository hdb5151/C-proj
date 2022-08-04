# CMake 最低的版本要求
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

# 指定模式
# set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(ALL_PROJ
    Cpp_Class
    Thread
)

# 包含头文件目录
include_directories(
    includes/
)
link_directories(
    /opt/percipio/lib
)

set(COMMON_SOURCES src/common/temp.cpp)
add_library(sample_common STATIC ${COMMON_SOURCES})

# 指定生成目标
# add_executable(${PROJECT_NAME} ${DIR_SRCS})
set(USED_3RD_LIB pthread m dl)

# target_link_libraries(${PROJECT_NAME} ${USED_3RD_LIB})
foreach(proj ${ALL_PROJ})
    get_filename_component(spath "src/${proj}" ABSOLUTE)

    if(EXISTS "${spath}/")
        file(GLOB sources src/${proj}/*.cpp)
        add_executable(${proj} ${sources})
        add_dependencies(${proj} sample_common ${TARGET_LIB})
        target_link_libraries(${proj} sample_common ${USED_3RD_LIB})
        set_target_properties(${proj} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
        message("------${CMAKE_BINARY_DIR}-----")

        # install(TARGETS ${proj} RUNTIME DESTINATION samples/)
    endif()
endforeach()

# ############################################################################################################
