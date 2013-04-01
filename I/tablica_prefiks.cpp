#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char txt[1000010];
int pref[1000010];

void PREF(char *t, int d, int *pre){
 int k = pre[0] = 0;
 t[d] = '#';
 for(int i=1;i<=d-1;i++){

  if(k + pre[k] > i) pre[i] = min(pre[i-k], pre[k] - i + k);
  else pre[i] = 0;

  while(t[pre[i]] == t[pre[i] + i]) pre[i]++;

  if(i + pre[i] > k + pre[k]) k = i;
 }
}

int main(){
 scanf("%s",txt);
 int d = strlen(txt);
 PREF(txt,d,pref);
  for(int i=0;i<d;i++) printf("%d ",pref[i]); printf("\n");
 return 0;
}
