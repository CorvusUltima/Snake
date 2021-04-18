#pragma once
#include <string>
#include <iostream>
#include<fstream>

class txtManipulation
{
public:
	
    std::string Txt_To_String(const char* filename);
	std::string get_file_contents(const char* filename);
	std::string get_substring(const char* filename,std::string start_pos, std::string end_pos);
	std::string get_substring(const char* filename, std::string start_pos,int number );//geting number in string by occurances 
	std::string remove_all_non_numberCH(std::string original_string);


	


};

