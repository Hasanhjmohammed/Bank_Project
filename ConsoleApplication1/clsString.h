#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;
class clsString
{
private:

    string _Value;
    char _Letter;
    vector<string>_veMasseg;
    string _Split="#//#";
    enum WahtCounterLetter {
        Capital = 0, Small = 1, All = 2
    };
  static  string PrintWord(string S1, int& index) {
        string word = "";

        while (S1[index] != ' ')
        {
            word += S1[index];
            index++;
        }
        return word;
    }

  static string trimleft(string  masseg) {

      for (short i = 0; i < masseg.length(); i++)
      {

          if (masseg[i] != ' ')
          {
              return masseg.substr(i, masseg.length() - 1);
          }
      }
      return "";
  }

  static string trimRight(string masseg) {
      for (short i = masseg.length() - 1; i >= 0; i--)
      {

          if (masseg[i] != ' ')
          {

              return masseg.substr(0, i + 1);
          }
      }
      return "";
  }
public:
    clsString() {
        _Value = "";
    }
    clsString(string value) {
       this-> _Value = value;
    }
    void setVector(vector<string> veMasseg) {
        _veMasseg = veMasseg;
    }
    vector<string> setVector() {
        return this->_veMasseg;
    }
    void setLetter(char Lettre) {
        this->_Letter= Lettre;
    }
   char getLetter() {
       return this->_Letter;
    }
   void setValue(string value) {
       this->_Value = value;
   }
   string getValue() {
       return this->_Value;
   }
  static void PrintFirstLetter(string masseg) {
       bool isFirstLetter = true;
       for (int i = 0; i < masseg.length(); i++)
       {
           if (masseg[i] != ' ' && isFirstLetter)
               cout << masseg[i] << endl;

           isFirstLetter = (masseg[i] == ' ' ? true : false);
       }
   }

  void PrintFirstLetter() {
      PrintFirstLetter(_Value);
  }

  static void PrintMassegAllLetterUpper(string S1) {
      for (int i = 0; i < S1.length(); i++)
      {
          S1[i] = toupper(S1[i]);
      }
      cout << S1 << endl;
  }

  void PrintMassegAllLetterUpper() {
      PrintMassegAllLetterUpper(_Value);
  }

  static void PrintMassegAllLetterlower(string S1) {
      for (int i = 0; i < S1.length(); i++)
      {
          S1[i] = tolower(S1[i]);
      }
      cout << S1 << endl;
  }
  void PrintMassegAllLetterlower() {
      PrintMassegAllLetterlower(_Value);
  }
 static char InverCarekter(char Letter) {
      return isupper(Letter) ? tolower(Letter) : toupper(Letter);
  }

 char InverCarekter() {
     return InverCarekter(this->_Letter);
 }

  static int CounterCapitalLetter(string masseg) {
     int counter = 0;

     for (int i = 0; i < masseg.length(); i++)
     {
         if (isupper(masseg[i]))
         {
             counter++;
         }
     }
     return counter;
 }
  int CounterCapitalLetter() {
      return CounterCapitalLetter(_Value);
  }
 static int CounterSamellLetter(string masseg) {
      int counter = 0;

      for (int i = 0; i < masseg.length(); i++)
      {
          if (islower(masseg[i]))
          {
              counter++;
          }
      }
      return counter;
  }

 int CounterSamellLetter() {
     return CounterSamellLetter(_Value);
 }
 static string InverString(string masseg) {

     for (int i = 0; i < masseg.length(); i++)
     {
         masseg[i] = InverCarekter(masseg[i]);
     }
     return masseg;
 }
 void InverString() {
   _Value=  InverString(this->_Value);
 }

  static int CounterLetter(string S1, WahtCounterLetter wahtCounterLetter = WahtCounterLetter::All) {

     if (wahtCounterLetter == WahtCounterLetter::All)
         return S1.length();
     int Counter = 0;
     for (int i = 0; i < S1.length(); i++)
     {
         if (wahtCounterLetter == WahtCounterLetter::Capital && isupper(S1[i]))
             Counter++;
         else if (wahtCounterLetter == WahtCounterLetter::Small && islower(S1[i]))
             Counter++;
     }

     return Counter;
 }

 int CounterLetter() {
     return CounterLetter(_Value);
 }

 static int CounterCharInMasseg(string S1, char C1, bool MathCase = true) {
     int Counter = 0;
     for (int i = 0; i < S1.length(); i++)
     {

         if (MathCase)
         {
             if (C1 == S1[i])
                 Counter++;
         }
         else
         {
             if (tolower(C1) == tolower(S1[i]))
                 Counter++;
         }
     }
     return Counter;
 }

