//Code to print all prime numbers upto integer n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> prime;
    int n = 53;
    int p = sqrt(n);
    for (int i =0; i < n; i++) {
        prime.push_back(1);
    }
    
    for (int i=2;i<=p;i++) {
        if (prime[i]==1) {
            for (int j=2;i*j<=n;j++) {
                prime[i*j] = 0;
            }
        }
    }
    
    for (int i =2; i < n; i++) {
        if (prime[i] == 1) {
            cout << i << endl;
        }
    }
    return 0;
}
