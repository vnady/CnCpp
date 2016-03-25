#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int CountInsertionSort(vector <int>  ar) {
    int ar_size=ar.size();
    int tmp;
    int count=0;

    if(ar_size < 2)
        return 0;

    for(int i=ar_size-1,j; i > 0;)
    {
        j = i-1;
        if(ar[j] > ar[i])
        {
            tmp = ar[i];
            ar[i] = ar[j];
            ar[j] = tmp;
            count += 1;

            while(i < (ar_size-1) && ar[i] > ar[i+1])
            {
                tmp = ar[i];
                ar[i] = ar[i+1];
                ar[i+1] = tmp;
                count += 1;

                i += 1;
            }
        }
        
        i = j;
    }

    return count;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;

    cin >>n;
    vector <int> ar;

    for(int i=0; i< n; i++)
    {
        int ar_tmp;
        cin >>ar_tmp;
        ar.push_back(ar_tmp);
    }

    cout <<CountInsertionSort(ar)<<endl;
    return 0;
}
