#include "std_lib_facilities.h"

void in_file_text(string& name_file, vector<string>& data);
string without_vowels(string& s);
void out_file_text(vector<string>& data, string& name_f);

int main()
{
    string name_file;
    vector<string> data;
    cout << "Enter a file name for reading text:\n";
    cin >> name_file;
    in_file_text(name_file, data); 
    cout << "Enter the name of the output file to write text without vowels:\n";
	//string name_f;
    cin >> name_file;
    out_file_text(data, name_file);
    return 0;
}

void in_file_text(string& name_file, vector<string>& data)
{
    ifstream ist(name_file);
    if(!ist) error("Unable to open input file ", name_file);
    ist.exceptions(ist.exceptions() | ios_base::badbit);
    //string temp_str;
    for(string temp_str; getline(ist, temp_str);)
    {
        data.push_back(temp_str);
    }
}

string without_vowels(string& s)
{
    string temp;
    for(char& x : s)
    {
        if(x != 'A' && x != 'a' && x != 'E' && x != 'e' && x != 'O' && x != 'o' && x != 'U' && x != 'u' && x != 'I' && x != 'i')
            temp += x;
        else
            continue;   
    }
   return temp;
}

void out_file_text(vector<string>& data, string& name_f)
{
   ofstream ost{name_f};
   if (!ost) error("Unable to open output file ", name_f);
   for(string& x: data)
   {
       ost << without_vowels(x) << '\n'; 
   }
}