#include "sdk.hpp"

namespace samp {

	std::uintptr_t get_library() {

		static std::uintptr_t samp = 0;
		if (samp) return samp;

		samp = reinterpret_cast<std::uintptr_t>(GetModuleHandleA("samp.dll"));
		if (samp == -1) samp = 0;
		return samp;
	}

	enum e_version get_version() {
	
		static auto ver = e_version::unknown;

		if (ver != e_version::unknown) return ver;

		auto samp = get_library();

		 if (*(unsigned char*)(samp + 0x129) == 0xF4)
			ver = e_version::r1;

		else if (*(unsigned char*)(samp + 0x129) == 0x00) {

			if (*(unsigned char*)(samp + 0x140) == 0xD0)
				ver = e_version::r3;

		}
		else if (*(unsigned char*)(samp + 0x129) == 0x31)
			ver = e_version::dl;

		return ver;
	}

	bool is_dl()  {
		return get_version() == e_version::dl;
	}

	bool is_r1() {
		return get_version() == e_version::r1;
	}

	bool is_r3() {
		return get_version() == e_version::r3;
	}

	bool is_inited() {

		if (get_version() == e_version::r1)
			return *reinterpret_cast<void**>(get_library() + 0x21A0F8) != nullptr;

		else if (get_version() == e_version::r3)
			return *reinterpret_cast<void**>(get_library() + 0x26E8DC) != nullptr;

		else if (get_version() == e_version::dl)
			return *reinterpret_cast<void**>(get_library() + 0x2ACA24) != nullptr;

		return false;
	}

}

