DEBUGER ::::::::::::::::::: DEBUGER

    #define ashraf
    #ifdef ashraf
         #define so(args...) {cerr<<"so: "; dbg,args; cerr<<endl;}
    #else
        #define so(args...)  // Just strip off all debug tokens
    #endif
    struct debugger{
        template<typename T> debugger& operator , (const T& v){
            cerr<<v<<" ";
            return *this;
        }
    }dbg;

STRING TOKENIZER ::::::::::::::::::::::::: STRING TOKENIZER

    char buf[100];
    gets(buf);
    char *p  = strtok(buf, " ");
    while(p != NULL){
        int t;
        sscanf(p , "%d", &t);
        cout << t << ' ';
        p = strtok(NULL , " ");
    }

COMPARE FUNCTION ::::::::::::::::::::: COMPARE FUNCTION

   // for priority queue compare somtime need
   //priority_queue< node, vector<node>, Comp> pq;
    class Boxer{
        public:
            string name;
            int strength;
    };
    struct Comp{
        bool operator()(const Boxer& a, const Boxer& b){
            return a.strength<b.strength;
        }
    };
    // for array compareing
    bool comp(int a , int b){
       if(a> b) return true;
       return false;
    }

BIG MOD CLASS :::::::::::::::::::::::::::::::  BIG MOD CLASS

    template < class T > inline T big(T b, T p, T N){
        if(!p) return 1;
        if(!(p&1)){
                T x = big(b,p/2,N);
                return (x * x)%N;
           }
        return (b * big(b,p-1,N))%N;
    }

POWER FUNCTION ::::::::::::::::::::::: POWER

    template < class T> T power(T b , T p){
       if(!p) return 1;
       T x = power(b,p/2);
       x *= x;
       if(p&1) x *= b;
       return x;
    }

GREATEST COMMON DIVISOR :::::::::::::: GCD

    inline int gcd(int a, int b) {
      while (a > 0 && b > 0) {
        if (a > b) a %= b;
        else b %= a;
      }
      return a + b;
    }

EXTENTED GCD ::::::::::::: EXTENTED GCD

    template < class T> T extentedGcd(T a, T b, T &X , T &Y){
         T x1 = 1 , y1 = 0;
         T x2 = 0 , y2 = 1;
         while(b){
            T x = x1 - (a/b)*x2;
            T y = y1 - (a/b)*y2;
            x1 = x2 ; y1 = y2;
            x2 = x  ; y2 = y;
            T temp = a;
            a = b;
            b = temp%b;

         }
         X = x1;  Y = y1;
         return a;
     }

DEPTH FIRST SEARCH :::::::::::::::::::::::::::: DFS

    int vis[NN], level[NN]; vector<int> adj[NN];
    void dfs(int u){
       vis[u]=1;
       for(auto v:adj[u])
          if(!vis[v])
            dfs(v);
    }

BREADTH FIRST SEARCH :::::::::::::::::::::: BFS

    int vis[NN], level[NN]; vector<int> adj[NN];
    void bfs(int source){
        queue <int> q;
        q.push(source);
        vis[source] = 1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                if(!vis[v]){
                    vis[v];
                    q.push(v);
                    level[v]=level[u]+1;
                }
            }
        }
       return;
    }

DIJKSTRA ::::::::::::::::::::::::::::::::: DIJKSTRA

    int dijkstra(int source){
          rep(i,0,node) dis[i] = inf;
          dis[source] = 0;
          priority_queue < pii, vector < pii > , greater < pii > > q;
          q.push(make_pair(dis[s],s));
          while(!q.empty()){
               int u = q.top().ss;
               q.pop();
               for(int i = 0 ; i < adjacentList[u].size() ; i++){
                   int v = adjacentList[u][i].ss;
                   int cost = adjacentList[u][i].ff;   // u theke v te jaoyar cost
                   if(cost + dis[u] < dis[v]){
                      dis[v] = cost+dis[u];
                      q.push(make_pair(dis[v],v));
                   }
               }
          }
    }

ARTICULATION POINT ::::::::::::::::::: CUT VERTEX

    int num[NN],low[NN],vis[NN],counter ; vector<int> adj[NN];

    void articulationPoint(int u){
        int child = 0;
        counter++;
        num[u] = counter;
        low[u] = counter;
        vis[u] = 1;
        for(int i = 0 ; i< g[u].size() ; i++){
            child++;
            int v = g[u][i];
            if(!vis[v]){
                vis[u] = 1;
                parent[v] = u;
                articulationPoint(v);
                low[u] = min(low[u],low[v]);
                //  cout << u << ' ' << v << ' ' << low[v] << ' ' << num[u] << endl;
                // equal cause oi edge er sathe back edge thakleO lav nai
                if(child > 1 && parent[u] == 0) save[u] = 1;
                if(low[v] >= num[u] && parent[u] != 0)
                    save[u] = 1;
            }
            else if(parent[u] != v)
                low[u] = min(low[u],num[v]);
        }
    }

STRONGLY CONNECTED COMPONENT ::::::::::::::::::::::::: SCC
    // it is a directional graph
    stack < int > st; map < int , vector <int> adjacentList;
    int vis[1000], low[100], num[1000];

    void SCC(int u)
    {
        vis[u] = grey;
        st.push(u);
        low[u] = num[u] = cnt++;
        for(int i = 0 ; i< adjacentList[u].size() ; i++)
        {
            int v = adjacentList[u][i];
            if(vis[v] == white)
                SCC(v);
            if(vis[u] == grey)
                low[u] = min(low[u],low[v]);
        }
        if(low[u] == num[u])
        {
            while(1){
                int temp = st.top();
                st.pop();
                vis[temp] = black;
                printf("%d ", temp);
                if(u == temp) break;
            }
            puts("");
        }
    }

SHRINK :::::::::::::::::::::::::::: DAG

void shrink(int node){
    for(int i = 1 ; i<= node ; i++){
        for(int j = 0 ;  j< adj[i].size() ; j++){
            if(parent[i] != parent[adj[i][j]]){
                    g[parent[i]].push_back(parent[adj[i][j]]);
            }
        }
    }
}

EDMOND KRAPS ::::::::::::::::: EDMOND KRAPS

    void argument(int v , int mmin){
       if(v == s){
         f = mmin;
         return;
       } else if(parent[v] != -1){
          argument(parent[v], min(mmin , resGraph[parent[v]][v]));
          resGraph[parent[v]][v] -= f;
          resGraph[v][parent[v]] += f;
       }

    }
    int edmondKarps(){
        int maxFlow = 0;
        while(1){
            f = 0;
            bool vis[NN];
            queue < int > q;
            q.push(s);
            memset(vis,0,sizeof vis);
            memset(parent , - 1 , sizeof(parent));
            while(!q.empty()){
               int u = q.front();
               q.pop();
               if(u == t) break;
               for(int i = 0 ; i< adjList[u].size() ; i++){
                  int v = adjList[u][i];
                  if(resGraph[u][v] > 0 && !vis[v]){
                      vis[v] = 1;
                      q.push(v);
                      parent[v] = u;
                  }
               }
            }
            argument(t , inf);
            if(f == 0) break; // can not sent more flow in this graph
            maxFlow += f;
        }
      return maxFlow;
    }

