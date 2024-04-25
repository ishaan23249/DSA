#include <iostream>
using namespace std;

__int64 maxSushi(__int64  cnt_b, __int64  cnt_s,__int64   cnt_c , int n_b, int n_s, int n_c, int p_b, int p_s, int p_c, __int64 r){
    // we will use the concept of binary search to find the maximum number of sushi. 
    // This will be a more optimised approach. 
    // __int64 is used because test case has many bits. 
    __int64  zero = 0; 
    __int64  low = 0;
    __int64  high = r+100;
    __int64  mid = 0;
    // 10^12 is given in the question as the range. 
    while (low <= high) {
        mid = low + (high - low)/2;
        __int64 A,B,C;
        A = max(zero, (cnt_b*mid - n_b)*p_b);
        B = max(zero, (cnt_s*mid - n_s)*p_s);
        C = max(zero, (cnt_c*mid - n_c)*p_c);
        __int64  total_price = A + B + C;
        if (total_price <= r) {
            low = mid + 1; 
        }
        else {
            high = mid - 1;
        }

    }
    return high;
    

}


int main() {
    string Recipe;
    cout << "Enter Recipe String" << endl;
    cin >> Recipe;
    int n_b, n_s, n_c;
    cout << "Enter n_b, n_s, n_c" << endl;
    cin >> n_b >> n_s >> n_c;
    int p_b, p_s, p_c;
    cout << "Enter p_b, p_s, p_c" << endl;
    cin >> p_b >> p_s >> p_c;
    __int64 r;
    cout << "Enter amount of yen (r)" << endl;
    cin >> r;
    
    __int64  cnt_b = 0;
    __int64  cnt_s = 0;
    __int64  cnt_c = 0;

    for (int i = 0; i<Recipe.length(); i++){
        char L = Recipe[i];
        if (L == 'B'){
            cnt_b++;
        }

        if (L == 'S'){
            cnt_s++;
        }
        if (L == 'C'){
            cnt_c++;
        }
    }

    cout << maxSushi( cnt_b, cnt_s, cnt_c , n_b, n_s, n_c, p_b, p_s,  p_c, r);
}

