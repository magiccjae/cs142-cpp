#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <ctime>

using namespace std;

bool reading(vector<string>& wordvector, string filename)    // reading function
#include <cstdlib>
{
	string word;
	ifstream in_file;

	in_file.open(filename.c_str());

	if(in_file.fail())					// check for the right fiename
	{
		cout << "Invalid filename" << endl;
		return true;
	}
	else
	{
		while(in_file >> word)			// putting the words into a vector
		{
			wordvector.push_back(word);
		}

		return false;
	}

}


void jumbling(vector<string>& wordvector)		// jumbling function
{

	for(int i = 0; i < wordvector.size(); i++)
	{
		string prefix = "";
		string postfix  = "";
		string temp_word = wordvector[i];

		if(!isalnum(wordvector[i][0]))			// check for pre-punctuation
		{
			prefix = wordvector[i][0];
			temp_word = wordvector[i].substr(1, wordvector[i].size()-1);
		}
		if(!isalnum(wordvector[i][wordvector[i].size()-1]))		// check for post-punctuation
		{
			postfix = wordvector[i][wordvector[i].size()-1];
			temp_word = temp_word.substr(0, wordvector[i].size()-1);
		}

		if(temp_word.length() > 3)		// check if the words contains more than 4 characters
		{
			random_shuffle(temp_word.begin()+1, temp_word.end()-1);			// actual jumble !
		}

		wordvector[i] = prefix + temp_word + postfix;		// put back the punctuations

	}

}

void writing(vector<string> wordvector, string filename)
{

	string word;
	ifstream in_file;
	ofstream out_file;

	in_file.open(filename.c_str());

	if(!in_file.fail())			// check if the output file name exists
	{
		filename = "stolen.txt";
	}
	in_file.close();

	out_file.open(filename.c_str());

	int counter = 1;

	for(int i = 0; i < wordvector.size(); i++)			// putting the words into a vector
	{
		out_file << wordvector[i] << " ";

		if(counter == 12)
		{
			out_file << endl;

			counter = 0;
		}

		counter ++;
	}

	out_file.close();

}


int main()
{
	srand((time(0)));

	string input_name;
	vector<string> word_vector;
	bool again = true;
	bool check1 = true;
	string output_name;

	while(again)
	{
		word_vector.clear();

		bool check2 = true;

		string choice;

		while(check1)
		{
			cout << "Please enter the input file name: ";
			cin >> input_name;

			check1 = reading(word_vector, input_name);

		}

		jumbling(word_vector);			// call for jumbling function

		cout << "Please enter the output file name: ";
		cin >> output_name;

		writing(word_vector, output_name);		// call for writing function


		while(check2)			// check for continuance
		{
			cout << "Wanna do it again? " << "Press 1 to do it again, or press 2 to quit: ";
			cin >> choice;

			if(choice == "1")
			{
				again = true;
				check1 = true;
				check2 = false;

			}
			else if(choice == "2")
			{
				again = false;
				check2 = false;
			}
			else
			{
				cout << "That's not an option." << endl;
				check2 = true;
			}
		}

	}

	system("pause");
	return 0;
}