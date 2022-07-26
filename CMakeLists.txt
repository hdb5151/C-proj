# CMake 最低的版本要求
cmake_minimum_required(VERSION 3.5)

# 定义项目名称变量PROJECT_NAME, 默认值为demo
set(PROJECT_NAME thread)

# 项目名称以及版本
project(${PROJECT_NAME})


########### Configuration ###########
# 设置C++的版本
set(CMAKE_CXX_STANDARD 17)

# 指定模式
# set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
# 包含头文件目录
include_directories(
    includes/
    )

# 当前目录下除了测试文件外所有的源文件的名称保存到 DIR_SRCS 变量
# set(DIR_SRCS deepstream_test_h264_app.c)
file(GLOB DIR_SRCS main.cc "src/*.cpp" "src/*.c")

# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})

set(USED_3RD_LIB  pthread m dl)

target_link_libraries(${PROJECT_NAME} ${USED_3RD_LIB})


#############################################################################################################
