// Client code
import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        try {
            // Create a client socket and connect to the server
            Socket clientSocket = new Socket("localhost", 12345);

            // Create input stream to receive data from the server
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

            // Receive data from the server
            String data = in.readLine();
            System.out.println("Received from server: " + data);

            // Close the connection
            in.close();
            clientSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
