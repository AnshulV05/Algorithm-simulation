#include <iostream>
#include <ctime>
using namespace std;
long long int power(long long int a, long long int r, long long int n)
{
    long long int ans = 1;
    long long int exponential = a % n;
    while (r > 0)
    {
        if (r % 2 == 1)
        {
            ans = (ans * exponential) % n;
        }
        exponential = (exponential * exponential) % n;
        r = r / 2;
    }
    return ans;
}

bool coprime(long long int n, long long int m)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return coprime(m % n, n);
    }
}

bool isprime(long long int n, long long int a)
{
    long long int x = n - 1;
    if (!coprime(a, n))
    {
        return false;
    }
    else
    {
        if (power(a, n - 1, n) != 1)
        {
            return false;
        }
        else
        {
            while (x % 2 == 0)
            {
                if (power(a, x / 2, n) != 1 && power(a, x / 2, n) != n - 1)
                {
                    return false;
                }
                else if (power(a, x / 2, n) == 1)
                {
                    x = x / 2;
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return true;
}

bool miller_rabin(long long int n, int x)
{ // X is number of times the random number is generated.
    bool answer = true;
    while (x > 0)
    {
        long long int a = 2 + rand() % (n - 2);
        if (!isprime(n, a))
        {
            answer = false;
            break;
        }
        x--;
    }
    return answer;
}

// Used to generate a prime number between x and y.
long long int gen_prime(long long int x, long long int y)
{
    for (long long int i = x; i < y; i++)
    {
        if (miller_rabin(i, 10))
        {
            return i;
        }
    }
    return -1; // When there is no prime number between the two
}
int main()
{
    int n;
    int choice;
    cout << "Choose any option"
         << "\n"
         << "1) List primes under a specified number"
         << "\n"
         << "2) Generate a prime between two numbers" << endl;
    cin >> choice;
    if (choice == 1)
    {
        cout<<"Enter the maximum range"<<endl;
        cin >> n;
        srand(time(0));
        int count = 0;
        for (int i = 3; i < n; i = i + 2)
        {
            if (miller_rabin(i, 5))
            {
                count++;
                cout << i << endl;
            }
        }
        // Finally it prints the total count of primes.
        cout << "The Total prime numbers are " << endl;
        cout << (count + 1) << endl;
    }
    else if (choice == 2)
    {
        long long int a,b;
        cout<<"Provide first number  : ";
        cin>>a;
        cout<<"Provide second number : ";
        cin>>b;
        long long int p = gen_prime(a,b);
        if(p==-1){
            cout<<"There is no prime in between"<<endl;
        }
        else{
            cout<<"Prime number is "<<p<<endl;
        }
    }
    else
    {
        cout << "Wrong choice exiting the program" << endl;
    }
}
