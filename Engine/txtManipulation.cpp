#include "txtManipulation.h"

std::string txtManipulation::Txt_To_String(const char* filename)
{
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    if (in)
    {
        std::string contents;
        in.seekg(0, in.end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return(contents);
    }
    throw(errno);

   
}

std::string txtManipulation::get_file_contents(const char* filename)
{
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    if (in)
    {
        return(std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>()));
    }
    throw(errno);
}

std::string txtManipulation::get_substring(const char* filename, std::string start_pos, std::string end_pos)
{
    
    std::string orginal_string = Txt_To_String(filename);//extracting file to a string 
    size_t  first = orginal_string.find(start_pos);
    size_t  last = orginal_string.find(end_pos);
    std::string strNew = orginal_string.substr(first+start_pos.length(), last-(start_pos.length()+first));
     
    
    return strNew;
}

std::string txtManipulation::remove_all_non_numberCH(std::string original_string)
{

  

    for (int i = 0; i < original_string.length(); i++)
    {    

        if (original_string.at(i) < '0' || original_string.at(i) > '9')
        {
            original_string.erase(i,i+1);
        }

    }
    
    return original_string;
}

