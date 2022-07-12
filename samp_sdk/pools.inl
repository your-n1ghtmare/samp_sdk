#pragma once

ALWAYS_INLINE c_player_pool* c_pools::player_pool()			{ return m_player_pool; }

ALWAYS_INLINE c_vehicle_pool* c_pools::vehicle_pool()		{ return m_vehicle_pool; }

ALWAYS_INLINE c_pickup_pool* c_pools::pickup_pool()			{ return m_pickup_pool; }

ALWAYS_INLINE c_object_pool* c_pools::object_pool()			{ return m_object_pool; }


ALWAYS_INLINE void*& c_pools::player_ptr()					{ return *m_player_ptr; }

ALWAYS_INLINE void*& c_pools::vehicle_ptr()					{ return *m_vehicle_ptr; }

ALWAYS_INLINE void*& c_pools::pickup_ptr()					{ return *m_pickup_ptr; }

ALWAYS_INLINE void*& c_pools::object_ptr()					{ return *m_object_ptr; }

ALWAYS_INLINE void*& c_pools::textdraw_ptr()				{ return *m_textdraw_ptr; }








