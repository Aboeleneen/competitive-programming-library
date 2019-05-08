#include <iostream>

using namespace std;
    /*          ex:  1  2 3 4
            (1) order o(log n)
            (2) mid = (start + end) /2 in normal examples -> mid = 2
            (3) but the better is mid = start + (end-start)/2 -> mid = 2
            (4) we want the right one always so we use this mid =  start+(1+end-start) /2 -> mid = 3
            (5) we can implement it by two methods (iterative or recursion )
            (5)  usually we have an external function called check to use it during the search
    */
int binarySearch(int a[],int start,int finish,int key)
{
   while(start<=finish)
   {
     int mid=(start+finish)/2;
     if(a[mid]<key)
     {
         start=mid+1;
     }
     else if(a[mid]>key)
     {
         finish=mid-1;
     }
     else
     {
         return mid;
     }
   }
   return -1;                //key not found
 }

  bool check(int num){
       // return true or false ;
   }
  int bin_search(int start,int end_v){
   if(start == end_v){
    return start ;
   }
   int mid = start+(1+end_v-start)/2;
   if(check(mid)){
       return bin_search(mid,end_v);
   }
   else{
       return bin_search(start,mid-1);
   }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
