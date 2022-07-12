#include "sdk.hpp"

c_pools::c_pools(void* ptr) : m_pools_ptr(ptr) {

	m_offsets.m_player			= { 0, 0x18, 0x8, 0x8 };
	m_offsets.m_vehicle			= { 0, 0x1C, 0xC, 0xC };
	m_offsets.m_object			= { 0, 0x4, 0x14, 0x14 };
	m_offsets.m_pickup			= { 0, 0x20, 0x10, 0x10 };
	m_offsets.m_textdraw		= { 0, 0x10, 0x20, 0x20 };

	const auto ver = static_cast<int>(samp::get_version());
	auto pools_addr = reinterpret_cast<std::uintptr_t>(m_pools_ptr);

	m_player_ptr			= reinterpret_cast<void**>(pools_addr + m_offsets.m_player[ver]);
	m_vehicle_ptr			= reinterpret_cast<void**>(pools_addr + m_offsets.m_vehicle[ver]);
	m_pickup_ptr			= reinterpret_cast<void**>(pools_addr + m_offsets.m_pickup[ver]);
	m_object_ptr			= reinterpret_cast<void**>(pools_addr + m_offsets.m_object[ver]);
	m_textdraw_ptr			= reinterpret_cast<void**>(pools_addr + m_offsets.m_textdraw[ver]);
	


	m_player_pool			= new c_player_pool(player_ptr());
	m_vehicle_pool			= new c_vehicle_pool(vehicle_ptr());
	m_pickup_pool			= new c_pickup_pool(pickup_ptr());
	m_object_pool			= new c_object_pool(object_ptr());
}

c_pools::~c_pools() {

	delete m_player_pool;
	delete m_vehicle_pool;
	delete m_pickup_pool;
	delete m_object_pool;
}


