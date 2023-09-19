#include "analyze.h"
#include "tuna.h"
#include "shell.h"
#include <iostream>
#include <string.h>
#include "modes.h"
#include "explorer.h"
#pragma warning(disable:4996)

/* ---written by: אברהם סבן
*  ---date: 18.09.2023
*  ---please dont copy
*  ---talk to me: +972585005617
*
*/



int main() {
	/* ===== INIT ===== */
	getTunaName(TUNA_NAME);
	tuna tr;
	tr.run();
}



//int WINAPI WinMain(_In_ HINSTANCE hI, _In_opt_ HINSTANCE hP, _In_ char* pC, _In_ int nC) {
//    /* ===== INIT ===== */
//    getTunaName(TUNA_NAME);
//
//    tuna tr;
//    tr.run();
//
//
//
//}
