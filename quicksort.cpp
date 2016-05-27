nclude <bits/stdc++.h>
using namespace std;

void quickSort(vector <int> &arr) {
    // Complete this function
    int i=0, j=1;
    int size = arr.size();
    int tmp;

    for(; j < size; j++)
    {
        if(arr[i] > arr[j])
        {
            tmp = arr[j];
            for(int t=j; t > i; t--)
            {
                arr[t] = arr[t-1];
            }
            arr[i] = tmp;
            i += 1;
        }
    }
    
    vector<int> sub1;
    if(i <= 1)
    {
        sub1.assgin(arr.begin(), arr.begin() + i);           
    }

    quikSort(arr[0:i]);
    quikSort(arr[i+1:]);

}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
