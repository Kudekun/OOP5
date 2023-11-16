#pragma once
#include<iostream>
#include <string>

namespace ATM {
	class Money {
	private:
		unsigned long UAH;
		unsigned char kopeck;
		void normalize();

	public:
		Money operator+(Money x);
		Money operator-(Money x);
		Money operator/(double x);
		Money operator*(double x);

		Money();
		Money(unsigned long Uah, unsigned char kop);
		Money(unsigned long Uah);

		void init(long UAH, unsigned char kopeck);
		void read();
		void display();
		std::string toString();
		Money add(Money x);
		Money sub(Money x);
		Money div(double x);
		Money mul(double x);
		void cmp(Money x);
	};
}
