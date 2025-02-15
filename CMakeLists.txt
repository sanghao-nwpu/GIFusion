cmake_minimum_required(VERSION 3.14)
project(GIFusion LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找Eigen库
find_package(Eigen3 REQUIRED)
message(STATUS "Found Eigen3: ${EIGEN3_INCLUDE_DIR}")

# 查找yaml-cpp库
find_package(yaml-cpp REQUIRED)
message(STATUS "Found yaml-cpp: ${YAML_CPP_INCLUDE_DIR}")

# 库的源码
add_library(GIFusion
    src/FusionCore.cpp
    src/ConfigParser.cpp
    src/FusionInterfaceImpl.cpp
)

# 包含目录
target_include_directories(GIFusion
    PUBLIC include
    PRIVATE src/internal
)

# 链接依赖
target_link_libraries(GIFusion
    PUBLIC Eigen3::Eigen
    PUBLIC yaml-cpp
)

# 安装规则
install(TARGETS GIFusion DESTINATION lib)
install(DIRECTORY include/GIFusion DESTINATION include)

# Demo示例
add_executable(demo_2d examples/demo_2d.cpp)
target_link_libraries(demo_2d GIFusion)

add_executable(demo_3d examples/demo_3d.cpp)
target_link_libraries(demo_3d GIFusion)