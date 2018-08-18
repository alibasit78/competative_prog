#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
   long long int sum=0;
    vector<long long int> temp(n);
    if(n==1)
        return 1;
    else
    {
        temp[0]=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
            {
                temp[i]=temp[i-1]+1;
            }
            else
            {   
                temp[i]=1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if( arr[i]>arr[i+1] && temp[i]<=temp[i+1] )
            {
                temp[i]=temp[i+1]+1;
            }
        }
        
    }
    for(int i=0;i<n;i++)
        sum+=temp[i];
    return sum;

}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
