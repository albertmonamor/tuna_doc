#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include <cstdlib>
#include "protocol.h"


using namespace nlohmann;
using namespace std;

// ---
// מבצע המרה מתווי 
// ascii
// לתווים רחבים לתמיכה בשפות שונות
// ---
WCHAR* MBTWChar(const string mbyte);

// notice: this function call free for wide_char parameter
// ---
// מבצע המרה מתווים רחבים לתווי
// ascii
// ---
string WCTMbyte(WCHAR* wide_char);

// ---
// מחזיר וקטור עם תוי 
// ascii
// כל תחו מציין את כונן המערכת שזמין לקריאה כתיבה
// ---
vector<char> get_drives_system();

// ---
// מחזיר את רשימת הכוננים בצורה המתאימה לפרוטוקול שידור הנתונים
// ---
json listDrives(string fptuna);

// like: "c:\\" without *, it append on this function 
// ---
// מחזיר את רשימת הקבצים מתוך התיקייה הספציפית, לא רקורסיבי
// param path: נתיב לתיקייה
// param is_file: בוליאני האם הנתיב קובץ או לא 
// ---
vector<string> base_listdir(string path, bool is_file);

// ---
// מחזיר את אשימת הקבצים בהתאם לפרוטוקול
// param path: נתיב לתיקייה
// ---
json listdir(string path);

// ---
// מחזיר את גודל  הקובץ, ללא תמיכה בתמונות מערכת וקבצים חריגים
// ---
DWORD get_sizefile(string path);

// /!\ this function not deallocate path
// ---
// מחזיר האם הנתיב תיקייה או לא
// ---
bool isDirectory(LPCWSTR path);


// ---
// מוחק קובץ, או תיקייה ריקה, אין רקורסיה
// ---
bool delete_path(string path);

// ---
// שינוי שם קובץ ע"י 
// MV
// ---
bool rename_path(string path, string npath);

// /!\ this function not deallocate path
// ---
// בודק האם הקובץ תקין כדי לערוך אותו, כלומר קובץ טקסט קריא ולא תמונה או אחר
// ---
bool isValidFileToEdit(LPCWSTR path);

// no images, no disks, /!\ this function not deallocate path
// ---
// האם הקובץ תקין לקריאה, כלומר הרשאות, וגודל הקובץ וסוג הקובץ
// ---
bool isValidFileToRead(LPCWSTR path);

// /!\ this function not deallocate path
// ---
// האם זה קובץ 
// ---
bool isFile(LPCWSTR path);

// /!\ this function not deallocate path
// ---
// האם הקובץ לא נתמך
// ---
bool isTypeFileUnsupported(string path);


// [!], verify file before
// ---
// פותח קובץ לקריאה, ומחזיר ידית וגודל הקובץ
// ---
pair<size_t, HANDLE> openFile(string path);

