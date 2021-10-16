#include <cape/utility.h>

#include <cassert>

struct A
{
	A(const int& n): n{n}, lvalue{0}, rvalue{0} {}
	A(int& n): n{0}, lvalue{n}, rvalue{0} {}
	A(int&& n): n{0}, lvalue{0}, rvalue{n} {}

	int n, lvalue, rvalue;
};

struct B
{
	template <class T1, class T2, class T3>
	B(T1&& a1, T2&& a2, T3&& a3): a1{cape::forward<T1>(a1)}, a2{cape::forward<T2>(a2)}, a3{cape::forward<T3>(a3)} {}

	A a1, a2, a3;
};

template<class T, class... Args>
T make_t(Args&&... args)
{
	return T(cape::forward<Args>(args)...);
}

int main()
{
	const int n1 = 10;
	int n2 = 5;
	B b = make_t<B>(n1, n2, 3);

	assert(b.a1.n == n1 && b.a1.lvalue == 0 && b.a1.rvalue == 0);
	assert(b.a2.n == 0 && b.a2.lvalue == n2 && b.a2.rvalue == 0);
	assert(b.a3.n == 0 && b.a3.lvalue == 0 && b.a3.rvalue == 3);

	return 0;
}
