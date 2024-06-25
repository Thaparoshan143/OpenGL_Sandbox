cmake_minimum_required(VERSION 3.13)

set (CMAKE_CXX_STANDARD 11)

project(SANDBOX)
file(GLOB SOURCES "./Platform/OpenGL/*.cpp")
file(GLOB SOURCES "./Platform/OpenGL/*.cpp")
add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/Sandbox/main.cpp ${CMAKE_SOURCE_DIR}/Sandbox/glad.cpp ${SOURCES})

# linkers directories for win
if (WIN32)
    target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lib/win/)
    target_link_libraries(${PROJECT_NAME} libfreetype.dll.a libglfw3dll.a)
endif (WIN32)

# linkers directories for apple
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lib/mac/)
    target_link_libraries(${PROJECT_NAME} libfreetype.6.dylib libglfw.3.3.dylib)
endif()

include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/includes/)
