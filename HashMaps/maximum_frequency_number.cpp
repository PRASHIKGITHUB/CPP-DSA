#include<bits/stdc++.h>
using namespace std;
int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> count;
    int maxfre=INT_MIN;
    int ans;
    for(int i=0;i<n;i++){
        count[arr[i]]++;
        maxfre=max(maxfre,count[arr[i]]);
    }
    for(int i=0;i<n;i++){
        if(maxfre==count[arr[i]]){
            ans=arr[i];
            break;
        }
    }
    return ans;
}
int main(){
    vector<int>v={1,2,3,1,2};
    cout<<maximumFrequency(v,5)<<endl;
    return 0;
}