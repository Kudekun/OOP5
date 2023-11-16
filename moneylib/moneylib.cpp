#include "pch.h"
#include "framework.h"
#include "Money.h"


namespace ATM {
    void Money::normalize()
    {
        if (kopeck > 100) {
            int count = static_cast<int>(kopeck) / 100;
            kopeck %= 100;
            UAH += count;
        }
    }

    Money Money::operator+(Money x)
    {
        Money temp;
        temp.UAH = this->UAH + x.UAH;
        temp.kopeck = this->kopeck + x.kopeck;
        temp.normalize();
        return temp;
    }

    Money Money::operator-(Money x)
    {
        Money temp;
        temp.UAH = this->UAH - x.UAH;
        if (this->kopeck < x.kopeck) {
            temp.UAH--;
            temp.kopeck = this->kopeck + 100 - x.kopeck;
        }
        else {
            temp.kopeck = this->kopeck - x.kopeck;
        }
        return temp;
    }

    Money Money::operator/(double x)
    {
        if (x > 0) {
            Money temp;
            temp.UAH = this->UAH / x;
            temp.kopeck = this->kopeck / x;
            temp.normalize();
            return temp;
        }
        else {
            return *this;
        }
    }

    Money Money::operator*(double x)
    {
        if (x >= 0) {
            Money temp;
            temp.UAH = this->UAH * x;
            temp.kopeck = this->kopeck * x;
            temp.normalize();
            return temp;
        }
        else {
            return *this;
        }
    }



    Money::Money()
    {
        UAH = 0;
        kopeck = 0;
        normalize();
    }

    Money::Money(unsigned long Uah, unsigned char kop)
    {
        UAH = Uah;
        kopeck = kop;
        normalize();
    }

    Money::Money(unsigned long Uah)
    {
        UAH = Uah;
        kopeck = 0;
        normalize();
    }

    void Money::init(long U, unsigned char k)
    {
        UAH = U;
        kopeck = k;
        normalize();
    }

    void Money::read()
    {
        std::cout << "Введіть кількість гривень: " << std::endl;
        std::cin >> UAH;
        std::cout << "Введіть кількість копійок: " << std::endl;
        std::cin >> kopeck;
        normalize();
    }

    void Money::display()
    {
        std::cout << "Гривні: " << UAH << "\t" << "Копійки: " << static_cast<int>(kopeck) << std::endl;
    }

    std::string Money::toString()
    {
        return std::to_string(UAH) + ',' + std::to_string(static_cast<int>(kopeck));
    }

    Money Money::add(Money x)
    {
        Money temp;
        temp.UAH = this->UAH + x.UAH;
        temp.kopeck = this->kopeck + x.kopeck;
        temp.normalize();
        return temp;
    }

    Money Money::sub(Money x)
    {
        Money temp;
        temp.UAH = this->UAH - x.UAH;
        if (this->kopeck < x.kopeck) {
            temp.UAH--;
            temp.kopeck = this->kopeck + 100 - x.kopeck;
        }
        else {
            temp.kopeck = this->kopeck - x.kopeck;
        }
        return temp;
    }


    Money Money::div(double x)
    {
        if (x > 0) {
            Money temp;
            temp.UAH = this->UAH / x;
            temp.kopeck = this->kopeck / x;
            temp.normalize();
            return temp;
        }
        else {
            return *this;
        }
    }

    Money Money::mul(double x)
    {
        if (x >= 0) {
            Money temp;
            temp.UAH = this->UAH * x;
            temp.kopeck = this->kopeck * x;
            temp.normalize();
            return temp;
        }
        else {
            return *this;
        }
    }

    void Money::cmp(Money x)
    {
        if (this->UAH == x.UAH && this->kopeck == x.kopeck)
            std::cout << "Значення рівні" << std::endl;
        else if (this->UAH == x.UAH) {
            if (this->kopeck > x.kopeck)
                std::cout << "Перше значення більше" << std::endl;
            else
                std::cout << "Друге значення більше" << std::endl;
        }
        else if (this->UAH > x.UAH)
            std::cout << "Перше значення більше" << std::endl;
        else
            std::cout << "Друге значення більше" << std::endl;
    }

}
