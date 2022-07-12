#pragma once

ALWAYS_INLINE c_pools* c_base::pools() { return m_pools; }

ALWAYS_INLINE int& c_base::game_state() { return *m_game_state_ptr; }

ALWAYS_INLINE void*& c_base::pools_ptr() { return *m_pools_ptr; }

ALWAYS_INLINE void*& c_base::settings_ptr() { return *m_settings_ptr; }

ALWAYS_INLINE char*& c_base::get_server_ip() { return m_server_addr_ptr; }

ALWAYS_INLINE std::uint16_t& c_base::get_server_port() { return *m_server_port_ptr; }




