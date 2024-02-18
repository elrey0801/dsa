// Link of this problem:
// https://www.hackerrank.com/challenges/extra-long-factorials/problem?h_r=internal-search&isFullScreen=true
#include<iostream>
#include<vector>

using namespace std;

void multiply(vector<short int> &res, int n) {
    int size = res.size();
    int product, carry = 0;
    for(int i = 0; i < size; ++i) {
        product = res[i] * n + carry;
        res[i] = product % 10;
        carry = product / 10;
    }
    while(carry) {
        res.push_back(carry % 10);
        carry /= 10;
    }
}

vector<short int> extra_long_factorial(int n) {
    if(n == 0 || n == 1) return {1};
    vector<short int> res(1, 1);
    for(int i = 2; i <= n; ++i) 
        multiply(res, i);
    return res;
}

int main() {
    int n = 100;
    vector<short int> res = extra_long_factorial(n);
    for(int i = res.size() - 1; i >= 0; --i) cout << res[i];
    
}