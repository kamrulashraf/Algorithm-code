// count distinct number in range l r

#include <bits/stdc++.h>
using namespace  std;

#define N 1000005
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};


int a[N] , res[N];
int block;
int mark[N];
struct query
{
   int l , r , in;
} arr[N];


bool cmp(query &aa , query &bb){
    int tempa = aa.l/block;
    int tempb = bb.l/block;
    if(tempa == tempb) return aa.r < bb.r;
    return tempa < tempb;
}


int add(int indx){
   mark[a[indx]]++;
   return mark[a[indx]] == 1;
}

int remove(int indx){
   mark[a[indx]]--;
   return mark[a[indx]]==0;
}
int main()
{
    int n;
    sca(n);
    block = sqrt(n);

    for(int i = 1 ; i<= n ; i++){
         sca(a[i]);
    }
    int q;
    sca(q);
    F(i,q){
       scaa(arr[i].l,arr[i].r);
       arr[i].in = i;
    }


    sort(arr,arr+q,cmp);
    int sum = 0 , l = 0 , r = 0;
    for(int i = 0 ; i< q ; i++){
       while(l > arr[i].l) sum  += add(--l);
       while(l < arr[i].l) sum -=  remove(l++);
       while(r > arr[i].r) sum -= remove(r--);
       while(r < arr[i].r) sum += add(++r);
       res[arr[i].in] = sum;
    }

    for(int i = 0 ; i<  q ; i++){
        printf("%d\n",res[i]);
    }

    return 0;

}

