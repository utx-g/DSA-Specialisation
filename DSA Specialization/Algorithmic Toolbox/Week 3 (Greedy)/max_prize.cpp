#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> max_prize(int n)
{
    vector<int> prize ;
    int k = 0;
    while(true)
    {
        if((k*(k+1)/2) > n)
        {
            break;
        }
        ++k;
    }
    k--;
    int remaining = n - (k*(k+1))/2;
    for(int i=1; i<=k; ++i)
    {
        prize.push_back(i);
    }
    prize[k-1] += remaining;
    return prize;
}

int main()
{
    int n;
    cin>>n;
    vector<int> answer = max_prize(n);
    cout<<answer.size()<<endl;
    for(int i = 0; i < answer.size(); ++i)
    {
        cout<<answer[i]<<' ';
    }
    return 0;
}
