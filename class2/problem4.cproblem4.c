#include<stdio.h>
#include<string.h>
#include<ctype.h>
void func(char* str){
    int state = 0;
    int len= strlen(str);
    if(str[len-1]=='\n'){
        str[len-2]='\0';
    }
    for(int i=0;str[i]!='\0';i++){
        char ch=str[i];
        if(isdigit(ch)){
            if(state==0 || state == 1){
                state =1;
            }
            else if(state ==2 || state ==3){
                state =3;
            }
            else if(state==4 || state==5 || state == 6){
                state = 6;
            }
        }


        else if(ch=='.'){
            if(state ==1){
                state = 2;
            }
            else{
                state=-1;
            }
        }
        else if(ch=='E'){
            if(state==1|| state ==3){
                state=4;
            }
            else{
                state=-1;
            }
        }
        else if((ch=='+'||ch=='-') && state ==4){
            state = 5;
        }
        else {
            state=-1;
            break;
        }
        if(state == -1){
            break;
        }
    }
    if(state ==1){
        printf("Integer Number\n");
    }
    else if(state ==3){
        printf("Floating point number\n");
    }
    else if(state == 6){
        printf("floating number with exp\n");
    }
    else{
        printf("Invalid\n");
    }

}
int main(){
    FILE *fp=fopen("problem4.txt","r");
    if(fp==NULL){
        printf("Unable to open file");
        return 1;
    }
    char str[50];
    while(fgets(str,sizeof(str),fp)){
        func(str);
       // printf("%s",str);
    }
    fclose(fp);
}
