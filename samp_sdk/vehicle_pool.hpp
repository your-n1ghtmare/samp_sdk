#pragma once

/*
*	### please respect other people's work
*	### author: your.n1ghtmare
*/

class c_vehicle_pool {

	struct {

		std::array<std::uintptr_t, 4> m_count;
		std::array<std::uintptr_t, 4> m_listed;
		std::array<std::uintptr_t, 4> m_gta_vehicle;

	}m_offsets;

private:
	void* m_vehicle_ptr		= nullptr;

	int* m_count_ptr		= nullptr;
	int* m_is_listed_ptr	= nullptr;

public:
	static constexpr auto max_vehicles = 2000u;

	c_vehicle_pool(void* player_ptr);
	~c_vehicle_pool() = default;

	int& get_count();
	int& is_listed(int id);

	void*& gta_vehicle(int id);



};



