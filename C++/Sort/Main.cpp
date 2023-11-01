#include <iostream>
#include <vector>

using namespace std;

class sorting{
public:
    void swap(vector<int>& nums, int i , int j){
        if(i < 0 || j < 0 || i >= nums.size() || j >= nums.size()){
            return ;
        }
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;

    }
    vector<int> BubbleSort(vector<int>& nums){
        vector<int> result;
        result.assign(nums.begin(),nums.end());
        for(int k =0; k < result.size(); k++){
            for(int i = 0 ; i < result.size(); i++){
                if(result[i] > result[i+1]){
                    swap(result,i,i+1);
                }
            }
        }
        return result;
    };

    void printList(vector<int>& nums){
        cout << "{";
        for (int i = 0; i < nums.size()-1; i++){
            cout << nums[i] << ",";
        }
        cout << nums[nums.size()-1] << "}" << endl;
    };
};

int main(){
    vector<int> nums = {3,45,6,1,2,878,3425,432,333};
    sorting sort;
    cout << "original list:" << endl;
    sort.printList(nums);
    vector<int> Bubble_res = sort.BubbleSort(nums);
    cout << "Bubble Sort: " << endl;
    sort.printList(Bubble_res);
    // cout << sort.BubbleSort(nums) << endl;
}