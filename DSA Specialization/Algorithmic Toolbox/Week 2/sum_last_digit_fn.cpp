#include <iostream>
#include <vector>
using namespace std;



int fibonacci_modulo(long long n)
{
    int previous = 0;
    int current = 1;
    int period = 60;
    int reduced_n = n%period;
    cout<< reduced_n;
    vector<int> series;
    series.push_back(0);
    series.push_back(1);
    for (int i = 2; i < period; i++)
    {
        int tmp = (series[i-2] + series[i-1])%10;
        series[i] = tmp;
        // cout<<series[i]<<' ';
    }
    // cout<<endl<<series[0]<<' ';
    // cout<<endl << reduced_n<<endl;
    return series[reduced_n];  
}
int fibonacci_sum(long long n)
{
    // sigma f(n) = fn+2 - 1
    int sum = 0;
    if (n>1)
    {
        int fnp2 = fibonacci_modulo(n+2);
        if (fnp2!=0)
        {
            fnp2 -= 1;
        }
        else
        {
            fnp2 = 9;
        }
        sum = fnp2;
        cout<<sum<<endl;
    }
    else
    {
        sum = n;
    }
    // cout<< sum<< endl;
    return sum;    
}

int main()
{
    long long n;
    cin >> n ;
    int answer = fibonacci_sum(n);
    // cout << answer;
    return 0;
}
