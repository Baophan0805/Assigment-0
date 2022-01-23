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


int reset_exp(int k){
    if(k<0) return 0;
    else if(k>900) return 900;
    else return k;
}
int firstMeet(int& EXP1, int& EXP2, const int& E1){
    //Complete this function to gain point on task 1
    
    //Reset value of EXP1,EXP2,E1
    EXP1=reset_exp(EXP1);
    EXP2=reset_exp(EXP2);
    
    
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
            EXP1=ceil(EXP1+E1/10.0);//1
            EXP1=reset_exp(EXP1);
        }else if(E1%2==0){
            EXP1=ceil(EXP1-E1/5.0);//1
            EXP1=reset_exp(EXP1);
        }
        return EXP1+EXP2;
    }    
    
    //E1 trong [400,999]
    if(400<=E1 && E1<=999){
        if (400<=E1 && E1<=499) {EXP2=ceil(EXP2+(E1/7.0)+9.0);EXP2=reset_exp(EXP2);}
        if (500<=E1 && E1<=599) {EXP2=ceil(EXP2+(E1/9.0)+11.0);EXP2=reset_exp(EXP2);}
        if (600<=E1 && E1<=699) {EXP2=ceil(EXP2+(E1/5.0)+6.0);EXP2=reset_exp(EXP2);}
        if (700<=E1 && E1<=799){
            EXP2=ceil(EXP2+(E1/7.0)+9.0);
            EXP2=reset_exp(EXP2);
            if(EXP2>200){
                EXP2=ceil(EXP2+(E1/9.0)+11.0);
                EXP2=reset_exp(EXP2);
            }
        }
        if (800<=E1 && E1<=999){
            EXP2=ceil(EXP2+(E1/7.0)+9.0+(E1/9.0)+11.0);
            EXP2=reset_exp(EXP2);
            if(EXP2>600){
                EXP2=ceil(EXP2+(E1/5.0)+6.0);EXP2=reset_exp(EXP2);
                EXP2=ceil(EXP2*1.15);EXP2=reset_exp(EXP2);
            }
        }
        EXP1=ceil(EXP1-0.1*E1);
        EXP1=reset_exp(EXP1);
        return EXP1+EXP2;       
    }
    return -999;
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    //Complete this function to gain point on task 2
    return -1;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    //Complete this function to gain point on task 3
    return -1;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
