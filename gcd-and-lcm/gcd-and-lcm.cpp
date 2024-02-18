#include<iostream>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int a = 1701, b = 3768;
    cout << "GCD = " << gcd(b, a) << " LCM = " << lcm(b, a);
}