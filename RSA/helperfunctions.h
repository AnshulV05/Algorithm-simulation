#include<iostream>
using namespace std;

typedef long long int ll;
//Extended gcd calculator
ll gcdExtended(ll a, ll b, ll *x, ll *y);

// Function to find modulo inverse of a
ll modInverse(ll A, ll M)
{
    ll x, y;
    ll g = gcdExtended(A, M, &x, &y);
    if (g != 1)
    {
        cout << "Inverse doesn't exist";
        return -1;
    }

    // m is added to handle negative x
    ll res = ((x % M) + M) % M;
    return res;
}

// Function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{

    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    // To store results of recursive call
    ll x1, y1;
    ll gcd = gcdExtended((b % a), a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

//Power function modulo n
ll power(ll a, ll r, ll n)
{
    ll ans = 1;
    ll exponential = a % n;
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

bool coprime(ll n, ll m)
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

bool isprime(ll n, ll a)
{
    ll x = n - 1;
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