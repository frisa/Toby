cmake_minimum_required(VERSION 3.10)

# Binaries
set(EXECUTABLE_NAME "sensor")
set(LIB_GRPC_NAME "sensor_grpc_proto")
set(LIB_CONF_NAME "sensor_conf_proto")
project(${EXECUTABLE_NAME})

set(GRPC_INSTALL_DIR "~/Grpc")
get_filename_component(GRPC_INSTALL_DIR_ABS "~/Grpc" ABSOLUTE)
list(APPEND CMAKE_PREFIX_PATH "${GRPC_INSTALL_DIR}")

find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(utf8_range REQUIRED)
find_package(absl REQUIRED)

# gRPC relevant
set(_PROTOBUF_PROTOC "${GRPC_INSTALL_DIR_ABS}/bin/protoc")
set(_GRPC_CPP_PLUGIN_EXECUTABLE "${GRPC_INSTALL_DIR_ABS}/bin/grpc_cpp_plugin")

get_filename_component(SENSOR_PROTO "../protos/sensor.proto" ABSOLUTE)
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

# Configuration protobuf relevant
get_filename_component(CONF_PROTO "../protos/configuration.proto" ABSOLUTE)
get_filename_component(CONF_PROTO_PATH "${CONF_PROTO}" PATH)
set(CONF_GENERATED_FILES "${CMAKE_CURRENT_LIST_DIR}/configuration")
set(CONF_PROTO_SRC "${CONF_GENERATED_FILES}/configuration.pb.cc")
set(CONF_PROTO_HDR "${CONF_GENERATED_FILES}/configuration.pb.h")

add_custom_command(
    OUTPUT "${CONF_PROTO_SRC}" "${CONF_PROTO_HDR}"
    COMMAND ${_PROTOBUF_PROTOC}
    ARGS    --cpp_out "${CONF_GENERATED_FILES}"
            -I "${CONF_PROTO_PATH}"
            "${CONF_PROTO}"
    DEPENDS "${CONF_PROTO}")
set(CONF_SOURCES
    ${CONF_PROTO_SRC}
    ${CONF_PROTO_HDR}
    )
add_library(${LIB_CONF_NAME} ${CONF_SOURCES})
target_link_libraries(${LIB_CONF_NAME}
    PRIVATE
        absl::base
        utf8_range::utf8_validity
        grpc++_reflection
        gRPC::grpc++
        protobuf::libprotobuf
)

# Qt relevant
IF(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "~/Qt/6.7.1/macos")
ELSE()
    list(APPEND CMAKE_PREFIX_PATH "~/Qt/6.7.1/gcc_64")
ENDIF()

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Quick)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(PROJECT_SOURCES
      main.cpp
      sensor.cpp
      sensor.hpp
      resources.qrc
   )
qt_standard_project_setup(REQUIRES 6.5)
qt6_add_executable(${EXECUTABLE_NAME} ${PROJECT_SOURCES})
target_compile_definitions(${EXECUTABLE_NAME}
        PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
    )
target_include_directories(${EXECUTABLE_NAME} 
    PRIVATE
        "./include"
        "${GRPC_GENERATED_FILES}"
        "${CONF_GENERATED_FILES}"
    )
target_link_directories(${EXECUTABLE_NAME} 
    PRIVATE
        "${GRPC_INSTALL_DIR_ABS}/lib")
target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
        ${LIB_GRPC_NAME}
        ${LIB_CONF_NAME}
        Qt6::Gui   
        Qt6::Quick
        grpc++_reflection
        gRPC::grpc++
        protobuf::libprotobuf
    )
