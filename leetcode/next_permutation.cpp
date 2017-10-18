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

void nextPermutation_me(vector<int>& nums){
    int len = nums.size();
    if(len <= 1){
        return;
    }

    int i;
    for(i = len - 1; i > 0; i--){
        if(nums[i] > nums[i - 1]){
            for(int j = len - 1; j > i - 1; j--){
                if(nums[j] > nums[i - 1]){
                    switchPos(nums[j], nums[i - 1]);
                    break;
                }
            }
            break;
        }
    }

    int toreverse = len - i;
    for(int j = 0; j < toreverse / 2; j++){
        switchPos(nums[j + i], nums[len - j - 1]);
    }
}

// it's better without deep nested structure
void nextPermutation(vector<int>& nums){
    int last = nums.size() - 1;
    int i, k; i = k = last;
    while(i > 0 && nums[i - 1] >= nums[i]){
        i--;
    }

    for(int s = i; s < k; s++, k--){
        swap(nums[s], nums[k]);
    }
    
    if(i > 0){
        int j = i - 1;
        while(i < last && nums[j] >= nums[i]){
            i++;
        }
        if(i == last + 1){
            swap(nums[j], nums[last]);
        }
        else{
            swap(nums[j], nums[i]);
        }
    }
}


int main(){
    //int list[] = {1, 2, 3, 4, 9, 8, 7, 6};
    //int list[] = {5, 4, 3, 2, 1};
    //int list[] = {2, 3, 1};
    //int list[] = {1, 3, 2};
    //int list[] = {6, 9, 5, 4, 3, 2, 1};
    //int list[] = {6, 9, 8, 4, 3, 2, 1};
    int list[] = {5, 1, 1};
    std::vector<int> nums ( list, list + sizeof(list) / sizeof(list[0]) );
    nextPermutation(nums);
    print(nums);
}




