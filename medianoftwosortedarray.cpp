#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;


void findMedianSortedArrays(int A[], int m, int B[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
	
    
}

int ksmallestintwosortedarray(int A[], int m, int B[], int n, int k)
{
	assert(m >= 0 && n >= 0 && k <= m + n);

	if(m == 0)
	{
		return B[k - 1];
	}else if(n == 0)
	{
		return A[k - 1];
	}

	int i = (int)((double)m/(m+n) * k);
	int j = k - i - 2;
	
	if(A[i] >= B[j] && A[i] <= B[j + 1])
		return A[i];
	else if(B[j] <= A[i+1] && B[j] >= A[i])
		return B[j];

	if(A[i] > B[j])
	{
		return ksmallestintwosortedarray(A, i, B + j + 1, n - j - 1, k - j - 1);
	}else 
	{
		return ksmallestintwosortedarray(A + i + 1, m - i - 1, B, j, k - i - 1);
	}
}









double findkthele(int A[], int m, int B[], int n, int k){
	if(m > n)
		return findkthele(B, n, A, m, k);

	if(m == 0)
		return B[k - 1];

	if(k == 1)
		return min(A[0], B[0]);

	if(k == m + n)
		return max(A[m - 1], B[n - 1]);

	int pa = min(k / 2, m);

	int pb = k - pa;

	if(A[pa - 1] < B[pb - 1])
		return findkthele(A + pa, m - pa, B, pb, k - pa);
	else
		return findkthele(A, pa, B + pb, n - pb, k - pb);
}


double findMedianSortedArrays1(int A[], int m, int B[], int n) {
	if( (m + n) % 2 == 1){
		double t1 = findkthele(A,m, B, n, (m + n) / 2 + 1);
		return t1;
	}else{
		double t1 = findkthele(A,m, B, n, (m + n) / 2);
		double t2 = findkthele(A,m, B, n, (m + n) / 2 + 1);
		return (t1 + t2) / 2;
	}
        
}



//09/08/2013

double findkth(int A[], int m, int B[], int n, int k){
	if(m > n)
		return findkth(B, n, A, m, k);

	if(m == 0)
		return B[k - 1];

	if(k == 1)
		return A[0] < B[0] ? A[0] : B[0];

	if(k == m + n)
		return A[m - 1] > B[n - 1] ? A[m - 1] : B[n - 1];						//errro 2

	int m1 = min(k / 2, m);

	int n1 = k - m1;

	if(A[m1 - 1] > B[n1 - 1]){
		return findkth(A, m1, B + n1, n - n1, k - n1);
	}else{
		return findkth(A + m1, m - m1, B, n1, k - m1);
	}

}

//09/08/2013
double findMedianSortedArrays3(int A[], int m, int B[], int n) {
	if((m + n) % 2 == 1){															//error 1
		return findkth(A, m, B, n, (m + n) / 2 + 1);
	}else{
		double t1 = findkth(A, m, B, n, (m + n) / 2);
		double t2 = findkth(A, m, B, n, (m + n) / 2 + 1);
		return (t1 + t2) / 2;
	}
    
}


int mainfindMedianSortedArrays3()
{
	int A[] = {1};
	int B[] = {1};
	double res = findMedianSortedArrays3(A, 1, B, 1);
	cout<<res<<endl;
	system("pause");
	return 0;
}