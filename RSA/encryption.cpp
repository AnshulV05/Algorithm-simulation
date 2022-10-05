#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "helperfunctions.h"
using namespace std;

typedef long long int ll;

void encrypt(string filename, string encryptedfile, ll n, ll a)
{
    ifstream inp(filename);
    ofstream out(encryptedfile);
    ostringstream tmp;
    tmp << inp.rdbuf();
    string fcont = tmp.str();
    cout << a << " " << n << endl;
    for (int i = 0; i < fcont.length(); i++)
    {
        out << power(int(fcont[i]), a, n) << " ";
    }
}
int main()
{
    ll a = 13329029;
    ll n = 40000229;
    encrypt("senderfile.txt", "encrypted_file", n, a);
}