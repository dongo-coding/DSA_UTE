#include <bits/stdc++.h>
using namespace std;
void heapify(int a[], int n, int i) {

      int largest = i;

      int left = 2 * i + 1;

      int right = 2 * i + 2;

      if (left < n && a[left] > a[largest])

        largest = left;

      if (right < n && a[right] > a[largest])

        largest = right; if (largest != i) { 

        swap(a[i], a[largest]); 

        heapify(a, n, largest);

      } 

   }

 

   void Heap_sort(int a[], int n) {

       for (int i = n / 2 - 1; i >= 0; i--)

          heapify(a, n, i);

       for (int i = n - 1; i >= 0; i--) { 

          swap(a[0], a[i]);

          heapify(a, i, 0);

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
	
	Heap_sort(a,n);
	
	cout<<"Array after using Heap Sort : ";
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
}
