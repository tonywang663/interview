#include <vector>

using namespace std;

static void swap(vector<int> &vec, size_t p, size_t q)
{
	int t = vec[q];
	vec[q] = vec[p];
	vec[p] = t;
}


static void quick(vector<int> &vec, int left, int right)
{
	if (left >= right)
		return;

	int first = vec[left];
	// p is the right end index of the array containing elements less than or equal to vec[left]
	int p = left;
	for (int i = left + 1; i <= right; i++)
	{
		if (vec[i] >= first)
		{
			continue;
		}
		else{
			swap(vec, p + 1, i);
			p = p + 1;
		}

	}
	// swap left to the end of the smaller array.
	swap(vec, left, p);
	quick(vec, left, p - 1);
	quick(vec, p + 1, right);
}