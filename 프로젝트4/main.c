//
//  main.c
//  프로젝트 4-표준입출력
//
//  Created by SUNJAE on 2022/01/15.


#include <stdio.h>
#include <string.h>
int GetMyString(char buffer[], int limit) // buffer: 문자열을 저장할 배열, limit: 문자열의 최대 길이
{
    int i;
    for (i=0;i<limit;i++) { //최대개수만큼 반복
        buffer[i]=getchar(); // 한개의 문자를 입력받는 getchar 함수를 반복문 처리해서 문자열로 저장
        if (buffer[i]=='\n'){ // enter 입력되면 입력 종료이므로 문자열 완성 후 함수 종료
            buffer[i]=0;// 문자열 끝에 0을 넣어서 완성
            return 1; //1반환(정상 입력됨)
        }
    }
    buffer[i]=0; // 반복문 빠져나옴.-> 입력개수 초과, 현재 위치에 0넣고 문자열 완성
    rewind(stdin); //표준 입력 버퍼에 남아있는 문자들 제거
    return 0; //초과이므로 0 반환
}

int Change(char string[])
{
    int num1=0, count=0;
    while (string[count]!=0&&string[count]!='\n') //fgets함수를 사용할때 문자열 끝에 '\n'이 추가되어서 '\n'도 숫자로 처리하므로 수정
    {
        num1=num1*10+(string[count]-'0');
        count++;
    }
    return num1;
}

