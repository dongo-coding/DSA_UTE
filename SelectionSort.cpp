#include <bits/stdc++.h>
using namespace std;
void selectionSort(int a[],int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j; 
            }
        }
        swap(a[i], a[min_idx]);
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
    
    selectionSort(a,n);
    
    cout<<"Array after using Selection sort: ";
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
