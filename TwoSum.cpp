#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class TwoSum
{
public:

    vector<int> sum(vector<int>& nums, int target){

        unordered_map< int, int> hashTable;

        for(int i = 0; i<nums.size(); i++ ){
            int complement = target - nums[i];

            if (hashTable.count(complement))
            {
                return{hashTable[complement],i};
            }
            hashTable[nums[i]] = i;

        }

        return {};
    }

};


int main(){

    TwoSum twoSum;

    vector<int> numbers = {2,4,13,6,3,1,7,9,8};

    int target = 10;

    vector<int> result = twoSum.sum(numbers,target);

    if (!result.empty())
    {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found!" << endl;
    }



    return 0;
}