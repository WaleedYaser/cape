#include <cape/types.h>

#include <cstdint>
#include <typeinfo>
#include <cassert>

int main()
{
	assert(typeid(cape::int8_t)  == typeid(std::int8_t));
	assert(typeid(cape::int16_t) == typeid(std::int16_t));
	assert(typeid(cape::int32_t) == typeid(std::int32_t));
	assert(typeid(cape::int64_t) == typeid(std::int64_t));

	assert(typeid(cape::uint8_t)  == typeid(std::uint8_t));
	assert(typeid(cape::uint16_t) == typeid(std::uint16_t));
	assert(typeid(cape::uint32_t) == typeid(std::uint32_t));
	assert(typeid(cape::uint64_t) == typeid(std::uint64_t));

	assert(typeid(cape::size_t) == typeid(std::size_t));
}