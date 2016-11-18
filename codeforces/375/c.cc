#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll n, m;
    cin >> n >> m;
    
    vector<ll> playlist(n);
    vector<queue<ll>> songsPlayedByBand(m + 1);
    queue<ll> others;
    set<pair<ll, ll>> values;
        
    for (ll i = 0; i < n; i++) {
        ll band;
        cin >> band;
        playlist[i] = band;
        if (band <= m) {
            songsPlayedByBand[band].push(i);
        } else {
            others.push(i);
        }
    }
    
    for (ll band = 1; band <= m; band++) values.insert(make_pair(songsPlayedByBand[band].size(), band));
    
    ll changes = 0;
    ll minNumber = n / m;
    for (;;) {
        auto minBand = *values.begin();
        if (minBand.first >= minNumber) break;

        ll song;
        if (!others.empty()) {
            song = others.front();
            others.pop();
        } else {
            auto maxBand = *prev(values.end());
            queue<ll> &songs = songsPlayedByBand[maxBand.second];
            song = songs.front();
            songs.pop();
            
            values.erase(maxBand);
            values.insert(make_pair(songs.size(), maxBand.second));
        }
        
        queue<ll> &songs = songsPlayedByBand[minBand.second];
        songs.push(song);
        values.erase(values.begin());
        values.insert(make_pair(songs.size(), minBand.second));

        playlist[song] = minBand.second;
        changes++;
    }
   
    printf("%lld %lld\n", minNumber, changes);
    for (ll i = 0; i < n; i++) {
        printf("%lld ", playlist[i]);
    }
    printf("\n");
    
    return 0;
}
