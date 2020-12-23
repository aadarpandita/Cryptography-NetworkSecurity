#include <stdio.h>
 
// Function to compute a^m mod n
int compute(int a, int m, int n)
{
    int r;
    int y = 1;
 
    while (m > 0)
    {
        r = m % 2;
 
        // fast exponentiation
        if (r == 1)
            y = (y*a) % n;
        a = a*a % n;
 
        m = m / 2;
    }
 
    return y;
}

int main()
{
    int p = 23;        // modulus
    int g = 5;        // base
 
    int a, b;    // a - Alice's Secret Key, b - Bob's Secret Key
    int A, B;    // A - Alice's Public Key, B - Bob's Public Key
 
    // choose secret integer for Alice's Pivate Key 
    a = 6;        
 
    // Calculate Alice's Public Key (Alice will send A to Bob)
    A = compute(g, a, p);
 
    // choose secret integer for Bob's Pivate Key
    b = 15;       
 
    
// Calculate Bob's Public Key (Bob will send B to Alice)
    B = compute(g, b, p);
 
    // Finding Secret key
    int keyA = compute(B, a, p);
    int keyB = compute(A, b, p);
 
    printf("Alice's Secret Key is %d\nBob's Secret Key is %d", keyA, keyB);
    printf("\n\n");
 
    return 0;
}
