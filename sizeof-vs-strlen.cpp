#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main()
{
    int a[6]={1,2,3,4,5,6};
    int *ptr=(int*)(&a+1);

    cout <<*(a+1)<<endl;
    cout <<*(ptr-1)<<endl;

    return 0;
}
