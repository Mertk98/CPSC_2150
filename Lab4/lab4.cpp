// Mert Kilic
// 100334228
#include <iostream>
#include "StackEmpty.h"
#include "Stack.h"
// StackEmpty is a helper exception class
// Stack is the custom stack class

int precedence(char op)
{
	if (op == '+' || op == '-')
	{
		return 1;
	}

	if (op == '*' || op == '/' || op == '%')
	{
		return 2;
	}

	return 0;
}

// Helper function to handle precedence
void handlePrdceIn2Pre(Stack<std::string>& opands, Stack<char>& ops, const char& op)
{

	if (precedence(op) > precedence(ops.peek()))
	{
		ops.push(op);
	}
	else
	{
		std::string opand1 = "";
		std::string opand2 = "";
		std::string oper = "";
	
		try {
			opand1 = opands.peek();
			opands.pop();
			opand2 = opands.peek();
			opands.pop();
			oper = ops.peek();
			ops.pop();

			opands.push(oper + opand2 + opand2);
		}
		catch (const StackEmpty& ex)
		{
			std::cout << "Error: Stack is empty!!!" << std::endl;
		}
	}
}

std::string in2prefix(const std::string& exp)
{
	Stack<char> ops;
	Stack<std::string> opands;
	std::string preExp = "";

	for (size_t i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(')
		{
			ops.push(exp[i]);
		}
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*'
			|| exp[i] == '/' || exp[i] == '%')
		{
			handlePrdceIn2Pre(opands, ops, exp[i]);
		}
		else if (exp[i] == ')')
		{
			try {
				while (ops.peek() != '(')
				{
					std::string opand1 = "";
					std::string opand2 = "";
					std::string op = "";

					opand1 = opands.peek();
					opands.pop();
					opand2 = opands.peek();
					opands.pop();
					op = ops.peek();
					ops.pop();
					opands.push(op + opand2 + opand1);
				}
				ops.pop();
			}
			catch (const StackEmpty& ex)
			{
				std::cout << "Error: Stack is empty!!" << std::endl;
			}
		}
		else if (exp[i] != ' ')
		{
			std::string tmp(1, exp[i]);
			opands.push(tmp);
		}
	}

	preExp = opands.peek();

	return preExp;
}

std::string pre2infix(const std::string& pre)
{
	Stack<std::string> opands;
	std::string inExp = "";

	for (size_t i = 1; i <= pre.length(); i++)
	{
		// reverse the str
		char current = pre[pre.length() - i];

		if (current == '+' || current == '-' || current == '*'
			|| current == '/' || current == '%')
		{
			std::string tmp = "";

			try
			{
				tmp += "(";
				tmp += opands.peek();
				opands.pop();
				tmp += current;
				tmp += opands.peek();
				opands.pop();
				tmp += ")";
				opands.push(tmp);
			}
			catch (const StackEmpty& ex)
			{
				std::cout << "Error: Stack is empty!!!" << std::endl;
			}
		}
		else if(current != ' ')
		{
			std::string tmp(1, current);
			opands.push(tmp);
		}
	}

	inExp = opands.peek();

	return inExp;
}

std::string post2infix(const std::string& post)
{
	Stack<std::string> opands;
	std::string inExp = "";

	for (size_t i = 0; i < post.length(); i++)
	{
		if (post[i] == '+' || post[i] == '-' || post[i] == '*'
			|| post[i] == '/' || post[i] == '%')
		{
			std::string tmp = "";

			try
			{
				std::string opand1 = "";
				std::string opand2 = "";

				opand2 = opands.peek();
				opands.pop();
				opand1 = opands.peek();
				opands.pop();

				tmp += "(";
				tmp += opand1;
				tmp += post[i];
				tmp += opand2;
				tmp += ")";

				opands.push(tmp);
			}
			catch (const StackEmpty& ex)
			{
				std::cout << "Error: Stack is empty!!!" << std::endl;
			}
		}
		else if (post[i] != ' ')
		{
			std::string tmp(1, post[i]);
			opands.push(tmp);
		}
	}

	inExp = opands.peek();

	return inExp;
}


int main()
{
	std::cout << "===== Infix to Prefix Test =====" << std::endl;
	std::string infix1 = "(( x % d ) + ( Y - c ))";
	std::string infix2 = "((A+ B  ) * t)";
	std::cout << "Infix expression : " << infix1 << std::endl;
	std::cout << "Prefix expression: " << in2prefix(infix1) << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Infix expression : " << infix2 << std::endl;
	std::cout << "Prefix expression: " << in2prefix(infix2) << std::endl;
	std::cout << "" << std::endl;

	std::cout << "===== Prefix to Infix Test =====" << std::endl;
	std::string prefix1 = "*+ABt";
	std::string prefix2 = "+%xd-Yc";
	std::cout << "Prefix expression : " << prefix1 << std::endl;
	std::cout << "Infix expression: " << pre2infix(prefix1) << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Prefix expression : " << prefix2 << std::endl;
	std::cout << "Infix expression: " << pre2infix(prefix2) << std::endl;
	std::cout << "" << std::endl;

	std::cout << "===== Postfix to Infix Test =====" << std::endl;
	std::string postfix1 = "AB+t*";
	std::string postfix2 = "xd%Yc-+";
	std::cout << "Postfix expression : " << postfix1 << std::endl;
	std::cout << "Infix expression: " << post2infix(postfix1) << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Postfix expression : " << postfix2 << std::endl;
	std::cout << "Infix expression: " << post2infix(postfix2) << std::endl;

	return 0;
}