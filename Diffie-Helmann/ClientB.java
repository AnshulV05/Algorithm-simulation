package Diffiehelmann;
import java.net.*;
import java.util.Scanner;

import java.io.*;

public class ClientB {
    private Socket socket = null; 
    private Integer n = 11743;
    private Integer g = 3;
    private String Name = null;  
    private Integer num = null;
    private Integer recieved = null;
    private Scanner sc = new Scanner(System.in);
    
    private void startConnection() throws IOException{
        this.recieved = sc.nextInt();

        // The key to connect to the server. i.e g^ab mod n
        Integer key = power(recieved, num, n); 
        // The key to connect to the server.
        try {
            socket = new Socket("localhost", key);
        } catch (java.net.ConnectException except) {
            //Shows Wrong code if there is no such server with the given key
            System.out.println("WRONG CODE");
        }
    }
    public ClientB(String Name, Integer num) throws UnknownHostException, IOException {
        this.num = num; //The number this person chooses. (i.e a or b).
        this.Name = Name; // The name of the person

        System.out.print("Hello, This is the terminal of ");
        System.out.println(Name);

        Integer sent = power(g, num, n);
        System.out.println(String.format("Sending the number %d", sent));
    }

    //  Function for a^r mod n
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
        /*
         * Don't change this function
         */
        String Name = args[0];
        Integer num = Integer.parseInt(args[1]);
        System.out.println("Started");
        try {
            ClientB client = new ClientB(Name, num);
            client.startConnection();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
