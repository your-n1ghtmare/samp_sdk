# samp_sdk

- samp_sdk is a library for simplified interaction with samp written in c++20

# support versions

support for multiple versions at runtime:  
- **03dl**    
- **0.3.7 r1**    
- **0.3.7 r3**    
- and maybe others in the future    

# credits

- **your.n1ghtmare**    
- **SR_Team**    
- **sc6ut**    

# example

- **#include "sdk.hpp"**
- std::string str = **g_samp->pools()->player_pool()->get_local_player_name()**;    
- float a = **g_samp->pools()->player_pool()->remote_player(id)->get_health()**;    
- int b = **g_samp->pools()->pickup_pool()->pickup_info(id)->get_model()**;    
