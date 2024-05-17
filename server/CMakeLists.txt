cmake_minimum_required(VERSION 3.10)
set(EXECUTABLE_NAME "sensor")
project(${EXECUTABLE_NAME})

IF(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "~/Qt/6.7.0/macos")
ELSE()
    list(APPEND CMAKE_PREFIX_PATH "~/Qt/6.7.0/gcc_64")
    list(APPEND CMAKE_PREFIX_PATH "~/Qt/6.7.0/gcc_64")
ENDIF()

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Quick)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#gRPC relevant
set(ABSL_ENABLE_INSTALL ON) # https://github.com/protocolbuffers/protobuf/issues/12185#issuecomment-1594685860
add_subdirectory("../../grpc" ${CMAKE_CURRENT_BINARY_DIR}/grpc EXCLUDE_FROM_ALL)
set(_PROTOBUF_LIBPROTOBUF libprotobuf)
set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
set(_REFLECTION grpc++_reflection)
set(_ORCA_SERVICE grpcpp_orca_service)
set(_GRPC_GRPCPP grpc++)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)

get_filename_component(SENSOR_PROTO "../protos/sensor.proto" ABSOLUTE)
get_filename_component(SENSOR_PROTO_PATH "${SENSOR_PROTO}" PATH)

set(GRPC_GENERATED_FILES "${CMAKE_CURRENT_LIST_DIR}/gen")
set(SENSOR_PROTO_SRC "${GRPC_GENERATED_FILES}/sensor.pb.cc")
set(SENSOR_PROTO_HDR "${GRPC_GENERATED_FILES}/sensor.pb.h")
set(SENSOR_GRPC_SRC "${GRPC_GENERATED_FILES}/sensor.grpc.pb.cc")
set(SENSOR_GRPC_HDR "${GRPC_GENERATED_FILES}/sensor.grpc.pb.h")

add_custom_command(
      OUTPUT "${SENSOR_PROTO_SRC}" "${SENSOR_PROTO_HDR}" "${SENSOR_GRPC_SRC}" "${SENSOR_GRPC_HDR}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${GRPC_GENERATED_FILES}"
        --cpp_out "${GRPC_GENERATED_FILES}"
        -I "${SENSOR_PROTO_PATH}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${SENSOR_PROTO}"
      DEPENDS "${SENSOR_PROTO}")

set(PROJECT_SOURCES
    main.cpp
    sensor.cpp
    sensor.hpp
    resources.qrc
    )

qt_standard_project_setup(REQUIRES 6.5)

qt6_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_compile_definitions(${PROJECT_NAME}
        PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_include_directories(${PROJECT_NAME} 
    PRIVATE
        "./include"
    )
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        Qt6::Gui   
        Qt6::Quick
    )
