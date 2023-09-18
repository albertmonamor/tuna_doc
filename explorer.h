#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include <cstdlib>
#include "protocol.h"


using namespace nlohmann;
using namespace std;

// convert UTF16 for UTF8
WCHAR* MBTWChar(const string mbyte);

// notice: this function call free for wide_char parameter
string WCTMbyte(WCHAR* wide_char);


// run from A to Z, check if one of them available
vector<char> get_drives_system();

// return list support tuna protocol
json listDrives(string fptuna);

// like: "c:\\" without *, it append on this function 
vector<string> base_listdir(string path, bool is_file);

json listdir(string path);

DWORD get_sizefile(string path);

// /!\ this function not deallocate path
bool isDirectory(LPCWSTR path);

// delete file forever
bool delete_path(string path);

bool rename_path(string path, string npath);

// /!\ this function not deallocate path
bool isValidFileToEdit(LPCWSTR path);

// no images, no disks, /!\ this function not deallocate path
bool isValidFileToRead(LPCWSTR path);

// /!\ this function not deallocate path
bool isFile(LPCWSTR path);

// /!\ this function not deallocate path
bool isTypeFileUnsupported(string path);


// [!], verify file before
pair<size_t, HANDLE> openFile(string path);

