/*
Examples:
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
*/


#include <iostream>
#include <vector>

using namespace std;

// dynamic
// each sub-problem(sub-array) solves its longest increasing sub array
int longestIncSubarr(vector<int> alist){
  int len = alist.size();
  if(len == 0){
    return 0;
  }

  vector<int> pos;
  pos.assign(len, 1);

  int longest = 1;
  for(int i = 0; i < len; i++){
    int target = alist[i];
    for(int j = 0; j < i; j++){
      if(alist[j] < target && pos[j] >= pos[i]){
        pos[i] = pos[j] + 1;
        if(pos[i] > longest){
          longest = pos[i];
        }
      }
    }
  }
  return longest;
}

int main(){
  vector<int> alist = {10, 22, 9, 33, 21, 50, 41, 60, 80};
  cout << longestIncSubarr(alist) << "\n";
}
