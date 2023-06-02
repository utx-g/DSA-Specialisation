#include <iostream>
#include <vector>
using namespace std;

int most_profit(int n, double arr[1000][2])
{
    double highest_unit = -1;
    int corr_index = -1;
    for(int i = 0; i < n; ++i)
    {   
        if(arr[i][1] > 0)
        {
            double unit = arr[i][0]/arr[i][1];
            if (unit> highest_unit)
            {
                highest_unit = unit;
                corr_index = i;
            }
        }
    }
    return corr_index;
}

double max_loot(int n, int capacity, double arr[1000][2])
{
    double max_value = 0.0f;
    int weight_sum;
    while(capacity>0)
    {
        weight_sum = 0;
        for(int i = 0; i < n; ++i)
        {
            weight_sum += arr[i][1];
        }
        if (weight_sum==0)
        {
            break;
        }
        int profitable_index = most_profit(n, arr);
        double profitable_weight = arr[profitable_index][1]; // change to double
        if(profitable_weight != 0)
        {
            double highest_unit = arr[profitable_index][0]/arr[profitable_index][1];
            if(profitable_weight<=capacity)
            {
                max_value += profitable_weight*highest_unit;
                capacity -= profitable_weight;
                arr[profitable_index][1] = 0;
            }
            else
            {
                max_value += capacity*highest_unit;
                capacity = 0;
            }
        } 
    }
    return max_value;
}

int main()
{
    int n, capacity;
    double arr[1000][2];
    cin >> n >> capacity;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            cin>> arr[i][j];
        }
    }
    double answer = max_loot(n, capacity, arr);
    cout << fixed;
    cout.precision(3); // Sets the precision to 3 decimal places
    cout << answer << endl;
    return 0;
}
