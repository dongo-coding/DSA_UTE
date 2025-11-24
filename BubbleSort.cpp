#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int a[],int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
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
    
    bubbleSort(a,n);
    
    cout<<"Array after using Bubble sort: ";
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
