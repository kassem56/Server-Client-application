# Client code
import socket

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Get the local machine name and define the port
host = socket.gethostname()
port = 12345

# Connect to the server
client_socket.connect((host, port))

# Receive data from the server
data = client_socket.recv(1024).decode()
print('Received from server:', data)

# Close the connection
client_socket.close()
