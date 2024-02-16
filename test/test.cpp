#include<iostream>

using namespace std;

vector<long> prime_list;
vector<long> min_factor(200001,200001);


void sieve(vector<long> &prime_list, long n) {
    bool checked_number[n+1];
    memset(checked_number, false, sizeof(checked_number));
    for(long i = 2; i < n; ++i) {
        if(!checked_number[i]) {
            prime_list.push_back(i);
            for(long ii = i*i; ii <= n; ii += i) {
                checked_number[ii] = true;
            }
        }
    }
}

void cal_min_factor() {
    for(long p : prime_list)
        min_factor[p] = p;
    
    for(long p : prime_list)
        for(long i = p; i < 200001; i += p) 
            min_factor[i] = min(min_factor[i], p);
}

int prime_factor(int n) {
    if(n == 1) return 0;
    int res = 0;
    while(min_factor[n] != n) {
        res++;
        n /= min_factor[n];
    }
    return res + 1;
}

int sumOfPowers(int a, int b){
    int res = 0;
    for(int i = a; i <= b; ++i) {
        res += prime_factor(i);
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    sieve(prime_list, 200001);
    cal_min_factor();
    int a, b; cin >> a >> b;
    cout << sumOfPowers(a, b);


}