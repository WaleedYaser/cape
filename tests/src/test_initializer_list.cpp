#include <cape/initializer_list.h>
#include <cassert>

int main()
{
	{
		cape::initializer_list<int> list;
		assert(list.size() == 0);
		assert(list.begin() == nullptr);
		assert(list.end() == nullptr);
	}

	{
		cape::initializer_list<int> list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		assert(list.size() == 10);

		int i = 0;
		for (const auto& n : list)
		{
			assert(n == i++);
		}
	}
}