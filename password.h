//password
#include<iostream>
#include<conio.h>
using namespace std;
class password{
    private:
    int i=0;
    char pass[100];
    public:
    char ch;
    char* passw(){
        while((ch=getch())!=13){
            if(ch==8){
                if(i==0){}
                else{
                    printf("\b \b");
                    i--;
                }
            }
            else{
                printf("*");
                pass[i]=ch;
                i++;
            }
        }
        pass[i]='\0';
        //cout<<endl<<pass<<endl;
        return pass;
    }
};
