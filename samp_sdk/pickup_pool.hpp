#pragma once

/*
*	### please respect other people's work
*	### author: your.n1ghtmare
*/

class c_pickup_info {

	struct {

		std::uintptr_t m_model;
		std::uintptr_t m_type;
		std::uintptr_t m_pos;

	}m_offsets;

private:
	void* m_pickup_info_ptr = nullptr;

public:
	c_pickup_info(void* ptr);
	~c_pickup_info() = default;

	int get_model();
	int get_type();
	std::tuple<float, float, float> get_pos();
};

class c_pickup_pool {

	struct {

		std::uintptr_t m_pickup_info;

	}m_offsets;

private:
	void* m_pickup_ptr = nullptr;
	void** m_pickup_info_ptr = nullptr;

public:
	static constexpr auto max_pickups = 4096u;

	c_pickup_pool(void* ptr);
	~c_pickup_pool() = default;

	class c_pickup_info* pickup_info(int id);

};



