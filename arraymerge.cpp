#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    // TODO:
    // Create temporary arrays
    // Copy data
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int* l = new int[size1];
    int* r = new int[size2];
    for (int i = 0; i < size1; i++){
        l[i] = arr[left+i];
    }
    for (int j = 0; j < size2; j++){
        r[j] = arr[left+j];
    }

    // Merge sorted halves back into arr

    int i = 0, j = 0, s = left;

    while (i < size1 && j < size2) {
        if (l[i] <= r[j]) {
            arr[s] = l[i];
            i++;
        } else {
            arr[s] = r[j];
            j++;
        }
        s++;
    }

    while (i < size1) {
        arr[s] = l[i];
        i++;
        s++;
    }

    while (j < size2) {
        arr[s] = r[j];
        j++;
        s++;
    }

    delete[] l;
    delete[] r;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // TODO:
        // Find middle
        int mid = (right + left) / 2;
        // Recursively sort left half
        mergeSort(arr, left, mid);
        // Recursively sort right half
        mergeSort(arr, mid+1, right);
        // Merge both halves
        merge(arr, left, mid, right);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[10] = {38, 27, 43, 3, 9, 82, 10, 5, 61, 14};
    int n = 10;

    cout << "Before Sorting: ";
    display(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "After Sorting: ";
    display(arr, n);

    return 0;
}
