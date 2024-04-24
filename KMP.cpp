//kmp algorithm for string matching returning first index where target string found 

class Solution {
    void computeLPS(string s, vector<int> & LPS)
    {
        int n = s.length();
        int len = 0;
        int i = 1;
        while(i < n)
        {
           if(s[i] == s[len])
           {
              len++;
              LPS[i] = len;
              i++;
           }
           else{
              if(len != 0)
              {
                 len = LPS[len - 1];
              }
              else{
                LPS[i] = 0;
                i++;
              }
           }
        }
    }
public:
    int KMP(string haystack, string needle) {
         vector<int> LPS(needle.length(), 0);
         computeLPS(needle, LPS);
         int j = 0;
         for(int i = 0; i < haystack.length(); i++)
         { 
            if(haystack[i] == needle[j])
            j++;
            else{
                if(j != 0)
                 {j = LPS[j - 1]; i--;}
            }
            if(j == needle.length())
            return i - j + 1;
         }
         return -1;
    }
};
