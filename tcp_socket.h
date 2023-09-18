#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <string>
#include <vector>
#include <list>
#include <memory>
#pragma comment(lib, "ws2_32.lib")
using namespace std;


list<pair<size_t, char*>> receive_proto(SOCKET, size_t&, int);
int send_proto(SOCKET, char*, size_t);

class tcp_socket
{
public:


	// init
	tcp_socket(const char* address, int port, int proto = 0);
	
	// delete
	~tcp_socket();

	int init_socket();
	// connect with socket
	int open_socket(const char* __address=0, int __port=0);

	// get packets
	list<pair<size_t, char*>> get_packet(size_t&lpacket, int buf_size=1024);

	// send packet
	int send_packet(char* packet, size_t lpacket);

	// communicate with get and send
	list<pair<size_t, char*>> communication(char* packet, size_t lpacket);

	const char* ip;
	int			port;

	void ts_cleanup();

	bool is_open = 0;
	SOCKET ltuna;

private:
	int BUF_SIZE = 4096;
	int proto = 0;
};


class tcp_streamer : public tcp_socket
{
public:
	tcp_streamer(const char* address, int port, int proto = 0);

	// hFile handle need close out this function
	bool ReadFromFile(HANDLE&hFile, SOCKET sock, size_t&lfile);

private:
	const size_t b4K = 4096;
};


const char* GetInterntProtclHost(const char*);



