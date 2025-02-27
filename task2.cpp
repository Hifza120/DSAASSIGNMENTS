#include"myStack.h"
#include<cstring>
bool isLetter(char	num) {
	if (num >= '0' && num <= '9') {
		return true;
	}
	else if (num >= 'a' && num <= 'z') {
		return true;
	}
	else if (num >= 'A' && num <= 'Z') {
		return true;
	}
	return false;
}
//BODMAS
int precedence(char op) {
	if (op == '+' || op == '-') {
		return 1;  // Lowest precedence
	}
	else if (op == '*' || op == '/') {
		return 2;  // Higher precedence
	}
	return 0;  
}

char* infixtopostfix(const char infixexpression[]) {
	myStack<char> S(20);
	char* postfixexpression = new char[2 * strlen(infixexpression)]; 
	int lastindex = 0;
	int index = 0;
	for (int i = 0; i < strlen(infixexpression); i++) {
		char ch = infixexpression[i];
		if (isLetter(ch)) {
			postfixexpression[index++] = ch;
		}
		else if (ch == '(' || ch == '{' || ch == '[') {
			S.push(ch);
			postfixexpression[index++] = ' ';
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			postfixexpression[index++] = ' ';
			while (!S.isEmpty() && precedence(S.top()) >= precedence(ch)) {
				postfixexpression[index++] = S.pop();
			}
			S.push(ch);
		}
		else if (ch == ')' || ch == '}' || ch == ']') {
			postfixexpression[index++] = ' ';
			char topchar = '0';
			if (!S.isEmpty()) {
				topchar = S.top();
			}
			while (!S.isEmpty() && (topchar != '(' && topchar != '[' && topchar != '{')) {
				postfixexpression[index++] = S.pop();
				topchar = S.top();

			}
			if (!S.isEmpty()) {
				char val = S.pop();
			}

		}

	}
	postfixexpression[index] = '\0';
	return postfixexpression;
}

int main() {
	char expression[100];
	cin.getline(expression, 100);
	char* postfixexpression = infixtopostfix(expression);
	cout << postfixexpression << endl;
	delete[] postfixexpression;
	postfixexpression = nullptr;
	return 0;
}