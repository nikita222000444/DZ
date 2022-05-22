#include<stdio.h>
#include<stdlib.h>
#include"functions.h"
#include<math.h>
#include<string.h>

int First(int num_)
{
	int count = 0;
	for (int i = 3; i < num_; i++)
	{
		if ((i % 3) == 0 || (i % 5) == 0)
			count += i;
	}

	return  count;
}

int Second(int num_)
{
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	int count = 6;
	while (1)
	{
		n1 = n2 + n3;
		if (n1 < num_)
			count += n1;
		else
			break;

		n2 = n1 + n3;
		if (n2 < num_)
			count += n2;
		else
			break;

		n3 = n1 + n2;
		if (n3 < num_)
			count += n3;
		else
			break;
	}
	
	return count;
}

int Prime(long long num_)
{

	if (num_ < 2)
		return 0;

	if (num_ == 2)
		return 1;

	if (num_ % 2 == 0)
		return 0;

	long long sqr = (long long)sqrt(num_) + 1;

	for (long long i = 3; i <= sqr; i += 2)
	{
		if (num_ % i == 0)
			return 0;
	}

	return 1;
}

long long Third(long long num_)
{
	long long tempsqrt = (long long) sqrt(num_) + 1;

	long long max = 0;

	long long temp = 0;
	for (long long i = 2; i < tempsqrt; i++)
		if (num_ % i == 0)
		{
			temp = num_ / i;
			if (Prime(temp))
				max = temp;
			else
				if (Prime(i))
					max = i;
		}

	return max;
}

int Pol(int num_)
{
	int num1 = 0;
	int i = 0;
	
	for (int temp = num_; temp > 0; temp /= 10)
		i += 1;
	i--;

	int lastdigit;
	
	for (int temp = num_; temp > 0; temp /= 10, i--)
	{
		lastdigit = temp % 10;
		num1 += (int)lastdigit * pow(10, i);
	}

	if (num1 == num_)
		return 1;
	else
		return 0;
}

int Fourth()
{
	int temp;
	int max;

	for(int i = 100; i < 1000; i++)
		for (int j = 100; j < 1000; j++)
		{
			temp = i * j;
			if (Pol(temp))
				max = temp;
		}
	
	return max;
}

long long Fifth(int num_)
{
	int f;
	for (long long i = 1; 1; i++)
	{
		f = 1;
		for (int j = 1; j < num_; j++)
			if (i % j != 0)
			{
				f = 0;
				break;
			}

		if (f == 1)
			return i;
	}
}

long long Sixth(int num_)
{
	long long count = 0;
	for (int i = 1; i <= num_; i++)
		count += i;

	long long SqrOfSum = (long long) pow(count, 2);

	count = 0;
	for (int i = 1; i <= num_; i++)
		count += (long long)pow(i, 2);
	
	long long SumOfSqr = count;

	if (SqrOfSum > SumOfSqr)
		return SqrOfSum - SumOfSqr;
	else
		return SumOfSqr - SqrOfSum;
}

int Seventh(int num_)
{
	int count = 1;
	
	for (int i = 3; 1; i++)
	{
		if (Prime(i))
			count++;

		if (count == num_)
			return i;
	}
}

