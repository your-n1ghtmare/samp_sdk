#pragma once

/*
*	### please respect other people's work
*	### author: your.n1ghtmare
*/

class c_player_pool {

	struct {

		std::array<std::uintptr_t, 4> m_local_player_id;
		std::array<std::uintptr_t, 4> m_local_player_nick;
		std::array<std::uintptr_t, 4> m_local_player_ping;
		std::array<std::uintptr_t, 4> m_local_player_score;

		std::array<std::uintptr_t, 4> m_is_listed;
		std::array<std::uintptr_t, 4> m_remote_players_ptr;
		

	}m_offsets;

private:
	void* m_player_ptr						= nullptr;

	std::uint16_t* m_local_player_id_ptr	= nullptr;
	void* m_local_player_name_ptr			= nullptr;
	int* m_local_player_ping_ptr			= nullptr;
	int* m_local_player_score_ptr			= nullptr;

	int* m_is_listed_ptr					= nullptr;
	void** m_remote_players_ptr				= nullptr;

public:
	static constexpr auto max_players		= 1004u;

	c_player_pool(void* ptr);
	~c_player_pool() = default;


	std::string	 get_local_player_name();
	std::tuple<float, float, float> get_local_player_pos();

	int& is_listed(int id);
	bool is_exists(int id);


	ALWAYS_INLINE std::uint16_t get_local_player_id();
	ALWAYS_INLINE int get_local_player_ping();
	ALWAYS_INLINE int get_local_player_score();


	class c_remote_player* remote_player(int id);
	class c_remote_player operator[](int id);


};



