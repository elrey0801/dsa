#include<iostream>
#include<vector>
#include<string>

using namespace std;

class LongNumber {
    public:
        vector<short int> absolute;
        bool is_negative = false;
        int digit;

        int get_digit() {
            return absolute.size();
        }

        void print_number() {
            if(this->is_negative) cout << '-';
            for(int i = this->get_digit() - 1; i >= 0; --i) 
                cout << this->absolute[i]; 
        }
};


LongNumber long_sub(LongNumber a, LongNumber b) {

}

LongNumber long_sum(LongNumber a, LongNumber b) {
    LongNumber res;
    if(a.is_negative && b.is_negative) res.is_negative = true;
    else if(a.is_negative) return long_sub(b, a);
    else if(b.is_negative) return long_sub(a, b);

    int a_digit = a.get_digit(), b_digit = b.get_digit();
    int p_a = 0, p_b = 0;
    int carry = 0, this_sum, this_a, this_b;

    while(p_a < a_digit || p_b < b_digit) {
        // 22
        // 49
        // 71
        if(p_a < a_digit) {
            this_a = a.absolute[p_a];
            p_a++;
        } else this_a = 0;
        if(p_b < b_digit) {
            this_b = b.absolute[p_b];
            p_b++;
        } else this_b = 0;
        this_sum = this_a + this_b + carry;
        carry = this_sum / 10;
        res.absolute.push_back(this_sum % 10);
    }
    while(carry) {
        res.absolute.push_back(carry % 10);
        carry /= 10;
    }
    return res;
}

LongNumber make_long_number(string n) {
    LongNumber res; 
    int p = 0;
    if(n[0] == '-') {
        res.is_negative = true;
        p++;
    }

    for(int i = n.size() - 1; i >= p; --i)
        res.absolute.push_back(n[i] - '0');
    
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    string a, b;
    cin >> a >> b;
    long_sum(make_long_number(a), make_long_number(b)).print_number();
}