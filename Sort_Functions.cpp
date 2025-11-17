#include <iostream>
#include <vector>
#include <ctime>    
#include <cstdlib>   
using namespace std;

void selectionSort(vector<double>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int mn = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[mn]) mn = j;
        swap(a[i], a[mn]);
    }
}

void insertionSort(vector<double>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        double key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int partitionQS(vector<double>& a, int l, int r) {
    double p = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
        if (a[j] < p) swap(a[++i], a[j]);
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(vector<double>& a, int l, int r) {
    if (l < r) {
        int p = partitionQS(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

void heapify(vector<double>& a, int n, int i) {
    int mx = i, L = 2 * i + 1, R = 2 * i + 2;
    if (L < n && a[L] > a[mx]) mx = L;
    if (R < n && a[R] > a[mx]) mx = R;
    if (mx != i) {
        swap(a[i], a[mx]);
        heapify(a, n, mx);
    }
}

void heapSort(vector<double>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

vector<double> randomArray(int n) {
    vector<double> a(n);
    for (int i = 0; i < n; i++)
        a[i] = (double)rand() / RAND_MAX * 1000000.0;
    return a;
}

double measure(void (*func)(vector<double>&), vector<double> a) {
    clock_t start = clock();
    func(a);
    clock_t end = clock();
    return (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
}

double measureQuick(vector<double> a) {
    clock_t start = clock();
    quickSort(a, 0, a.size() - 1);
    clock_t end = clock();
    return (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));

    int N = 50000;   
    vector<double> original = randomArray(N);

    cout << "Selection Sort: " << measure(selectionSort, randomArray(N)) << " ms\n";
    cout << "Insertion Sort: " << measure(insertionSort, randomArray(N)) << " ms\n";
    cout << "Quick Sort: "    << measureQuick(randomArray(N)) << " ms\n";
    cout << "Heap Sort: "     << measure(heapSort, randomArray(N)) << " ms\n";

    return 0;
}
