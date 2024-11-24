#include<stdio.h>
#include<string.h>
void bitstuffing(char *input,int frame_size){
    int i, j=0;
    char stuffed[200];
    int  count=0;
    for(i=0 ;i<strlen(input) ;i++){

        if(input [i]=='1') {
            count++;
        }
        else{
            count =0;
        }
        stuffed[j++]=input[i];
        if(count == 5){
            stuffed[j++]='0';
            count=0;
        }
    }
    stuffed[j++]='\0';
    printf("original data :%s\n",input);
    printf("stuffed data :%s\n",stuffed);
}
int main(){
    int frame_size;
    char data[200];
    printf("enter the frame size:");
    scanf("%d",&frame_size);
    printf("enter the data of frame:");
    scanf("%s",&data);
    bitstuffing(data,frame_size);
    return 0;
}