MAXIMUM BIPARTITED MATCHING :::::: MBM

    int vis[100005], color[100005] ,match[100005];

    int aur(int u){
       if(vis[u] == 1) return 0;
       vis[u] = 1;
       for(int i = 0 ; i< g[u].size() ; i++){
          int v = g[u][i];
          if(match[v] == -1 || aur(match[v])){
             match[v] = u;
             return 1;
          }
       }
       return 0;
    }

    int MBM(){
        //first check bipartitite grraph .. then push one side to vector v;
        int res = 0;
        memset(match,-1,sizeof(match));
        for(auto it : v){
            memset(vis,0,sizeof(vis));
            res += aur(it);
        }
        return res;
    }

DISJOINT SET DS :::::::::: DISJOINT SET DS

    class DSU{
     int parent[1000], rank[1000],sz = 1000;
     public:
           void clr(){
                memset(rank,0,sizeof(rank));
                for(int i = 0 ; i< sz ; i++)
                   parent[i] = i;
           }
        bool makeUnion(int a , int b){
           int parA = dsuFind(a);
           int parB = dsuFind(b);
           if(parA ==  parB) return 0;
           else{
               if(rank[parA] >= rank[parB]) swap(parA,parB);
               parent[parA] = parB;  // rank of parB is greater than parA
               if(rank[parA] == rank[parB]) rank[parB]++;   // increasing rank of parB( with whom connect anoter child)
               return 1;
           }
        }
        int dsuFind(int a){
            if(parent[a] == a) return a;
            return parent[a] = dsuFind(parent[a]);

        }

    };

    class DSUsmall{
       int parent[1005],sz = 1000;
       DSUsmall(){
          rep(i,0,sz) parent[i] = i;
       }
       int findUnion(int a){
            if(parent[a] == a) return a;
            return parent[a] = dsuFind(parent[a]);
        }
        bool makeUnion(int x, int y){
           int a = findUnion(x);
           int b = findUnion(y);
           if(a==b) return false;
           parent[a] = b;
           return true;
        }
    };

MINIMUM SPANING TREE :::::::::::::::::::::: KRUSKAL

    kruskal(){
        priority_queue < node , vector < node > , comp > q;
        for(int i = 0 ; i< edge ; i++){
             take(u,v,cost);
             q.push(node(cost,u,v));
        }
        DSU a; int res = 0;  // use my dsu class
        while(!q.empty()){
             if(!a.makeUnion())
                res += q.top().cost;
             q.pop();
        }
        return res;
    }

WARSHALL ::::::::::::::::::::::: WARSHALL

    int mar[NN][NN][NN];
    void warshall(int n){
       rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1)
           if(mat[i][k]+mat[k][j]<mat[i][j]) mat[i][j]=mat[i][k]+mat[k][j];
    }

PRIME SEIVE ::::::::::::::::::::  PRIME SEIVE

    inline void seive(long long num){
    bool a[num+5];
    memset(a,0,sizeof(a));
    for(int i = 3 ; i*i <= num ; i+= 2)
      if(!a[i])
         for(int j = i*i ; j<= num ; j+= 2*i)
           a[j] = 1;
    prime.push_back(2);
    for(int i = 3 ; i<= num ; i+= 2)
        if(!a[i])
           prime.push_back(i);
   }

BITWISE SEIVE ::::::::::::::::::: BITWISE SEIVE
    inline void seive(long long num){
    for(int i = 3 ; i*i <= num ; i+= 2)
      if(!(a[i/64]&(1LL<<(i%64))))
         for(int j = i*i ; j<= num ; j+= 2*i)
           a[j/64] |= (1LL<<(j%64));
    prime[cnt++] = 2;
    for(int i = 3 ; i<= num ; i+= 2)
        if(!(a[i/64]&(1LL<<(i%64))))
           prime[cnt++];
    }
    
SEGMENTED SEIVE ::::::::::::::::::::::: SEGMENTED SEIVE
    // HOW MANY PRIME IN RANGE(b,e)
    int segmentSeive(long long b , long long e){
        seive();
        int counter = 0;
        memset(a,0,sizeof(a));
        if(b == 1) b++;
        for(int i = 0 ; prime[i]*prime[i] <= e && i < prime.size() ; i++){
            long long p = prime[i];
            long long start= p*p;
            if(start < b)
                start = (b+p-1)/p*p;
                for(long long j = start ; j<= e ; j+= p)
                a[j-b] = 1;
        }
        for(long long i = b ; i <= e ; i++)
            if(a[i-b] == 0)
                counter++;
        return counter;
    }

