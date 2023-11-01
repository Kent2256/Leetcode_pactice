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
    int Partition(vector<int>& nums, int left, int right){
        int privot = nums[(left+right)/2];
        while (left < right){
            while(nums[left] < privot){
                left++;
            }
            while(nums[right] > privot){
                right--;
            }
            if(left < right){
                swap(nums, left,right);
                left++; 
                right--;
            }
        }
        return left;
    };
    void QuickSort(vector<int>& nums, int left, int right){
        if(left < right){
            int pivot = Partition(nums, left ,right);
            if(pivot - 1 >left){
                QuickSort(nums, left, pivot - 1);
            }
            if(pivot + 1 < right){
                QuickSort(nums, pivot + 1, right);
            }
        }
    };
    void merge_array(vector<int>& nums, vector<int>& helper, int low, int middle, int high){
        for(int i = low; i <= high;i++){
            helper[i] = nums[i];
        }

        //Create the pointor
        int Leftpos = low;
        int Rightpos = middle+1;
        int current = low;

        while( Leftpos <= middle && Rightpos <= high){
            if (helper[Leftpos] > helper[Rightpos]){
                nums[current] = helper[Rightpos];
                Rightpos++;
            }
            else{
                nums[current] = helper[Leftpos];
                Leftpos++;
            }
            current++;
        }
        if(Leftpos > middle){
            return;
        }
        int remain = middle - Leftpos;
        for( int i = 0; i <= remain; i++){
            nums[current+i] = helper[Leftpos+i];
        }
    };
    void mergesort_div(vector<int>& nums, vector<int>& helper, int low, int high){
        if(low<high){
            int middle = (low + high)/2;
            mergesort_div(nums,helper,low,middle);
            mergesort_div(nums,helper,middle+1,high);
            merge_array(nums,helper,low,middle,high);
        }
    };
    void mergesort(vector<int>& nums){
        vector<int> helper(nums.size());
        mergesort_div(nums,helper,0,nums.size()-1);
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
    // cout << "QuickSort" << endl;
    // sort.QuickSort(nums,0,nums.size()-1);
    cout << "MergeSort" << endl;
    sort.mergesort(nums);
    sort.printList(nums);
    // vector<int> Bubble_res = sort.BubbleSort(nums);
    // cout << "Bubble Sort: " << endl;
    // sort.printList(Bubble_res);
    // cout << sort.BubbleSort(nums) << endl;
}