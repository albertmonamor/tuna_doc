#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <string>
#include <vector>
#include <list>
#include <memory>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

// ---
// תפקידו לעבוד עם ידית שקע, מנהל את קבלת המידע על פי הפרוטוקול ומחזיר רשימת בלוקים 
// בגודל 1024 בתים
// param sock: ידית החיבור לקריאה
// param pSize: ממלא אותו בסך הנתונים שנקראו
// param buf_size: הגדרה כמה בתים לקרוא בכל פעם מהשקע
// ---
list<pair<size_t, char*>> receive_proto(SOCKET, size_t&, int);

// ---
// תפקידו לעבוד עם ידית שקע, מנהל את שליחת המידע על פי הפרוטוקול ומחזיר סטטוס מתוך השקע
// param sock: ידית השקע
// param packet: הנתונים לשליחה שמובנים על פי הפרוטוקול
// param lpacket: אורך הנתונים שישלחו 
// ---
int send_proto(SOCKET, char*, size_t);



class tcp_socket
{

public:


	// ---
	// param address: כתובת השרת אליו להתחבר
	// param port: היציאה כדי ליצור שקע
	// param proto: דגל להגדרות השקע עצמו
	// ---
	tcp_socket(const char* address, int port, int proto = 0);
	
	// delete
	~tcp_socket();

	// ---
	// מאתחל את  השקע
	// ---
	int init_socket();
	
	// ---
	// מאתחל את החיבור מסוג
	// IPv4
	// ומנסה להתחבר
	// param __address: כתובת השרת אליו נרצה להתחבר
	// param __port: היציאה
	// ---
	int open_socket(const char* __address=0, int __port=0);

	// ---
	// מעטפת לפונקציה
	// receive_proto
	// param lpkacet: מגדיר לו את אורך הנתונים שהתקבלו
	// param buf_size:
	// ---
	list<pair<size_t, char*>> get_packet(size_t&lpacket, int buf_size=1024);

	// ---
	// מעטפת לפונקציה
	// send_proto
	// param packet: הנתונים שאותם השקע יכתוב
	// param lpacket: אורך הנתונים
	// ---
	int send_packet(char* packet, size_t lpacket);

	// ---
	// מעטפת לפונקציות 
	// 1. send_packet
	// 2. get_packet
	// ---
	list<pair<size_t, char*>> communication(char* packet, size_t lpacket);

	// ---
	// ניקוי כללי וסגירת השקעים
	// ---
	void ts_cleanup();

	const char* ip;
	int			port;
	bool is_open = 0;
	SOCKET ltuna;

private:
	int BUF_SIZE = 4096;
	int proto = 0;
};


class tcp_streamer : public tcp_socket
{
public:
	// ---
	// param address: כתובת השרת המרוחק
	// param port: כתובת היציאה
	// param proto:
	// ---
	tcp_streamer(const char* address, int port, int proto = 0);

	// hFile handle need close out this function
	// ---
	// קריאה מתוך קובץ בכונן לתוך שקע בקצב של 4096 נתונים לפעימה
	// param hFile: ידית הקובץ התקינה
	// param sock: שקע תקשורת
	// param lfile: יתמלא באורך הנתונים שנקראו מתוך הקובץ ושודרו
	// ---
	bool ReadFromFile(HANDLE&hFile, SOCKET sock, size_t&lfile);

private:
	const size_t b4K = 4096;
};


// ---
// מקבל שם מארח ומחזיר כתובת אינטרנט פרוטוקול
// param host: שם המארח
// ---
const char* GetInterntProtclHost(const char*);



