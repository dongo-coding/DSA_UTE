#include <bits/stdc++.h>
using namespace std;
void shellSort(int a[], int n){
	 for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i++) {
            int temp = a[i];
            int j = i;
            while (j >= interval && a[j - interval] > temp) {
                a[j] = a[j - interval];
                j -= interval;
            }
            a[j] = temp;
        }
    }
}
int main ()
{
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	cin.ignore();
	
	string dong;
	getline(cin,dong);
	
	int a[100000];
	int cnt=0;
	
	stringstream ss(dong);
	string temp;
	
	while(getline(ss, temp, ',')) {
		a[cnt++] = atoi(temp.c_str());
	}
	
	shellSort(a,n);
	
	cout<<"Array after using Shell Sort : ";
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
}
