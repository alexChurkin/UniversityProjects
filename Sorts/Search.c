
int linear_search(int arr[], int size, int element)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == element) return i;
	}
	return -1;
}

int binary_search(int arr[], int size, int element)
{
	int l = 0, r = size - 1;
	while (l <= r)
	{
		int c = (l + r) / 2;
		if (element == arr[c]) return c;
		else if (element < arr[c]) r = c - 1;
		else l = c + 1;
	}
	return -1;
}