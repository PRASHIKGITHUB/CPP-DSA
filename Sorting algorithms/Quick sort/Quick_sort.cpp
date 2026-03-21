#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int s, int e)
{
    int cnt = 0;
    int pivot = arr[s];
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);
    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[e] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(vector<int> &nums, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int k = partition(nums, s, e);

    quickSort(nums, s, k - 1);
    quickSort(nums, k + 1, e);
}
int main()
{
    vector<int> v = {-4, 0, 7, 4, 9, -5, -1, 0, -7, -1};
    quickSort(v, 0, v.size() - 1);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    // -4,0,7,4,9,-5,-1,0,-7,-1
    return 0;
}