#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;


int profitable_segment(int n, vector <vector <int>> times)
{
    int index, start_time = 1000000000, end_time = 1000000000;
    for(int i = 0; i < n; ++i)
    {
        vector <int> row = times[i];
        if(row[0]< start_time)
        {
            start_time = row[0];
            index = i;
        }
    }
    for(int i = 0; i < n; ++i)
    {
        vector <int> row = times[i];
        if(row[0] == start_time)
        {
            if(row[1]< end_time)
                {
                    end_time = row[1];
                    index = i;
                }
        }
    }
    return index;
}


vector<int> collecting_sign(int n, vector <vector <int>> times)
{
    vector<int> trips;
    while(n!=0)
    {
        int choice = profitable_segment(n,times);
        int start = times[choice][0];
        int shortest_end = 1000000000;
        int end = times[choice][1];
        // cout<<"Choice "<<start<<' '<<end<<endl; 
        for(int i = 0;  i < times.size(); ++i){
            vector<int> time = times[i];
            if(time[0]<=end)
            {
                // cout<< "Erase "<<time[0]<<' '<<time[1]<<endl;
                times.erase(times.begin() + i);
                if(shortest_end>time[1])
                {
                    shortest_end = time[1];
                }
                i--;
                n--;
            }
        }
        // cout<<shortest_end<<endl;
        trips.push_back(shortest_end);
    }
    return trips;
}

int main()
{
    int n;
    vector <vector<int>> times;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        vector <int> row;
        int a,b;
        cin >> a>>b;
        row.push_back(a);
        row.push_back(b);
        times.push_back(row);
    }
    vector<int> answer = collecting_sign(n, times);


    // cout<<"---------------Answer---------------"<<endl;
    cout<<answer.size()<<endl;
    for(int i = 0; i < answer.size(); ++i)
    {
        cout<<answer[i]<<' ';
    }
    return 0;
}
