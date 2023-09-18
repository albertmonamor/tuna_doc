#pragma once
#include "tcp_socket.h"
#include <sstream>
#include <nlohmann/json.hpp>


using namespace nlohmann;




// simple socket. use with http protocol
class http: tcp_socket
{
public:
	http(const char* ip, int port=80, string index="/", string params="");
	// get method
	string get();
	// post method, RETURN json but as string 
	json post();

	// vars
	string index;
	string params;
	string method = "GET";
	const char* host;

private:
	string s_http_packet(string method);
};

