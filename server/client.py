from __future__ import print_function

import logging

import grpc
import server.sensor_pb2 as sensor_pb2
import server.sensor_pb2_grpc as sensor_pb2_grpc


def run():
    print("Will try to greet world ...")
    with grpc.insecure_channel("localhost:50051") as channel:
        stub = sensor_pb2_grpc.GreeterStub(channel)
        response = stub.SayHello(sensor_pb2.HelloRequest(name="you"))
    print("Greeter client received: " + response.message)


if __name__ == "__main__":
    logging.basicConfig()
    run()
