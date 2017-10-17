// Next Permutation

/*
Implement next permutation, which rearranges numbers into the next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order 
(ie, sorted in ascending order).

Examples:
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

# include <iostream>
# include <vector>

using namespace std;

void print(std::vector<int>& result){
    for(std::vector<int>::iterator it = result.begin(); it != result.end(); ++it){
        std::cout << *it << ' ';
    }
    cout << "\n";
}

void switchPos(int& first, int& second){
    int temp = first;
    first = second;
    second = temp;
}

void nextPermutation(vector<int>& nums){
    int len = nums.size();
    if(len <= 1){
        return;
    }

    int i;
    for(i = len - 1; i > 0; i--){
        if(nums[i] > nums[i - 1]){
            int j;
            for(j = i; j < len; j++){
                if(nums[i - 1] >= nums[j]){
                    switchPos(nums[i - 1], nums[j - 1]);
                    break;
                }
            }
            if(j == len){
                switchPos(nums[i - 1], nums[len - 1]);
                break;
            }
            break;
        }
    }

    int toreverse = len - i;
    for(int j = 0; j < toreverse / 2; j++){
        switchPos(nums[j + i], nums[len - j - 1]);
    }
}

int main(){
    //int list[] = {1, 2, 3, 4, 9, 8, 7, 6};
    //int list[] = {5, 4, 3, 2, 1};
    //int list[] = {2, 3, 1};
    //int list[] = {1, 3, 2};
    //int list[] = {6, 9, 5, 4, 3, 2, 1};
    //int list[] = {6, 9, 8, 4, 3, 2, 1};
    int list[] = {1, 5, 1};
    std::vector<int> nums ( list, list + sizeof(list) / sizeof(list[0]) );
    nextPermutation(nums);
    print(nums);
}




