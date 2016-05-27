#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    int arr_size;
    vector <int> arr;
    vector <strng> result;

    cin >>n;
    while(n>0)
    {
        cin >>arr_size;

        for(int i=0; i < arr_size; i++)
        {
            int tmp;
            cin >>tmp;
            arr.psuh_back(tmp);
        }
        
        //calculate Maximum Subarray
        int Max_noContiguous = 0;
        int Max_Contiguous;
        int i=0;
        while(i < arr_size)
        {
            if(arr[i] > 0)
            {
                Max_noContiguous += arr[i]; 
            }
        }


        n--;
    }
    return 0;
}
