#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=0;
        int size=s.size();
        int reslut=1;
        
        if(0 == size)
        {
            return 0;
        }
        else if(1 == size)
        {
            return 1;
        }
        
        string d(s);
        sort(d.begin(), d.end());
        
        if(d[0] == d[size-1])
        {
            return 1;
        }
        
        int i=0;
        while(i < (size-1) && d[i] != d[i+1])
        {
            i++;
        }
        if(size-1 == i)
        {
            return size;
        }
        
        //字母重复切割子串
        int j=0,prej=0,jn=0,tmp;
        while(j < size && s[0] == s[j])j++;
        prej = j-1;
        
        if(s[0] != d[i])
        {
            while(j<size)
            {
                while(j < size && s[j] != d[i]) j++;
                
                //跳过连续出现的重复字母
                jn=j;
                while(jn < size && s[jn] == s[jn+1]) jn++;
                if((j-prej) < reslut)
                {
                    prej = jn;
                    j = jn+1;
                    
                    continue;
                }
                
                if(0 == prej)
                {
                    tmp = lengthOfLongestSubstring(s.substr(prej,j+1));
                    if(tmp > reslut)
                    {
                        reslut = tmp;
                    }
                    
                    prej = jn;
                }
                else if(size == j)
                {
                    tmp = lengthOfLongestSubstring(s.substr(prej,j));
                    if(tmp > reslut)
                    {
                        reslut = tmp;
                    }
                }
                else
                {
                    tmp = lengthOfLongestSubstring(s.substr(prej,j));
                    if(tmp > reslut)
                    {
                        reslut = tmp;
                    }
                    
                    tmp = lengthOfLongestSubstring(s.substr(prej+1,j+1));
                    if(tmp > reslut)
                    {
                        reslut = tmp;
                    }
                    
                    prej = jn;
                }
                
                j = jn+1;
            }
        }
        else if(s[0] == d[i])
        {
            while(j<size)
            {
                while(j < size && s[j] != d[i]) j++;
                
                //跳过连续出现的重复字母
                jn=j;
                while(jn < size && s[jn] == s[jn+1]) jn++;
                
                if((j-prej) < reslut)
                {
                    prej = jn;
                    j = jn + 1;
                    
                    continue;
                }
                
                if(size == j)
                {
                    tmp = lengthOfLongestSubstring(s.substr(prej,j));
                    if(tmp > reslut)
                    {
                        reslut = tmp;
                    }
                }
                else
                {
                    tmp = lengthOfLongestSubstring(s.substr(prej,j));
                    if(tmp > reslut)
                    {
                        reslut = tmp;
                    }
                    
                    tmp = lengthOfLongestSubstring(s.substr(prej+1,j+1));
                    if(tmp > reslut)
                    {
                        reslut = tmp;
                    }
                    
                    prej = jn;
                }
                
                j = jn+1;
            }
        }
        
        return reslut;
    }
};
int main()
{
    class Solution s;
    
    string str;
    cin>>str;
    cout <<s.lengthOfLongestSubstring(str)<<endl;
    
    return 0;
}
