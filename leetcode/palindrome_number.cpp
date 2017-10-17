// Palindrome Number

// Determine whether an integer is a palindrome. Do this without extra space.

# include <iostream>
#include <stdlib.h>

bool isPalindrome(int x) {
    int org = abs(x);
    int reverse = 0;
    while(x != 0){
        reverse = reverse * 10 + x % 10;
        x = x / 10;
    }

    if((reverse - org) == 0){
        return true;
    }
    else return false;
}

int main(){
    if(isPalindrome(-12321)){
        std::cout << "yes\n";
    }
}