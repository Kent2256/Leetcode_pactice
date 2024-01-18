Given three strings a, b, and c, your task is to find a string that has the minimum length and 
contains all three strings as substrings.
If there are multiple such strings, return the lexicographically smallest one.

Return a string denoting the answer to the problem.

Notes

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b.
A substring is a contiguous sequence of characters within a string.
 

Example 1: abcbca
            bcaabc
           bca cba
Input: a = "abc", b = "bca", c = "aaa"
Output: "aaabca"
Explanation:  We show that "aaabca" contains all the given strings: a = ans[2...4], b = ans[3..5], c = ans[0..2]. It can be shown that the length of the resulting string would be at least 6 and "aaabca" is the lexicographically smallest one.
Example 2:

Input: a = "ab", b = "ba", c = "aba"
Output: "aba"
Explanation: We show that the string "aba" contains all the given strings: a = ans[0..1], b = ans[1..2], c = ans[0..2]. Since the length of c is 3, the length of the resulting string would be at least 3. It can be shown that "aba" is the lexicographically smallest one.
 

Constraints:23456234567
            00000012345

1 <= a.length, b.length, c.length <= 100
a, b, c consist only of lowercase English letters.

class Solution {
public:
    string mergetwoString(string a, string b){
        int n=a.length(), m=b.length();
        //1. check included or not 
        if(a.find(b)!=a.npos) return a;
        //2. merge string
        int i=min(m,n)-1;
        string res="";
        while(i>=0 && res==""){
            if(a.substr(n-i)==b.substr(0,i)) res= a + b.substr(i);
            i--; 
        }
        return res;
    }
    string minimumString(string a, string b, string c) {
        string s[3]={a,b,c};
        string res=""; 
        string temp;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(j==i)continue;
                for(int k=0;k<3;k++){
                    if(k==i || k==j)continue;
                        temp = mergetwoString(s[i],s[j]);
                        if(res=="")res = mergetwoString(temp,s[k]);
                        else{
                            temp = mergetwoString(temp,s[k]);
                            if(res.length()>temp.length()) res=temp;
                            else if(res.length()==temp.length()) res = res<temp?res:temp;
                        }
                }
            }
        }
        return res;
    }
};
class Solution
{
public:

    std::string buildString(const std::string &s1, const std::string &s2)
    {
        if (s1.find(s2) == std::string::npos)
        {
            int m = s1.size();
            int n = s2.size();
            int overlap = 0;

            for (int i = m - 1; i >= 0; --i)
            {
                int j = i;
                int k = 0;
                while (  j < m
                    && k < n
                    && s1[j] == s2[k])
                {
                    ++j;
                    ++k;
                }

                if (j == m)
                {
                    overlap = std::max(overlap, m - i);
                }
            }
            return s1.substr(0, m - overlap) + s2;
        }
        return s1;
    }

    std::string getMinString(const std::string &s1, const std::string &s2, const std::string &s3)
    {
        auto myMin = [] (const auto &left, const auto &right)
        {
            if (left.size() < right.size())
            {
                return left;
            }
            else if (right.size() < left.size())
            {
                return right;
            }
            return std::min(left, right);
        };

        std::string strings[] = { buildString(buildString(s1, s2), s3),
                                  buildString(buildString(s1, s3), s2),
                                  buildString(buildString(s2, s1), s3),
                                  buildString(buildString(s2, s3), s1),
                                  buildString(buildString(s3, s1), s2),
                                  buildString(buildString(s3, s2), s1),
                                  buildString(s1, buildString(s2, s3)),
                                  buildString(s1, buildString(s3, s2)),
                                  buildString(s2, buildString(s1, s3)),
                                  buildString(s2, buildString(s3, s1)),
                                  buildString(s3, buildString(s1, s2)),
                                  buildString(s3, buildString(s2, s1)) };

        std::string minString(s1 + s2 + s3);
        for (int i = 0; i < 12; ++i)
        {
            if (  strings[i].find(s1) != std::string::npos
               && strings[i].find(s2) != std::string::npos
               && strings[i].find(s3) != std::string::npos)
            {
                minString = myMin(minString, strings[i]);
            }
        }

        return minString;
    }

    std::string minimumString(const std::string &a, const std::string &b, const std::string &c)
    {
        return getMinString(a, b, c);
    }
};