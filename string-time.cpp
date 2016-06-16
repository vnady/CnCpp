#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string time;
    cin >> time;
    char nums[]="0123456789";
    
    if(time[time.size()-2] == 'P')
    {
        if(time[0] == '0')
        {
            if(time[1] > '7')
            {
                time[0] = '2';
                time[1] = nums[(time[1] - '0') + ('2' - '0') - 10];
            }
            else
            {
                time[0] = '1';
                time[1] = nums[(time[1] - '0') + ('2' - '0')];
            }
        }
        else
        {
            time[0] = '2';
            time[1] = nums[(time[1] - '0') + ('2' - '0')];
        }
    }
    
    cout <<time.substr(0,time.size()-2)<<endl;
    
    return 0;
}
