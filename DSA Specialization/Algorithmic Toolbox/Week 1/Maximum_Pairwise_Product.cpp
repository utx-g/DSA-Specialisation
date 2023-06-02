#include <iostream>
#include <vector>
using namespace std;



long long Maximum_Pairwise_Product(int n, vector<int>& inp)
{
    int max1 , max2, element, max1_index, max2_index;
    max1 = max2 = element = max1_index = max2_index = -1;
    for(int i = 0; i < n; ++i)
    {
        element = inp[i];
        if (element > max1)
        {
            max1 = element;
            max1_index = i;
        }
    }
    for(int i = 0; i < n; ++i)
    {
        element = inp[i];
        if (element > max2 && i != max1_index)
        {
            max2 = element;
            max2_index = i;
        }
    }
    return ((long long)(max1))*max2;
}


int main() 
{
    int n;
    long long mpp;
    cin>>n;
    vector<int> inp;
    for(int i = 0; i < n;++i)
    {
        int x;
        cin >> x;
        inp.push_back(x); 
    }
    mpp = Maximum_Pairwise_Product(n, inp);
    cout<<(mpp);
    return 0;
}
