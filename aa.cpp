#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CountChangeSubstrPair(string _str)
{
    vector<string> veSubstr;
    int size = _str.size();
    int len=1;
    int count=0;

    /* create substring */
    while(len <size){
    for(int i=0; i+len<= size; i++)
    {
        veSubstr.push_back(_str.substr(i,len));    
    }

    len++;
    }    

    /* count change substr pair */
    size = veSubstr.size();
    string tmp;
    const char *p;

    for(int i=0, j; i < size-1;)
    {
        j = i+1;
        while(j<size)
        {
            tmp.assign(veSubstr[j].rbegin(), veSubstr[j].rend());
            p = veSubstr[j].c_str();

            if(veSubstr[i].size() != tmp.size())
            {
                break;
            }

            if(tmp == veSubstr[i])
            {
                count += 1;
                cout <<veSubstr[j]<<endl;

                veSubstr.erase(veSubstr.begin()+i);
                veSubstr.erase(veSubstr.begin()+j);
                i -= 1;
                size = veSubstr.size();

                break;
            }

            j++;

            tmp.clear();
        }

        i++;
    }

    return count;
}


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    vector<int> result;
    int n;
    //char c;

    cin>>n;
    //c=getchar();
    
    for(int i=0; i < n; i++)
    {
        cin >>s;

        result.push_back(CountChangeSubstrPair(s));
    }

    for(int i=0; i < n; i++)
    {
        cout <<result[i]<<endl;
    }

    return 0;
}
