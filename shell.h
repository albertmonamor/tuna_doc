#pragma once

#include <memory>
#include <sstream>
#include <windows.h>
#include <iostream>
using namespace std;


// run commmand by using cmd.exe file, using pipe to write & read
// not support multiply commands, cant use && to chains commands
char* run_pshell(const string& cmd, size_t&lout);