EULER TOTIENT :::::::::: EULER TOTIENT

    phi(n) = (1-1/p1)*(1-1/p2)*n
    int phi[N], hit[N]; // save value in phi array
    void eulerPhi(int num)
    {
        int i , j , k ;
        phi[1] = 1;
        for(i = 2 ; i<=num ; i++)
            phi[i] = i;
        for(i = 2 ; i<= num ; i++)
        if(hit[i] == 0){
            phi[i] = phi[i]-1;
            for(j = 2*i ; j <= num ; j+=i)
            {
                hit[j]=1;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }

SUMMATION OF DIVISOR :::::::::::::::::::::::SOD

    int sod(int n){
    // formula :: sod(20) = (1+2^1+2^2)*(1+5^1)
         seive();
         int res = 1;
         for(int i = 0 ; prime[i]*prime[i] <= n && i < prime.size() ; i++){
            int temp = 1;
            int p = 1;
            if(n%prime[i]==0){
                  while(n%prime[i]==0){
                     p = p*prime[i];
                     temp += p;
                     n /= prime[i];
                  }
                  ans *= temp;
            }
         }
         if(n != 1) res *= (n+1);
         return res;
        }

NUMBER OF DIVISOR :::::::::::::::: NOD

    template < class T > T NOD(T n){
       // generate before cubicroot(n) seive()
       T counter, res = 1;
       for(auto p : prime){
           if(p*p*p > n) break;
           counter = 1;
           while(n%p==0)
                 n /= p,
                 counter++;
           res *= counter;
       }
       if(isprime(n)) res *= 2;
       else if(isprime(sqrt(n))) res *= 3;
       else if(n!=1) res *= 4;
       return res;
    }

NUMBER OF DIVISOR :::::::::::::::::: Nlog(N)

    for(int i = 1  ; i <= 1e6 ; i++){
        for(int j = i ; j<= 1e6 ; j+= i)
             numberofdivisor[j]++;
    }

SUMATION OF NUMBER OF DIVISOR ::::::::::::::::: SNOD

    int snod(int num){
        int sq = sqrt(num), res = 0;
        for(int i = 1 ; i<= temp ; i++){
           res += num/i - i;
        }
        return 2*res + temp;
    }

LOWER BOUND ::::::::: LOWER BOUND

    template <class T> inline T lowerBound(T b , T e , T key, T arr[]){
      while(b <= e){
        T mid = (b+e)/2;
        if(arr[mid] < key) // for upper bound use <= //
            b = mid+1;
        else e = mid-1;
      }
      return b;
    }

BISECTION  :::::::::::::::::::  BISECTION
    // squre root
    double bisection(int num){
        double begin = 1 , end = num , mid;
        while(end - begin > EPS){
            mid = (begin+end)/2;
            if(mid*mid > num)
                end = mid;
            else begin = mid;
        }
        return (begin+end)/2.0;
    }

TRINARY SEARCH ::::::::::::::::::::::::: TRINARY SEARCH

    double trinarySearch(double b , double e){
          while(e-b > .000000001){
             double m1 = b+(e-b)/3.0;
             double m2 = b+ 2.0*(e-b)/3.0;
             if(fun(m1) <= fun(m2)+ EPS)
                b = m1;
             else e = m2;
          }
          return b;
    }

nCr itterative::::::::::::::::::::::::::::::::::: nCr

    void nCr(int n){
         rep(i,0,n+1) rep(j,0,i+1){
            if(i==j || j == 0) ncr[i][j] = 1;
            else ncr[i][j] = ncr[i-1][j-1]+ ncr[i-1][j];
         }
    }

DEARRANGMENT :::::::::::::::::: DEARRANGMENT

    long long dp[21];
    int deArrangment(long long n){
     if(n == 1 || n == 2) return dp[n] = n-1;
     if(dp[n] != -1) return dp[n];
     return dp[n] = (n-1)*(deArrangment(n-1)+deArrangment(n-2));
    }

CATALAN NUMBER :::::::::::: CATALAN NUMBER

    template <class T> void catalan(T num){
         // make dp global variable // this is precalculation
        unsigned long long i, j, DP[10000] ;
        dp[0] = 1;
        dp[1] = 1;
        for(i = 2; i <= num ; i++)
            for(j = 0 ; j< i ; j++)
                dp[i] += dp[j]*dp[i-j-1];
    }

BACKTRACKING :::::::::::::: BACKTRACKING

    inline void backtack()
    {
        // s is the string  name // vector name is taken // vis is mapping array // MAKE THEM GLOBAL
        if(taken.size() == s.size()){
            for(int i = 0 ; i< s.size() ; i++)
                printf("%d", taken[i]);
            return;
        }
        for(int i = 0 ; i< s.size() ; i++){
            if(vis[i] == 0){
                vis[i] = true;
                taken.push_back(s[i]);
                backtack();
                vis[i] = false;
                taken.pop_back();
            }
        }
    }

HISTOGRAM ::::::::::::::::::::: HISTOGRAM

    int histogram(int a[ ] , int n){
           int dp[105] = {0};
           stack < pi > st;
           st.push(make_pair(-inf,-1));
           for(int i = 0 ; i < n ; i++){
               while(st.top().first >= a[i])
                  st.pop();
                dp[i] += i-st.top().second;
                st.push(make_pair(a[i],i));
           }
           reverse(a,a+n);
           while(!st.empty()) st.pop();
           st.push(make_pair(-inf,-1));
           for(int i = 0 ; i < n ; i++){
               while(st.top().first >= a[i])
                  st.pop();
                dp[n-i-1] += i-st.top().second-1; // i have already taken this
                st.push(make_pair(a[i],i));
           }
           reverse(a,a+n);
           int ans = 0;
           for(int i = 0 ; i< n ; i++){
              ans = max(ans , dp[i]*a[i]);
           }
      return ans;
    }

LONGEST INCREASING SUBSECUENCE ::::::::: LIS

    int a[1000000] , sub[1000001] , pos[100000];

    int lis(int n){
       int len = 0;
       rep(i,0,n+1) sub[i] = inf;
       sub[0] = -inf;
       for(int i = 0 ; i< n ; i++){
          f[i] = lower_bound(sub,sub+n, a[i]) - sub;
          sub[f[i]] = a[i];
          len = max(len , f[i]);
       }
      return len;
    }

    void lisSolutionPrint(){
       int temp = lis(n);
       vector < int > secuence;
       for(int i = n ; i >= 1 ; i--){
          if(f[i-1] == temp){
                secuence.push_back(a[i-1]);
                temp--;
          }
       }
       reverse(secuence.begin(),secuence.end());
       for(auto it : secuence) printf("%d ",it);
    }

    // order squre root solution
    int nsqLis(int n){
       int len = 0;
       for(int i = 0 ;  i < n  ; i++){
          for(int j = i+1 ; j< n ; j++){
            if(a[j] > a[i] && sub[j] < sub[i]+1)
                sub[j] = sub[i]+1;
                len = max(len,sub[j]);
          }
       }
       return len;
    }

    void nsqprint(){
       int temp = nsqLis(n);
       vector < int > secuence;
       for(int i = n- 1 ; i >= 0 ; i++){
          if(sub[i] == temp)
             secuence.push_back(a[i]),
             temp--;
       }
       reverse(secuence.begin(),secuence.end());
       for(auto it : secuence) printf("%d ",secuence[i]);
    }

MAXIMUM SUBSET PRODUCT ::::::::::::::::::::::: MSP

    int maximumSubsetProduct(int a[]){
       int pre_max = a[0];
       int pre_min = a[0];
       int res = a[0];
       for(int i = 1 ; i< n ; i++){
            int cur_max = MAX(pre_max*a[i] , pre_min*a[i] , a[i]);
            int cur_min = MIN(pre_max*a[i] , pre_min*a[i] , a[i]);
            ans = max(cur_max , cur_min);
            pre_max = cur_max;
            pre_min =  cur_min ;

       }
       return res;
    }

MAXIMUM SUBSET SUM:::::::::::: MAXIMUM SUBSET SUM

    int maximumSubsetSum(int a[]){
       int sum = 0 ,res = -10000000;
       for(int i = 0, j = 0 ; i< n ; i++){
           sum += a[i];
           sum = max(0,sum);
           res = max(sum,res);
       }
       return res;
    }

MINIMUM EDIT DISTANCE ::::::::::::: MINIMUM EDIT DISTANCE

    // defination : you are given two string how many oparetion need to make two string equal
    class minimumEditDistance{
       int dp[100][100];
       string a , b;
       public :
         minimumEditDistance(string a , string b){
            this -> a = a;
            this -> b = b;
         }
         int getDistance(){
            for(int i = 0 ; i <= a.size() ; i++) dp[0][i] = i;
            for(int i = 0 ; i <= b.size() ; i++) dp[i][0] = i;
            for(int i = 1 ; i <= a.size() ; i++)
              for(int j = 1 ; j <= b.size() ; j++){
                  dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
                  dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
                  if(a[i-1] != b[j-1]) dp[i][j]++;
              }
             return dp[a.size()][b.size()];
         }
    };

LEXIGRAPHICAL SORT :::::::::::::::::::::::: LEXIGRAFICAL SORT

   // always remember this is directional graph ..
    int vis[100] , indeg[100]; map < int , vector <int> > adjacentList;
    void lexigraphical_sort(){
        int counter = 0;
        while(counter < node){
             for(int i = 1 ; i<= node ; i++){
                 if(indeg[i] == 0 && vis[i] == 0){
                     vis[i] = 1;
                     printf("%d\n", i);
                     for(int j = 0 ; j< adjacentList[i].size() ; j++){
                        int v = adjacentList[i][j];
                        indeg[v]--;
                     }
                    break;
                 }
             }
        }
    }

LONGEST COMMON SUBSEQUENCE ::::::::::::::::::::::: LCS

    int dp[105][105];
    int lcs(string a , string b){
        for(int i = 1 ; i<= a.size() ; i++){
            for(int j = 1 ; j<= b.size() ;j++){
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
            }
        }
        return dp[a.size()][b.size()];
    }

BINARY INDEXED TREE ::::::::::::::::::::::::::::: BIT

    // start from indx 1 else not work
    int sum(int indx)
    {
        int sum = 0;
        while (indx){
            sum += tree[indx];
            indx -= indx & -indx;
        }
        return sum;
    }

    void update(int n, int indx, int val){
        while (indx <= n){
            tree[indx] += val;
            indx += indx & (-indx);
        }
    }

SEGMENT TREE ::::::::::::::::::::::::::: SEGMENT TREE

    int makeSegment(int node , int b ,int e){
        if(b==e) return tree[node] = a[b];
        int m = (b+e)>>1;
        return tree[node] = makeSegment( node<<1,b,m) + makeSegment((node<<1)+1,m+1,e);
    }
    int query(int node, int b ,int e , int l , int u){
        if( l > e || u < b) return 0;
        if(b >= l && e <= u) return tree[node];
        int m = (b+e)>>1;
        return query(node<<1,b,m,l,u)+query((node<<1)+1,m+1,e,l,u);
    }
    int update(int node ,int b , int e , int indx, int val){
        if(indx > e || indx < b) return 0;
        if(b >= indx && e <= indx) return tree[node] = value;
        int m = (b+e)>>1;
        tree[node] = update(node<<1,b,m,indx,val)+update((node<<1)+1,m+1,e,indx,val);
    }

SEGMENT TREE LAZY PROPAGRATION ::::::::::::::: LAZY PROPAGRATION

    long long makeSegment(int node , int b ,int e){
        if(b==e) return tree[node] = a[b];
        int m = (b+e)>>1;
        return tree[node] = makeSegment( node<<1,b,m) + makeSegment((node<<1)+1,m+1,e);
    }

    long long update(int node,int b,int e, int i,int j,int val){
       int left=node*2;
       int right=left+1;
         if(lazy[node]){
            tree[node]+=(e-b+1)*lazy[node];
            if(b!=e)
              lazy[left]+=lazy[node];
              lazy[right]+=lazy[node];
            lazy[node] = 0;
         }
         if(e<i||b>j) return tree[node]; // this line must be after lazy propagrate
                                         // don't take it  before

         if(b>=i&&e<=j){
            if(b!=e)
              lazy[left]+=val,
              lazy[right]+=val;
            return tree[node]+=(e-b+1)*val;
         }
         int m = (b+e)/2;
         return tree[node] = update(left,b,m,i,j,val)+update(right,m+1,e,i,j,val);
    }

    long long query(int node,int b,int e,int i ,int j){
       int left=node*2;
       int right=left+1;
         if(lazy[node]){
            tree[node]+=(e-b+1)*lazy[node];
            if(b!=e)
              lazy[left]+=lazy[node];
              lazy[right]+=lazy[node];
            lazy[node] = 0;
         }
         if(e<i||b>j) return 0;
         if(b>=i && e<=j)
            return tree[node];
         int m = (b+e)/2;
         return query(left,b,m,i,j)+query(right,m+1,e,i,j);
    }

RANGE MINIMUM QUERY ::::::::::::::::::::::::::::::: RMQ

    int a[100005], table[100005][22];
    void RMQ_init(int n){
        for(int i=0;i<n;i++) table[i][0] = a[i];
        for(int len = 1;(1<<len)<=n;len++)
            for(int i=0;(i+(1<<len))<=n;i++)
                table[i][len] = min(table[i][len-1],table[i+(1<<(len-1))][len-1]);
        return;
    }

    int getmin(int i,int j){
        int k = log2(j-i+1);
        return min(table[i][k],table[j-(1<<k)+1][k]);
    }

MODULAR INVERSE FOR PRIME NUMBER:::::::::::::::::::: MOD INV

    long long modInverse(ll n, ll mod){
      return big((ll) n,mod-2, mod);
    }

INSERTION SORT ::::::::::::::::::: INSERTION SORT

      // a is array a[0---(n-1)]
    for(int i = 1 ; i< n ; i++){
        int key = a[i];
        int j = i-1;
        while(j >=0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }

MERGE SORT :::::::::::::::::::::::::::::::::::::::::::: MERGE SORT

    int a[NN];
    void Merge(int b , int m , int e){
        int n1 = m-b+1;
        int n2 = e-m;
        int left[30],right[30]; // supporting array
        rep(i,0,n1) left[i] = a[b+i];
        rep(i,0,n2) right[i] = a[m+i+1];
        int i = 0 , j = 0 , k = b;
        while(i < n1 && j < n2){
            if(left[i] < right[j])
                a[k] = left[i] , i++;
            else a[k] = right[j] , j++;
            k++;
        }
        while(i < n1) a[k] = left[i] , i++, k++;
        while(j < n2) a[k] = right[j], j++, k++;

    }
    void mergeSort(int b , int e){
       if(b < e){
           int m = (b+e)/2;
           mergeSort(b,m);
           mergeSort(m+1,e);
           Merge(b,m,e);
       }
    }

TRIE :::::::::::::::::::::::::::::::::::: TRIE

    struct node
    {
      int mark;
      node *child[26];
      node(){
        for(int i = 0 ; i< 26 ; i++){
          child[i] = NULL;
          mark = 0;
        }
      }
    } *root;
    // root = new node();
    // declare in main function
    void insertTrie(string s){
        node *cur = root;
        for(auto x : s){
            int temp = x- 'a';
            if(cur -> child[temp] == NULL){
               cur -> child[temp] = new node();

            }
            cur = cur -> child[temp];
        }
        cur -> mark = 1;
    }

    void del(node *u){
        for(int i = 0 ; i< 26 ; i++)
            if(u -> child[i])
                del(u -> child[i]);
        delete u;
    }

LONGEST COMMON ANCESTOR ::::::::::::::::::: LCA

    // find the level of node and parent using bfs or dfs
    table[NN][22] , p[NN] , level[NN];
    void lcaPreCal(int n){
        for(int i=0;i<= n;i++) table[i][0] = p[i];
        for(int len=1;(1<<len)<=n;len++){
          for(int i=0;i <=n;i++){
            if(table[i][len-1] != -1)
               table[i][len]=table[table[i][len-1]][len-1];
             else table[i][len] = -1;
          }
        }
    }

    int lca(int u,int v){
       if(level[u] < level[v]) swap(u,v);

       int diff;
       // make u , v lavel same
       while(diff = level[u]-level[v]){
           int k = log2(diff);
           u = table[u][k];
       }

       if(u==v) return u;
       for(int i = 20 ; i >= 0 ; i--){
             if(table[u][i] == table[v][i]) continue;
             u = table[u][i];
             v = table[v][i];
       }
       return table[u][0];
    }

KNUTH MORRIS PRATT :::::::::::::::::::::::::::::::: KMP

    // my implement
    int pre[NN], counter = 0;
    void prefixCal(string a){
       int j = 0;
       for(int i = 1 ; i< a.size() ; i++){
          if(a[i]!=a[j]){
            while(j>0 && a[pre[--j]]!=a[i])
                 j=pre[j];
            j = pre[j]; // last time not enter so update need
          }
          if(a[i]==a[j]){
              pre[i]=j+1;
              j++;
          } else pre[i] = 0;
       }

    }

    int kmp(string s , string sub){
         int target = sub.size();
         int j = 0;
         for(int i = 0 ; i< s.size() ; i++){
              if(s[i] != sub[j]){
                while(j>0 && sub[pre[--j]] != s[i])
                  j = pre[j];
                j = pre[j];
              }
              if(s[i] == sub[j]){
                j++;
              }
              if(j==target){
                counter++;
                j = pre[--j];
              }
         }
    }

   // THIS IS EASIER TO USE AT CONTEST
    void kmpPreprocess(char *sub)
    {
        int i = 0, j = -1; // 1  based
        b[i] = j;
        m = strlen(sub);
        while(i < m){
            while(j >= 0 && sub[i] != sub[j])
                j = b[j];
            i++, j++;
            b[i] = j;
        }
    }

    int kmp(char *s , char *sub){
      int i=0,j=0,counter=0;
      int n = strlen(s);
      int m = strlen(sub);
      while(i<n){
        while( j>= 0 && s[i] != sub[j]) // i is the pointer of main string 
           j = b[j];                    // j is the pointer of sub string
         i++ , j++;
         if(j==m) counter++ , j = b[j];
      }
      return counter;
    }

MATRIX EXPONENTIAL :::::::::::::::::::::: FIBONACII SERIES

struct MAT
{
	 long long r,c;
	 long long a[2][2];
	 MAT(long long a,long long b){
	 	r = a;
	 	c = b;
	 }
     void init(long long temp[]){
     	for(long long i = 0 ; i<r*c ; i++){
     		a[i/c][i%c] = temp[i];
     	}
     }
     void print(){
          for(long long i = 0 ; i< r ; i++){
          	 for(long long j = 0; j < c ; j++){
          	 	 cout << a[i][j] << ' ';
          	 }
          	 cout << endl;
          }
     }
     MAT operator*(MAT b){
     	 MAT sum(r,b.c);
     	 long long temp[r*c];
     	 memset(temp,0,sizeof temp);
     	 sum.init(temp);
     	 for(long long i = 0 ; i< r ; i++){   // row 1st mat
     	 	 for(long long j = 0 ; j< b.c ; j++){  // col 2nd mat
                   for(long long k=0; k<c ;k++){   // col 1st matss
                   	  sum.a[i][j] += (a[i][k]*b.a[k][j])%mod;
                      if(sum.a[i][j] >= mod) sum.a[i][j] = sum.a[i][j]%mod; 
                   }
     	 	 }
     	 }
     	 return sum;

     }
};

MAT pow(MAT b , long long p){
    if(p == 0 || p == 1)
      return b;
    if(p&1){
        return b*pow(b,p-1);
    }
    else{
        MAT temp = pow(b,p/2);
        return temp*temp;
    }

}
long long power(long long b, long long p){
     if(p == 0 || p == 1) return b;
     if(p&1) return b*power(b,p-1);
     else{
        long long x = power(b,p/2);
        return x*x;
     }
}
Z-Algorithm :::::::::::::::::::: Z-Algorithm

  vector < int > zAlgorithm(string s){
        vector< int > z(s.size());
        int left=0, r=0,len=s.size();

        for(int i = 1 ; i< len ; i++){
              if(i <= r) z[i] = min(r-i+1 , z[i-left]);

              while( i < len && s[z[i]] == s[i+z[i]])
                  z[i]++;

              if( i+z[i]-1 > r){
                  left = i;
                  r = i+z[i]-1;
              }
        }
        return z;
  }



ALL POSIBLE SUBSET :::::::::::::::::: ALL POSIBLE SUBSET

    void subset(int n){
        for(int i = 0 ; i < (1<<n) ; i++){
            printf("{");
            for(int j = 0 ; j< n ; j++){
                if(i&(1<<j))
                    cout << j+1 << ' ';
            }
            printf("\n");
        }
    }

BIG NUMBER MOD ::::: BIG NUMBER MOD

( base ^ (power% phi[mod]) )%mod;

DIGIT DP :::::::::::::::: DIGIT DP
    #define NN 15
    #define ll long long
    int u[NN] , l[NN];
    long long dp[NN][2][2][2][NN];
    int n;
    // next state
    //flag = flag| i? 1:0
    //islow = islow & (i==lower[index])
    //ishigh = ishigh & (i==upper[index])
    // oviously send string of equal size
    long long call(int in , bool flag ,bool islow , bool ishigh,int carry){
        if(in >= n)
           return carry;
        ll  res = 0;
        if(dp[in][flag][islow][ishigh][carry] !=-1)
           return dp[in][flag][islow][ishigh][carry];
        for(int i = 0 ; i< 10 ; i++){
             if(islow && i < l[in]) continue;
             if(ishigh && i> u[in]) continue;
             if(i == 0 && flag)
               res += call(in+1,flag,islow&(i==l[in]),ishigh&(i==u[in]),carry+1);
             else
               res +=call(in+1,flag | i?1:0,islow&(i==l[in]),ishigh&(i==u[in]),carry);

        }
        return dp[in][flag][islow][ishigh][carry] =res;
    }

MILLER RABIN TEST ::::::: MILLER RABIN TEST


// This function is called for all k trials. It returns
// false if n is composite and returns false if n is
// probably prime.
// d is an odd number such that d*2<sup>r</sup> = n-1
// for some r >= 1
bool miillerTest(int d, int n)
{
	// Pick a random number in [2..n-2]
	// Corner cases make sure that n > 4
	int a = 2 + rand() % (n - 4);

	// Compute a^d % n
	int x = power(a, d, n);

	if (x == 1 || x == n-1)
	return true;

	// Keep squaring x while one of the following doesn't
	// happen
	// (i) d does not reach n-1
	// (ii) (x^2) % n is not 1
	// (iii) (x^2) % n is not n-1
	while (d != n-1)
	{
		x = (x * x) % n;
		d *= 2;

		if (x == 1)	 return false;
		if (x == n-1) return true;
	}

	// Return composite
	return false;
}

// It returns false if n is composite and returns true if n
// is probably prime. k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(int n, int k)
{
	// Corner cases
	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;

	// Find r such that n = 2^d * r + 1 for some r >= 1
	int d = n - 1;
	while (d % 2 == 0)
		d /= 2;

	// Iterate given nber of 'k' times
	for (int i = 0; i < k; i++)
		if (miillerTest(d, n) == false)
			return false;

	return true;
}

// Driver program
int main()
{
	int k = 4; // Number of iterations

	cout << "All primes smaller than 100: \n";
	for (int n = 1; n < 100; n++)
	if (isPrime(n, k))
		cout << n << " ";

	return 0;
}


CONVEXHULL ::::::::::::::: CONVEXHULL

#define PI      acos(-1.0)
 
double grad(double n){ return (PI*n)/180; }
double agrad(double n){ return (180*n)/PI; }
 
// global variable
pll g;
 
ll disSq(pll a , pll b){
     ll x = a.ff - b.ff;
     ll y = a.ss - b.ss;
     ll ret = x*x+y*y;
     return ret;
}
 
ll triArea(pll a , pll b , pll c){
    // if anti clock wise positive else negative
    ll area  = a.ff*b.ss + b.ff*c.ss+c.ff*a.ss;
    area -= a.ss*b.ff+ b.ss*c.ff+c.ss*a.ff;
    return area;
}
 
bool convexComp(pll a, pll b){
    ll area = triArea(g,a,b);
    if(area > 0) return true;
    else if( area == 0 && disSq(g,a) < disSq(g,b))
       return true;
    return false;
}
pll inputPoint(){
    ll x , y;
    scanf("%lld %lld",&x,&y);
    return {x,y};
}
 
class ConvexHull{
    public:
      pll pointArr[NN], convex[NN];
      int n, m, cur; // m-1  is convexhull no of point loop :: 1 to m-1
      // if m <= 2 then m = convex  point
    void convexSort(){
         g = pointArr[0];
         for(int i=1;i < n;i++){
             if(pointArr[i].ff < g.ff)
                g = pointArr[i];
             else if(pointArr[i].ff == g.ff && pointArr[i].ss < g.ss){
                g = pointArr[i];
             }
         }
         sort(pointArr,pointArr+n,convexComp);
    }
 
    void makeHull(){
         convexSort();
         if(n == 1){
             convex[0] = pointArr[0];
             convex[1] = pointArr[0];
             m = 1;
             return;
         }
 
         cur = 3;
         pointArr[n] = pointArr[0];
         convex[0] = pointArr[n-1];
         convex[1] = pointArr[0];
         convex[2] = pointArr[1];
         for(int i = 2; i<= n;i++){
             ll area = triArea(convex[cur-2],convex[cur-1],pointArr[i]);
             if(area > 0){
                convex[cur] = pointArr[i];
                cur++;
             }
             else if(area == 0){
              // if take
              // convex[cur] = arr[i];
              // cur++;
              // if not take
              // else
              convex[cur-1] = pointArr[i];
            }
            else{
              cur--;
              i--;
            }
         }
 
         m = cur-1;
         convex[0] = convex[m-1];
         convex[m] = convex[1];
    }
};
 
double findAgle(pll a , pll b , pll c){
    double B = disSq(a,c);
    double A = disSq(b,c);
    double C = disSq(a,b);
    double angle = ((A+C-B)/(2*sqrt(A*C)));
    angle = acos(angle);
    return angle;
 
}




GEOMETRY FUNTION :: 

ll squreDistance(pll a , pll b){
      ll x = a.ff-b.ff;
      ll y = a.ss-b.ss;
      return x*x+y*y;
}

double scetor(long long r , double angle){
      return r*r*.5*(angle-sin(angle));
}



HASHING ::::::::::::::::::: HASHING

const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
int hashString[N], hashPattern[N];
long long hashFuntion(string s, int hashVal[]){
    ll temp = 0;
    for(int i =  0 ; i< s.size() ; i++){
         temp = temp*base + s[i]-'a'+1;
         temp = temp%mod;
         hashVal[i+1] = (temp+mod)%mod;
    }
    return (temp+mod)%mod;
}


void preCalculate(){
   power[0] = 1;
   for(int i = 0 ; i<= 500005;i++){
      power[i+1] = (power[i]*base)%mod;
   }
}


ll hashValBetween(int i , int j,ll hashVal[]){
    return (hashVal[j] - (hashVal[i-1]*power[j-i+1])%mod + mod)%mod; // 1 based indx
}


class HashClass{
       public:
          long long hashVal[N],power[N],base,mod,SZ;
       HashClass(){
            SZ = N-1;
            mod = MOD[0];
            base = BASE[0];
            power[0] = 1;
            hashVal[0] = 0;
            for(int i = 1 ; i<SZ;i++)
                 power[i]=(power[i-1]*base)%mod;
       }

       void hashFuntion(string s){
            for(int i = 0 ; i< s.size();i++)
                hashVal[i+1] = (hashVal[i]*base+s[i])%mod; // 1 base indx
       }

       long long hashValBetween(int i ,int j){
           long long ret = (hashVal[j]-hashVal[i-1]*power[j-i+1])%mod; // 1 based indx
           return (ret+mod)%mod;
       }
};



AHO CORASICK ::::::::::::::::::::::::: AHO CORASICK

class ahoCorasick{
   #define SIZE 10000
public:
   struct node
   {
       int val;
       int child[26];
       void clear(){
          memset(child,0,sizeof child);
       }
   } trie[SIZE];
   public:
      int nodeNumber, par[SIZE],fail[SIZE],root, mark[SIZE];
   ahoCorasick(){
      root = 0;
      nodeNumber = 0;
      trie[root].clear();
   }
   void addTrie(string s){
        int cur = root;
        for(int i=0;i<s.size();i++){
            int c = s[i]-'a';
            if(trie[cur].child[c] == 0){
                 nodeNumber++;  // new create node number
                 trie[nodeNumber].clear();
                 trie[cur].child[c] = nodeNumber;
                 trie[nodeNumber].val = c;
            }
            cur = trie[cur].child[c];
        }
        mark[cur]++;
        // do something to mark end of string
   }


   void calFail(){
       queue < int > q;
       q.push(0);
       while(!q.empty()){
           int u=q.front();
           q.pop();
           for(int i = 0 ; i<26;i++){
              int v = trie[u].child[i]; // v is chiled node number
              if(v){
                  q.push(v);
                  par[v] =u;
              }
           }
           if(u==0){
               // if root
               fail[u] =0;
               par[u]=0;
               continue;
           }

           int p = par[u]; //u er parent
           int f = fail[p]; // parent er failuer
           int letter = trie[u].val; // letter er value
           while(f && trie[f].child[letter]==0){
               f = fail[f]; // joto khon porjonto failuer value pabo na
           }

           fail[u] = trie[f].child[letter]; // node number
           if(fail[u] == u) fail[u] = 0;
       }
   }

   int gotoState(int state , int c){
        if(trie[state].child[c])
            return trie[state].child[c];
        cout << "debug" << endl;
        int f = fail[state];
        while(f && trie[f].child[c] ==0){
            f = fail[f];
        }

        return trie[f].child[c];
   }
};



void initGlobalParent(){
   for(int i = 0 ; i< 180 ; i++)
      golobalParent[i]=i;
}


AHO CORASICK ::::::::::::::::::: POINTER :::::::::::::::::::::::: AHO CORASICK


class ahoCorasik{
    public:
  struct node
  {
     int mark ;
     char val;
     node *child[26];
     node *fail;
     node(){
        mark = 0;
        for(int i = 0 ; i< 26 ; i++)
            child[i] = NULL;
     }
  } *root;

  ahoCorasik(){
    root = new node();
  }
    void addTrie(char s[], int indx){
      node *cur = root;
      for(int i = 0 ; s[i] ; i++){
        int c = s[i]-'a';
        if(cur -> child[c] == NULL){
           cur -> child[c] = new node();
        }
        cur = cur -> child[c];
        cur -> val = s[i];
      }
      cur -> mark = indx;
    }

    void calFail(){
      root -> fail = NULL;
      queue < node* > q;
      q.push(root);
      while(!q.empty()){
        node *u = q.front();
        q.pop();
        for(int i = 0 ; i< 26 ; i++){
            node *v;
            v = u -> child[i];
            if(v==NULL) continue;
            q.push(v);
            node *p = u -> fail;
            while(p != NULL && p->child[i]==NULL){
                 p = p-> fail;
            }
            if(p==NULL)
              u -> child[i] -> fail = root;
            else u-> child[i]-> fail = p->child[i];

        }
      }
    }

    void del(node *u){
      for(int i = 0 ; i<26 ; i++){
         if(u->child[i])
          del(u->child[i]);
      }
      delete u;
    }

    void clear(){
        del(root);
        root = new node();
    }


    int searchFunction(char s[]){
      node *cur = root;
      int counter = 0;
      for(int i = 0 ; s[i] ; i++){
          int c = s[i]-'a';
          while(cur->child[c]==NULL && cur != root){
              cur = cur -> fail; // if not exit goto fail state where sucessfull
              }
          if(cur-> child[c]==NULL)
             cur = root;
          else cur = cur-> child[c];

          node *temp = cur;
          while(temp != root){
                  if(temp-> mark){
                    // cout << s[i] << ' ' << i  << ' ' << temp-> mark << endl;
                    res[temp->mark]++; //res is global counter arr 
                    counter++;
                  }

                  temp = temp-> fail;
          }
      }
      return counter;
    }


};



K-TH  SEGMENT TREE :::::::::::: K-TH SEGMENT TREE

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define NN 30005
std::vector<ll > tree[4*NN];
ll a[NN];
void update(int node,int b,int e){
   int left = 2*node;
   int right = left+1;
   int m = (b+e)/2;
   if(b == e){
     tree[node].push_back(a[b]);
     return;
   }
   update(left,b,m);
   update(right,m+1,e);
   int len1 = tree[left].size();
   int len2 = tree[right].size();
   tree[node].resize(len1+len2); // **must care about it
   merge(tree[left].begin() , tree[left].end() , tree[right].begin(), tree[right].end() , tree[node].begin());
   return;
}

int  query(int node,int b,int e, int i , int j, int key){
    int m = (b+e)/2;
    int left = 2*node;
    int right = left+1;
    if( b > j || e < i) return 0;
    if( b >= i && e <= j){
       int pos = upper_bound(tree[node].begin() , tree[node].end() , key) - tree[node].begin();
       return tree[node].size()-pos;
    }
    int p1 = query(left,b,m,i,j,key);
    int p2 = query(right,m+1,e,i,j,key);
    return p1+p2;
}




BINARY INDEX TREE BINARY SEARCH :::::::: BIT

int find(int x){
   int ret = 0, num = 0;
   for(int i = 20 ; i>= 0 ; i--){ // i = log2(N)
      ret += (1<<i);
      if(ret >= N || num + tree[ret] >= x) // >= means x theke soto upper bound
        ret -= (1<<i); // not taken this fragment
      else
        num += tree[ret]; // taken this fragment
   }
   return ret+1;  // explain before
}



UNORDERED SET ::::::::::: UNORDERED SET

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
// #ifdef __mr__
//     #include "prettyprint.hpp"
// #endif
#define endl                        ('\n')
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using orderset = tree<
    T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;


orderset< int > s;
s.insert(5);
s.erase(5);
*s.find_by_order(n - 1); // find the n th element
pos = s.order_of_key(k); // how many number are less than k



SQURE ROOT DECOMPRESSION :::::::::::::: KTH NUMBER

#define N 1000005
#define ll long long
ll block = 550;
ll a[N];
std::vector< ll > v[550];

int query(ll l , ll r ,  ll x){
     ll res = 0 , i;
     for( i = l ; i<= r && i%block ; i++)
         res += (a[i] < x);
     for(  ; i+block <= r ; i+=block){
         int t = i/block;
         int tt = lower_bound(v[t].begin(),v[t].end(),x)-v[t].begin();
         res += tt;
     }
     for( ; i <= r ; i++)
         res += (a[i]<x);
     return res;

}
void update(int indx , ll val){
    int blockNo = indx/block;
    int pos = lower_bound(v[blockNo].begin(),v[blockNo].end(),a[indx])-v[blockNo].begin();
    a[indx] = val;
    v[blockNo][pos]=val;
    sort(v[blockNo].begin(),v[blockNo].end());
}

void blockGenarate(){
    for(int i = 0 ; i< n ; i++){
       scanf("%lld",&a[i]);
       v[i/block].push_back(a[i]);
    }
    for(int i = 0 ; i< block ; i++){
       sort(v[i].begin() , v[i].end());
    }
}



2D BIT :::::::::::::::: 2D BINARY INDEX TREE

int sum(int x , int y){
  int ret = 0;
  while(x){
    int indx = y;
    while(indx){
      ret += tree[x][indx];
      indx -= indx & -indx;
    }
    x -= x &-x;
  }
  return ret;
}

void update(int x , int y , int val){
     while(x <= mmax){
       int indx = y;
       while(indx <= mmax){
         tree[x][indx] += val;
         indx += indx & -indx;
       }
       x += x & -x;
     }
}



nCr ::::::::::::::::::: ncr up to 10^6

long long ncr(long long n , long long r){
    long long ret =  fac[n];
    ret = (ret*modInverse(fac[r],MOD))%MOD;
    ret = (ret*modInverse(fac[n-r],MOD))%MOD;
    return ret;
}


MATRIX ::::::::::::::::: MATRIX MULTIPLICATION

matrix mul(matrix a,matrix b){
     matrix c;
     c.row=a.row;
     c.clm=b.clm;
    for(int i=0;i<c.row;i++)
     for(int j=0;j<c.clm;j++){
         c.mat[i][j]=0;
         for(int k=0;k<a.clm;k++)
              c.mat[i][j]=(c.mat[i][j]+(a.mat[i][k]%M*b.mat[k][j]%M)%M)%M;
     }
     return c;
}


OVERFLOW CHECK :::::::::::::::: OVERFLOW CHECK

/* this function calculates (a*b)%c taking into account that a*b might overflow */
long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}



GAUSS-JORDAN :::::::::::::::::::::::::: GAUSS

Gauss-Jordan Elimination
 
n = number of linear equations
m = number of variables
ar[i][m] = right-hand side value of constants
 
For instance, the system of linear equations becomes:
 
2x + y -z = 8      ----->  (i)
-3x -y + 2z = -11  ----->  (ii)
-2x + y + 2z = -3  ----->  (iii)
 
n = 3 (x, y, z), m = 3 (i, ii, iii)
ar[0] = {2, 1, -1, 8}    ----->  (i)
ar[1] = {-3, -1, 2, -11} ----->  (ii)
ar[2] = {-2, 1, 2, -3}   ----->  (iii)
 
 
Returns -1 when there is no solution
Otherwise returns the number of independent variables (0 for an unique solution)
Contains a solution in the vector res on successful completion
Note that the array is modified in the process
 
***/
 
int n, m;
double ar[MAXROW][MAXCOL];
 vector <double> res;
int hit[105];
 
 
int gauss(int n, int m, double ar[MAXROW][MAXCOL], vector<double>& res){
    res.assign(m, 0);
    vector <int> pos(m, -1);
    int i, j, k, l, p, free_var = 0;
 
    for (j = 0, i = 0; j < m && i < n; j++){
        for (k = i, p = i; k < n; k++){
            if (abs(ar[k][j]) > abs(ar[p][j])) p = k;
        }
        if (abs(ar[p][j]) > EPS){
            pos[j] = i;
            for (l = j; l <= m; l++) swap(ar[p][l], ar[i][l]);
 
            for (k = 0; k < n; k++){
                if (k != i){
                    double x = ar[k][j] / ar[i][j];
                    for (l = j; l <= m; l++) ar[k][l] -= (ar[i][l] * x);
                }
            }
            i++;
        }
    }
 
    for (i = 0; i < m; i++){
        if (pos[i] == -1) free_var++;
        else res[i] = ar[pos[i]][m] / ar[pos[i]][i];
    }
 
    for (i = 0; i < n; i++) {
        double val = 0.0;
        for (j = 0; j < m; j++) val += (res[j] * ar[i][j]);
        if (abs(val - ar[i][m]) > EPS) return -1;
    }
 
    return free_var;
}
 

int main(){

    int free_variables;

    /// Example from wikipedia
    n = 3; /// 3 Equations
    m = 3; /// 3 Variables
    ar[0][0] = 2, ar[0][1] = 1, ar[0][2] = -1, ar[0][3] = 8; /// 2x + y -z = 8
    ar[1][0] = -3, ar[1][1] = -1, ar[1][2] = 2, ar[1][3] = -11; /// -3x -y + 2z = -11
    ar[2][0] = -2, ar[2][1] = 1, ar[2][2] = 2, ar[2][3] = -3; /// -2x + y + 2z = -3


    free_variables = gauss(n, m, ar, res);
    printf("Free variables = %d\n", free_variables);
    printf("x = %0.2f\n", res[0]);
    printf("y = %0.2f\n", res[1]);
    printf("z = %0.2f\n", res[2]);

    /// Another example
    n = 1; /// 1 Equation
    m = 3; /// 3 Variables
    ar[0][0] = 1, ar[0][1] = 1, ar[0][2] = 1, ar[0][3] = 10; /// x + y + z = 10

    free_variables = gauss(n, m, ar, res);
    printf("Free variables = %d\n", free_variables); /// 2 free variables (they are assigned 0)
    printf("x = %0.2f\n", res[0]);
    printf("y = %0.2f\n", res[1]);
    printf("z = %0.2f\n", res[2]);


    /// Another example when no solution exists
    n = 1; /// 1 Equation
    m = 3; /// 3 Variables
    ar[0][0] = 0, ar[0][1] = 0, ar[0][2] = 0, ar[0][3] = 10; /// 0 + 0 + 0 = 10, inconsistent

    free_variables = gauss(n, m, ar, res);
    printf("Free variables = %d\n", free_variables); /// -1 implies no valid solution exists

    return 0;
}




MILAR RABIN :::::::::::::::::::: MILAR RABIN



unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long c){
    unsigned long long x = 0,y = a%c;
 
    while(b>0){
        if(b&1) x = (x+y)%c;
        y = (y<<1)%c;
        b >>= 1;
    }
 
    return x;
}
 
unsigned long long pow(unsigned long long a, unsigned long long b, unsigned long long c){
    unsigned long long x = 1, y = a;
 
    while(b>0){
        if(b&1) x = mulmod(x,y,c);
        y = mulmod(y,y,c);
        b >>= 1;
    }
 
    return x;
}
 

 
bool miller_rabin(unsigned long long p, int it){
    if(p<2) return false;
    if(p==2) return true;
    if((p&1)==0) return false;
 
    unsigned long long s = p-1;
    while(s%2==0) s >>= 1;
 
    while(it--){
        unsigned long long a = rand()%(p-1)+1,temp = s;
        unsigned long long mod = pow(a,temp,p);
 
        if(mod==-1 || mod==1) continue;
 
        while(temp!=p-1 && mod!=p-1){
            mod = mulmod(mod,mod,p);
            temp <<= 1;
        }
 
        if(mod!=p-1) return false;
    }
 
    return true;
}

