#pragma once

/*
*	### please respect other people's work
*	### author: your.n1ghtmare
*/

namespace samp {

	enum class e_version : int {
		unknown = 0,
		r1 = 1,
		r3 = 2,
		dl = 3
	};

	std::uintptr_t get_library();
	enum e_version get_version();
	
	bool is_dl();
	bool is_r1();
	bool is_r3();

	bool is_inited();

}
