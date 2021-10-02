#include <cape/algorithm.h>
#include <cassert>

struct Number
{
	int x;
	constexpr bool operator==(const Number& other) const noexcept { return x == other.x; }
};

constexpr bool compare_number(const Number& a, const Number& b) noexcept { return a.x < b.x; }


int main()
{
	{
		assert(cape::max(5, 10) == 10);
		assert(cape::max(10, 5) == 10);
		assert(cape::max({5, 10, 122}) == 122);
		assert(cape::max({10, 122, 5}) == 122);
	}

	{
		Number a{5};
		Number b{10};
		Number c{122};

		assert(cape::max(a, b, compare_number) == b);
		assert(cape::max(b, a, compare_number) == b);

		assert(cape::max({a, b, c}, compare_number) == c);
		assert(cape::max({b, a, c}, compare_number) == c);
	}


	{
		assert(cape::min(5, 10) == 5);
		assert(cape::min(10, 5) == 5);
		assert(cape::min({5, 10, 1}) == 1);
		assert(cape::min({10, 1, 5}) == 1);
	}

	{
		Number a{5};
		Number b{10};
		Number c{1};

		assert(cape::min(a, b, compare_number) == a);
		assert(cape::min(b, a, compare_number) == a);

		assert(cape::min({a, b, c}, compare_number) == c);
		assert(cape::min({b, a, c}, compare_number) == c);
	}


	{
		assert(cape::minmax(5, 10).first == 5);
		assert(cape::minmax(5, 10).second == 10);

		assert(cape::minmax(10, 5).first == 5);
		assert(cape::minmax(10, 5).second == 10);

		assert(cape::minmax({5, 10, 122}).first == 5);
		assert(cape::minmax({5, 10, 122}).second == 122);

		assert(cape::minmax({10, 122, 5}).first == 5);
		assert(cape::minmax({10, 122, 5}).second == 122);
	}

	{
		Number a{5};
		Number b{10};
		Number c{122};

		assert(cape::minmax(a, b, compare_number).first == a);
		assert(cape::minmax(a, b, compare_number).second == b);

		assert(cape::minmax(b, a, compare_number).first == a);
		assert(cape::minmax(b, a, compare_number).second == b);

		assert(cape::minmax({a, b, c}, compare_number).first == a);
		assert(cape::minmax({a, b, c}, compare_number).second == c);

		assert(cape::minmax({b, a, c}, compare_number).first == a);
		assert(cape::minmax({b, a, c}, compare_number).second == c);
	}
}
