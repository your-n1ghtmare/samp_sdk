#include "sdk.hpp"

c_pickup_pool::c_pickup_pool(void* ptr) :m_pickup_ptr(ptr) {

	m_offsets.m_pickup_info = 0xF004;

	auto pickup_addr			= reinterpret_cast<std::uintptr_t>(m_pickup_ptr);
	m_pickup_info_ptr			= reinterpret_cast<void**>(pickup_addr + m_offsets.m_pickup_info);

}

c_pickup_info* c_pickup_pool::pickup_info(int id) {

	if (id < 0 || id >= max_pickups) {
		throw std::runtime_error("pickup pool: invalid id");
	}

	return std::make_unique< c_pickup_info >(&m_pickup_info_ptr[id * 20]).release();
}

c_pickup_info::c_pickup_info(void* ptr) : m_pickup_info_ptr(ptr) {

	m_offsets.m_model = 0x0;
	m_offsets.m_type = 0x4;
	m_offsets.m_pos = 0x8;
}

int c_pickup_info::get_model() {

	auto data_addr = reinterpret_cast<std::uintptr_t>(m_pickup_info_ptr);
	return *reinterpret_cast<int*>(data_addr + m_offsets.m_model);
}

int c_pickup_info::get_type() {

	auto data_addr = reinterpret_cast<std::uintptr_t>(m_pickup_info_ptr);
	return *reinterpret_cast<int*>(data_addr + m_offsets.m_type);
}

std::tuple<float, float, float> c_pickup_info::get_pos() {

	auto data_addr = reinterpret_cast<std::uintptr_t>(m_pickup_info_ptr);

	auto x = *reinterpret_cast<float*>(data_addr + m_offsets.m_pos + 0x0);
	auto y = *reinterpret_cast<float*>(data_addr + m_offsets.m_pos + 0x4);
	auto z = *reinterpret_cast<float*>(data_addr + m_offsets.m_pos + 0x8);
	return std::make_tuple(x, y, z);
}