int Eighth(int num_)
{
	char Num[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

	int mult = 1;
	int maxmult = 0;
	int borderI = 1002 - num_;
	int borderJ;

	for (int i = 0; i < borderI; i++)
	{
		mult = 1;
		borderJ = i + num_;
		
		for (int j = i; j < borderJ; j++)
		{
			mult *= Num[j] - 48;
			
		}
		
		if (mult > maxmult)
			maxmult = mult;
	}
	return maxmult;
}

int Triple(int num1_, int num2_, int num3_)
{
	int Sqrnum1 = (int)pow(num1_, 2);
	int Sqrnum2 = (int)pow(num2_, 2);
	int Sqrnum3 = (int)pow(num3_, 2);
	
	if (Sqrnum1 + Sqrnum2 == Sqrnum3 || Sqrnum2 + Sqrnum3 == Sqrnum1 || Sqrnum1 + Sqrnum3 == Sqrnum2)
		return 1;
	else
		return 0;
}

int Nineth(int num_)
{
	for (int a = 1; a < num_/2; a++)
		for (int b = 1; b < num_/2; b++)
			for (int c = 1; c < num_/2; c++)
				if (Triple(a, b, c) && (a + b + c) == num_)
					return a * b * c;
	return 0;
}

int Tenth(int num_)
{
	int sum = 0;
	for (int i = 0; i < num_; i++)
		if (Prime(i))
			sum += i;
	return sum;
}

int Eleventh()
{
	FILE* f;
	fopen_s(&f, "11.txt", "r");
	if (!f)
		return 0;

	int arr[20][20] = { 0 };

	char str[64] = "";
	int j;
	int x;
	int i;
	for (i = 0; fgets(str, 64, f); i++)
	{
		j = 0;
		for (x = 0; str[x]; x+=3, j++)
			arr[i][j] = (str[x] - 48) * 10 + (str[x + 1] - 48);
	}
	
	int mult = 0;
	int multtemp;
	for(i = 3; i < 17; i++)
		for (j = 3; j < 17; j++)
		{
			multtemp = arr[i][j] * arr[i][j - 1] * arr[i][j - 2] * arr[i][j - 3];
			if (multtemp > mult)
				mult = multtemp;

			multtemp = arr[i][j] * arr[i][j + 1] * arr[i][j + 2] * arr[i][j + 3];
			if (multtemp > mult)
				mult = multtemp;

			multtemp = arr[i][j] * arr[i - 1][j] * arr[i - 2][j] * arr[i - 3][j];
			if (multtemp > mult)
				mult = multtemp;

			multtemp = arr[i][j] * arr[i + 1][j] * arr[i + 2][j] * arr[i + 3][j];
			if (multtemp > mult)
				mult = multtemp;

			multtemp = arr[i][j] * arr[i - 1][j - 1] * arr[i - 2][j - 2] * arr[i - 3][j - 3];
			if (multtemp > mult)
				mult = multtemp;

			multtemp = arr[i][j] * arr[i + 1][j + 1] * arr[i + 2][j + 2] * arr[i + 3][j + 3];
			if (multtemp > mult)
				mult = multtemp;

			multtemp = arr[i][j] * arr[i - 1][j + 1] * arr[i - 2][j + 2] * arr[i - 3][j + 3];
			if (multtemp > mult)
				mult = multtemp;

			multtemp = arr[i][j] * arr[i + 1][j - 1] * arr[i + 2][j - 2] * arr[i + 3][j - 3];
			if (multtemp > mult)
				mult = multtemp;
		}

	return mult;
}

int Triangle(int num_)
{
	int triangle = 0;
	for (int i = 1; triangle <= num_; i++)
	{
		if (triangle == num_)
			return 1;
		triangle += i;
	}
	return 0;
}

int Dividers(int num_)
{
	int count = 0;
	int tempsqrt = (int)sqrt(num_) + 1;
	for (int i = 1; i < tempsqrt; i++)
	{
		if (i * i == num_)
			count++;
		else 
			if (num_ % i == 0)
				count += 2;
	}
	return count;
}

int Twelfth(int num_)
{
	for (int i = 1; 1; i++)
	{
		if (Triangle(i) && (Dividers(i) > num_))
			return i;
	}
}

int BigNumConstruct(struct BigNum* out_, char* in_)
{
	int length = strlen(in_);
	
	out_->arr = malloc(sizeof(short) * length);
	if (!out_->arr)
		return 0;

	out_->length = length;
	
	for (int i = 0; i < out_->length; i++)
		out_->arr[i] = in_[i] - 48;
	return 0;
}

struct BigNum* SumOfBigNum(struct BigNum* x_, struct BigNum* y_)
{
	int length, i, j;
	int f = 1;
	
	if (x_->length >= y_->length)
		length = x_->length;

	if (x_->length < y_->length)
		length = y_->length;

	struct BigNum* res = malloc(sizeof(struct BigNum));
	if (!res)
		return 0;

	res->length = length;
	res->arr = malloc(sizeof(short) * res->length);
	if (!res->arr)
		return 0;

	int w;
	for(w = res->length - 1;w >= 0; w--)
		res->arr[w] = 0;

	int temp;
	w = res->length - 1;
	j = y_->length - 1;
	i = x_->length - 1;
	
	for (; i >= 0 && j >= 0 && w >= 0; i--, j--, w--)
	{
		temp = x_->arr[i] + y_->arr[j];
		res->arr[w] += temp;
		if (res->arr[w] >= 10 && w != 0)
		{
			res->arr[w] = temp % 10;
			res->arr[w - 1] += temp / 10;
		}
		if (temp >= 10 && w == 0)
		{
			f = 0;
			break;
		}
	}

	if (f)
	{
		if (x_->length >= y_->length)
			for (; w >= 0 && i >= 0; w--, i--)
				res->arr[w] += x_->arr[i];

		if (x_->length < y_->length)
			for (; w >= 0 && j >= 0; w--, j--)
				res->arr[w] += y_->arr[j];
		return res;
	}
	if (!f)
	{
		free(res);
		struct BigNum* res = malloc(sizeof(struct BigNum));
		if (!res)
			return 0;

		res->length = length + 1;

		res->arr = malloc(sizeof(short) * res->length);
		if (!res->arr)
			return 0;

		int w;
		for (w = res->length - 1; w >= 0; w--)
			res->arr[w] = 0;

		w = res->length - 1;
		j = y_->length - 1;
		i = x_->length - 1;

		for (; i >= 0 && j >= 0; i--, j--, w--)
		{
			temp = x_->arr[i] + y_->arr[j];
			res->arr[w] += temp;

			if (res->arr[w] >= 10)
			{
				temp = res->arr[w];
				res->arr[w] = temp % 10;
				res->arr[w - 1] += temp / 10;
			}
		}
		if (x_->length >= y_->length)
			for (; w >= 0 && i >= 0; w--, i--)
				res->arr[w] += x_->arr[i];

		if (x_->length < y_->length)
			for (; w >= 0 && j >= 0; w--, j--)
				res->arr[w] += y_->arr[j];
		return res;
	}
}
int Thirteenth()
{
	FILE* f;
	fopen_s(&f, "13.txt", "r");
	if (!f)
		return 0;

	struct BigNum** Nums = malloc(sizeof(struct BigNum) * 128);
	if (!Nums)
		return 0;
	for (int i = 0; i < 100; i++)
	{
		Nums[i] = malloc(sizeof(struct BigNum));
		if (!Nums[i])
			return 0;
	}
	
	char str[64] = "";
	int i;
	struct BigNum* Sum = malloc(sizeof(struct BigNum));
	if (!Sum)
		return 0;
	Sum->length = 50;

	Sum->arr = malloc(sizeof(short) * Sum->length);
	if (!Sum->arr)
		return 0;

	for (i = Sum->length; i >= 0; i--)
		Sum->arr[i] = 0;

	for (i = 0; fgets(str, 64, f); i++)
	{
		str[50] = '\0';
		BigNumConstruct(Nums[i], str);
		Sum = SumOfBigNum(Sum, Nums[i]);
		
	}

	for (int i = 0; i < 10; i++)
		printf("%d", Sum->arr[i]);

}


int Collatz(int num_)
{
	int n = num_;
	int count = 1;
	while(n != 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = 3 * n + 1;
		count++;
	}
	return count;
}

int Fourteenth(int num_)
{
	int MainNum = 0;
	int MaxCount = 0;
	for (int i = 0; i < num_; i++)
	{
		if (Collatz(i) > MaxCount)
		{
			MainNum = i;
			MaxCount = Collatz(i);
		}
	}
	return MainNum;
}



unsigned long long int Fifteenth()
{
	unsigned long long int arr[21][21] = { 0 };
	for (int i = 0; i < 21; i++)
		arr[i][0] = 1;

	for (int i = 0; i < 21; i++)
		arr[0][i] = 1;

	for (int i = 1; i < 21; i++)
		for (int j = 1; j < 21; j++)
		{
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
			printf("%d|%d -- %llu\n",i ,j, arr[i][j]);
		}

	return arr[20][20];
}

int Brackets(char* str_)
{
	int i = 0;
	int j = 0;

	for (; str_[i]; i++)
		if (str_[i] == '(')
			for (j = i; str_[j]; j++)
				if (str_[j] == ')')
				{
					str_[j] = ' ';
					str_[i] = ' ';
					break;
				}

	for (i = 0; str_[i]; i++)
	{
		if (str_[i] == '(')
			return -1;
		if (str_[i] == ')')
			return i;
	}
	return 0;
}

int DatesToStruct(FILE* f, struct Date* dates_)
{
	char str[16] = "";
	int i = 0;
	int n = 0;
	for (; fgets(str, 16, f); i++)
	{
		n++;
		dates_[i].day = 10 * (str[0] - 48) + (str[1] - 48);
		dates_[i].month = 10 * (str[3] - 48) + (str[4] - 48);
		dates_[i].year = 1000 * (str[6] - 48) + 100 * (str[7] - 48) + 10 * (str[8] - 48) + (str[9] - 48);
	}
	return n;
}

int CompDates(struct Date date1_, struct Date date2_)
{
	if (date1_.year > date2_.year)
		return 1;

	if (date1_.year < date2_.year)
		return -1;

	if (date1_.year == date2_.year)
	{
		if (date1_.month > date2_.month)
			return 1;

		if (date1_.month < date2_.month)
			return -1;

		if (date1_.month == date2_.month)
		{
			if (date1_.day > date2_.day)
				return 1;

			if (date1_.day < date2_.day)
				return -1;

			if (date1_.day == date2_.day)
				return 0;
		}
	}
}

void DatesSort(struct Date* dates_, int count_)
{
	struct Date temp;
	for (int i = 0; i < count_ - 1; i++)
		for (int j = count_ - 1; j > i; j--)
			if (CompDates(dates_[j - 1], dates_[j]) == -1)
			{
				temp = dates_[j];
				dates_[j] = dates_[j - 1];
				dates_[j - 1] = temp;
			}
}

void DatesFunc(FILE* f)
{
	FILE* g;

	fopen_s(&g, "DatesOut.txt", "w");
	if (!g)
		return 0;

	struct Date* dates = malloc(sizeof(struct Date) * 1024);
	if (!dates)
		return 0;

	int n = DatesToStruct(f, dates);

	DatesSort(dates, n);

	for (int i = 0; i < n; i++)
		fprintf(g, "%.2d/%.2d/%.4d\n", dates[i].day, dates[i].month, dates[i].year);
}