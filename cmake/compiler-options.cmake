cmake_minimum_required(VERSION 3.18)
if(${CMAKE_VERSION} VERSION_LESS 3.18)
cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
cmake_policy(VERSION 3.18)
endif()

include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG("-std=c++23" COMPILER_SUPPORTS_CXX23)
CHECK_CXX_COMPILER_FLAG("-std=c++20" COMPILER_SUPPORTS_CXX20)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX23)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")
elseif(COMPILER_SUPPORTS_CXX23)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
elseif(COMPILER_SUPPORTS_CXX20)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif(COMPILER_SUPPORTS_CXX14)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
elseif(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

#########################
# --- Build Options --- #
#########################

option(USE_FEATURE_TEST "Use Feature Test library" OFF)
if (USE_FEATURE_TEST)
  add_definitions(-DUSE_FEATURE_TEST)
endif()

option(USE_SSL_METHOD	    "Use Https/SSL system"      OFF)
if (USE_SSL_METHOD)
  add_definitions(-DUSE_SSL_METHOD)
endif()

option(ENABLE_TESTING	    "Use test mode" FALSE)
if (ENABLE_TESTING)
  add_definitions(-DENABLE_TESTING)
endif()

option(ENABLE_CLANG_TIDY    "Enabling the test of clang-tidy"  FALSE)
if (ENABLE_CLANG_TIDY)
  add_definitions(-DENABLE_CLANG_TIDY)
endif()


option(ENABLE_CPPCHECK	    "Enabling the test of cppcheck"  FALSE)
if (ENABLE_CPPCHECK)
  add_definitions(-DENABLE_CPPCHECK)
endif()


option(SIMPLE_BUILD	    "Build the project as minimally as possible" FALSE)
if (SIMPLE_BUILD)
  add_definitions(-DSIMPLE_BUILD)
endif()

option(ENABLE_ASAN	    "Enable address sanitizer"  FALSE)
if (ENABLE_ASAN)
  add_definitions(-DENABLE_ASAN)
endif()

option(BUILD_DOC	    "Build the project's documentation"  OFF)
if (BUILD_DOC)
  add_definitions(-DBUILD_DOC)
endif()


option(FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)."  TRUE)
if (FORCE_COLORED_OUTPUT)
  add_definitions(-DFORCE_COLORED_OUTPUT)
endif()


option(ENABLE_SAFE_ONLY	    "Enabling the build of safe codes only!"  FALSE)
if (ENABLE_SAFE_ONLY)
  add_definitions(-DENABLE_SAFE_ONLY)
  SET (CMAKE_CXX_FLAGS "-Werror")
endif()

option(ENABLE_WARN_MODE	    "Enabling the build of safe codes only!"  FALSE)
if (ENABLE_WARN_MODE)
  add_definitions(-DENABLE_WARN_MODE)
  SET (CMAKE_CXX_FLAGS "-Wall")
endif()

option(BUILD_DEBUG_MODE "Enable developer (debug) mode" ON)
if (BUILD_DEBUG_MODE)
  add_definitions(-DBUILD_DEBUG_MODE)
endif()

option(DEBUG_LOGGING	    "Enabling the build of debug logging" FALSE)
if (DEBUG_LOGGING)
  add_definitions(-DDEBUG_LOGGING)
endif()


option(ENABLE_STATIC_LIB_BUILD "Build Static Version" OFF)
if (ENABLE_STATIC_LIB_BUILD)
  add_definitions(-DENABLE_STATIC_LIB_BUILD)
endif()


option(ENABLE_SHARED_LIB_BUILD "Build Shared Version" OFF)
if (ENABLE_SHARED_LIB_BUILD)
  add_definitions(-DENABLE_SHARED_LIB_BUILD)
endif()

option(ENABLE_BINARY_BUILD "Build Executable Version" ON)
if (ENABLE_BINARY_BUILD)
  add_definitions(-DENABLE_BINARY_BUILD)
endif()

option(ENABLE_HEADER_ONLY_BUILD "Header Only Version" OFF)
if (ENABLE_HEADER_ONLY_BUILD)
  add_definitions(-DENABLE_HEADER_ONLY_BUILD)
endif()

option(FORCE_LATEST_STANDARD_FEATURE "Forcing to enable updated programming language." FALSE)
if (FORCE_LATEST_STANDARD_FEATURE)
  add_definitions(-DFORCE_LATEST_STANDARD_FEATURE)
endif()

##################################
# --- Installation Variables --- #
##################################

set(DIST_PATH ${PROJECT_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DIST_PATH}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DIST_PATH}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${DIST_PATH}/lib)

