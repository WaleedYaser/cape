#include <cape/utility.h>

#include <vector>
#include <cassert>

int main()
{
	std::vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> v2 = cape::move(v1);

	assert(v1.data() == nullptr);
	assert(v2.data());

	for (int i = 0; i < 10; ++i)
	{
		assert(v2[i] == i);
	}
}
