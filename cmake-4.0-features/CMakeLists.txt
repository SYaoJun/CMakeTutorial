cmake_minimum_required(VERSION 4.0)
project(cmake4_features_demo LANGUAGES CXX)

# C++23 支持示例
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 获取当前消息日志级别 (CMake 4.0+ 新增)
cmake_language(GET_MESSAGE_LOG_LEVEL current_log_level)
message(STATUS "CMake Message Log Level: ${current_log_level}")

# 添加可执行文件
add_executable(cpp23_demo src/main.cpp)

# 使用新的目标属性设置 (CMake 4.0)
target_compile_features(cpp23_demo PRIVATE cxx_std_23)
