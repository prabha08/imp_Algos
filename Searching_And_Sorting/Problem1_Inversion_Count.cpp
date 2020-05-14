/*Let A[0 ... n-1] be an array of n distinct positive integers.
If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). 
Given an integer array A, your task is to find the number of inversions in A.
Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).
Output format :
Count of inversions
Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Sample Input 2 :
5
2 5 1 3 4
Sample Output 1 :
4 */

//Sol : 

long long merge(int A[], long long l1, long long r1, long long l2,
                long long r2) {
  long long lsz = r1 - l1 + 1;
  long long rsz = r2 - l2 + 1;
  long long sz = lsz + rsz;
  int arr[sz];
  long long i = l1, j = l2, k = 0;
  long long inv = 0, tinv = 0;

  while (1) {
    if (i <= r1 && j <= r2) {
      if (A[j] < A[i]) {
        inv = lsz - (i - l1);
        tinv += inv;
        arr[k++] = A[j++];
      } else {
        arr[k++] = A[i++];
      }
    } else if (i > r1 && j <= r2) {
      arr[k++] = A[j++];
    } else if (i <= r1 && j > r2) {
      arr[k++] = A[i++];
    } else {
      break;
    }
  }

  for (i = l1; i <= r2; i++) {
    A[i] = arr[i - l1];
  }

  return tinv;
}

long long mergeSort(int A[], long long l, long long r) {
  if (l >= r) {
    return 0;
  }
  long long mid = l + (r - l) / 2;
  long long left = mergeSort(A, l, mid);
  long long right = mergeSort(A, mid + 1, r);

  long long inv = merge(A, l, mid, mid + 1, r);

  return (inv + left + right);
}

long long solve(int A[], long long n) { 
  
  return mergeSort(A, 0, n - 1); 

}

