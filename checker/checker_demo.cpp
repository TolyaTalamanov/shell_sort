#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
#include "checker.h"
using namespace std;

vector<int> load_data_from_file(string file_path);

int main(int argc, char* argv[]){
	string input_data_path  = string(argv[1]);
	string output_data_path = string(argv[2]);

	Checker checker;

	auto input_data  = load_data_from_file(input_data_path);
	auto output_data = load_data_from_file(output_data_path);

	vector<int> true_data(input_data.begin(), input_data.end());
	sort(true_data.begin(), true_data.end());

	if(output_data == true_data){
		checker.write_message("AC. Arrays are equal.");
	}	
	else{
		checker.write_message("WA. Output is't correct");
	}
	return 0;
}
vector<int> load_data_from_file(string file_path){
	ifstream data_file(file_path);
	vector<int> data;

	if(!data_file){
		throw runtime_error("failed open file");
	}

	istream_iterator<int> begin_file(data_file);
	istream_iterator<int> end_file;

	copy(begin_file, end_file, back_inserter(data));

	data_file.close();

	return data;
}
