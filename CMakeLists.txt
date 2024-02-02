# cmake最小版本
cmake_minimum_required(VERSION 3.20)

# 项目名称
project(QSTDLIB VERSION 1.0.0 LANGUAGES CXX)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "other")

# 设置调试库的后缀
set(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "add a postfix, usually d on windows")
set(CMAKE_RELEASE_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")
set(CMAKE_RELWITHDEBINFO_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")
set(CMAKE_MINSIZEREL_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")

# 设置当前DEV目录
set(DEV_DIR ${CMAKE_CURRENT_SOURCE_DIR})

if (WIN32)
  # 告诉编译器以utf-8编码
  add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")
  # 设置DEBUG输出目录
  set(DEV_RUNTIME_OUTPUT_DIR_DEBUG ${DEV_DIR}/bin)
  set(DEV_LIBRARY_OUTPUT_DIR_DEBUG ${DEV_DIR}/bin)
  set(DEV_ARCHIVE_OUTPUT_DIR_DEBUG ${DEV_DIR}/bin)
  # 设置RELEASE输出目录
  set(DEV_RUNTIME_OUTPUT_DIR_RELEASE ${DEV_DIR}/bin)
  set(DEV_LIBRARY_OUTPUT_DIR_RELEASE ${DEV_DIR}/bin)
  set(DEV_ARCHIVE_OUTPUT_DIR_RELEASE ${DEV_DIR}/bin)
else(UNIX)
  set(DEV_RUNTIME_OUTPUT_DIR ${DEV_DIR}/bin)
  set(DEV_LIBRARY_OUTPUT_DIR ${DEV_DIR}/bin)
  set(DEV_ARCHIVE_OUTPUT_DIR ${DEV_DIR}/bin)
endif()

add_subdirectory("test")
