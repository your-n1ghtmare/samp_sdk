#include "sdk.hpp"

c_remote_player::c_remote_player(void* ptr) : m_remote_player_ptr(ptr) {

	m_offsets.m_remote_player_data			= { 0, 0x0, 0x0, 0x8 };
	m_offsets.m_remote_player_name			= { 0, 0xC, 0xC, 0x14 };

	m_offsets.m_remote_player_npc			= { 0, 0x4, 0x24, 0x4 };
	m_offsets.m_remote_player_score			= { 0, 0x24, 0x20, 0x0 };
	m_offsets.m_remote_player_ping			= { 0, 0x28, 0x4, 0xC };

	m_offsets.m_remote_player_samp_ped		= { 0, 0x0, 0x0, 0x4 };
	m_offsets.m_remote_player_id			= { 0, 0xAB, 0x8, 0x0 };
	m_offsets.m_remote_player_health		= { 0, 0x1BC, 0x1B0, 0x1B0 };
	m_offsets.m_remote_player_armour		= { 0, 0x1B8, 0x1AC, 0x1AC };
	m_offsets.m_remote_player_afk			= { 0, 0x1D1, 0x1D1, 0x1D1 };

	m_offsets.m_remote_player_gta_ped		= { 0, 0x2A4, 0x2A4, 0x2A4 };

	const auto ver = static_cast<int>(samp::get_version());
	auto remote_player_addr					= reinterpret_cast<std::uintptr_t>(m_remote_player_ptr);

	m_remote_player_data					= reinterpret_cast<void**>(remote_player_addr + m_offsets.m_remote_player_data[ver]);
	m_remote_player_name					= reinterpret_cast<void*>(remote_player_addr + m_offsets.m_remote_player_name[ver]);

	m_remote_player_npc						= reinterpret_cast<int*>(remote_player_addr + m_offsets.m_remote_player_npc[ver]);
	m_remote_player_score					= reinterpret_cast<int*>(remote_player_addr + m_offsets.m_remote_player_score[ver]);
	m_remote_player_ping					= reinterpret_cast<int*>(remote_player_addr + m_offsets.m_remote_player_ping[ver]);
}

std::string c_remote_player::get_name() {

	struct msvc_string {
		union {
			char  szString[0x10];
			char* pszString;
		};
		size_t length;
		size_t allocated;
	};
	auto string = *reinterpret_cast<msvc_string*>(m_remote_player_name);
	if (string.allocated < 0x10) return { string.szString, string.length };
	return { string.pszString, string.length };
}

bool c_remote_player::is_npc() {

	return *reinterpret_cast<int*>(m_remote_player_npc);
}

int c_remote_player::get_score() {

	return *reinterpret_cast<int*>(m_remote_player_score);
}

int c_remote_player::get_ping() {

	return *reinterpret_cast<int*>(m_remote_player_ping);
}

void*& c_remote_player::samp_ped() {

	auto data_addr = reinterpret_cast<std::uintptr_t>(remote_data());
	auto version = static_cast<int>(samp::get_version());
	return *reinterpret_cast<void**>(data_addr + m_offsets.m_remote_player_samp_ped[version]);
}

std::uint16_t& c_remote_player::get_id() {

	auto data_addr = reinterpret_cast<std::uintptr_t>(remote_data());
	auto version = static_cast<int>(samp::get_version());
	return *reinterpret_cast<std::uint16_t*>(data_addr + m_offsets.m_remote_player_id[version]);
}

float& c_remote_player::get_health() {

	auto data_addr = reinterpret_cast<std::uintptr_t>(remote_data());
	auto version = static_cast<int>(samp::get_version());
	return *reinterpret_cast<float*>(data_addr + m_offsets.m_remote_player_health[version]);
}

float& c_remote_player::get_armour() {

	auto data_addr = reinterpret_cast<std::uintptr_t>(remote_data());
	auto version = static_cast<int>(samp::get_version());
	return *reinterpret_cast<float*>(data_addr + m_offsets.m_remote_player_armour[version]);
}

bool c_remote_player::is_afk() {

	auto data_addr = reinterpret_cast<std::uintptr_t>(remote_data());
	auto version = static_cast<int>(samp::get_version());

	return (*reinterpret_cast<int*>(data_addr + m_offsets.m_remote_player_afk[version]) == 2);
}

void*& c_remote_player::gta_ped() {

	auto samp_ped_addr = reinterpret_cast<std::uintptr_t>(samp_ped());
	auto version = static_cast<int>(samp::get_version());
	return *reinterpret_cast<void**>(samp_ped_addr + m_offsets.m_remote_player_gta_ped[version]);
}


