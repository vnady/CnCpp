#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
bool IsChangePairStr(const string _str1, const string _str2)
{
    int size1=_str1.size(), size2=_str2.size();
    size_t po=string::npos;

    if(size1 != size2)
    {
        return false;
    }

    string tmp;
    tmp.assign(_str1.begin(), _str1.end());

    for(int j=0; j < size1; j++)
    {
        po=tmp.find(_str2[j], 0);
        if(po != ::string::npos)
        {
            tmp.erase(po, 1);
        }
        else
        {
            return false;
        }
    }

   if(tmp.size() != 0)
   {
       return false;
   } 

   return true;
}
*/

int CountChangeSubstrPair(string _str)
{
    vector<string> veSubstr;
    int size = _str.size();
    int len=1;
    int count=0;
    string strTmp;

    /* create substring */
    while(len <size){
    for(int i=0; i+len<= size; i++)
    {
        strTmp=_str.substr(i,len);
        std::sort(strTmp.begin(), strTmp.end());
        veSubstr.push_back(strTmp);
        strTmp.clear();    
    }
    
    len++;
    }    
    
    /* local optimization */
    int CharNum[26]={0};
    for(int i=0;i < size; i++)
    {
        CharNum[_str[i]-'a'] += 1;
    }
    
    int tmp;

    for(int i=0; i < 26; i++)
    {
        tmp = CharNum[i];
        if(!(tmp < 2))
        {   
            count += ((tmp*(tmp-1))/2); 
        }
    }
    /* count change substr pair */
    int size_substr = veSubstr.size();
    for(int i=size, j; i < size_substr-1;i++)
    {
        j = i+1;
        while(j<size_substr)
        {
            if(veSubstr[j] == veSubstr[i])
            {
                count += 1;
                /* enable code to ignore repeat pair
                veSubstr.erase(veSubstr.begin()+i);
                j -= 1;
                veSubstr.erase(veSubstr.begin()+j);
                i -= 1;
                size = veSubstr.size();
                break;
                */
            }
            j++;
        }
    }

    return count;
}


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    int n;
    //char c;

    cin>>n;
    //c=getchar();
    
    for(int i=0; i < n; i++)
    {
        cin >>s;

        cout <<CountChangeSubstrPair(s)<<endl;
    }

    return 0;
}
