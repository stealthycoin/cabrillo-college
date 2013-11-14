#include "Stack.h"
#include <iostream>
int main() {
	
	Stack s;
	
	double d;
	while (std::cin >> d) {
		s.push(d);
	}
	
	while (!s.isempty()) {
		std::cout << s.pop() << std::endl;
	}
}