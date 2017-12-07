This program implements an algorithm to convert an input infix expression to a postfix expression as shown in the examples below. 
As shown below, the program requires the inputted infix expression to be enclosed by single quotes. 
In addition, the program evaluates the postfix expression and prints the resulting value. A Makefile has been provided for compilation. 

Example input/output:

./lab08.out ’6 + 4 * 2.5’

Postfix Expression: 6 4 2.5 * +
Postfix Evaluation: 16

./lab08.out ’( 6 + 4 ) * 2.5’

Postfix Expression: 6 4 + 2.5 *
Postfix Evaluation: 25

./lab08.out ’( ( 6 + 4 ) * 2.5 )’

Postfix Expression: 6 4 + 2.5 *
Postfix Evaluation: 25

./lab08.out ’( 19.5 - 8 ) * 2 / 10 + 6’

Postfix Expression: 19.5 8 - 2 * 10 / 6 +
Postfix Evaluation: 8.3

./lab08.out ’5.75 * ( ( 23.9 - 8.9 ) + 2 ) * 9 / 7.5’

Postfix Expression: 5.75 23.9 8.9 - 2 + * 9 * 7.5 /
Postfix Evaluation: 117.3

./lab08.out ’( 6 + 7.5 ) * ( ( 2 - 1.5 ) + 2.5 * 4 )’

Postfix Expression: 6 7.5 + 2 1.5 - 2.5 4 * + *
Postfix Evaluation: 141.75

