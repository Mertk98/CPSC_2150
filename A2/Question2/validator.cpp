#include <iostream>
#include <string>
#include <fstream>
#include "Stack.h"
#include "StackEmpty.h"

bool validate(std::string str1, std::string str2)
{
	return str1 == str2;
}

bool handleValidation(Stack<std::string>& stack, std::string line)
{
	std::string openingTagName = "";
	std::string closingTagName = "";
	bool opening = false;
	bool closing = false;
	
	for (size_t i = 0; i < line.length(); i++)
	{
		line[i] = std::tolower(line[i]);

		if (line[i] == '<' && line[i+1] != '/' && opening == false)
		{
			opening = true;
		}

		else if (opening == true && line[i] == '/' && line[i + 1] == '>')
		{
			openingTagName = "";
			opening = false;
		}

		else if (line[i] == '>' && opening == true)
		{
			stack.push(openingTagName);
			openingTagName = "";
			opening = false;
		}

		else if (opening == true && line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			openingTagName += line[i];
		}

		else if (line[i] == '<' && line[i + 1] == '/' && closing == false)
		{
			closing = true;
		}

		else if ( line[i] == '>' && closing == true)
		{
			closing = false;

			if (validate(stack.peek(), closingTagName))
			{
				stack.pop();
			}
			else
			{
				return false;
			}

			closingTagName = "";
		}

		else if (closing == true && line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '/')
		{
			closingTagName += line[i];
		}
	}

	return stack.isEmpty();
}


int main()
{
	// create an empty stack
	Stack<std::string> stack;
	//string var to hold html structure
	std::string html = "";
	std::string fileNames[2] = {"valid.txt", "invalid.txt"};

	for (int i = 0; i < 2; i++)
	{
		// Stream object
		std::fstream myFile;
		myFile.open(fileNames[i]);

		// getting lines from input file
		if (myFile.is_open())
		{
			std::string line;

			while (std::getline(myFile, line))
			{
				html += (line + '\n');
			}
			myFile.close();
		}
	
		if (handleValidation(stack, html))
		{
			std::cout << "Html structure in " << fileNames[i] <<  " is valid" << std::endl;
		}
		else
		{
			std::cout << "Html structure in " << fileNames[i] << " is invalid" << std::endl;
		}
	}


	return 0;
}