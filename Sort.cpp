#include<iostream>
#include<vector>
using namespace std;

//•	Selection sort:

void SelectionSort(int a[], int n){
    int i, j, min_idex;
    for(i = 0; i < n ; i++){
        min_idex = i;
        for(j = i + 1; j < n ; j++){
            if(a[j] < a[min_idex]){
                min_idex = j;
            }
        }
        if(min_idex != i){
            swap(a[min_idex],a[i]);
        }
    }

}

// Insertion sort:

void InsertionSort(int a[], int n){
    
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void BubbleSort(int a[], int n){
    int i, j;
    for(i = 0; i < n ; i++){
        for(j = i + 1; j < n - 1; j++){
            if(a[j] < a[i]){
                swap(a[j], a[i]);
            }
        }
    }
}

void merge(int a[], int l, int m, int r){
    vector <int> x(a + l, a + m + 1);
    vector <int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while(i < x.size() && j < y.size()){
        if(x[i] <= y[j]){
            a[l] = x[i]; l++; i++;
        } else {
            a[l] = y[j]; l++; j++;
        }
    }
    while(i < x.size()){
        a[l] = x[i]; l++; i++;
    }
    while(j < y.size()){
        a[l] = y[j]; l++; j++;
    }
}

void MergeSort(int a[], int l, int r){
    if(l >= r){
        return;
    }
    int m = (l + r)/2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int partition(int a[], int l, int h)
{
    int pivot = a[h];
    int i = (l - 1);
 
    for (int j = l; j <= h - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[h]);
    return (i + 1);
}

void QuickSort(int a[], int l, int h)
{
    if (l < h) {
        int pi = partition(a, l, h);
        QuickSort(a, l, pi - 1);
        QuickSort(a, pi + 1, h);
    }
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int getMax(int a[], int n) {
  int max = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  return max;
}

void countingSort(int a[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  for (int i = 0; i < size; i++)
    count[(a[i] / place) % 10]++;

  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  for (int i = size - 1; i >= 0; i--) {
    output[count[(a[i] / place) % 10] - 1] = a[i];
    count[(a[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    a[i] = output[i];
}

void RadixSort(int a[], int size) {
  int max = getMax(a, size);
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(a, size, place);
}


int main (){
    int a[4] = {2,1,4,3};
    SelectionSort(a,4);
    InsertionSort(a,4);
    BubbleSort(a,4);
    MergeSort(a ,0 ,4);
    HeapSort(a,4);
    RadixSort(a,4);
    for(int i = 0 ; i < 4; i++){
        cout << a[i] << " ";
    }
}