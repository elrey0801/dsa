#include<iostream>
#include<vector>

using namespace std;

void sieve(vector<long> &prime_list) {
    long n; cin >> n;
    bool checked_number[n+1];
    memset(checked_number, false, sizeof(checked_number));
    for(long i = 2; i < n; ++i) {
        if(!checked_number[i]) {
            for(long ii = i*i; ii <= n; ii += i) {
                checked_number[ii] = true;
            }
        }
    }
}

void print_prime(vector<long> &prime_list) {
    for(long n : prime_list) cout << n << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    vector<long> prime_list;
    sieve(prime_list);
    print_prime(prime_list);
}
