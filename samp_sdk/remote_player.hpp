#pragma once

/*
*	### please respect other people's work
*	### author: your.n1ghtmare
*/

class c_remote_player {

	struct {

		std::array<std::uintptr_t, 4> m_remote_player_data;
		std::array<std::uintptr_t, 4> m_remote_player_name;

		std::array<std::uintptr_t, 4> m_remote_player_npc;
		std::array<std::uintptr_t, 4> m_remote_player_score;
		std::array<std::uintptr_t, 4> m_remote_player_ping;

		std::array<std::uintptr_t, 4> m_remote_player_samp_ped;
		std::array<std::uintptr_t, 4> m_remote_player_id;
		std::array<std::uintptr_t, 4> m_remote_player_health;
		std::array<std::uintptr_t, 4> m_remote_player_armour;
		std::array<std::uintptr_t, 4> m_remote_player_afk;

		std::array<std::uintptr_t, 4> m_remote_player_gta_ped;

	}m_offsets;

private:
	void* m_remote_player_ptr		= nullptr;

	void** m_remote_player_data		= nullptr;
	void* m_remote_player_name		= nullptr;

	int* m_remote_player_npc		= nullptr;
	int* m_remote_player_score		= nullptr;
	int* m_remote_player_ping		= nullptr;

public:
	c_remote_player(void* ptr);
	~c_remote_player() = default;

	std::string get_name();

	bool is_npc();
	int get_score();
	int get_ping();

	void*& gta_ped();
	void*& samp_ped();

	std::uint16_t& get_id();
	float& get_health();
	float& get_armour();

	bool is_afk();

	ALWAYS_INLINE void*& remote_data();

};