  int  CounterCharInMasseg() {
      return CounterCharInMasseg(_Value, _Letter);
 }
 static bool IsVowel(char Letter) {
      Letter = toupper(Letter);
      return(Letter == 'A' || Letter == 'E' || Letter == 'I' ||
          Letter == 'O' || Letter == 'U');
  }
 bool IsVowel() {
     return IsVowel(this->_Letter);
 }
 static int CounterVowel(string S1) {
     int Counter = 0;
     for (int i = 0; i < S1.length(); i++)
     {
         if (IsVowel(S1[i]))
             Counter++;
     }
     return Counter;
 }

 int CounterVowel()
 {
     return CounterVowel(_Value);
 }

 static void PrintVowel(string S1) {
     int Counter = 0;
     for (int i = 0; i < S1.length(); i++)
     {
         if (IsVowel(S1[i]))
             cout << S1[i] << setw(5);
     }

 }
 void PrintVowel() {
     PrintVowel(_Value);
 }
 static void PrintSingelWord(string masseg) {
     bool isFirstLetter = true;
     string TempWord = "";
     for (int i = 0; i < masseg.length(); i++)
     {
         if (masseg[i] != ' ' && isFirstLetter)
         {
             cout << PrintWord(masseg, i) << endl;

         }
         isFirstLetter = (masseg[i] == ' ' ? true : false);
     }

     cout << "\n-----------------------\n" << masseg;
 }
 void PrintSingelWord() {
     PrintSingelWord(_Value);
 }

 static int CountenWord(string masseg) {
     bool isFirstLetter = true;
     int Counter = 0;
     for (int i = 0; i < masseg.length(); i++)
     {
         if (masseg[i] != ' ' && isFirstLetter)
         {


             // cout << PrintWord(masseg,i) << endl;
             Counter++;
         }

         isFirstLetter = (masseg[i] == ' ' ? true : false);
     }

     return Counter;
 }

 int CountenWord() {
    return CountenWord(this->_Value);
 }

 static vector<string> Split(string masseg, string demo="#//#") {
     vector <string> vstring;
     string sword;
     int pos = 0;
     while ((pos = masseg.find(demo)) != std::string::npos)
     {
         sword = masseg.substr(0, pos);

         if (sword != "")
         {
             vstring.push_back(sword);


         }
         masseg.erase(0, pos + demo.length());
     }

     if (masseg != "")
         vstring.push_back(masseg);

     return vstring;
 }

 vector<string>Split() {
     return Split(_Value);
 }

 static string trim(string& masseg) {

     return (trimleft(trimRight(masseg)));
 }
 void trim() {
   _Value=  trim(this->_Value);
 }
 static void joinstring(vector<string>veMasseg, string split) {
     string masseg = "";
     for (string s : veMasseg)
     {
         masseg += s + split;

     }
     cout << masseg.substr(0, masseg.length() - split.length());
 }
 void joinstring() {
     joinstring(this->_veMasseg,this-> _Split);
 }
 static void ReaservString(string masseg) {
     vector<string>veword;
     string s = "";
     veword = Split(masseg, " ");
     vector <string>::iterator iter = veword.end();
     while (iter != veword.begin())
     {
         iter--;
         s += *iter + " ";

     }
     cout << s;
 }

 void ReaservString() {
     ReaservString(_Value);
 }

 static string ReaplaceStringusingBildInFanction(string masseg, string word, string wordreplace) {

     int pos = 0;
     pos = masseg.find(word);
     while (pos != std::string::npos)
     {
         masseg.replace(pos, word.length(), wordreplace);
         pos = masseg.find(word);
     }

     return masseg;

 }
 void ReaplaceStringusingBildInFanction(string world,string ReplaceWord) {
     _Value=  ReaplaceStringusingBildInFanction(_Value,world,ReplaceWord);
 }


 static string Removepunctaution(string & masseg) {
     string s2 = "";
     for (int i = 0; i < masseg.length(); i++)
     {

         if (!ispunct(masseg[i]))
         {
             s2 += masseg[i];
         }
     }

     return s2;
 }
 void Removepunctaution() {
     _Value=  Removepunctaution(_Value);
 }

 static bool IsFindWordInMasseg(string masseg, string word) {
     int pos = masseg.find(word);
     return (pos!= std::string::npos);
 }

};

