cmake_minimum_required(VERSION 3.5.1)
project(pissues)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find needed packages
find_package(Boost COMPONENTS system thread REQUIRED)
  
# Header directory
include_directories(include)

# Source directory
file(GLOB SOURCES "src/*.cpp")

# Set the executable target
add_executable(pissues ${SOURCES})

# Link target libraries
target_link_libraries(pissues ${PROJECT_LINK_LIBS} pthread)

# Install the library in the project /lib location
install(TARGETS pissues DESTINATION ${PROJECT_SOURCE_DIR}/bin )
