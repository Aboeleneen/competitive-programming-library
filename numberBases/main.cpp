#include <iostream>
#include<bits/stdc++.h>

using namespace std;

string letters = "0123456789ABCDEF" ;
int toInt(char c){return letters.find(c) ;}
long long convertToBase10(string num , long long base){
   long long res = 0 ;
   for(int i=0;i<num.size();i++){
    res*=base ;
    res+=toInt(num[i]);
   }
   return res ;
}
string convertFromBase10(long long num , long long base){
   string res="" ;
   while(num!=0){
           int lastDigit = num%base;
           res=letters[lastDigit]+res;
           num/=base;
   }
   return res ;
}
int main()
{
   cout << convertToBase10("AA",16);
   cout << convertFromBase10(171,16);
    return 0;
}
