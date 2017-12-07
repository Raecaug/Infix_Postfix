/*
 * Parth Patel
 */

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

bool isOp(string op);//Tests for operators//
int prec(string op);//Returns int corresponding to operator precedence//

int main(int argc, char *argv[])
{
  string token, token2;
  string infix = argv[1];//Infix expression//
  stringstream ss(infix);//ss can be split using getline for tokens//

  stack<string> operators;
  string postfix, top;

  while(getline(ss, token, ' '))//Splits infix into individual tokens//
  {                             //Now building postfix expression
    if(isOp(token))//If token is an operator, push to stack//
    {
      if(token == "(")//Push left parenthesis onto stack//
      {
        operators.push(token);
      }
      else if(token == ")")//Pop and append until '('
      {
        top = operators.top(); operators.pop();
        while(top != "(")
        {
          postfix.append(top); postfix.append(" ");
          top = operators.top(); operators.pop();
        }
      }
      else//If operator is +, -, *, or / //
      {
          while(!operators.empty() &&
                prec(operators.top()) >= prec(token))
          {
            postfix.append(operators.top()); postfix.append(" ");
            operators.pop();
          }
          operators.push(token);
      }
    }
    else//If token is an operand, append to postfix//
    {
      postfix.append(token);
      postfix.append(" ");
    }
  }
  //Reached end of infix, now pop and append until stack is empty//
  while(!operators.empty())
  {
    postfix.append(operators.top()); postfix.append(" ");
    operators.pop();
  }

  cout << "Postfix Expression: " << postfix << endl;
  //Infix has been fully converted, stored and printed. Now evaluating//

  stringstream pf(postfix);//Use getline to split into chars//
  stack<double> save;
  double temp, op1, op2;

  while(getline(pf, token2, ' '))//Cycles while there are operators and operands//
  {
    if(!isOp(token2))//If not an operator, push onto stack//
    {
      temp = stod(token2);
      save.push(temp);
    }
    else if(isOp(token2))//If the token2 is an operator//
    {
      if(token2 == "+")//Add top 2 from stack and push//
      {
        op1 = save.top(); save.pop();
        op2 = save.top(); save.pop();
        temp = op1 + op2;
        save.push(temp);
      }
      if(token2 == "-")//Subtract top 2 from stack and push//
      {
        op1 = save.top(); save.pop();
        op2 = save.top(); save.pop();
        temp = op2 - op1;
        save.push(temp);
      }
      if(token2 == "*")//Multiply top 2 from stack and push//
      {
        op1 = save.top(); save.pop();
        op2 = save.top(); save.pop();
        temp = op1 * op2;
        save.push(temp);
      }
      if(token2 == "/")//Divide top 2 from stack and push//
      {
        op1 = save.top(); save.pop();
        op2 = save.top(); save.pop();
        temp = op2 / op1;
        save.push(temp);
      }
    }
  }
  //All operands have been evaluated, stack contains answer now//
  //Printing evaluation of postfix//
  cout << "Postfix Evaluation: " << save.top() << endl;

  return 0;
}

bool isOp(string op)//Tests for operator//
{
  if(op == "(" ||
          op == ")" ||
          op == "+" ||
          op == "-" ||
          op == "*" ||
          op == "/")
          return true;
  else
          return false;
}

int prec(string op)//Returns int corresponding to operator precedence//
{
  if(op == "*" || op == "/"){return 3;}

  else if(op == "+" || op == "-"){return 2;}

  else if(op == "("){return 1;}
  return 0;
}
