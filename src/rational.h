#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <cmath>
#include <exception>
using namespace std;

class MyException : public std::exception {
	public:
	const char* what() const noexcept { return "MyException";}
};

class Rational
{
public:
	Rational(int numerator=0, int denominator=1)  {
		
		
		try {
		
			if(denominator==0)
				throw MyException{};
			else 
				numer=numerator ;
				denom=denominator;
		}
		catch(int denominator) { cout << "wrong denominator value - unable to create object\n"; };
	

	} // konstruktor obiektu:ułamka
	~Rational() {}	// destruktor obiektu:ułamka
	Rational(const Rational& copy) : numer{ copy.numer }, denom{ copy.denom }{};	// konstruktor kopiujący ułamka
	Rational& operator=(const Rational& copy) // przypisanie ułamka 2 do ułamka 1
	{
		numer = copy.numer;
		denom = copy.denom;
		return *this;
	}
	Rational& operator=(int i) // pokazywanie liczby całkowitej jako ułamek
	{
		numer = i;
		denom = 1;
		
		return *this;
	}

	int numerator() const { return numer; }; // odwolanie sie do zmiennej prywatnej
	int denominator() const { return denom; } // odwolanie sie do zmiennej prywatnej

	//int gcd(int a, int b);

	static Rational normalize(const Rational& other); // skrocenie ulamka do najprostszej postaci
	static Rational normalized(int numerator, int denominator); // wyswietlenie ulamka w najprostszej postaci

	Rational operator+(const Rational& other) const; // dodawanie ułamka zwykłego do pierwotnego num/denom 
	Rational operator-(const Rational& other) const; // odejmowanie ułamka zwykłego do pierwotnego num/denom 
	Rational operator*(const Rational& other) const; // mnożenie ułamka zwykłego do pierwotnego num/denom 
	Rational operator/(const Rational& other) const; // dzielenie ułamka zwykłego do pierwotnego num/denom 

	Rational operator+() const;
	Rational operator-() const;

	bool operator==(const Rational& other) const;// wyswietlenie: porownywanie ulamkow
	bool operator>=(const Rational& other) const; // wyswietlenie: porownywanie ulamkow
	bool operator<=(const Rational& other) const; // wyswietlenie: porownywanie ulamkow
	bool operator>(const Rational& other) const; // wyswietlenie: porownywanie ulamkow
	bool operator<(const Rational& other) const; // wyswietlenie: porownywanie ulamkow*/

private:
	int numer; // wartosc licznika
	int denom;	// wartosc mianownika
	int gcd;	// greatest common divisor - NWD

	void initialize(int numerator, int denominator);

	friend std::ostream& operator<<(std::ostream& os, const Rational& other);
	friend std::istream& operator>>(std::istream& is, Rational& other);
	
};
	Rational operator+(const Rational& r, int i);
	Rational operator-(const Rational& r, int i);
	Rational operator*(const Rational& r, int i);
	Rational operator/(const Rational& r, int i);
	Rational operator+(int i, const Rational& r);
	Rational operator-(int i, const Rational& r);
	Rational operator*(int i, const Rational& r);
	Rational operator/(int i, const Rational& r);

#endif
