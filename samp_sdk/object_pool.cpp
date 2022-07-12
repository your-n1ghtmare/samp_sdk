#include "sdk.hpp"

c_object_pool::c_object_pool(void* ptr) : m_object_ptr(ptr) {

	m_offsets.m_count			= { 0, 0x0, 0x0, 0x0 };
	m_offsets.m_listed			= { 0, 0x4, 0x4, 0x4 };

	auto ver = static_cast<int>(samp::get_version());
	auto object_addr = reinterpret_cast<std::uintptr_t>(m_object_ptr);

	m_count_ptr					= reinterpret_cast<int*>(object_addr + m_offsets.m_count[ver]);
	m_is_listed_ptr				= reinterpret_cast<int*>(object_addr + m_offsets.m_listed[ver]);

}

int& c_object_pool::get_count()
{
	return *reinterpret_cast<int*>(m_count_ptr);
}

int& c_object_pool::is_listed(int id)
{

	if (id < 0 || id >= max_objects) {
		throw std::runtime_error("object_pool: invalid id");
	}
	return m_is_listed_ptr[id];
}


