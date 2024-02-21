You are given an array of strings arr. 
A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting 
some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int result=0;
        for(int i=0;i<arr.size();i++){
            int cur=0;
            bool flag=true;
            int cache[27] = {0};
            for(char c:arr[i]){
                cache[c-'a']++;
                if(cache[c-'a'] > 1){
                    flag = false;
                    break;
                };
            }
            if(!flag)continue;
            cur+=arr[i].size();
            for(int k=i+1;k<arr.size();k++){
                flag=true;
                int move=0;
                while(move >= 0 && move < arr[k].size()){
                    if(flag){
                        cache[arr[k][move]-'a']++;
                        if(cache[arr[k][move]-'a'] > 1)flag=false;
                        else move++;
                    }
                    else{
                        cache[arr[k][move]-'a']--;
                        move--;
                    }
                }
                if(flag) cur+=arr[k].size();
            }
            result = max(cur,result);
        }
        return result;
    }
        
};

["abcdefghijklm","bcdefghijklmn","cdefghijklmno","defghijklmnop","efghijklmnopq","fghijklmnopqr","ghijklmnopqrs","hijklmnopqrst","ijklmnopqrstu","jklmnopqrstuv","klmnopqrstuvw","lmnopqrstuvwx","mnopqrstuvwxy","nopqrstuvwxyz","opqrstuvwxyza","pqrstuvwxyzab"]

class Solution {
public:
    void rec(vector<string>& arr, vector<int>& cache, int i,int &cur, int &res){
        if(i>=arr.size())return;
        bool flag=true;
        int k=0;
        while( k >= 0 && k <arr[i].size()){
            if(flag){
                cache[arr[i][k]-'a']++;
                if(cache[arr[i][k]-'a'] > 1)flag = false;
                else k++;
            }
            else {
                cache[arr[i][k]-'a']--;
                k--;
            }
        }
        if(flag){
            cur+=arr[i].size();
            res = max(res,cur);
            rec(arr,cache,i+1,cur,res);
            cur-=arr[i].size();
            for(char c:arr[i])cache[c-'a']--;
        }
        rec(arr,cache,i+1,cur,res);
    }
    int maxLength(vector<string>& arr) {
        int res=0;
        int cur=0;
        vector<int> cache(27,0);
        rec(arr,cache,0,cur,res);
        return res;
    }
};

class Solution 
{
public:
    int maxLength(vector<string>& arr) 
    {
        int max_len = 0;
        
        // [1] we should first throw away all strings with any
        //    duplicate characters; strings with all unique 
        //    characters are the subsets of the alphabet, thus,
        //    can be encoded using binary form
        vector<bitset<26>> unique;
        for (auto s : arr)
        {
            bitset<26> bin;
            for (char ch : s) bin.set(ch - 'a');
            if (bin.count() == s.size())
                unique.push_back(bin);
        }
        
        // [2] now start with an empty concatenation and iteratively
        //    increase its length by trying to add more strings
        vector<bitset<26>> concat = {bitset<26>()};
        for (auto& u : unique)
            for (int i = concat.size() - 1; i >= 0; i--)
                if ((concat[i] & u).none())
                {
                    concat.push_back(concat[i] | u);
                    max_len = max(max_len, (int)(concat[i].count() + u.count()));
                }
        
        return max_len;
    }
};