#include <cape/utility.h>
#include <cassert>

int main()
{
	{
		int a = 5;
		int b = 10;
		cape::swap(a, b);
		assert(a == 10 && b == 5);
	}

	{
		int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		int b[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
		cape::swap(a, b);
		for (int i = 0; i < 10; ++i)
		{
			assert(a[i] == 10 + i && b[i] == i);
		}
	}
}