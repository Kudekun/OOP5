#include<iostream>
#include<Windows.h>
#include"Money.h"

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	ATM::Money a{ 15 }, b{ 8, 130 }, add, sub, div, mul;

	a.display();
	b.display();

	add = a + b;
	sub = a - b;
	div = a / 2;
	mul = a * 2;


	std::cout << "add: ";
	add.display();
	std::cout << "sub: ";
	sub.display();
	std::cout << "div: ";
	div.display();
	std::cout << "mul: ";
	mul.display();

	return 0;
}
