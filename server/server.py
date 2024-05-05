from concurrent import futures
import logging
import grpc
import sensor_pb2
import sensor_pb2_grpc

class Sensor(sensor_pb2_grpc.SensorServicer):
    def SayHello(self, request, context):
        return sensor_pb2.HelloReply(message="Hello, %s!" % request.name)

def serve():
    port = "50051"
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    sensor_pb2_grpc.add_SensorServicer_to_server(Sensor(), server)
    server.add_insecure_port("[::]:" + port)
    server.start()
    print("Server started, listening on " + port)
    server.wait_for_termination()

if __name__ == "__main__":
    logging.basicConfig()
    serve()
