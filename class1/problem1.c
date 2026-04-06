// write a C program that scans and counts the number of charecters,words and lines in a file
#include<stdio.h>
int main()
{
   FILE *fptr;
   fptr=fopen("problem1.txt","w");
   if(fptr==NULL){
    printf("Error");
    return 1;
   }
   char ch;
   while((ch=getchar())!='~'){
    fputc(ch,fptr);
   }
   fclose(fptr);
   // open for reading
   int cha=0,w=1,line=1;
   fptr=fopen("problem1.txt","r");
   while((ch=fgetc(fptr))!=EOF){
        if(ch!=' '){
            cha++;
        }
        if(ch=='\n'){
            cha--;
        }
        if(ch==' '||ch=='\n'){
            w++;
        }
        if(ch=='\n')
        line++;
   }
   fclose(fptr);
   printf("Characters : %d\n",cha);
   printf("Words : %d\n",w);
   printf("Lines : %d\n",line);
   return 0;
}