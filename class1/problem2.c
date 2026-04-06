// Write a C program to identify valid or invalid variables in a file
#include<stdio.h>
#include<stdbool.h>
int main(){
    FILE *fptr;
    fptr=fopen("problem2.txt","w");
    char ch;
    while((ch=getchar())!='~'){
        fputc(ch,fptr);
    }
    fclose(fptr);
    char line[100];
    bool flag=true;
    while(fgets(line,sizeof(line),fptr)){
        if(line[0]>=97&&line[0]<=122){
            flag=true;
        }
        else{
            flag=false;
        }
        for(int i=0;i<100;i++){
            if(line[i]=='\n'){
                flag=false;
            }
        }
        if(flag){
            printf("valid");
        }
        else{
            printf("Invalid");
        }
    }
    fclose(fptr);

}
