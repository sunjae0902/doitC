//
//  main.c
//  플젝8
//
//  Created by SUNJAE on 2022/02/10.
//함수 포인터를 사용하여 같은 형식의 함수를 반복문으로 호출하기

#include <stdio.h>
int Sum(int a, int b){
    return a+b;
}
int Sub(int a, int b){
    return a-b;
}

int Mul(int a, int b){
    return a*b;
}

int Div(int a, int b){
    return a/b;
}


int main() {
    
    int (*p[4])(int, int)={&Sum,&Sub,&Mul,&Div};
    char op_table[4]={'+','-','*','/'};
    for (int i=0;i<4;i++){
        printf("%d %c %d = %d\n",8,op_table[i],2, (*p[i])(8,2));
    }
    
    return 0;
}
