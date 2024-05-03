cmake_minimum_required(VERSION 3.10)
project(toby)

IF(APPLE)
    set(CMAKE_PREFIX_PATH "/Users/jan/Qt/6.5.0/macos/lib/cmake/Qt6")
ELSE()
    set(CMAKE_PREFIX_PATH "/home/frid/Qt/6.6.2/gcc_64")
ENDIF()

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Quick)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt_standard_project_setup(REQUIRES 6.5)

qt6_add_executable(${PROJECT_NAME})

qt6_add_qml_module(${PROJECT_NAME}
    URI mainwindow
    VERSION 1.0
    QML_FILES 
        ./qml/main.qml)

target_sources(${PROJECT_NAME} 
    PRIVATE
        ./src/main.cpp
        ./src/pcdata.cpp
        ./inc/pcdata.h
    )

target_include_directories(${PROJECT_NAME} 
    PRIVATE
        "~/Qt/6.5.0/macos/lib/QtGui.framework/Headers"
        "~/Qt/6.5.0/macos/lib/QtQml.framework/Headers"
        "./inc"
    )
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        Qt6::Gui   
        Qt6::Quick
    )
