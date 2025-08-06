cmake_minimum_required(VERSION 3.31)
project(CPP_Design_Pattern)

set(CMAKE_CXX_STANDARD 20)
# ------------------------------------------------------------
# Set variable PROJECT_ROOT as the root directory of the project, we can use it in our source files
add_compile_definitions(PROJECT_ROOT="${CMAKE_SOURCE_DIR}")

# ------------------------------------------------------------
# Using custom_spdlog library for logging
include(FetchContent)
FetchContent_Declare(
        custom_spdlog
        GIT_REPOSITORY https://github.com/raymondtruongdev/custom_spdlog.git
        GIT_TAG master  # or specific version tag
)
FetchContent_MakeAvailable(custom_spdlog)

# Set the log level of 'spdlog' globally to control which log messages are displayed
# + SPDLOG_LEVEL_TRACE
# + SPDLOG_LEVEL_DEBUG
# + SPDLOG_LEVEL_INFO
# + SPDLOG_LEVEL_WARN
# + SPDLOG_LEVEL_ERROR
# + SPDLOG_LEVEL_CRITICAL
# + SPDLOG_LEVEL_OFF
add_compile_definitions(SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE)

# ------------------------------------------------------------
# Define main executable for the project
add_executable(CPP_Design_Pattern main.cpp)

# ------------------------------------------------------------
# Then link with custom_spdlog
target_link_libraries(CPP_Design_Pattern PRIVATE custom_spdlog::custom_spdlog)
