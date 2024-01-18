One way to serialize a binary tree is to use preorder traversal. 
When we encounter a non-null node, we record the node's value. 
If it is a null node, we record using a sentinel value such as '#'.


For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.

Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.

It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid.

For example, it could never contain two consecutive commas, such as "1,,3".
Note: You are not allowed to reconstruct the tree.

 

Example 1:

Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
Example 2:

Input: preorder = "1,#"
Output: false
Example 3:

Input: preorder = "9,#,#,1"
Output: false
 

Constraints:

1 <= preorder.length <= 104
preorder consist of integers in the range [0, 100] and '#' separated by commas ','.

class Solution {
public:
    bool isValidunity(vector<int>& preorderlist,const int& n, int& cur){
         bool left,right;
         //left
         if(++cur >= n)return false;
         if(preorderlist[cur]==1){
            left = isValidunity(preorderlist,n,cur);
         }
         else{
            left=true;
         }
         //right
         if(++cur >= n)return false;
         if(preorderlist[cur]==1){
            right = isValidunity(preorderlist,n,cur);
         }
         else{
            right=true;
         }
         return left&&right;
    }
    bool isValidSerialization(string preorder) {
        if(preorder[0] == '#')return preorder.length()==1;
        vector<int> preorderlist;
        int i=0;
        string temp="";
        while(i<preorder.length()){
            if(preorder[i]==','){
                if(temp=="#")preorderlist.push_back(0);
                else preorderlist.push_back(1);
                temp="";
                i++;
            }
            else{
                temp+=preorder[i];
                i++;
            }
        }
        if(temp=="#")preorderlist.push_back(0);
        else preorderlist.push_back(1);
        int n=preorderlist.size();
        int cur = 0;
        return isValidunity(preorderlist,n,cur) && cur==n-1;
    }
};

class Solution {
public:
    bool isValidSerialization(string pre) {
        int vac=1;
        for(int i=0;i<pre.size();i++)
        {
            //if we encounter a , then do nothing
            if(pre[i]==',')
                continue;
            
            //reduce the vacancy as the current value eats up a vacancy by becoming the child of the previous parent node
            vac--;
            //increment the iterator till we encounter a nmbr because node value can be of more than one digit
            while(i<pre.size() && pre[i]>='0'&&pre[i]<='9'&&pre[i]!=',')i++;
            // if here we have an invalid vacancy then preorder is not correct i.e tree cannot be formed out of it
            if(vac<0)
                return false;
            //if the current value is not # then it will contribute 2 vacancy of left and right child hence increase vacancy
            if(pre[i]!='#')
                vac+=2;
        }
        //if vacancy is still left but string is finished then we will return false
        if(vac)
            return false;
        return true;
    } // isValidSerialization()
};