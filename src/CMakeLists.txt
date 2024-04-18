add_library(src tcp_server.cpp tcp_client.cpp tcp_connection.cpp message_basic.cpp)
target_include_directories(src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(src PUBLIC ${CMAKE_PREFIX_PATH}\\asio-1.30.2\\include)
