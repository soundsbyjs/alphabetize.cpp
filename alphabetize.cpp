
#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>


int main(int argc, char* argv[])
{
	// an array of vectors of strings to store the file
	// man that's a mouthful
	
	if(argc != 3)
	{
		printf("Invalid syntax. Pass name of file to alphabetize and name of file to output to.\n");
		return -1;
	}
	if (argv[1] == argv[2])
	{
		printf("Files can't be the same name.\n");
		return -1;
	}
	std::array<std::vector<std::string>, 26> arrWords;
		
	std::fstream file;
	std::string filename = argv[1];
	file.open(filename);
		
	std::string nextWord;
	
	// sort each word by its starting letter
	while(file >> nextWord)
	{
		if(nextWord[0] >= 'a' && nextWord[0] <= 'z' )
			arrWords[nextWord[0] - 'a'].push_back(nextWord);
		else if(nextWord[0] >= 'A' && nextWord[0] <= 'Z')
			arrWords[(nextWord[0] + 32) - 'a'].push_back(nextWord);
	}
	file.close();
	for(int i = 0; i < 26; i++)
	{
		std::sort(arrWords[i].begin(), arrWords[i].end());
	}
	
	std::ofstream fileWrite;
	fileWrite.open(argv[2]);
	int count = 0;
	for(auto i : arrWords)
	{
		for(auto j : i)
		{
			fileWrite << j << " ";
			count++;
			if(count == 14)
			{
				fileWrite << std::endl;
				count = 0;
			}
		}
		fileWrite << std::endl << std::endl;
	}
	fileWrite.close();
}
