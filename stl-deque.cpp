#include<iostream>
#include<deque>
using namespace std;

void printKMax(int arr[], int n, int k)
{
    deque<int> suarr;
    int max=arr[0];
    
    if(1 == k)
    {
        for(int i=0; i < n; i++)
        {
            cout <<arr[i]<<" ";
        }
    }
    else
    {
        for(int i=0; i < k; i++)
        {
            suarr.push_back(arr[i]);
            if(max < arr[i])
            {
                max = arr[i];
            }
        }
        cout <<max<<" ";
        
        for(int j=k; j < n; j++)
        {
            if(max == suarr[0])
            {
                max = suarr[1];
                for(int i=2; i < k; i++)
                {
                    if(max < suarr[i])
                    {
                        max = suarr[i];
                    }
                }
            }
            
            if(max < arr[j])
            {
                max = arr[j];
            }
            
            suarr.push_back(arr[j]);
            suarr.pop_front();
            
            cout<<max<<" ";
        }
    }
    cout<<"\n";
}

int main()
{
    int t;
    cin >>t;
    while(t>0)
    {
        int n,k;
        cin>>n>>k;
        
        int i=0;
        int arr[n];
        for(; i < n; i++)
        {
            cin>>arr[i];
        }
        
        printKMax(arr, n, k);
        t--;
    }
    
    return 0;
}
