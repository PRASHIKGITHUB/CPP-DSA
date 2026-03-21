#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        size = 0;
        arr[0] = -1;
    }

    void insert(int val) // max TC is O(log(n))
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()//it will always delete the max element that is first element
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }

        // put last node element at root node
        arr[1] = arr[size];

        // remove last node
        size--;

        // put root node at corect position
        int i = 1;

        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex] && arr[leftIndex] > arr[rightIndex])//leftIndex par dal diya
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }

            else if (rightIndex < size && arr[i] < arr[rightIndex] && arr[leftIndex] < arr[rightIndex])//right index par dal diya
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }

            else
            {
                return;
            }
        }
    }
};
// note that except ith index everything else is heap
void heapify(int arr[], int size, int i)
{
    int largest = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;

    if (leftIndex <= size && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
        cout << "moto" << endl;
    }
    if (rightIndex <= size && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
        cout << "hello" << endl;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}
int main()
{
    heap h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(6);
    h.insert(7);
    h.print();
    // h.deletefromHeap();
    // h.print();
    int arr[] = {-1, 1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    for (int i = n / 2; i >=1; i--)//you dont need to do this for leaf nodes
    {
        heapify(arr, n, i);
    }
    // heapify(arr,n,3);
    cout << "Printing the array" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}