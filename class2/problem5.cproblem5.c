#include<stdio.h>
int main(){
    FILE *fp=fopen("problem5.txt","r");
    if(fp==NULL){
        printf("Unable to open file");
        return 1;
    }
    char ch,next;
    while((ch=fgetc(fp))!= EOF){
        if(ch=='/'){
            next=fgetc(fp);
            //
            if(next=='/'){
                while((ch=fgetc(fp))!='\n' && ch!=EOF);
                putchar('\n');
            }
            /**/
            else if(next=='*'){
                while(1){
                    ch=fgetc(fp);
                    if(ch=='*' && (next=fgetc(fp))=='/'){
                        break;
                    }
                }
            }
            //comment nh.just /
            else{
                putchar(ch);
                putchar(next);
            }
        }
        else{
            putchar(ch);
        }
    }
    fclose(fp);
}

