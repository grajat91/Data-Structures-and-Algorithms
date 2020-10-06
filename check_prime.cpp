#include <bits/stdc++.h>
using namespace std;

void prime_check (int n) {
    
    int p = sqrt(n);
    int c = 0;
    for (int i=2;i<=p;i++) {
        if (n%i == 0) {
            cout << n <<" is not a prime number\n";
            c++;
        }
    }
    if (c == 0) {
        cout << n <<" is a prime number\n";
    }
}

int main()
{
    int n = 7;
    prime_check(n);
    return 0;
}
