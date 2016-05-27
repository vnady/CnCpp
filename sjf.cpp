#include<iostream>
#include<vector>
using namespace std;

float waitingTimeSJF(int *requestTimes, int *durations, int n)
{
    int sum_r=0;
    int sum_dura=0;
    int sum_ndura=0;
    
    //重新排序
    
    for(int i=0; i<n; i++)
    {
        sum_r += requestTimes[i];
        sum_dura += durations[i];
        if(i < n-1)
        {
            sum_ndura += (i+1)*durations[i];
        }
    }

    return  (requestTimes[0] + sum_dura - (sum_r + sum_ndura)/n);
}
