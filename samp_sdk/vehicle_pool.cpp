#include "sdk.hpp"

c_vehicle_pool::c_vehicle_pool(void* ptr) : m_vehicle_ptr(ptr) {

	m_offsets.m_count				= { 0, 0x0, 0x0, 0x0 };
	m_offsets.m_listed				= { 0, 0x3074, 0x3394, 0x3394 };

	m_offsets.m_gta_vehicle			= { 0, 0x4FB4, 0x52D4, 0x52D4 };


	auto ver = static_cast<int>(samp::get_version());
	auto vehicle_addr = reinterpret_cast<std::uintptr_t>(m_vehicle_ptr);

	m_count_ptr						= reinterpret_cast<int*>(vehicle_addr + m_offsets.m_count[ver]);
	m_is_listed_ptr					= reinterpret_cast<int*>(vehicle_addr + m_offsets.m_listed[ver]);

}

int& c_vehicle_pool::get_count()
{
	return *reinterpret_cast<int*>(m_count_ptr);
}

int& c_vehicle_pool::is_listed(int id) {

	if (id < 0 || id >= max_vehicles) {
		throw std::runtime_error("vehicle_pool: invalid id");
	}
	return m_is_listed_ptr[id];
}

void*& c_vehicle_pool::gta_vehicle(int id)
{
	auto addr = ((size_t*)m_vehicle_ptr)[id];

	auto version = static_cast<int>(samp::get_version());
	return *reinterpret_cast<void**>(addr + m_offsets.m_gta_vehicle[version]);
}
