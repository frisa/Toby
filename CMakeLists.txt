cmake_minimum_required(VERSION 3.10)
project(toby)

IF(APPLE)
    set(CMAKE_PREFIX_PATH "/Users/jan/Qt/6.5.0/macos/lib/cmake/Qt6")
ELSE()
    set(CMAKE_PREFIX_PATH "/home/frid/Qt/6.6.2/gcc_64")
ENDIF()

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Gui Widgets Core)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt_add_executable(${PROJECT_NAME} ./src/main.cpp)
qt_standard_project_setup()
target_include_directories(${PROJECT_NAME} 
    PRIVATE
        "~/Qt/6.5.0/macos/lib/QtCore.framework/Headers"
        "~/Qt/6.5.0/macos/lib/QtQml.framework/Headers"
        "~/Qt/6.5.0/macos/lib/QtGui.framework/Headers"
        "~/Qt/6.5.0/macos/lib/QtWidgets.framework/Headers" 

    )
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Quick Qt6::Gui Qt6::Widgets)
