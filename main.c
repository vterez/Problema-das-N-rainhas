#include <stdio.h>
#include <stdlib.h>

void printa(int n,int *mat){
    int a=0; while (a<n){printf("Mat %d ",mat[a]);a++;}printf("\n");
}

void reseta(int b,int n,int *mat, int *back){
    int a=b+1;int c;while (a<n){if(mat[a]!=-1){c=mat[a];back[c]=-1;};mat[a]=-1;a++;}
}

int linha(int a, int *mat, int n, int *c){
    if(a<n){int b=mat[a]+1;//printf("A %d MAT %d \n",a,mat[a]);
    if(a==0){if(b<n){c[b]=a;return b;}else return -2;}
    else while(b<n){if(c[b]==-1){
            if(mat[a-1]==b-1)b++;else if(mat[a-1]==b+1)b+=3;else {c[b]=a;return b;}}
    else b++;};}
    return -2;
}

int diagonal(int *mat, int n){
    int b=1,c=0;
    while(c<n){ while(b<n){
        if(mat[b]-mat[c]==b-c||mat[b]-mat[c]==c-b) {return 0;} else b++;};c++;b=c+1;
} return 1;}

void aloca(int a, int *mat, int n,int *back){
    int c=a,b;
    if(a==n){ if(diagonal(mat,n)==1){printa(n,mat);back[n]++;printf("%d\n",back[n]);}}
    b=linha(c,mat,n,back);
   while(b!=-2) {if(mat[a]!=-1){
        if(back[mat[a]]!=-1)back[mat[a]]=-1;};mat[a]=b;aloca(a+1,mat,n,back);
   b=linha(c,mat,n,back);}
    if(c>0&&b==-2){c--;reseta(c,n,mat,back);}
    }


int main()
{   int n;
    scanf("%d",&n);
    int *mat=(int*)malloc(n*sizeof(int));
    int *back=(int*)malloc((n+1)*sizeof(int));
    int a=0;
    while (a<n){

            mat[a]=-1;
            back[a]=-1;
        a++;
    };
    back[n]=0;

    a=0;
    aloca(0,mat,n,back);

    return 0;
}
