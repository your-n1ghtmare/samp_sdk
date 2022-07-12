#include "sdk.hpp"

c_player_pool::c_player_pool(void* ptr) : m_player_ptr(ptr) {

	m_offsets.m_local_player_id				= { 0, 0x4, 0x2F1C, 0x0 };
	m_offsets.m_local_player_nick			= { 0, 0xA, 0x2F22, 0x4 };
	m_offsets.m_local_player_ping			= { 0, 0x26, 0x2F14, 0x2F34 };
	m_offsets.m_local_player_score			= { 0, 0x2A, 0x2F18, 0x2F38 };

	m_offsets.m_is_listed					= { 0, 0xFDE, 0xFB4, 0xFD4 };
	m_offsets.m_remote_players_ptr			= { 0, 0x2E, 0x4, 0x24 };

	const auto ver = static_cast<int>(samp::get_version());
	auto player_addr = reinterpret_cast<std::uintptr_t>(m_player_ptr);

	m_local_player_id_ptr			= reinterpret_cast<std::uint16_t*>(player_addr + m_offsets.m_local_player_id[ver]);
	m_local_player_name_ptr			= reinterpret_cast<void*>(player_addr + m_offsets.m_local_player_nick[ver]);
	m_local_player_ping_ptr			= reinterpret_cast<int*>(player_addr + m_offsets.m_local_player_ping[ver]);
	m_local_player_score_ptr		= reinterpret_cast<int*>(player_addr + m_offsets.m_local_player_score[ver]);

	m_is_listed_ptr					= reinterpret_cast<int*>(player_addr + m_offsets.m_is_listed[ver]);
	m_remote_players_ptr			= reinterpret_cast<void**>(player_addr + m_offsets.m_remote_players_ptr[ver]);
}

std::string c_player_pool::get_local_player_name() {

	struct msvc_string {
		union {
			char  szString[0x10];
			char* pszString;
		};
		std::size_t length;
		std::size_t allocated;
	};
	auto string = *reinterpret_cast<msvc_string*>(m_local_player_name_ptr);
	if (string.allocated < 0x10) return { string.szString, string.length };
	return { string.pszString, string.length };
}

std::tuple<float, float, float> c_player_pool::get_local_player_pos() {

	auto gta_ped_addr = *reinterpret_cast<std::uintptr_t*>(0xB6F5F0);
	if (!gta_ped_addr) return std::make_tuple(0.f, 0.f, 0.f);
	auto matrix_addr = *reinterpret_cast<std::uintptr_t*>(gta_ped_addr + 0x14);
	auto x = *reinterpret_cast<float*>(matrix_addr + 0x30);
	auto y = *reinterpret_cast<float*>(matrix_addr + 0x34);
	auto z = *reinterpret_cast<float*>(matrix_addr + 0x38);
	return std::make_tuple(x, y, z);
}

int& c_player_pool::is_listed(int id) {

	if (id < 0 || id >= max_players) {
		throw std::runtime_error("c_player_pool: invalid player id");
	}
	return m_is_listed_ptr[id];
}

bool c_player_pool::is_exists(int id) {

	if (is_listed(id) != 1) return false;
	auto ped = remote_player(id);
	if (!ped->remote_data()) return false;
	if (!ped->samp_ped()) return false;
	if (!ped->gta_ped()) return false;
	return true;
}

c_remote_player* c_player_pool::remote_player(int id) {

	if (id < 0 || id >= max_players) {
		throw std::runtime_error("player_pool: invalid id");
	}

	return std::make_unique< c_remote_player >(m_remote_players_ptr[id]).release();
}

c_remote_player c_player_pool::operator[](int id) {
	return remote_player(id);
}
