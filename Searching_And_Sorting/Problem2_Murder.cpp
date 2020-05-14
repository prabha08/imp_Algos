// https://www.spoj.com/DCEPC2/problems/DCEPC206/  

#include <iostream>
using namespace std;

long long merge(long long arr[], int l, int m, int r) {
	int i=l, j=m, k=0;
	long long sum=0, tsum=0;
	long long  temp[r-l+1];
	
	while(i<m && j<=r) {
		//cout<<i<<" a[i] "<<arr[i]<<j<<" a[j] "<<arr[j]<<endl;
		if(arr[i]<arr[j]) {
			sum+=arr[i];
			temp[k++]=arr[i++];
		}
		else {
			tsum+=sum; 
			//if(l==0 && r==6)
			//	cout<<"sum "<<sum<<" j "<<j<<" a[j] "<<arr[j]<<endl;
			temp[k++] = arr[j++];
		}
	}
	
	for(; i<m; i++) {
		sum+=arr[i];
		temp[k++]=arr[i];
	}
	for(; j<=r; j++) {
		tsum+=sum;
		//if(l==0 && r==3)
			//cout<<"see "<<j<<" a[j] "<<arr[j];<<endl;
		temp[k++] = arr[j]; //cout<<" k "<<k<<endl;
	}
	 
	for(int i=l,k=0; i<=r; i++,k++) { //store back result
		arr[i] = temp[k];	
	//	cout<<arr[i]<<" "<<temp[k]<<"    ";
	}
	//cout<<endl;
	return tsum;
}

long long mergeSort(long long arr[], int l, int r) {
	if(l>=r) return 0;
	int m = (l+r)/2;
	long long leftCount  = mergeSort(arr, l, m);
	long long rightCount = mergeSort(arr, m+1, r);
	
	//cout<<l<<m<<r<<endl; cout<<"-------"<<endl;
	long long currCount = merge(arr, l, m+1, r);
	//cout<<"currentCount "<<currCount<<endl;
	return leftCount+rightCount+currCount;
}

int main() {
	int t; cin>>t;
	
	while(t--) {
		int n; cin>>n;
		long long arr[n];
		for(int i=0; i<n; i++) {
			cin>>arr[i];
		}
		cout<<mergeSort(arr, 0, n-1)<<endl;
	}
	return 0;
}
