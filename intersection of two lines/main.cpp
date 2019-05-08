#include <iostream>
#define ll long long
using namespace std;
struct point{
  ll x ,y ;
};
ll x , y ;
bool intersectionOfTwoLine(ll x1,ll y1 ,ll x2 ,ll y2 , ll x3 , ll y3 ,ll x4 ,ll y4){

     ll a,b,c,d,e,f ;
     a=x2*y1-x1*y2;
     b=x2-x1;
     c=y2-y1;
     d=x4*y3-x3*y4;
     e=x4-x3;
     f=y4-y3;

     double check = b*f-e*c ;

     if(check != 0) {
        x= (a*e - d*b)/check ;
        y = (a*f - d*c) / check ;
        return true ;
       // return x >=min(x1,x2) && x <=max(x1,x2) && y >=min(y1,y2) && y <=max(y1,y2);
       // if (x1,y1) and (x2,y2) is a segement
     }

     return false ;


}
// the line is defined by its equation(ax+by+c=0) and i need two points on it
int cur = 0 ;
ll lines[MAX][4];
void generatePoints(ll a , ll b , ll c ){

    if(a==0){
        lines[cur][0]=0;
        lines[cur][1]= c==0?0:-1.0*(c*1.0/b*1.0);
        lines[cur][2]=1;
        lines[cur][3]= c==0?0:-1.0*(c*1.0/b*1.0);
        cur++;
        return;
    }

    if(b==0){
         lines[cur][0]= c==0?0:-1.0*(c*1.0/a*1.0);
         lines[cur][1]=0;
         lines[cur][2]= c==0?0:-1.0*(c*1.0/a*1.0);
         lines[cur][3]=1;
         cur++;
         return;
    }
      lines[cur][0]=1;
      lines[cur][1]= (c+a)==0?0:-1.0*((c+a)*1.0/b*1.0);
      lines[cur][2]= 2;
      lines[cur][3]=  (c+2*a)==0?0:-1.0*((c+2*a)*1.0/b*1.0);
      cur++;

}


// the line is defined by its equation(ax+by+c=0) and i  have a segment defined by two points (x1,y1) and (x2,y2)
// substitute with first and second points in the line to get their signs(s1,s2)
// s1 < 0 --> point under the line
// s1 > 0 --> point over the line
// s1 = 0 --> point on the line
// this function to check if this line cross over this segment or not
bool checkLineCrossSegement(ll a , ll b , ll c , ll x1 , ll y1 , ll x2 , ll y2){
      ll s1=a*x1+b*y1+c;
      ll s2=a*x2+b*y2+c;
      if((s1>0 && s2<0)||(s1<0&&s2>0)){
        return true ;
      }
      return false;
}
// orientation of an ordered triplet of points in the plane can be:
//  counterClockWise (return 2 )
//  clockWise ( return 1 )
//  coLinear ( return 0 )
//  we will use slope (p1 and p2) (p2 and p3)
//  the orientation depends on whether the expression : (y2-y1)(x3-x2)-(y3-y2)(x2-x1) is positive , negative or zero
int clockWiseTest(point p1 , point p2 , point p3){
   ll check = (p2.y-p1.x)*(p3.x-p2.x)-(p3.y-p2.y)*(p2.x-p1.x);
   if(check == 0) return 0 ;
   if(check  > 0) return 1 ;
   else return 2
}
// we can check whether two line segments are intersecting or not using clockWiseTest as follow: (p1,q1) (p2,q2)
// general case:
//              (p1,q1,p2) (p1,q1,q2) have different orientation
//              (p2,q2,p1) (p2,q2,q1) have different orientation
// special case:
//               (p1,q1,p2) (p1,q1,q2) (p2,q2,p1) (p2,q2,q1) are coLinear
//                x-projections of(p1,q1) and (p2,q2) intersect
//                y-projections of(p1,q1) and (p2,q2) intersect
bool onSegment(point p , point q , point r){
    return q.x >=min(p.x,r.x) && q.x <=max(p.x,r.x) && q.y >=min(p.y,r.y) && q.y <=max(p.y,r.y);
}
bool intersectTwoSegments(point p1 , point q1 , point p2 , point q2){
    // four orientations
    ll o1 = clockWiseTest(p1,q1,p2);
    ll o2 = clockWiseTest(p1,q1,q2);
    ll o3 = clockWiseTest(p2,q2,p1);
    ll o4 = clockWiseTest(p2,q2,q1);

    // general case
    if(o1!=o2&&o3!=o4)
        return true;
    // special cases
    // p1,q1,p2 are coLinear and p2 lies on segment p1q1
    if(o1==0&&onSegment(p1,p2,q1)) return true ;
    // p1,q1,q2 are coLinear and q2 lies on segment p1q1
    if(o2==0&&onSegment(p1,q2,q1)) return true ;
    // p2,q2,p1 are coLinear and p1 lies on segment p1q1
    if(o3==0&&onSegment(p2,p1,q2)) return true ;
    // p2,q2,q1 are coLinear and q1 lies on segment p1q1
    if(o4==0&&onSegment(p2,q1,q2)) return true ;

    return false ;
}
int main()
{
    cout << intersectionOfTwoLine(1,1,6,1,6,0,6,1) << endl ;
    cout << x << " " << y ;
    return 0;
}
