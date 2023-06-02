#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int furthest_stop(int current, int d, int m, int n, int arr[300])
{
    int range = current + m;
    int stop = -1;
    if (range>d)
    {
        return d;
    }
    for(int i = 0; i < n; ++i)
    {
        if (arr[i]>=current && arr[i]<= range) 
        {
            stop = arr[i];
        }
    }
    if(current == stop)
    {
        return -1;
    }
    return stop;
}
int car_fuel(int d, int m , int n, int arr[300])
{
    int min_stops = 0;
    int current = 0;
    while (current<d)
    {
        // cout<<current<<' ';
        int next_stop = furthest_stop(current,d,m,n,arr);
        if (next_stop != -1 )
        {
            // cout<<next_stop<<endl;
            if (next_stop != d)
            {
                min_stops++;
            }
            current = next_stop;
        }
        else
        {
            return -1;
        }
    }
    return min_stops;
}

int main()
{
    int d, m, n, arr[300];
    cin >> d >> m >> n;
    for(int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int answer = car_fuel(d,m,n,arr);
    cout << answer << endl;
    return 0;
}
