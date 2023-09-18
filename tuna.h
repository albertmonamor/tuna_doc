#pragma once
#include "analyze.h"
#include "protocol.h"
#include "tuna_socket.h"
#include <thread>

class tuna : tuna_socket
{
public: 
	// init tuna
	tuna();
	// delete tuna
	//~tuna();
	// start point processes
	void run();
	// processes and communication
	void proto_communication();
	// mode ping 
	void mode_ping();
	// mode shell
	void mode_shell(json info);
	// mode shell 2
	void mode_shell_terminal(json info);
	// mode screen
	void mode_screen(json info);
	// mode explorer
	void mode_explorer(json info);
	// mode streamer
	void mode_streamer(json info);
	// mode scanner: not suppport here
	void del__mode_scanner();
	// mode signal
	void mode_signal(json sig);
	// 
	void cleanup();

private:
	int kill_me = 0;

};

