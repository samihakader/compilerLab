//opening file
#include<stdio.h>
int main(){
     FILE *fptr;
    fptr=fopen("basics.txt","w");
    if(fptr==NULL){
        printf("File not opened");
        return 1;
    }
    // char text[200];
    // fgets(text,sizeof(text),stdin);
    // fputs(text,fptr);
    // fclose(fptr);
    //input
    char ch;
    while((ch=getchar())!= '~'){
        fputc(ch,fptr);
    }
    fclose(fptr);
    //output
    //reading
    fptr=fopen("basics.txt","r");
    while((ch=fgetc(fptr))!=EOF){
        putchar(ch);
    }
    fclose(fptr);
    return 0;
}