#pragma once


ALWAYS_INLINE std::uint16_t c_player_pool::get_local_player_id() { return *m_local_player_id_ptr; }

ALWAYS_INLINE int c_player_pool::get_local_player_ping() { return *m_local_player_ping_ptr; }

ALWAYS_INLINE int c_player_pool::get_local_player_score() { return *m_local_player_score_ptr; }



