//
//  main.c
//  프로젝트 2- 연산자
//
//  Created by SUNJAE on 2022/01/01.
//

#include <stdio.h>
//1바이트에서 원하는 비트만 0으로 변경하고 나머지는 기존값 유지하기: & 연산자 사용
unsigned char ResetBit(unsigned char data, unsigned char bit_num)
{
    if (bit_num<8) data=data&~(0x01<<bit_num);
    return data;
}
//원하는 비트만 1로 변경하고 나머지는 기존 값 유지하기: |연산자 사용
unsigned char SetBit(unsigned char data2, unsigned char bit_num2)
{
    if (bit_num2<8) data2=data2 | ~(0x01<<bit_num2);
    return data2;
}
//특정 비트 값 확인하기
unsigned char GetBit(unsigned char data3,unsigned char bit_num3)
{
    unsigned char bit_state=0;
    if (bit_num3<8) {
        bit_state=data3&(0x01<<bit_num3);
        bit_state=bit_state>>bit_num3;
    }
    return bit_state;
}

//Set,Reset 함수 한번에 사용하기<- value 값이 1이냐 0이냐에 따라 다른 기능 수행
unsigned char ModifyBit(unsigned char Data, unsigned char Bit_num, char value)
{
    char mask;
    mask=0x01<<Bit_num;
    if (value==1) Data=Data | mask;
    else Data=Data&~mask;
    return Data;
}

int ReturnNum()
{
    int num=5;
    return num;
}

void main()
{
    unsigned char lamp_state=0x7F;
    printf("%X->",lamp_state);
    lamp_state=ResetBit(lamp_state, 3);
    printf("%X\n",lamp_state);
    
    unsigned char lamp_state2=0x77;
    printf("%X->",lamp_state2);
    lamp_state2=SetBit(lamp_state2, 3);
    printf("%X\n",lamp_state2);
    
    unsigned char lamp_state3=0x75;
    unsigned char bit_state;
    int i;
    
    printf("%X->",lamp_state3);
    
    for (i=0;i<8;i++) {
        bit_state=GetBit(lamp_state3, 7-i);
        printf("%d",bit_state);
        
    }
    printf("\n") ;
    
    unsigned char Lamp=0x7F;
    printf("%X->",Lamp);
    Lamp=ModifyBit(Lamp, 3, 0);
    printf("%X->",Lamp);
    Lamp=ModifyBit(Lamp, 3, 1);
    printf("%X\n",Lamp);
    
    unsigned char daTa=5; //변수가 짝수인지 홀수인지 판단하는 프로그램ㅇ
    if (daTa&0x01) printf("홀수\n");
    else printf("짝수\n");
    
    
    //지역 변수와 전역 변수 : 새로운 지역변수 num_을 새로 선언, 전역<지역, 중복되지 않게 주의하기
    int num_;
    num_=ReturnNum(num_);
    printf("%d\n",num_);
    
    int j,count=0;
    for (;j<10;j++) {
        if (count==5) count=0; //j나 count가 5가될때마다 .
        printf("%d,",count++); //반복문이 실행될때마다 count도 1씩 증가됨
    }
    
    
    

}
