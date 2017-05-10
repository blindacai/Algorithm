// 2. Reverse Integer

/*
Example:
Reverse digits of an integer.
x = 123, return 321
x = -123, return -321

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
*/

# include <iostream>
# include <vector>
#include <math.h>

const int INT_MAX = 2147483647;
const int INT_MIN = -2147483648;

int build_int(std::vector<int>& int_list){
    long result = 0;
    int len = int_list.end() - int_list.begin();
    for(int i = 0; i < len; i++){
        result += int_list[i] * pow(10, len-i-1);
    }

    if(result > INT_MAX || result < INT_MIN){
        return 0;
    }
    else return result;
}

int reverse(int x) {
    std::vector<int> digits;   // initialize without knowing size

    while(x != 0){
        digits.push_back(x - (x / 10) * 10);
        x = x / 10;
    }

    return build_int(digits);
}

int reverse1(int x){
    long res = 0;
    while(x != 0){
        res = res * 10 + x % 10;
        x = x / 10;

        if(res > INT_MAX || res < INT_MIN){
            return 0;
        }     
    }
    return res;
}

int main(){
    std::cout << reverse(1234567893) << '\n';
    std::cout << reverse1(1234567893) << '\n';
}