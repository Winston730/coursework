#pragma once

#include <string>
using namespace System;

std::string& Convert_String_to_string(String^ s, std::string& os);//������������ System::string ^ � std::string
String^ Convert_string_to_String(std::string& os, String^ s);//������������ std::string � System::string ^ 
