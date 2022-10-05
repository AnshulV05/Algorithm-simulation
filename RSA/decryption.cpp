#include <iostream>
#include <string>
#include<fstream>
#include "helperfunctions.h"
using namespace std;
typedef long long int ll;

// Predefined values in the program
ll p = 4783;
ll q = 8363;
ll phi = 39987084;
ll a = 13329029;
ll n = 40000229;
ll a_inv = 13329029;

//Function that decrypts the file according to the constants specified.
void decrypt(string filename, string decryptedfile)
{
    ifstream inp(filename);
    ofstream out(decryptedfile);
    string p;
    while(inp>>p){
        ll recieved= stoi(p);
        ll asciival = power(recieved,a_inv,n);
        out<<char(asciival);
    }
}

//Main Function.
int main()
{
    decrypt("encrypted_file","output.txt");
}
