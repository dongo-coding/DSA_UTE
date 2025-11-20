#include <bits/stdc++.h>
using namespace std;

void countSort(int a[], int n, int exp) {
    int output[100000];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n) {
    int maxVal = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > maxVal)
            maxVal = a[i];

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cin.ignore();

    string dong;
    getline(cin, dong);

    int a[100000];
    int cnt = 0;

    stringstream ss(dong);
    string temp;

    while (getline(ss, temp, ',')) {
        a[cnt++] = atoi(temp.c_str());
    }

    radixSort(a, n);

    cout << "Array after using Radix Sort : ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
