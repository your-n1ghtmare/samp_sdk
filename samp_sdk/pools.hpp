#pragma once

/*
*	### please respect other people's work
*	### author: your.n1ghtmare
*/

class c_pools {

	struct {

		std::array<std::uintptr_t, 4> m_player;
		std::array<std::uintptr_t, 4> m_vehicle;
		std::array<std::uintptr_t, 4> m_object;
		std::array<std::uintptr_t, 4> m_pickup;
		std::array<std::uintptr_t, 4> m_textdraw;

	}m_offsets;

private:
	void* m_pools_ptr						= nullptr;

	void** m_object_ptr						= nullptr;
	void** m_textdraw_ptr					= nullptr;
	void** m_player_ptr						= nullptr;
	void** m_vehicle_ptr					= nullptr;
	void** m_pickup_ptr						= nullptr;

	class c_player_pool* m_player_pool		= nullptr;
	class c_vehicle_pool* m_vehicle_pool	= nullptr;
	class c_pickup_pool* m_pickup_pool		= nullptr;
	class c_object_pool* m_object_pool		= nullptr;

public:
	c_pools(void* ptr);
	~c_pools();

	ALWAYS_INLINE void*& object_ptr();
	ALWAYS_INLINE void*& textdraw_ptr();
	ALWAYS_INLINE void*& player_ptr();
	ALWAYS_INLINE void*& vehicle_ptr();
	ALWAYS_INLINE void*& pickup_ptr();

	ALWAYS_INLINE class c_player_pool* player_pool();
	ALWAYS_INLINE class c_vehicle_pool* vehicle_pool();
	ALWAYS_INLINE class c_pickup_pool* pickup_pool();
	ALWAYS_INLINE class c_object_pool* object_pool();


};


