#include<iostream>
using namespace std;

long long CountComonations(int list[], int n, int money)
{
    long long count=0;
    int i=n-1;
    
    if(money == 0)
    {
        return 0;
    }

    for(; i>-1; i--)
    {
        if(money >= list[i])
        {
            break;
        }    
    }   

    if(0 == i)
    {
        return 1;
    }

    int t=money/list[i];
    if(0 == money % list[i])
    {
        count += 1;
    }
    else
    {
        count += CountComonations(list, i, money - list[i]*t);
    }

    for(int j=0; j<t; j++)
    {
        count += CountComonations(list, i, (money-list[i]*j));
    }

    return count;
}

int main()
{
    int list[9]={1,5,10,50,100,500,1000,2000,5000};
    int money;

    cin>>money;

    cout <<CountComonations(list, 9, money)<<endl;

    return 0;
}
