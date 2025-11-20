#include <bits/stdc++.h>
using namespace std;
void quickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
			j--;
		}
		if (i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		quickSort(a, i, r);
	}
	if (l < j){
		quickSort(a, l, j);
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
	
	quickSort(a, 0, n-1);
	
	cout<<"Array after using Quick Sort : ";
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
}
