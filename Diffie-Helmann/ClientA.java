package Diffie-Helmann;

import java.net.*;
import java.util.Scanner;

import java.io.*;

public class ClientA {
    private ServerSocket server = null; // The server of the client.
    private Socket socket = null;
    private Integer n = 11743;
    private Integer g = 3;
    private String Name = null;
    private Integer num = null; // a or b
    private Integer recieved = null; // the number recieved.
    private Scanner sc = new Scanner(System.in);

    //Constructor for the ClientA (server) with which ClientB (client) would connect.
    private void startServer(){
        this.recieved = sc.nextInt(); // The number recieved from the B's terminal. i.e g^b mod n

        Integer key = power(recieved, num, n); // Key would then be g^(ab) mod n.

        try {
            /*
             * INITIALIZING THE ServerSocket
             */
            server = new ServerSocket(key);

            System.out.println("Server started");
            System.out.println("Waiting for the client ...");

            // Server of A starts listening.
            // Since only B knows the key it would be able to connect.
            socket = server.accept();

            // Finally the connection is setup between the players.
            // Hence print the line below.
            System.out.println("Successfully Connected");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public ClientA(String Name, Integer num) {

        this.num = num; // The number this person chooses. (i.e a or b).
        this.Name = Name; // The name of the person.

        System.out.print("Hello, This is the terminal of ");
        System.out.println(Name);
        
        /*
         * Below are the operations to be performed.
         * This server prints the number x^a mod n so that it is publicly available.
         * It then waits for an input which is the number shown on b's terminal
         */
        Integer sent = power(g, num, n);
        System.out.println(String.format("Sending the number %d", sent));
    }

    //Function to calculate a^r mod n
    int power(int a, int r, int n) {
        int ans = 1;
        int exponential = a % n;
        while (r > 0) {
            if (r % 2 == 1) {
                ans = (ans * exponential) % n;
            }
            exponential = (exponential * exponential) % n;
            r = r / 2;
        }
        return ans;
    }

    public static void main(String args[]) {
        String Name = args[0];
        Integer num = Integer.parseInt(args[1]);
        System.out.println("Started");
        try {
            // Create a new client class.
            ClientA client = new ClientA(Name, num);
            client.startServer();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
