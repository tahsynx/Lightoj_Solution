#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;

// Define Some Variables
#define eps 1e-14
#define si 55
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 1000000000 //10^9

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
i64 i,j,l,n,k,m,cs=1,dp[si][si][si];

i64 bmod(i64 a,i64 b)
{
    if(b==0)
        return 1;
    i64 x=bmod(a,b/2);
    x=(x*x)%mod;
    if(b%2==1)
        x=(x*a)%mod;
    return x;
}

int gcd(int a,int b)
{
    while(b>0)
    {
        a%=b;
        a^=b;
        b^=a;
        a^=b;
    }
    return a;
}

i64 lcm(i64 a,i64 b)
{
	return ((a*b)/gcd(a,b));
}

int main()
{
    int test;
    for(n=1;n<=50;n++)
    {
        for(dp[n][1][n]=1,k=2;k<=n;k++)
        {
            for(m=n/k;m<n;m++)
            {
                for(i=n-m;i<=n-1;i++)
                dp[n][k][m]+=dp[i][k-1][m];
                for(i=1;i<=m-1;i++)
                dp[n][k][m]+=dp[n-m][k-1][i];
            }
        }
    }
    for(n=1;n<=50;n++)
    {
        for(k=1;k<=n;k++)
        {
            for(m=2;m<=50;m++)
            dp[n][k][m]+=dp[n][k][m-1];
        }
    }
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lld%lld%lld",&n,&k,&m);
        printf("Case %lld: %lld\n",cs++,dp[n][k][m]);
    }
    return 0;
}
