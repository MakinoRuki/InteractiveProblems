#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;
int t, b;
int res[N];
int main() {
    scanf("%d%d", &t, &b);
    for (int cas=1; cas <= t; ++cas) {
        int l = 1, r = b;
        int cnt=0;
        int sp = -1;
        int dp = -1;
        bool flip = false;
        bool rev = false;
        while(l < r) {
            if (cnt>0 && (cnt%10==0)) {
                printf("%d\n", (sp>=0 ? sp : 1));
                fflush(stdout);
                char v[2];
                scanf("%s", v);
                if (sp >= 0 && v[0]-'0' != res[sp]) flip = true;
                cnt++;
                printf("%d\n", (dp>=0 ? dp : 1));
                fflush(stdout);
                scanf("%s", v);
                if (dp>=0) {
                    if (v[0]-'0' != res[dp]) {
                        rev = !flip;
                    } else {
                        rev = flip;
                    }
                }
                cnt++;
                if (flip) {
                    for (int i = 1; i < l; ++i) {
                        res[i] ^= 1;
                    }
                    for (int i = r+1; i <= b; ++i) {
                        res[i] ^= 1;
                    }
                }
                if (rev) {
                    int j1 = 1; 
                    int j2 = b;
                    while(j1 < l && j2 > r) {
                        swap(res[j1], res[j2]);
                        j1++;
                        j2--;
                    }
                }
                flip = false;
                rev = false;
            }
            char v1[2], v2[2];
            printf("%d\n", l);
            fflush(stdout);
            scanf("%s", v1);
            cnt++;
            printf("%d\n", r);
            fflush(stdout);
            scanf("%s", v2);
            cnt++;
            if (v1[0] == v2[0] && sp < 0) sp = l;
            if (v1[0] != v2[0] && dp < 0) dp = l;
            res[l++] = v1[0]-'0';
            res[r--] = v2[0]-'0';
        }
        for (int i = 1; i <= b; ++i) {
            printf("%c",res[i]+'0');
        }
        printf("\n");
        fflush(stdout);
        char resp[2];
        scanf("%s", resp);
    }
    return 0;
}
