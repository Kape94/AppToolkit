cmake_minimum_required(VERSION 3.22)
project(AppToolkit)

find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

file(GLOB SRC_FILES *.cpp _internal/*.cpp)
add_library(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC 
        GLEW::GLEW
        glfw
        glm::glm
        imgui::imgui
)