void main() {
  //문자 한 개를 입력받는 함수: getchar 함수
    // 문자 한 개씩 2번 입력 받기
/*    int input_data; // char형도 가능
    input_data=getchar(); //표준 입력 함수를 사용하여 문자 한 개를 입력받음
    getchar();
    
    printf("first: %c\n",input_data);
    input_data=getchar(); //변수 중복 사용 가능
    getchar();
    printf("second: %c\n",input_data);
    
    // rewind 함수로 초기화
    input_data=getchar(); //첫번재 문자 입력
    rewind(stdin); // 입력버퍼를 초기화 rewind 함수, stdin포인터
    printf("first: %c\n",input_data); //출력
    
    input_data=getchar();
    rewind(stdin);
    printf("second: %c\n",input_data); */
    
/* getc함수: 표준 입출력, 파일 입출력에 사용 stdin인수 input_data=getc(stdin);
 파일을 열고 해당 파일의 포인터를 매개변수로 넘김-> 파일에서 1바이트씩 읽어서 전달
 표준입출력 주소를 넘김-> 문자 한개씩 출력 가능 */
    
    
//문자열을 입력받는 gets함수: 매개변수로 char배열로 선언된 변수의 시작 주소 넘김.
// gets 함수로 문자열 입력받기 (오류 시 fgets 함수 사용)
 /* char input_string[10];
    fgets(input_string,10,stdin); // 문자열을 입력받아 input_string 변수에 저장, 문자열 메모리 최대크기(enter값 포함), 표준 입력 장치를 뜻하는 stdin 사용
    printf("string: %s\n",input_string);
  
    // 입력 취소 처리: 정상적으로 입력X: NULL 값 반환 , 정상: 문자열의 시작 주소 반환 */
 /*   char input_string[10];
    if (NULL!= fgets(input_string,10,stdin))
        printf("input: %s\n",input_string);
    else printf("input-> Cancled\n"); */
    
    // gets 함수에서 키 입력 횟수 제한하기 -> 프로그램의 비정상적 종료 방지 (GetMyString함수)
    char temp[10];
    int state;
    state=GetMyString(temp, 9); // 최대 9개까지만 받는다, state: 반환값이 저장됨
    
    if (state==1) printf("input: %s\n",temp); //정상 입력된 경우
    else printf("input: %s -> out of range\n",temp); //입력 개수가 초과된 경우
    
    // 문자열을 정수로 변환-> 연산 가능
    int pos_num=100,i,temp_num,num=0;
    char string[4]="123";
    
    for (i=0;i<3;i++) {
        temp_num = string[i]-'0';
        num=num+temp_num * pos_num;
        pos_num=pos_num/10;
    }
    printf("%d\n",num);
   
    /*길이 제한 없이 문자열 형식의 숫자를 정수로 변환(1)
    int posNum=1, Num=0, count,j ;
    char num_string[4]="123";
    count=strlen(num_string);
    for (j=0;j<count-1;j++) posNum=posNum*10; // 문자열의 길이보다 1작은만큼 반복해서 posNum 10배씩 증가.
    for (j=0;j<count;j++){
        Num=Num+(num_string[j]-'0')*posNum;
        posNum=posNum/10;
        }
    printf("%s->%d\n",num_string,Num);
    //(2)
    int num2=0,count2=0;
    char num_string2[4]="123";
    while (num_string2[count2]!=0) { //문자열이 끝날때까지 반복 0:아스키코드
        num2=num2*10+(num_string2[count2]-'0');
        count2++; //다음 문자로 이동
    }
    printf("%s->%d\n",num_string2,num2); */
    
    //fgets함수를 사용해 두 개의 숫자를 입력받아 합산하기 (Change함수)
    int result=0;
    char str1[16],str2[16];
    printf("input first number:");
    fgets(str1, 16, stdin); //첫번째 문자열 입력
    printf("input second number:");
    fgets(str2, 16, stdin); //두번째 문자열 입력
    result=Change(str1)+Change(str2); //결과
    printf("%d+%d=%d\n",Change(str1),Change(str2),result);
    
    //atoi 함수 이용하면 같은 결과 -> <stdlib.h> 헤더
    
//scanf 함수- 정수 두개 입력받아 더하는 프로그램
    int int_data1,int_data2;
    
    
    printf("첫번째 정수 입력:");
    scanf("%d",&int_data1); //&: 각 변수의 주소를 알려줌
    
    printf("두번째 정수 입력:");
    scanf("%d",&int_data2); // 줄바꿈 기호 넣지X
   
    printf("%d+%d=%d\n",int_data1,int_data2,int_data2+int_data1);
    
    // 공백 문자로 구분해서 8,10,16진수 입력받기
    int n1,n2,n3;
    scanf("%o %d %x",&n1,&n2,&n3); //입력 받은 수를 각 형태에 맞게 변환하여 각 변수에 저장
    printf("%d %d %d\n",n1,n2,n3);
    
    // 사용자의 잘못된 입력 처리하기-나이 입력 받기
    int num3=0;
    while(1) {
        printf("input age:");
        if (scanf("%d",&num3)==0) {
            rewind(stdin);
            printf("[Enter] digit number!\n");
        }
        else if (num3>0 && num3<=130){
            break;}
        else {
            printf("Incorrect Age!\n");
        }
    }
    printf("your age: %d\n",num3);

    
// 연습문제 1
    int n4,n5,n6;
    
    
    
    printf("세 개의 정수 입력:");
    scanf("%d %d %d",&n4,&n5,&n6);
    
    printf("평균: %f\n",(n4+n5+n6)/3.0);
    
// 연습문제 2
    rewind(stdin);
    char data1[32],data2[32];
    int lenth; // fgets함수는 뒤에 \n을 포함하므로 잘라야 함
    
    printf("first string:");
    fgets(data1,32,stdin);
    printf("second string:"); //줄바꿈 x
    fgets(data2, 32, stdin);
    
    lenth=strlen(data1);
    
    if (lenth>0) data1[lenth-1]=0; // \n제거
    strcat(data1, data2);
    printf("%s\n",data1);
    
//연습문제 3
    rewind(stdin);
    char 이름[4],혈액형;
    int 심박수;
    float 키,몸무게;
    scanf("%s %01f %01f %c %d",&이름,&몸무게,&키,&혈액형,&심박수);
    printf("이름:%s,몸무게:%fkg,키:%fcm,혈액형:%c형,심박수:%d회\n",이름,몸무게,키,혈액형,심박수);
    
    
    
    
}
