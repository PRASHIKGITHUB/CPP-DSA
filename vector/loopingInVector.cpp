#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    vector<int> v; // if size were mentioned you could have used it as an array while taking input
    for (int i = 0; i < 5; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    // for loop
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " "; // here size is defined so we can use
    }
    cout << endl;
    v.insert(v.begin() + 2, 6);
    // while loop
    int idx = 0;
    while (idx < v.size())
    {   
        cout << v[idx++] << " ";
    }
    idx = 0;
    cout << endl;
    v.erase(v.end() - 2);//----------<>
    while (idx < v.size())
    {
        cout << v[idx++] << " ";
    }

    return 0;
}