cmake_minimum_required(VERSION 3.10)
project(toby)

IF(APPLE)
    set(CMAKE_PREFIX_PATH "/Users/jan/Qt/6.5.0/macos/lib/cmake/Qt6")
ELSE()
    set(CMAKE_PREFIX_PATH "/home/frid/Qt/6.6.2/gcc_64")
ENDIF()

find_package(Qt6 REQUIRED COMPONENTS Qml)
find_package(Qt6 REQUIRED COMPONENTS Quick)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt_add_executable(${PROJECT_NAME} ./src/main.cpp)
qt_standard_project_setup()
target_sources(${PROJECT_NAME} PRIVATE ./src/main.cpp)

target_include_directories(${PROJECT_NAME} 
    PRIVATE
        "~/Qt/6.5.0/macos/lib/QtCore.framework/Headers"
        "~/Qt/6.5.0/macos/lib/QtQml.framework/Headers"
    )

qt_add_qml_module(${PROJECT_NAME} 
    URI qml
    RESOURCE_PREFIX "/qml"
    QML_FILES ./qml/main.qml)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Quick)
