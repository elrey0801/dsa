#include<iostream>
#include<vector>

using namespace std;

class LongNumber {
    public:
        vector<short int> absolute;
        bool is_negative = false;
};

LongNumber long_sub(LongNumber &a, LongNumber &b) {

}

LongNumber long_sum(LongNumber &a, LongNumber &b) {
    LongNumber res;
    if(a.is_negative && b.is_negative) res.is_negative = true;
    else if(a.is_negative) return long_sub(b, a);
    else if(b.is_negative) return long_sub(a, b);
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
}