# CMake 4.0 新特性示例

## 主要新特性

### 1. C++23 支持
```cmake
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```

### 2. 改进的 FetchContent
- 支持 `FETCHCONTENT_UPDATES_DISCONNECTED` 缓存变量
- 更灵活的依赖管理

### 3. 新的 find_package 改进
- 更好的版本冲突处理
- 改进的包组件支持

### 4. cmake_language 命令增强
```cmake
cmake_language(GET_MESSAGE_LOG_LEVEL log_level)
message(STATUS "Current log level: ${log_level}")
```

### 5. 预设 (Presets) 改进
- 支持 `condition` 字段的更多条件表达式
- 改进的架构/编译器自动检测

## 更多资源
- [CMake 4.0 Release Notes](https://cmake.org/cmake/help/latest/release/4.0.html)
