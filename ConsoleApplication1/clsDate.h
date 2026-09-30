#pragma once
#pragma warning (disable :4996)
#include<iostream>
#include<iomanip>
#include"clsString.h"
#include"Student.h"

class clsDate
{
private:

	short _day;
	short _month;
	short _year;
	

	static short FindIndexOfDay(clsDate Date) {
		short a = ((14 - Date._month) / 12);
		short y = Date._year - a;
		short m = Date._month + (12 * a) - 2;
		short d = (Date._day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
		return d;
	}
public:
	clsDate() {
		time_t t = time(0);
		tm* now = localtime(&t);
		this->_year = now->tm_year + 1900;
		this->_month = now->tm_mon + 1;
		this->_day = now->tm_mday;
		//cout << "\n" << this ->_day;
	}

	clsDate(string Date) {
		vector<string>vDate = clsString::Split(Date,"/");
		this->_day= stoi(vDate[0]);
		this->_month = stoi(vDate[1]);
		this->_year = stoi(vDate[2]);
	}
	clsDate(short day,short month,short year) {
		this->_day = day;
		this->_month = month;
		this->_year= year;
	}
	clsDate(int NumberOfDay,short year) {
		this->_month = 1;
		this->_year = year;
		while (NumberOfDay>CountDaysInYear(this->_year))
		{
			NumberOfDay -= CountDaysInYear(this->_year);
			this->_year++;
		}
		while (NumberOfDay > CountDayInMonth(year, this->_month))
		{
			NumberOfDay -= CountDayInMonth(year, this->_month);
			this->_month++;
		}
		this->_day = NumberOfDay;
	
	}
	short getDay() {
		return this->_day;
	}
	short getMonth() {
		return this->_month;
	}
	short getYear() {
		return this->_year;
	}
	 void Print() {
		cout << this->_day << "/" << this->_month << "/" << this->_year << endl;
	}

	static bool IsLeapYear(int year) {
		return (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
	}

	bool IsLeapYear() {
		return IsLeapYear(_year);
	}

static	short CountDaysInYear(int year) {
		return IsLeapYear(year) ? 366 : 365;

	}

 short CountDaysInYear() {
	return CountDaysInYear(_year);
}
 static short CountHoursInyear(int year) {

	return CountDaysInYear(year) * 24;
}

 short CountHoursInyear() {
	return CountHoursInyear(_year);
}

 static int CounterMintInYear(int year) {

	return CountHoursInyear(year) * 60;
}
int CounterMintInYear() {
	return  CounterMintInYear(_year);
}
static int CounterSecondInYear(int year) {

	return  CounterMintInYear(year) * 60;
}
int CounterSecondInYear() {
	return CounterSecondInYear(_year);
}
static short CountDayInMonth(int year, int Month) {

	if (Month < 1 || Month>12)
		return 0;
	if (Month < 1 || Month>12)
		return 0;
	short arrOfMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(year) ? 29 : 28) : arrOfMonth[Month - 1];
}
short CountDayInMonth(){
	return  CountDayInMonth(_year,_month);
}


static string FindDayByIndex(clsDate Date) {
	short IndexDay = FindIndexOfDay(Date);
	string Day[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	return Day[IndexDay];
}
string FindDayByIndex() {
	return FindDayByIndex(*this);
}
static string FindMonthByIndex(short IndexMonth) {
	string arr[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","oct","Nov","Dec" };
	return arr[IndexMonth - 1];
}
string FindMonthByIndex() {
	return FindMonthByIndex(this->_month);
}

static void PrintThemaOfMonth(short year, short Month) {
	cout << "------------------ " << FindMonthByIndex(Month) << "----------------------\n";
	cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n";
	short DayOfMonth = CountDayInMonth(year, Month);
	short index = FindIndexOfDay(clsDate(1, Month, year));

	while (index > 0)
	{
		// cout << index ;
		cout << left << setw(5) << " ";
		index--;
	}
	// cout << "end";

	for (int i = 1; i <= DayOfMonth; i++) {
		cout << left << setw(5) << i;
		if (FindDayByIndex(clsDate(i, Month, year) )== "Saturday")
			cout << endl;
	}
	cout << "\n------------------------------------------\n";
}

void PrintThemaOfMonth() {
	PrintThemaOfMonth(this->_year,this->_month);
}

 static void PrintAllMonthInYear(short year) {
	cout << "\n-----------------------------\n";
	cout << "\t Calender -" << year << "\n";
	cout << "---------------------------------\n";
	for (int i = 1; i <= 12; i++)
	{

		PrintThemaOfMonth(year, i);
	}
}

 void PrintAllMonthInYear() {
	 PrintAllMonthInYear(this->_year);
 }

 static short HowDayInYearFromBegingingtoNow(clsDate Date) {
	 short NumberOfDays = 0;

	 for (int i = 1; i < Date._month; i++)
	 {
		 NumberOfDays += CountDayInMonth(Date._year, i);
	 }
	 NumberOfDays += Date._day;
	 return NumberOfDays;
 }

 void HowDayInYearFromBegingingtoNow() {
	 HowDayInYearFromBegingingtoNow(*this);
 }
 static void PrintCompleteDateByNumberOfDay(short NumberOfDay, short year) {
	 clsDate Date= clsDate(NumberOfDay, year);
	 Date.Print();
 }

 static clsDate IncreessDaysToDate(short AddingDays,clsDate Date) {
	 short Remainder = HowDayInYearFromBegingingtoNow(Date) + AddingDays;
	 Date._month = 1;
	 while (true)
	 {
		 if (Remainder > CountDayInMonth(Date._year, Date._month))
		 {
			 Remainder -= CountDayInMonth(Date._year, Date._month);
			 Date._month++;
			 if (Date._month > 12)
			 {
				 Date._year++;
				 Date._month = 1;
			 }
		 }
		 else
		 {
			 Date._day = Remainder;
			 break;
		 }

	 }
	 //Date.Print();
	 return Date;
 }
 void IncreessDaysToDate(int AddingOfDays) {
	*this= IncreessDaysToDate(AddingOfDays,*this);
 }

 static bool IsDate1LessDate2(clsDate Date1, clsDate Date2) {

	 return Date1._year < Date2._year ? true : (Date1._year == Date2._year ? (Date1._month < Date2._month ? true : Date1._month == Date2._month ? (Date1._day < Date2._day) : false) : false);
 }
 bool IsDate1LessDate2(clsDate Date) {
	 return IsDate1LessDate2(*this, Date);
 }

 static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {

	 return Date1._year == Date2._year ? (Date1._month == Date2._month ? (Date1._day == Date2._day) : false) : false;
 }
 bool IsDate1EqualDate2(clsDate Date) {
	 return IsDate1EqualDate2(*this,Date);
 }
static bool IsLastDayInMonth(clsDate Date1) {

	 return Date1._day == CountDayInMonth(Date1._year, Date1._month) ? true : false;
 }
bool IsLastDayInMonth() {
	return IsLastDayInMonth(*this);
}

 static bool IsLastMonthInYear(clsDate Date1) {
	  
	return Date1._month == 12 ? true : false;
}
 bool IsLastMonthInYear() {
	 return IsLastMonthInYear(*this);
 }
static clsDate IncressDateByOneDay(clsDate Date) {
	 if (IsLastDayInMonth(Date))
	 {
		 if (IsLastMonthInYear(Date))
		 {
			 Date._year++;
			 Date._month = 1;
			 Date._day = 1;
		 }
		 else
		 {
			 Date._month++;
			 Date._day = 1;
		 }

	 }

	 else
	 {
		 Date._day++;
	 }
	 return Date;
 }
 void IncressDateByOneDay() {
	 *this  = IncressDateByOneDay(*this);
 }
 static int DiffDate (clsDate Date1, clsDate Date2, bool Include = false) {
	 int Day = 0;
	 while (IsDate1LessDate2(Date1, Date2))
	 {
		 Day++;
		 Date1 = IncressDateByOneDay(Date1);
	 }
	 return Include ? ++Day : Day;
 }
 int DiffDate(clsDate Date) {
	 return DiffDate(*this,Date);
 }
 static int AgeByDay(clsDate DateBrith, bool Include = false) {
	 int Day = 0;
	 clsDate Date2=clsDate();
	/* time_t t = time(0);
	 tm* now = localtime(&t);
	 Date2._year = now->tm_year + 1900;
	 Date2._month = now->tm_mon + 1;
	 Date2._day = now->tm_wday;*/
	 while (IsDate1LessDate2(DateBrith, Date2))
	 {
		 Day++;
		 DateBrith = IncressDateByOneDay(DateBrith);
	 }
	 return Include ? ++Day : Day;
 }

 static void SwapDate(clsDate& Date1, clsDate& Date2) {
	 clsDate SwapDate;

	 SwapDate._year = Date1._year;
	 SwapDate._month = Date1._month;
	 SwapDate._day = Date1._day;

	 Date1._year = Date2._year;
	 Date1._month = Date2._month;
	 Date1._day = Date2._day;

	 Date2._year = SwapDate._year;
	 Date2._month = SwapDate._month;
	 Date2._day = SwapDate._day;
 }
 static int DiffAboHahood(clsDate Date1, clsDate Date2, bool Include = false) {
	 int Day = 0;
	 short FlageSwap = 1;
	 if (!IsDate1LessDate2(Date1, Date2))
	 {
		 SwapDate(Date1, Date2);
		 FlageSwap = -1;
	 }
	
	 while (IsDate1LessDate2(Date1, Date2))
	 {
		 Day++;
		 Date1 = IncressDateByOneDay(Date1);
	 }
	 return Include ? ++Day * FlageSwap : Day * FlageSwap;
 }
 int DiffAboHahood(clsDate Date) {
	 return DiffAboHahood(*this,Date);
 }
 static string DateToString(clsDate Date) {
	 return to_string(Date._day) + "/" + to_string(Date._month) + "/" + 
		 to_string(Date._year);
 }
 static string GetSysteamDateTimeString() {
	 short Sec, Min, Hou, Day, Month, Year;
	 time_t t = time(0);
	 tm* now = localtime(&t);
	 Year = now->tm_year + 1900;
	 Month = now->tm_mon + 1;
	 Day = now->tm_mday;
	 Hou = now->tm_hour;
	 Min = now->tm_min;
	 Sec = now->tm_sec;
	 return to_string(Day) + "/" + to_string(Month) + "/" +
		 to_string(Year) +" - "+ to_string(Hou)+":"+to_string(Min)+":"+to_string(Sec);
 }
};

