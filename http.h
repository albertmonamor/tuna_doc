#pragma once
#include "tcp_socket.h"
#include <sstream>
#include <nlohmann/json.hpp>


using namespace nlohmann;




// ---
// מחלקה לניהול בסיסי של תקשורת בפרוטוקול 
// http
// 2 מתודות בלבד
// ---
class http: tcp_socket
{
public:
	// ---
	// param ip: כתובת השרת המרוחק
	// param port: יציאה
	// param index: נתיב לניווט בשרת
	// param params: ארגומנטים בעת שימוש באחד מהמתודות לצורך העברת מידע לשרת
	// ---
	http(const char* ip, int port=80, string index="/", string params="");
	
	// ---
	// GET מתודה
	// ---
	string get();

	// ---
	// POST מתודה
	// מחזיר את גוף ההודעה כמחרוזת
	// ---
	json post();

	// vars
	string index;
	string params;
	string method = "GET";
	const char* host;

private:
	// ---
	// מרכיב את חבילת המידע על פי הפרוטוקול
	// ---
	string s_http_packet(string method);
};

