#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int array[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void heapify(int array[], int n, int current)
{
    int largest = current;
    int left = 2 * current + 1;
    int right = 2 * current + 2;
    if (left < n && array[left] > array[largest])
    {
        largest = left;
    }
    if (right < n && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != current)
    {
        swap(array[current], array[largest]);
        heapify(array, n, largest);
    }
}

int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Before Heapify: ";
    printArray(array, n);
    int nonLeafStart = (n / 2) - 1;
    for (int i = nonLeafStart; i >= 0; i--)
    {
        heapify(array, n, i);
    }
    cout << "After Heapify: ";
    printArray(array, n);

    return 0;
}
