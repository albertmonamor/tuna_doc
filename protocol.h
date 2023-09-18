#pragma once
#include <iostream>
#include <map>
#include <nlohmann/json.hpp>


using namespace std;
using namespace nlohmann;

// vars
extern const char*			OK;
extern const int			PACKET_ERROR_I;
extern const list<pair<size_t, char*>>	PACKET_ERROR;
extern const pair<json, char*> BLOCK_ERROR;
extern map<string, int>		SETTING;
extern json					PACKET_T_PROTOCOL;
extern const size_t				MAX_LEN_PROTO;
extern const size_t				MAX_LEN_EDITOR;
extern const size_t				MIN_CHANGE_FRM;
extern string				KEY_XOR;
extern const string			SERVER;
extern const string			API_KEY;
extern const char*			S_KEY;
extern map<int, string> MODE_PACKAGE;
extern char EMPTY[];
extern json SCREEN_S;
extern const int SUM_BLOCKS;
extern char BLOCK_FRM[];
extern wchar_t TUNA_NAME[256];
extern const vector<string> TYPE_FILE_BINARY;
// function
string new_key_xor();

