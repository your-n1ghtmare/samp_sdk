#include "sdk.hpp"

c_base::c_base() {

	if (samp::get_version() == samp::e_version::unknown) {
		throw std::runtime_error("base: unknown version");
	}

	m_offsets.m_samp_info			= { 0, 0x21A0F8, 0x26E8DC, 0x2ACA24 };
	m_offsets.m_settings			= { 0, 0x3C5, 0x3D5, 0x3D5 };
	m_offsets.m_game_state			= { 0, 0x3BD, 0x3CD, 0x3CD };
	m_offsets.m_pools				= { 0, 0x3CD, 0x3DE, 0x3DE };

	m_offsets.m_server_addr			= { 0, 0x20, 0x30, 0x30 };
	m_offsets.m_server_port			= { 0, 0x225, 0x235, 0x235 };

	const auto ver = static_cast<int>(samp::get_version());

	m_samp_ptr					= *reinterpret_cast<void**>(samp::get_library() + m_offsets.m_samp_info[ver]);
	auto samp_addr				= reinterpret_cast<std::uintptr_t>(m_samp_ptr);

	m_game_state_ptr			= reinterpret_cast<int*>(samp_addr + m_offsets.m_game_state[ver]);
	m_settings_ptr				= reinterpret_cast<void**>(samp_addr + m_offsets.m_settings[ver]);
	m_pools_ptr					= reinterpret_cast<void**>(samp_addr + m_offsets.m_pools[ver]);

	m_server_addr_ptr			= reinterpret_cast<char*>(samp_addr + m_offsets.m_server_addr[ver]);
	m_server_port_ptr			= reinterpret_cast<std::uint16_t*>(samp_addr + m_offsets.m_server_port[ver]);

	m_pools = new c_pools(pools_ptr());
}

c_base::~c_base() {
	delete m_pools;
}


