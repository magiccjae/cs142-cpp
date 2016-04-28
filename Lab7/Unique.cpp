#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void filter(vector<string>& filter_vector, string word)
{
	bool duplicate = false;

	for(int i = 0; i < filter_vector.size(); i++)
	{
		if(word == filter_vector[i])
		{
			duplicate = true;
		}
	}

	if(duplicate == false)
	{
		filter_vector.push_back(word);

	}
}


int main()
{
	cout << "Please enter the file name: ";
	string filename;
	getline(cin, filename);
	ifstream in_file;
	in_file.open(filename.c_str());

	if(in_file.fail())
	{
		cout << "file is not opened." << endl;
		return 0;
	}
	else
	{
		cout << "file is opened." << endl;
	}

	vector<string> word_vector;
	string word;

	while(in_file >> word)
	{
		filter(word_vector, word);
	}

/*	for(int i = 1; i < word_vector.size(); i++)
	{
		cout << i << " " << word_vector[i] << endl;
	}
*/

	sort(word_vector.begin()+1, word_vector.end());

	ofstream out_file;

	string outfilename;
	cout << "Enter your output file name: ";
	getline(cin, outfilename);

	out_file.open(outfilename.c_str());

	out_file << word_vector.size() << endl;

	for(int i = 1; i < word_vector.size(); i++)
	{
		out_file << word_vector[i] << endl;
	}

	system("pause");
	return 0;
}