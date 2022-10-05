## Instructions to run the program
* The Prime I have choosen in this case is p = 11743. A primitive root of p comes out to be 3.
To check the functions to calculate the primitive root refer to 'primitive.cpp'

To simulate the algorithm between A and B (here considered as two terminals),
1. Type ```javac Diffie-Helmann/*.java``` command in the directory which contains the Directory **Diffie-Helmann** to compile the java files.
2. Execute the ClientA file by running ```java Diffie-Helmann.ClientA <name-of-client> <Number-choosen-by-A i.e a> ```
3. This would start the Terminal showing which number has been returned by A.
4. Execute the ClientB file by running ```java Diffie-Helmann.CLientB <name-of-client> <Number-choosen-by-B i.e b> ```
5. This would start the Terminal showing which number has been returned by B.
6. Type the number shown on B's terminal screen on Terminal of person A. This would start the server of A by the encrypted key.
7. Type the number shown on A's terminal screen on Terminal of person B. This would start socket for B.
8. If the Key entered are correct for both the terminals, The program successfully exits by showing a message "Successfully connected". Otherwise it shows the message "WRONG CODE"
