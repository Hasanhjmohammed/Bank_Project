#pragma once
#include <iostream>
#include<string>
#include<math.h>
#include<random>
using namespace std;
class clsUtil
{
public:
	enum enCharType {
		smallletter = 1,
		capitallettre = 2,
		specialcarcter = 3,
		digit = 4,
		mix=5
	};
	static int SumOfNumbers(int n1, int n2) {
		return  n1 + n2;
	}
	static int SumOfNumbers(int n1, int n2, int n3) {

		return (SumOfNumbers(n1,n2) + n3);
	}

static	void Srand() {
	cout << GetRandomNumber(1,100);
	}
static int GetRandomNumber(int From, int To) {
	int rund = rand() % (To - From + 1) + From;
	return rund;
}


static void Swap (int& a, int& b) {

	int temp = a;
	a = b;
	b = temp;
}
static void Swap(string & a, string & b) {

	string temp = a;
	a = b;
	b = temp;
}
static void Swap(float  & a,float & b) {

	float temp = a;
	a = b;
	b = temp;
}
static int  PrintFactorial(int n) {

	int factorial = 1;
	for (int i = n; i >= 1; i--)
	{
		factorial *= i;
	}
	return factorial;
};
static string Encryption(string masseg, short Key) {
	string encryptinname = "";

	for (int i = 0; i < masseg.length(); i++) {

		// cout << encryptinname << endl;
		encryptinname = encryptinname + char((int)masseg[i] + Key);

	}
	//cout << encryptinname << endl;
	return encryptinname;
}

static  string Decryption(string masseg, short Key) {
	string decryptinname = "";

	for (int i = 0; i < masseg.length(); i++) {

		// cout << encryptinname << endl;
		decryptinname = decryptinname + char((int)masseg[i] - Key);

	}
	//cout << decryptinname << endl;
	return decryptinname;
}
static char GetRand(enCharType Letterrand) {
	switch (Letterrand)
	{
	case mix:
		return GetRand(enCharType(GetRandomNumber(1, 4)));

	case smallletter:
		return (char)GetRandomNumber(97, 122);

	case capitallettre:
		return (char)GetRandomNumber(65, 90);

	case specialcarcter:
		return (char)GetRandomNumber(33, 47);

	case digit:
		return (char)GetRandomNumber(48, 57);
	default:
		break;
	}


}
static string CreateWord(enCharType  Letterrand, short length) {
	string word = "";
	for (int i = 1; i <= length; i++) {
		word += GetRand(Letterrand);
	}
	return word;
}
static string CreateKey(int length,enCharType Type) {
	string key = "";
	key += CreateWord(Type, length) + "-";
	key += CreateWord(Type, length) + "-";
	key += CreateWord(Type, length) + "-";
	key += CreateWord(Type, length);
	return key;
}

static void CreateKeys(int Number) {

	for (int i = 1; i <= Number; i++) {
		cout << "Key [" << i << "] :" << CreateKey(4,enCharType::capitallettre) << endl;
	}
}

static void ShuffelAreayElement(int arry[100], int lenghtArry) {
	for (int i = 0; i < lenghtArry; i++) {
		Swap(arry[GetRandomNumber(1, lenghtArry) - 1], arry[GetRandomNumber(1, lenghtArry) - 1]);
	}
}

static void PrintOfArr(int Arr[100], int length) {
	for (int i = 0; i < length; i++)
	{
		cout << Arr[i] << endl;
	}
}
static void CreateManyKeysInArrayandPrint(string Array[100], int arrLenght)
{
	for (int i = 0; i < arrLenght; i++)
	{
		Array[i] = CreateKey(4,enCharType::smallletter);
	}

	for (int i = 0; i < arrLenght; i++) {
		cout << "Key [" << i + 1 << "] :" << Array[i];

		cout << endl;
	}
}

static string NumberTotext(long int Number) {

	if (Number == 0)
		return "";
	if (Number >= 1 && Number <= 19)
	{
		string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Neun",
			"Ten","Elfen","Twelf","Therteen","Fourteen","Fivteen","SixTeen","SevemTeen",
			"Eghitteen","Neunteen" };
		return arr[Number];
	}
	if (Number >= 20 && Number <= 99)
	{
		string arr[] = { "","","Twenty","Therty","Fourty","Fivty","Sixty","Sevnty","Eighty"
			,"Neunty" };
		return arr[Number / 10] + " " + NumberTotext(Number % 10);
	}
	if (Number >= 100 && Number <= 199)
	{

		return "One Hunders " + NumberTotext(Number % 100);
	}
	if (Number >= 200 && Number <= 999)
	{
		/*string arr[] = { "","","Twenty","Therty","Fourty","Fivty","Sixty","Sevnty","Eighty"
			,"Neunty" };*/
		return NumberTotext(Number / 100) + " Hunder " + NumberTotext(Number % 100);
	}
	if (Number >= 1000 && Number <= 1999)
	{

		return  "One Thauthend " + NumberTotext(Number % 1000);
	}
	if (Number >= 2000 && Number <= 999999)
	{

		return  NumberTotext(Number / 1000) + " Thauthends " + NumberTotext(Number % 1000);
	}
	if (Number >= 1000000 && Number <= 1999999)
	{

		return  "One  Millois " + NumberTotext(Number % 1000000);
	}
	if (Number >= 2000000 && Number <= 999999999)
	{

		return NumberTotext(Number / 1000000) + " Millois " + NumberTotext(Number % 1000000);
	}
	if (Number >= 1000000000 && Number <= 1999999999)
	{

		return  " One Billois " + NumberTotext(Number % 1000000000);
	}
	if (Number >= 2000000000 && Number <= 9999999999)
	{

		return NumberTotext(Number / 1000000000) + " Billois " + NumberTotext(Number % 1000000000);
	}

	return"";
}

};

