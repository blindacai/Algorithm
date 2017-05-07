// 1. Two Sum

/*
Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

# include <iostream>
# include <vector>


void print(std::vector<int>& result){
    for(std::vector<int>::iterator it = result.begin(); it != result.end(); ++it){
        std::cout << *it << ' ';
    }
}


// runtime: 116ms
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> result;

    for(std::vector<int>::iterator it = nums.begin(); it != nums.end() - 1; ++it){
        int len = nums.end() - it;
        for(int i = 1; i < len; i++){
            if(*it + *(it + i) == target){
                result.push_back(it - nums.begin());
                result.push_back(it + i - nums.begin());
                break;
            }
        }
    }
    return result;
}

int main(){
    int list[] = {6, 2, 11, 12, 7};
    std::vector<int> nums( list, list + sizeof(list) / sizeof(list[0]) );
    std::vector<int> result = twoSum(nums, 9);
    print(result);
}