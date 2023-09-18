#pragma once
#include "tcp_socket.h"
#include <nlohmann/json.hpp>


using namespace std;
using namespace nlohmann;

class tuna_socket:tcp_socket
{
public:
	// init object
	tuna_socket();

	// create setting socket
	int create_set_sock();
	// connect
	int connect(int error = 10060);
	// send protocol to server
	void send_protocol();
	// set setting
	bool set_setting();
	// get packet & decrypt binary
	pair<json, char*>  get_packet_p();
	// send 
	void send_packet_p(char*, size_t);

	void tunas_cleanup();


	json setting_sock = R"({"timeout": 10})"_json;

};

