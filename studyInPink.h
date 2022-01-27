/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

bool exist_80(int P[20]){
    size_t k=(&P)[1]-P;
    for(int i=0;i<k;i++){
        if(P[i]==80) break;
        if(i==k-1) return false;
    }
    return true;
}
int reset_hp(int k){
    if(k<0) return 0;
    else if(k>999) return 999;
    else return k;
}
int reset_m(int k){
    if(k<0) return 0;
    else if(k>2000) return 2000;
    else return k;
}

int reset_exp(int k){
    if(k<0) return 0;
    else if(k>900) return 900;
    else return k;
}
int firstMeet(int& EXP1, int& EXP2, const int& E1){
    //Complete this function to gain point on task 1
    
    //Reset value of EXP1,EXP2,E1
    
    
    
    
    //E1 trong [0,399]
    if(0<=E1 && E1<=399){
        if(0<=E1 && E1<=49) {EXP2+=25;EXP2=reset_exp(EXP2);}//1
        if(50<=E1 && E1<=99) {EXP2+=50;EXP2=reset_exp(EXP2);}
        if(100<=E1 && E1<=149) {EXP2+=85;EXP2=reset_exp(EXP2);}
        if(150<=E1 && E1<=199) {EXP2+=25+50;EXP2=reset_exp(EXP2);}
        if(200<=E1 && E1<=249) {EXP2+=25+85;EXP2=reset_exp(EXP2);}
        if(250<=E1 && E1<=299) {EXP2+=50+85;EXP2=reset_exp(EXP2);}
        if(300<=E1 && E1<=399) {EXP2+=25+50+85;EXP2=reset_exp(EXP2);}

        if(E1%2==1){
            EXP1=reset_exp(int(ceil(EXP1+E1/10.0)));//1
            
        }else if(E1%2==0){
            EXP1=reset_exp(int(ceil(EXP1-E1/5.0)));//1
            
        }
        return EXP1+EXP2;
    }    
    
    //E1 trong [400,999]
    if(400<=E1 && E1<=999){
        if (400<=E1 && E1<=499) {EXP2=reset_exp(int(ceil(EXP2+(E1/7.0)+9.0)));}
        if (500<=E1 && E1<=599) {EXP2=reset_exp(int(ceil(EXP2+(E1/9.0)+11.0)));}
        if (600<=E1 && E1<=699) {EXP2=reset_exp(int(ceil(EXP2+(E1/5.0)+6.0)));}
        if (700<=E1 && E1<=799){
            EXP2=reset_exp(int(ceil(EXP2+(E1/7.0)+9.0)));
            
            if(EXP2>200){
                EXP2=reset_exp(int(ceil(EXP2+(E1/9.0)+11.0)));
                
            }
        }
        if (800<=E1 && E1<=999){
            EXP2=reset_exp(int(ceil(EXP2+(E1/7.0)+9.0+(E1/9.0)+11.0)));
            
            if(EXP2>600){
                EXP2=reset_exp(int(ceil(EXP2+(E1/5.0)+6.0)));
                EXP2=reset_exp(int(ceil(EXP2*1.15)));
            }
        }
        EXP1=reset_exp(int(ceil(EXP1-0.1*E1)));
        
        return EXP1+EXP2;       
    }
    return -999;
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    //Complete this function to gain point on task 2

    double d1,d2,d;
    d1=(E2/9)+10;
    d2=0.35*E2;
    
    EXP1=reset_exp(EXP1);
    EXP2=reset_exp(EXP2);
    HP2=reset_hp(HP2);
    M2=reset_m(M2);

    if(0<=E2 && E2<=999){
        if(0<=E2 && E2<=299) {d=d1;}
        if(300<=E2 && E2<=499) {d=d1+d2;}        
        if(500<=E2 && E2<=999) {d=1.17*(d1+d2);}
        if(E2%2==0) M2=reset_m(int(ceil(M2+pow(E2,2)/50)));        
        EXP2=reset_exp(int(ceil(EXP2+d)));
        EXP1=reset_exp(int(ceil(EXP1+d/3)));
        HP2=ceil(HP2-pow(E2,3)/pow(2,23));   
        return EXP2+HP2+M2+EXP1;
    }
    return -999;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    //Complete this function to gain point on task 3
    if(E3<0||E3>999) return -999;
    EXP1=reset_exp(EXP1);
    M1=reset_m(M1);
    HP1=reset_hp(HP1);
    //Path 1
    int k=0;
    int P1[9]={1,3,5,7,9,11,13,15,17};
    for(int i=0;i<9;i++){
        P1[i]=(P1[i]+E3)%26+65;
        if(P1[i]==80) k=i+1;
        if (k==0) {
            M1=reset_m(int(ceil(M1-81*E3/9.0)));
        }else{
            HP1=reset_hp(HP1-80*k*2);
            EXP1=reset_exp(int(ceil(EXP1+(1000-80*k)%101)));
            M1=reset_m(int(ceil(M1-k*E3/9.0)));
        }   
    }
    
    //Path 2
    k=0;
    int P2[7]={2,3,5,7,11,13,17};
    int s=0,m;
    for(int i=0;i<7;i++){
        P2[i]=(P2[i]+E3)%26;
        s+=P2[i];
    }
    m=ceil(s/7.0);//cast data tye
    for(int i=0;i<7;i++){
        P2[i]=(P2[i]+s+m)%26+65;
        if(P2[i]==80) k=i+1;
        if(k==0){
            M1=reset_m(int(ceil(M1-49*E3/9.0)));

        }else{
            HP1=reset_hp(HP1-80*k*2);
            EXP1=reset_exp(int(ceil(EXP1+(1000-80*k)%101)));
            M1=reset_m(int(ceil(M1-k*E3/9.0)));
        }
    }
    
    //Path 3
    k=0;
    int P3[20];
    int max=0;
    //gan so vao mang
    for(int i=0;i<20;i++){
        P3[19-i]=(2*(i+1))*(2*(i+1));        
    }
    //bien doi lan 1
    for(int i=0;i<20;i++){
        P3[i]=(P3[i]+E3*E3)%113;
    }
    //tim max
    for(int i=0;i<20;i++){
        if(max<P3[i]){
            max=P3[i];
        }       
    }
    //bien doi lan 2
    //Ver khác
    for(int i=0;i<20;i++){
        P3[i]=int(ceil(double(P3[i]+E3)/max))%26+65;
        if(P3[i]==80){
            k=i+1;
            HP1=reset_hp(HP1-P3[i]*k*3);
            EXP1=reset_exp(int(ceil(EXP1+(3500-P3[i]*k)%300)));
            M1=reset_m(int(ceil(M1-k*E3/9.0)));
            break;
        }
        if(i==19) M1=reset_m(int(ceil(M1-400*E3/9.0)));
    }
     
    
    
    
    //Path 4
    k=0;
    int P4[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int min,min_idx;
    for(int i=0;i<12;i++){
        P4[i]=int(P4[i]+pow(ceil(E3/29.0),3))%9;
        if(min>P4[i]){
            min=P4[i];
            min_idx=i+1;
        }
    }
    for(int i=0;i<12;i++){
        P4[11-i]=(P4[i]+E3)*int(ceil((min/min_idx)))%26+65;            
    }
    for(int i=0;i<12;i++){
        if(P4[i]==80){
            k=i+1;
            HP1=reset_hp(HP1-P4[i]*k*4);
            EXP1=reset_exp(int(ceil(EXP1+(4500-P4[i]*k)%400)));
            break;
        }
    }
    if(!exist_80(P1)&&!exist_80(P2)&&!exist_80(P3)&&!exist_80(P4)){
        HP1=reset_hp(HP1-(59*E3)%900);
        EXP1=reset_exp(EXP1-(79*E3)%300);
        return -1;
    }




    


    return HP1+EXP1+M1;
}
//them ham reset_hp

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
