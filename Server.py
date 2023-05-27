# Server code
import socket

# Create a socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Get the local machine name and define the port
host = socket.gethostname()
port = 12345

# Bind the socket to a specific address and port
server_socket.bind((host, port))

# Listen for incoming connections
server_socket.listen(1)

# Wait for a client to connect
print('Waiting for a client to connect...')
client_socket, addr = server_socket.accept()
print('Client connected:', addr)

# Send a message to the client
message = 'Hello, client!'
client_socket.send(message.encode())

# Close the connection
client_socket.close()
server_socket.close()
