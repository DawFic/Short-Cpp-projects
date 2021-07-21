#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include "dataVector.h"

using namespace std;

vector<string> split(const string& data, const string delimiter = "")
{
        vector<string> vector;

        if (delimiter == "")
        {
                vector.push_back(data);
                return vector;
        }

        istringstream const_string_data(data);

        string word;
        const char delim = delimiter[0];
        while (getline(const_string_data,word,delim))
        {
                        vector.push_back(word);
        }

        return vector;
}


string join(const vector<string>& data, const string& delimiter)
{
        string return_string = "";

        for (uint8_t i = 0; i < data.size(); i++)
        {
                return_string += data[i];
                return_string += i == data.size() - 1 ? "" : delimiter;
        }

        return return_string;
}
dataVector<int> open_csv(string sciezka){
	ifstream file_read;
        file_read.open(sciezka);
        vector<vector<string>> v_of_line;
        vector<string> v_from_file;
	string tekstZPliku;
	dataVector<int> v;
        while (getline(file_read, tekstZPliku))
                v_from_file.push_back(tekstZPliku);
        int tmp_int;
        for (int i = 0; i < v_from_file.size(); i++)
        {
                ostringstream tmp2;
                tmp2 << v_from_file[i] << endl;
                vector<string> tmp_v = split(tmp2.str(),";");
                v_of_line.push_back(tmp_v);
        }
        for(int i = 0; i < v_of_line.size(); i++)
        {
                for(int j = 0; j < v_of_line[i].size(); j++)
                {
                        if(j == 1 && i>0)
                        {
                                string a = v_of_line[i][j];
                                tmp_int = atoi(a.c_str());
                                v.push_back(move(tmp_int));
                        }

                }
        }
	file_read.close();
	return v;
}
void write_csv(string sciezka, dataVector<int> v){
        ofstream file;
        file.open(sciezka);

        file << "Index" << ";" << "Value" <<  endl;

        for (int i = 0; i < v.size(); i++)
        {
                ostringstream tmp;
                tmp << i << ";" << v[i] << endl;

                vector<string> vector = split(tmp.str(),";");

                file << join(vector, ";");
        }
        file.close();
}



int main()
{
	dataVector<int> test;
	test.push_back(53);
	test.push_back(55);
	test.push_back(57);

	write_csv("test.csv", test);
	dataVector<int> v;
	v = open_csv("test.csv");
	cout << v << endl;
}
