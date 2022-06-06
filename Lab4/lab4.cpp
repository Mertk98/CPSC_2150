#include <iostream>
#include "StackEmpty.h"
#include "Stack.h"

std::string in2prefix(const std::string& in, Stack<char> ops, Stack<std::string> opands)
{
	std::string str = "";
	if(in.length() == 0)
	{
		return "";
	}

	else if(in[0] == '(' || in[0] == '+' || in[0] == '-'
	|| in[0] == '*' || in[0] == '/' || in[0] == '%')
	{
		ops.push(in[0]);
	}
	
	else if(in[0] == ')')
	{
		while(!opands.isEmpty())
		{
			str = opands.peek() + str;
			opands.pop();
		}
		str = ops.peek() + str;
		ops.pop();
		ops.pop();
	}

	else
	{
		if(in[0] != ' ')
		{
			std::string tmp(1,in[0]);
			opands.push(tmp);
		}
	}
	
	return str + in2prefix(in.substr(1, in.length()), ops, opands);
}

//std::string pre2infix(std::string pre)
//{
//
//}
//
//std::string post2infix(std::string post)
//{
//y
//}


int main()
{
	Stack<char> ops;
	Stack<std::string> opands;
	std::string exp = "(( x%d )+(Y-c))";

	std::cout << in2prefix(exp, ops, opands) << std::endl;

	return 0;
}