#include<iostream>

using namespace std;

long long mod_expo_recursive(int x, int y, int m) {
    if(y == 0) return 1;
    if(y % 2 == 0) return mod_expo_recursive(x * x, y / 2, m) % m;
    return ((x % m) * mod_expo_recursive(x * x, (y - 1) / 2, m)) % m;
}

long long mod_expo(int x, int y, int m) {
    if(y == 0) return 1;
    long long res = 1;
    while (y > 0) {
        if(y % 2 == 0) {
            x = (x * x) % m;
            y /= 2;
        } else {
            res = (res * x) % m;
            x = (x * x) % m;
            y = (y - 1) / 2;
        }
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    int x, y, m;
    cin >> x >> y >> m;
    cout << mod_expo_recursive(x, y, m) << endl;
    cout << mod_expo(x, y, m);
}