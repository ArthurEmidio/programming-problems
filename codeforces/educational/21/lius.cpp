#include <bits/stdc++.h>

#define INF 2139062143
#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i= int(ini); i<(int)lim; ++i)
#define ford(i, ini, lim) for(int i= int(ini); i>=(int)lim; --i)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
ll arr[100005];
int n; ll sum;
int main(){
    scanf("%d", &n);
    fori(i,0,n){
        scanf("%lld", &arr[i]);
        sum += arr[i];
    }
    if(sum&1 || n==1){
        printf("NO\n");
        return 0;
    }
    ll cur = 0;
    set<ll> s;
    fori(i,0,n){
        cur += arr[i];
        s.insert(arr[i]);
        if(cur > sum/2){
            ll dx = cur - sum/2;
            if(s.find(dx) != s.end()){
                printf("YES\n");
                return 0;
            }
        }
        else if(cur == sum/2){
            printf("YES\n");
            return 0;
        }
    }
    reverse(arr,arr+n);
    cur = 0;
    s.clear();
    fori(i,0,n){
        cur += arr[i];
        s.insert(arr[i]);
        if(cur > sum/2){
            ll dx = cur - sum/2;
            if(s.find(dx) != s.end()){
                printf("YES\n");
                return 0;
            }
        }
        else if(cur == sum/2){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
	return 0;
}
