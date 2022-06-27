#ifndef _BT_H_
#define _BT_H_
#include <iostream>
#include <climits>
#include <cmath>
#include <string>
#include "Stack.h"
#include "StackEmpty.h"
#include "Node.h"

template <typename T>
class BT
{
private:
    Node<T>* root_;
    void handlePrecedence(Stack<T>& operators, Stack<Node<T>*>& operands, const char& op);
    void destroyTree(Node<T>* node);
    // traverse the tree by using inorder traversal algorithm
    void inOrderTraversal(Node<T>* node);
    void postOrderTraversal(Node<T>* node, std::string& str);
public:
    BT();
    bool isEmpty();
    int precedence(char op);
    Node<T>* infixTree(std::string infixExpr);
    void createExprTree(std::string expr);
    void printTree();
    void postfix(std::string& str);
    ~BT();
};

template <typename T>
BT<T>::BT()
{
    root_ = nullptr;
}

template <typename T>
bool BT<T>::isEmpty()
{
    return root_ == nullptr;
}

template <typename T>
int BT<T>::precedence(char op)
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

template <typename T>
void BT<T>::handlePrecedence(Stack<T>& operators, Stack<Node<T>*>& operands, const char& op)
{
    if (precedence(op) > precedence(operators.peek()))
    {
        operators.push(op);
    }
    else
    {
        Node<T>* opand1 = nullptr;
        Node<T>* opand2 = nullptr;
        char oper;

        try {
            opand1 = operands.pop();
            opand2 = operands.pop();
            oper = operators.pop();
            Node<T>* node = new Node<T>(opand2, opand1, oper);

            operands.push(node);
            operators.push(op);
        }
        catch (const StackEmpty& ex)
        {
            std::cout << "Error: Stack is empty!!!" << std::endl;
        }
    }
}

template <typename T>
Node<T>* BT<T>::infixTree(std::string infixExpr)
{
    Stack<char> operators;
    Stack<Node<T>*> operands;

    for (size_t i = 0; i < infixExpr.length(); i++)
    {
        if (infixExpr[i] == '(')
        {
            operators.push(infixExpr[i]);
        }
        else if (infixExpr[i] == ')')
        {
            try {
                while (operators.peek() != '(')
                {
                    Node<T>* opand1 = nullptr;
                    Node<T>* opand2 = nullptr;
                    char op;

                    opand1 = operands.pop();
                    opand2 = operands.pop();
                    op = operators.pop();

                    Node<T>* tmp = new Node<T>(opand2, opand1, op);
                    operands.push(tmp);
                }
                operators.pop();
            }
            catch (const StackEmpty& ex)
            {
                std::cout << "Error: Stack is empty!!" << std::endl;
            }
        }
        else if (infixExpr[i] == '+' || infixExpr[i] == '-' ||
            infixExpr[i] == '*' || infixExpr[i] == '/')
        {
            if (!operators.isEmpty())
            {
                handlePrecedence(operators, operands, infixExpr[i]);
            }
            else
            {
                operators.push(infixExpr[i]);
            }
        }
        else if(infixExpr[i] != ' ')
        {
            Node<T>* tmp = new Node<T>(infixExpr[i]);
            operands.push(tmp);
        }
    }

    if (!operators.isEmpty() && operators.peek() != ')' && operators.peek() != '(')
    {
        Node<T>* opand1 = nullptr;
        Node<T>* opand2 = nullptr;
        char op;

        opand1 = operands.pop();
        opand2 = operands.pop();
        op = operators.pop();

        Node<T>* tmp = new Node<T>(opand2, opand1, op);
        operands.push(tmp);
    }

    return operands.pop();
}

template <typename T>
void BT<T>::createExprTree(std::string expr)
{
    root_ = infixTree(expr);
}

template <typename T>
void BT<T>::inOrderTraversal(Node<T>* node)
{
    if (node != nullptr)
    {
        inOrderTraversal(node->left_);
        std::cout << node->data_ << " ";
        inOrderTraversal(node->right_);
    }
}

template <typename T>
void BT<T>::printTree()
{
    if (!isEmpty())
    {
        inOrderTraversal(root_);
    }
}

template <typename T>
void BT<T>::postOrderTraversal(Node<T>* node, std::string& str)
{
    if (node != nullptr)
    {
        postOrderTraversal(node->left_, str);
        postOrderTraversal(node->right_, str);
        str = str + node->data_;
    }
}

template <typename T>
void BT<T>::postfix(std::string& str)
{
    if (!isEmpty())
    {
        postOrderTraversal(root_, str);
    }
}


template <typename T>
void BT<T>::destroyTree(Node<T>* node)
{
    if (node != nullptr)
    {
        destroyTree(node->left_);
        destroyTree(node->right_);
        delete node;
    }
}

template <typename T>
BT<T>::~BT()
{
    if (root_ != nullptr)
    {
        destroyTree(root_);
    }
}

#endif // !_BT_H_