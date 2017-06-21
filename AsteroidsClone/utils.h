#pragma once
#include <iostream>
#include <fstream>
#include <string>

//File reader
std::string read_file(const char* path);
std::string read_file(std::string path);

//Callbacks
void error_callback(int error, const char* description);