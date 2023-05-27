// Server code
import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        try {
            // Create a server socket
            ServerSocket serverSocket = new ServerSocket(12345);

            System.out.println("Waiting for a client to connect...");

            // Wait for a client to connect
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected: " + clientSocket.getInetAddress());

            // Create output stream to send data to the client
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

            // Send a message to the client
            String message = "Hello, client!";
            out.println(message);

            // Close the connection
            out.close();
            clientSocket.close();
            serverSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
