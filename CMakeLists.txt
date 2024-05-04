cmake_minimum_required(VERSION 3.10)
set(EXECUTABLE_NAME "toby")
project(${EXECUTABLE_NAME})

set(CMAKE_PREFIX_PATH "/Users/jan/Qt/6.5.0/macos/lib/cmake/Qt6")

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Quick)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(PROJECT_SOURCES
    src/main.cpp
    src/logic.cpp
    inc/logic.h
    src/pcinfo.cpp
    inc/pcinfo.h
    resources/resources.qrc
    )

qt_standard_project_setup(REQUIRES 6.5)

qt6_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_compile_definitions(${PROJECT_NAME}
        PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

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
