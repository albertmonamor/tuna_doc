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

	// ---
	// ממלא קבועים במידע לגבי המערכת, מפתחות, ועוד
	// ---
	int create_set_sock();
	
	// ---
	// מעטפת לפונקציות לחיבור לשרת המפעיל
	// param error: קוד שגיאה שמשמש לפעולות לוגיות
	// ---
	int connect(int error = 10060);
	
	// ---
	// שליחת מבנה על פי הפרוטוקול שמכיל את נתוני הסוס, הגדרות, מפתחות, ודברים שישמשו 
	// את גרפיקת המפעיל ואוטומציות בהקשר לנתונים של הסוס
	// ---
	void send_protocol();
	
	// ---
	// חיבור לשרת הראשי, הורדת נתוני המפעיל
	// ---
	bool set_setting();
	
	// ---
	// מעטפת לקריאה (לא כתיבה)על גבי השקע הראשי שממתין לפקודות מהמפעיל
	// ---
	pair<json, char*>  get_packet_p();
	
	// ---
	// שליחת נתונים על גבי השקע הראשי להחזר לצד המפעיל
	// ---
	void send_packet_p(char*, size_t);

	// ---
	// ניקוי כללי וסגירת כל החיבורים
	// ---
	void tunas_cleanup();


	json setting_sock = R"({"timeout": 10})"_json;

};

