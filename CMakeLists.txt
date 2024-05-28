cmake_minimum_required(VERSION 3.10)
set(EXECUTABLE_NAME "toby")
project(${EXECUTABLE_NAME})
add_subdirectory(sensor)

# Setup names
set(EXECUTABLE_NAME "toby")
set(LIB_GRPC_NAME "toby_grpc_proto")
set(LIB_CONF_NAME "toby_conf_proto")

# Setup paths
set(GRPC_INSTALL_DIR "~/Grpc")
get_filename_component(GRPC_INSTALL_DIR_ABS "~/Grpc" ABSOLUTE)
list(APPEND CMAKE_PREFIX_PATH "${GRPC_INSTALL_DIR_ABS}")
IF(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "~/Qt/6.7.1/macos")
ELSE()
    list(APPEND CMAKE_PREFIX_PATH "~/Qt/6.7.1/gcc_64")
ENDIF()

# Find packages
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)
find_package(utf8_range REQUIRED)
find_package(absl REQUIRED)

# Setup gRPC
set(_PROTOBUF_PROTOC "${GRPC_INSTALL_DIR_ABS}/bin/protoc")
set(_GRPC_CPP_PLUGIN_EXECUTABLE "${GRPC_INSTALL_DIR_ABS}/bin/grpc_cpp_plugin")
get_filename_component(SENSOR_PROTO "${CMAKE_SOURCE_DIR}/protos/sensor.proto" ABSOLUTE)
get_filename_component(SENSOR_PROTO_PATH "${SENSOR_PROTO}" PATH)
set(GRPC_GENERATED_FILES "${CMAKE_CURRENT_LIST_DIR}/generated")
set(SENSOR_PROTO_SRC "${GRPC_GENERATED_FILES}/sensor.pb.cc")
set(SENSOR_PROTO_HDR "${GRPC_GENERATED_FILES}/sensor.pb.h")
set(SENSOR_GRPC_SRC "${GRPC_GENERATED_FILES}/sensor.grpc.pb.cc")
set(SENSOR_GRPC_HDR "${GRPC_GENERATED_FILES}/sensor.grpc.pb.h")
add_custom_command(
    OUTPUT "${SENSOR_PROTO_SRC}" "${SENSOR_PROTO_HDR}" "${SENSOR_GRPC_SRC}" "${SENSOR_GRPC_HDR}"
    COMMAND ${_PROTOBUF_PROTOC}
    ARGS    --grpc_out "${GRPC_GENERATED_FILES}"
            --cpp_out "${GRPC_GENERATED_FILES}"
            -I "${SENSOR_PROTO_PATH}"
            --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
            "${SENSOR_PROTO}"
      DEPENDS "${SENSOR_PROTO}")
set(GRPC_SOURCES
    ${SENSOR_PROTO_SRC}
    ${SENSOR_PROTO_HDR}
    ${SENSOR_GRPC_SRC}
    ${SENSOR_GRPC_HDR}
      )
add_library(${LIB_GRPC_NAME} ${GRPC_SOURCES})
target_link_libraries(${LIB_GRPC_NAME}
    PRIVATE
        grpc++_reflection
        gRPC::grpc++
        protobuf::libprotobuf)

# Setup conf proto
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(PROJECT_SOURCES
    sources/main.cpp
    sources/logic.cpp
    sources/pcinfo.cpp
    resources.qrc
    )
set(PROJECT_INCLUDES
    include/logic.h
    include/pcinfo.h
    )
qt_standard_project_setup(REQUIRES 6.5)
qt6_add_executable(${EXECUTABLE_NAME} ${PROJECT_SOURCES} ${PROJECT_INCLUDES})
include_directories(${Protobuf_INCLUDE_DIRS})
target_include_directories(${EXECUTABLE_NAME}
    PRIVATE
        "./include"
        "${GRPC_GENERATED_FILES}"
    )
target_link_directories(${EXECUTABLE_NAME} 
    PRIVATE
        "${GRPC_INSTALL_DIR_ABS}/lib")
target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
        ${LIB_GRPC_NAME}
        Qt6::Gui   
        Qt6::Quick
    )
