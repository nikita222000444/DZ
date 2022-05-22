#pragma once
struct BigNum
{
	short* arr;
	int length;
};
struct Date
{
	short day;
	short month;
	short year;
};
struct BigNum* SumOfBigNum(struct BigNum* x_, struct BigNum* y_);

int Thirteenth();

int Collatz(int num_);

int Fourteenth(int num_);

unsigned long long int Fifteenth();



int BigNumConstruct(struct BigNum* out_, char* in_);


int Second(int num_);

int Prime(long long num_);

long long Third(long long num_);

int Pol(int num_);

int Fourth();

long long Fifth(int num_);

long long Sixth(int num_);

int Seventh(int num_);

int Eighth(int num_);

int Triple(int num1_, int num2_, int num3_);

int Nineth(int num_);

int Tenth(int num_);

int Eleventh();

int Triangle(int num_);

int Dividers(int num_);

int Twelfth(int num_);
