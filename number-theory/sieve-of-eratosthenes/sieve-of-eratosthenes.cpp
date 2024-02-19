#include<iostream>
#include<vector>

using namespace std;

void sieve(vector<long> &prime_list, long n) {
    bool checked_number[n+1];
    memset(checked_number, false, sizeof(checked_number));
    for(long i = 2; i < n; ++i) {
        if(!checked_number[i]) {
            for(long ii = i*i; ii <= n; ii += i) {
                checked_number[ii] = true;
            }
        }
    }
    for(long i = 2; i <= n; ++i)
        if(not checked_number[i])
            prime_list.push_back(i);
}

void print_prime(vector<long> &prime_list) {
    for(long n : prime_list) cout << n << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    long n; cin >> n;
    vector<long> prime_list;
    sieve(prime_list, n);
    print_prime(prime_list);
}
