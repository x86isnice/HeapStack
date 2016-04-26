#include <iostream>

using namespace std;
int HeapSize = 100;

inline int GetLeft(int index)
{
   return (index*2+1);
}

inline int GetRight(int index)
{
   return (index*2 +2);
}

 inline void swap(int &a,int &b)
 {
    int tem = a;
    a = b;
    b= tem;
 }

inline void HeapFit(int arr[], int index)
{
     int large = index;
     int left = GetLeft(index);
     int right = GetRight(index);

     if (left < HeapSize && arr[left] > arr[index])
           large = left;

     if (right < HeapSize && arr[right] > arr[large])
            large = right;

     if (large != index)
     {
         swap(arr[large] , arr[index]);
         HeapFit(arr , large);
     }
}

void BuildHeap(int arr[], int length)
{
     for (int i = length/2; i >=0; i--)
     {
        HeapFit(arr, i);
     }
}

void sort_Myheap(int arr[],int length)
{
     for (int i = length-1; i > 0 ; i--)
     {
        swap(arr[0],arr[i]);
        BuildHeap(arr, i);
     }
}

int main()
{
    int a[11] ={23,67,211,445,3,76,2,99,43,56};
    sort_Myheap(a,10);
    for (int i = 0; i < 10; i++)
       cout << a[i];
    return 0;
}
