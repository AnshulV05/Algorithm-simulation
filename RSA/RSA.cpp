#include <iostream>
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

//An efficient primality testing method
bool miller_rabin(ll n, int x)
{ // X is number of times the random number is generated.
    bool answer = true;
    while (x > 0)
    {
        ll a = 2 + rand() % (n - 2);
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
ll gen_prime(ll x)
{
    for (ll i = x; i < 1000000; i++)
    {
        if (miller_rabin(i, 10))
        {
            return i;
        }
    }
    return -1;
}

//Main program
int main()
{
    ll p, q, a;
    ll r1; // Range of first prime
    ll min;

    cout << "#### USER B ####" << endl;
    cout << "Provide a number after which you want to choose first prime"<<endl;
    cin >> r1;
    min = r1;
    p = gen_prime(r1);
    cout << "Choosen Prime number is " << p << endl;
    cout << "Provide a number after which you want to choose second prime" << endl;
    cin >> r1 ;
    if (r1 < min)
        min = r1;
    q = gen_prime(r1);
    cout << "Choosen Prime number is " << q << endl;
    ll phi = (p - 1) * (q - 1);
    ll n = p * q;

    a = phi/3;
    while(!coprime(a,phi)){
        a = a+1;
    }

    cout << "A choosen a for you is " << a <<endl;
    ll a_inv = modInverse(a, phi);
    cout<<a_inv<<endl;
// --------------------------------------------------------------------- //
    cout << "#### USER A ####" << endl;
    ll x;
    cout<< "Choose the number which you want to send. Note that it should be less than "<<n<<endl;
    cin>>x;
    ll returned_no = power(x,a,n);
    cout<< "Sending the number "<<returned_no<<endl;
// -------------------------------------------------------------------- //
    cout << "#### USER B ####" << endl;
    cout<<" Computing number at B's side"<<endl;
    cout<<"--------------------------------"<<endl;
    ll answer = power(returned_no,a_inv,n);
    if(answer == x){
        cout<<"Viola! : > You got the correct answer "<<x<<endl;
    }
    else{
        cout<<"OH No! : < You got the wrong answer "<<answer<<endl;
    }
}
