#include <iostream>
using namespace std;


void obratSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]); 
            }
        }
    }
}


void selectionSort(int arr[], int n) 
{ 
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j; 
            }
        }
        swap(arr[min_idx], arr[i]); 
    }
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot) { 
            i++;
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i + 1], arr[high]); 
    return (i + 1);
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high)
    {
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    int arr1[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Исходный массив для обратной сортировки: ";
    printArray(arr1, n1);

    obratSort(arr1, n1);

    cout << "Отсортированный массив: ";
    printArray(arr1, n1);

    
    int arr2[] = { 29, 10, 14, 37, 13 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Исходный массив для сортировки выбором: ";
    printArray(arr2, n2);

    selectionSort(arr2, n2); 

    cout << "Отсортированный массив: ";
    printArray(arr2, n2);

    
    int arr3[] = { 10, 7, 8, 9, 1, 5 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    cout << "Исходный массив для быстрой сортировки: ";
    printArray(arr3, n3);

    quickSort(arr3, 0, n3 - 1); 

    cout << "Отсортированный массив: ";
    printArray(arr3, n3);

    return 0;
}