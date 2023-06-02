#include <iostream>
#include <vector>
using namespace std;



int fibonacci_modulo(long long n, int m)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;
    int period = 60;
    int reduced_n = n % period;

    for (int i = 2; i <= reduced_n; i++)
    {
        int tmp = (previous + current) % m;
        previous = current;
        current = tmp;
    }

    return current;
}
int fibonacci_sum(long long n, long long m)
{
    // sigma f(n) = fn+2 - 1
    int sum = 0;
    int fnp1 = n;
    int fmp2 = m;
    if (n>0)
    {
        fnp1 = fibonacci_modulo(n+1,10);
    }
    else
    {
        fnp1++;
    }
    if (m>0)
    {
        fmp2 = fibonacci_modulo(m+2, 10);
    }
    else 
    {
        fmp2++;
    }
    sum = fmp2-fnp1;
    
    if (sum<0)
    {
        sum += 10;
    }
    return sum;    
}

int main()
{
    long long n, m;
    cin >> n >> m;
    int answer = fibonacci_sum(n, m);
    cout << answer << endl;
    return 0;
}
