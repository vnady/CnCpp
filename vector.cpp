#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    
    int size;
    vector<int> ver;
    vector<string> result;
    
    while(n-- > 0)
    {
        ver.clear();
        
        cin>>size;
        for(int i=0; i<size; i++)
        {
            int tmp;
            cin>>tmp;
            ver.push_back(tmp);
        }
        if(std::accumulate(ver.begin()+1, ver.end(), 0) == 0 || std::accumulate(ver.begin(), ver.end()-1, 0) ==  0)
        {
            result.push_back("YES\n");
        }
        else
        {
            int i=1;
            for(; i<size-1; i++)
            {
                int sumR=0,sumL=0;
                for(int j=0; j<i; j++)
                {
                    sumR += ver[j];
                }
                for(int j=i+1; j<size; j++)
                {
                    sumL += ver[j];
                }
                
                if(sumR == sumL)
                {
                    result.push_back("YES\n");
                    break;
                }
            }
            
            if(i == size-1)
            {
                result.push_back("NO\n");
            }
        }
    }
    
    n = result.size();
    for(int i=0; i < n; i++)
    {
        cout <<result[i];
    }

    return 0;
}
