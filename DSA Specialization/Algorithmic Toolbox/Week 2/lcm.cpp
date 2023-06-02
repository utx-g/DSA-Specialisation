#include <iostream>
#include <vector>

using namespace std;
long gcd_fast(long n, long m)
{
    if (m == 0)
        return n;
    return gcd_fast(m, n % m);
}
long lcm_fast(long n, long m)
{
    long double prod = n*m;
    int gcd = gcd_fast(n,m);
    return prod/gcd;    
}

int main()
{
    long n, m;
    cin >> n >> m;
    long answer = lcm_fast(n, m);
    cout << answer << endl;
    return 0;
}
