//  Longest Substring Without Repeating Characters

/*
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

# include <iostream>

using namespace std;

// wrong; fail at "pwwkew"
int lengthOfLongestSubstring_(string s) {
    if(s.length() == 0){
        return 0;
    }
    else{
        int longest = 1;
        for(int i = 0; i < s.length(); i++){
            int count = 1;
            for(int j = i - 1; j >= 0; j--){
                if(s[j] != s[i]){
                    count++;
                }
                else break;
            }
            if(count > longest){
                longest = count;
            }
        }
        return longest;
    }
}

int lengthOfLongestSubstring(string s){
    if(s.length() == 0){
        return 0;
    }
    else{
        int longest = 1;
        int prev_longest = 1;
        for(int i = 1; i < s.length(); i++){
            int count = 1;
            for(int j = i - 1; j >= i - prev_longest; j--){
                if(s[j] != s[i]){
                    count++;
                }
                else break;
            }
            if(count < prev_longest + 1){
                prev_longest = count;
            }
            else{
                prev_longest++;
            }
            if(prev_longest > longest){
                longest = prev_longest;
            }
        }
        return longest;
    }
}
// Assume at position n, the substring 0...n-1 has the longest string without repeating chars
// then if n is not duplicate with any chars in the longest substring ends at n-1
// the new longest substring at n is prev + 1

int main(){
    cout << lengthOfLongestSubstring("wpwpwpkew") << "\n";
    cout << lengthOfLongestSubstring("bbbbb") << "\n";
    cout << lengthOfLongestSubstring("abcabcbb") << "\n";
    cout << lengthOfLongestSubstring("pwwkew") << "\n";
}