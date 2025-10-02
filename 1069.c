
#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        char s[1001];
        scanf("%s", s);
        int stack = 0, ans = 0;
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='<'){
                stack++;
            } else if(s[i]=='>' && stack>0){
                stack--;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
