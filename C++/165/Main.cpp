Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. 
Each revision consists of digits and may contain leading zeros. 
Every revision contains at least one character. 
Revisions are 0-indexed from left to right, 
with the leftmost revision being revision 0, 
the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in 
left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. 
This means that revisions 1 and 001 are considered equal. 
If a version number does not specify a revision at an index, 
then treat the revision as 0. For example, version 1.0 is less than version 1.1 
because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.

class Solution {
public:
    vector<int> toVec(string s){
        vector<int> res;
        int temp=0;
        for(char c:s){
            if(c=='.'){
                res.push_back(temp);
                temp=0;
            }
            else{
                temp*=10;
                temp+=c-'0';
            }
        }
        res.push_back(temp);
        return res;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        v1=toVec(version1);v2=toVec(version2);
        int v1_n=v1.size(),v2_n=v2.size();
        int i=0;
        while(i<v1_n&&i<v2_n){
            if(v1[i]!=v2[i])return v1>v2?1:-1;
            i++;
        }
        if(v1_n==v2_n)return 0;
        if(v1_n>v2_n){
            while(i<v1_n){
                if(v1[i])return 1;
                i++;
            }
            return 0;
        }
        else{
            while(i<v2_n){
                if(v2[i])return -1;
                i++;
            }
            return 0;
        }
    }
};