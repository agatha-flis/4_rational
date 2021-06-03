#include <iostream>
#include "rational.h"

// wyświetlanie ułamków



Rational Rational::normalize(const Rational& other) // skrocenie ulamka do najprostszej postaci
{	
	int a = other.numer;
	int b = other.denom;
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
	Rational v(other.numer / a, other.denom / a);

	if (v.numer > 0 && v.denom < 0) 
	{
		v.numer *= -1;
		v.denom *= -1;
	}
	else if (v.numer < 0 && v.denom < 0)
	{
		v.numer *= -1;
		v.denom *= -1;
	} 
	return v;
}

Rational Rational::normalized(int numerator, int denominator) // wyswietlenie ulamka w najprostszej postaci
{
	int a =numerator;
	int b = denominator;
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return Rational(numerator / a, denominator / a);
}


std::ostream& operator<<(std::ostream& os, const Rational& other) // wyświetlanie ułamka w postaci wymiernej
{
	try {
		if(other.denom==0)
			throw other.denom;
		else 
			os <<other.numer << "/" << other.denom;
		}
		catch(int denom) { cout << "wrong denominator value - unable to show object\n"; };
	
	return os;
}

std::istream& operator>>(std::istream& is, const Rational& other) // przyjęcie do programu ułamka w postaci wymiernej
{

	cout<<"numerator = ";
	is >> other.numer;
	cout<<"denominator = ";
	is >> other.denom;

	return is;
}


// proste operacje na samych ułamkach

Rational Rational::operator+(const Rational& other) const // dodawanie ułamka zwykłego do pierwotnego num/denom 
{
	int r1=numer * other.denom + other.numer * denom;
	int r2=denom * other.denom;
	
	Rational v (r1,r2);
	return normalize(v);
}

Rational Rational::operator-(const Rational& other) const // odejmowanie ułamka zwykłego do pierwotnego num/denom 
{
	int r1=numer * other.denom - other.numer * denom;
	int r2=denom * other.denom;
	
	Rational v(r1,r2);
	return normalize(v);
	
}

Rational Rational::operator*(const Rational& other) const // mnożenie ułamka zwykłego do pierwotnego num/denom 
{
	int r1=numer * other.numer;
	int r2=denom * other.denom;
	
	Rational v(r1,r2);
	return normalize(v);
}

Rational Rational::operator/(const Rational& other) const // dzielenie ułamka zwykłego do pierwotnego num/denom 
{
	int r1=numer * other.denom;
	int r2=denom * other.numer;
	
	Rational v(r1,r2);
	return normalize(v);

}

// ???

/*Rational Rational::operator+() const
{
	return 0;
}

Rational Rational::operator-() const
{
	
	return 0;
	
} */

// porównywanie ułamków

bool Rational::operator==(const Rational& other) const // wyswietlenie: porownywanie ulamkow
{
	//Rational v1{ numer * other.denom, denom * other.denom };
	//Rational v2{ other.numer * denom, denom * other.denom };
	if (numer * other.denom == other.numer * denom)
		return true;
	else 
		return false;
}

bool Rational::operator>=(const Rational& other) const // wyswietlenie: porownywanie ulamkow
{
	//Rational v1{ numer * other.denom, denom * other.denom };
	//Rational v2{ other.numer * denom, denom * other.denom };
	if (numer * other.denom >= other.numer * denom)
		return true;
	else 
		return false;
}

bool Rational::operator<=(const Rational& other) const // wyswietlenie: porownywanie ulamkow
{
	//Rational v1{ numer * other.denom, denom * other.denom };
	//Rational v2{ other.numer * denom, denom * other.denom };
	if (numer * other.denom <= other.numer * denom)
		return true;
	else 
		return false;
}

bool Rational::operator>(const Rational& other) const // wyswietlenie: porownywanie ulamkow
{
	//Rational v1{ numer * other.denom, denom * other.denom };
	//Rational v2{ other.numer * denom, denom * other.denom };
	if (numer * other.denom > other.numer * denom)
		return true;
	else 
		return false;
}

bool Rational::operator<(const Rational& other) const // wyswietlenie: porownywanie ulamkow*/
{
	//Rational v1{ numer * other.denom, denom * other.denom };
	//Rational v2{ other.numer * denom, denom * other.denom };
	if (numer * other.denom < other.numer * denom)
		return true;
	else 
		return false;
}

// operacje ułamek-liczba całkowita

Rational operator+(const Rational& r, int i) // dodawanie ułamka i liczby całkowitej
{
	Rational v{ r.numerator() * 1 + i * r.denominator(), r.denominator() * 1 };
	Rational::normalize(v);
	return v;
}

Rational operator-(const Rational& r, int i) // odejmowanie ułamka i liczby całkowitej
{
	Rational v{ r.numerator() * 1 - i * r.denominator(), r.denominator() * 1 };
	Rational::normalize(v);
	return v;
}

Rational operator*(const Rational& r, int i) // mnożenie ułamka i liczby całkowitej
{
	Rational v(r.numerator() * i, r.denominator() * 1);
	Rational::normalize(v);
	return v;
}

Rational operator/(const Rational& r, int i) // dzielenie ułamka i liczby całkowitej
{
	Rational v(r.numerator() * 1, r.denominator() * i);
	Rational::normalize(v);
	return v;
}



Rational operator+(int i, const Rational& r) // dodawanie liczby całkowitej i ułamka
{
	Rational v{ r.numerator() * 1 + i * r.denominator(), r.denominator() * 1 };
	Rational::normalize(v);
	return v;
}

Rational operator-(int i, const Rational& r) // odejmowanie liczby całkowitej i ułamka
{
	Rational v{ i * r.denominator() - r.numerator() * 1, r.denominator() * 1 };
	Rational::normalize(v);
	return v;
}

Rational operator*(int i, const Rational& r) // mnożenie liczby całkowitej i ułamka
{
	Rational v(i * r.numerator(), 1 * r.denominator());
	Rational::normalize(v);
	return v;
}

Rational operator/(int i, const Rational& r) // dzielenie liczby całkowitej i ułamka
{
	Rational v(i * r.denominator(), 1 * r.numerator());
	Rational::normalize(v);
	return v;
}