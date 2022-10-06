## Instructions to run the code
* To understand the Basic working of the algorithm compile the program **RSA.cpp** by executing the following: <br>
1. ```g++ RSA.cpp``` <br>
2. ```./a.out``` <br>
Follow the interactive instruction given on the terminal to proceed further and get the result.

To understand a basic working of file encryption, Follow the given instructions: <br>
1. Write the text which you want to encryt in the file named "**senderfile.txt**". 
2. Execute ```g++ encryption.cpp```. This would produce a file named "**encrypted_file**".
3. The encrypted_file contains numbers with spaces in between them, To decode the text run ```g++ decryption.cpp```.
4. The above command produces a file named "**output.txt**". To check whether the decryption is correct, execute <br> ```diff output senderfile.txt```.

In my case I have used the following numbers: <br>
**p = 4783** <br>
**q = 8363** <br>
**n = 40000229** <br>
**a = 13329029** <br>

The file **public_availabledata.h** contains the data that is available publicly. <br>
The file **helperfunctions.h** contains functions useful for calculation.



