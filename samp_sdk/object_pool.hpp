#pragma once

/*
*	### please respect other people's work
*	### author: your.n1ghtmare
*/

class c_object_pool {

	struct {

		std::array<std::uintptr_t, 4> m_count;
		std::array<std::uintptr_t, 4> m_listed;
		
	}m_offsets;

private:
	void* m_object_ptr = nullptr;

	int* m_count_ptr = nullptr;
	int* m_is_listed_ptr = nullptr;

public:
	static constexpr auto max_objects = 1000u;

	c_object_pool(void* ptr);
	~c_object_pool() = default;

	int& get_count();
	int& is_listed(int id);


};



