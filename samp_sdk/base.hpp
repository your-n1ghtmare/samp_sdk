#pragma once

/*
*	### please respect other people's work
*	### author: your.n1ghtmare
*/

class c_base {

	struct {
		std::array<std::uintptr_t, 4> m_samp_info;
		std::array<std::uintptr_t, 4> m_settings;
		std::array<std::uintptr_t, 4> m_game_state;
		std::array<std::uintptr_t, 4> m_pools;
		std::array<std::uintptr_t, 4> m_server_addr;
		std::array<std::uintptr_t, 4> m_server_port;

	}m_offsets;

private:
	void* m_samp_ptr					= nullptr;
	int* m_game_state_ptr				= nullptr;
	void** m_settings_ptr				= nullptr;
	void** m_pools_ptr					= nullptr;

	char* m_server_addr_ptr				= nullptr;
	std::uint16_t* m_server_port_ptr	= nullptr;


	class c_pools* m_pools				= nullptr;

public:
	c_base();
	~c_base();


	ALWAYS_INLINE int&				game_state();
	ALWAYS_INLINE void*&			settings_ptr();
	ALWAYS_INLINE void*&			pools_ptr();

	ALWAYS_INLINE class c_pools*	pools();

	ALWAYS_INLINE char*&			get_server_ip();
	ALWAYS_INLINE std::uint16_t&	get_server_port();

};


inline const auto g_samp = std::make_unique< c_base >();

