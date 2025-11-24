#include <bits/stdc++.h>
using namespace std;
void insertionSort(int a[],int n){
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
int main ()
{
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    cin.ignore();
    int a[1000000];
    int cnt=0;
    
    string dong;
    getline (cin,dong);
    
    stringstream ss(dong);
    string temp;
    while(getline(ss,temp,',')){
        a[cnt++]=atoi(temp.c_str());
    }
    
    insertionSort(a,n);
    
    cout<<"Array after using Insertion sort: ";
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
