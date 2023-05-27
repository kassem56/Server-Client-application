// Server code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(12345);

    // Bind the socket to a specific address and port
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 1) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for a client to connect...\n");

    // Wait for a client to connect
    struct sockaddr_in clientAddress;
    int clientAddressLength = sizeof(clientAddress);
    int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, (socklen_t *)&clientAddressLength);
    if (clientSocket == -1) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected: %s\n", inet_ntoa(clientAddress.sin_addr));

    // Send a message to the client
    char message[] = "Hello, client!";
    send(clientSocket, message, strlen(message), 0);

    // Close the connection
    close(clientSocket);
    close(serverSocket);

    return 0;
}
