#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int v;
    struct no *e,*d;
}no;

no* ins(no *r,int v){
    if(!r){
        r=(no*)malloc(sizeof(no));
        r->v=v;
        r->e=r->d=NULL;
    }else if(v<r->v) r->e=ins(r->e,v);
    else r->d=ins(r->d,v);
    return r;
}

int f1,f2,f3;

void preo(no *r){
    if(!r) return;
    if(!f1) printf(" ");
    printf("%d",r->v);
    f1=0;
    preo(r->e);
    preo(r->d);
}

void ino(no *r){
    if(!r) return;
    ino(r->e);
    if(!f2) printf(" ");
    printf("%d",r->v);
    f2=0;
    ino(r->d);
}

void posto(no *r){
    if(!r) return;
    posto(r->e);
    posto(r->d);
    if(!f3) printf(" ");
    printf("%d",r->v);
    f3=0;
}

int main(){
    int c,n,v;
    scanf("%d",&c);
    for(int i=1;i<=c;i++){
        scanf("%d",&n);
        no *r=NULL;
        for(int j=0;j<n;j++){
            scanf("%d",&v);
            r=ins(r,v);
        }
        printf("Case %d:\n",i);
        printf("Pre.: ");
        f1=1;
        preo(r);
        printf("\nIn..: ");
        f2=1;
        ino(r);
        printf("\nPost: ");
        f3=1;
        posto(r);
        printf("\n\n");
    }
    return 0;
}
