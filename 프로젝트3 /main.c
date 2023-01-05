//
//  main.c
//  프로젝트3-포인터
//
//  Created by SUNJAE on 2022/01/04.
//

#include <stdio.h>











#include <string.h>
int GetStringLenth(char daTa[]) //daTa변수에 저장된 문자열의 길이를 반환하는 함수
{
    int count=0;
    while (daTa[count]!=0) count++;
    return count;
}

void Test(short DATA)
{
    short soft=0; //초기화
    soft=DATA;
    }

void Test2(short *ptR) // 매개변수로 포인터 변수 ptR선언->main 함수의 Tips 변수 주소를 받음
{
    short Soft=0;
    Soft=*ptR; // 해당 주소에 저장된 값 가져옴 (5) Soft=Tips
    *ptR=3; // Tips=3 // 값 변경가능
}

void swap(int *pa, *pb) // 매개변수로 포인터변수 pa(start),pb(end)설정 , 각각 start, end 의 주소 넘겨받음
{
    int Temp;
    Temp=*pa;  // temp에 start변수에 저장된 값 96 임시 저장 (96 5 96)
    *pa=*pb; // (5 5 96)
    *pb=Temp; //(5 96 96)
}

void Myfun(char *p_char, short *p_short,int *p_int)
{ if (p_char!=NULL) *p_char=1; // 포인터 변수에 NULL 저장: 아직 주소를 저장하지 않고 초기화된 상태, 어떤 형태의 주소가 전달될 지 몰라서 세개의 자료형 추가
  else if (p_short!=NULL) *p_short=1; // 실제로 사용할 포인터 변수에만 변수의 주소값 전달. 나머지는 사용X
  else *p_int=1;
    
}
void Myfun2 (void * p5, char flag)
{ //flag에 전달된 값에 따라 형 변환 후 전달된 주소에 1대입
    if (flag==0) *(char *)p5=1;
    else if (flag==1) *(short*) p5=1;
    else *(int *) p5=1; // flag가 0도 1도 아니면 int *형
    
    
}

int GetData(void *p_data, char type)
{
    int result=0;
    if (type==1) result=*(char*)p_data; // 1바이트만 저장
    else if (type==2) result= *(short *) p_data; //2바이트 저장
    else if (type==4) result=*(int*)p_data; //4바이트 저장
    return result;    // 사용자가 type변수에 지정하는 값에 따라 그 값과 같은 바이트만큼 출력
}

void main ()
{
    //배열과 문자열
    short student [20]; // 자료형 변수명 요소 개수 요소엔 무조건 상수 저장 (자료형이 같은 변수들을 한번에 여러 개 저장) 0~19
  //0번 학생 성적에 100점 저장
   
   
    
    // 쉼표를 사용해 초기화-> 쉼표뒤는 모두 0으로 초기화
    short student2[20]={0,}; //모두 0으로 초기화
    printf("%d",student2[20]);
    
    //배열 요소에 저장된 값 연산
    char data[5]={1,2,3,4,5};
    int result=0,j;
    for (j=0;j<5;j++){
        result+=data[j];
        
    }
    printf("data배열 각 요소의 합은 %d입니다\n",result);
    
    //문자열
    char Data[22]="Don't worry, Be happy!";  //문자열로 자동 저장됨
    printf("%s\n",Data);
    
    // 문자열의 길이 구하는 함수 만들기
    int daTa_length; //문자열의 길이를 저장하는 변수
    char daTa[10]="happy";
    daTa_length=GetStringLenth(daTa);
    printf("daTa length=%d\n",daTa_length);
    
    // c내장 함수 -strlen : 문자열 길이 출력
    int len1=strlen(daTa);
    printf("%d\n",len1);
    // strcpy: 문자열 복사, strcat: 문자열 뒤에 문자열 추가
    char Result[16]; //새로운 문자열을 저장할 변수
    strcpy(Result, daTa); // daTa문자열을 복사해서 Result에 저장
    strcat(Result,"me too"); // Result변수에 새로운 문자열 추가
    printf("%s + me too= %s\n", daTa,Result);
    
    char DAta[6]="Hello";
    char REsult[13]; //메모리 크기 주의
    strcpy(REsult,DAta);
    strcat(REsult," world!");
    printf("%s\n",REsult);
    
    // 2차원 배열
    char DATA[2][3]={{1,2,3},{4,5,6}}; // 2차원 형식, char[4] 형식의 1차원 배열 5개를 묶어 2차원으로 배열
    //[y-1][x-1]: <행을 그룹으로 묶은 경우>, [x-1][y-1] : 열을 그룹으로 묶은 경우
    
    // 1차원 배열을 사용하여 3행 4열 바둑판 정보 저장 후 알려주기
    char bad[12]={0,0,2,1,1,2,2,1,0,1,2,0};
    int i,x,y;
    for (i=0;i<12;i++){
        x=i%4+1; //열 번호: 나머지에 +1
        y=i/4+1; //행 번호: 몫에 +1
        printf("%d행 %d열에",y,x);
        if (bad[i]==1) printf(" 검은 돌이 놓여 있습니다\n");
        else if (bad[i]==2) printf(" 흰 돌이 놓여 있습니다\n");
        else printf(" 바둑 돌이 없습니다\n");
            
    }
  // 2차원 배열을 사용하여 바둑판 정보 저장하고 알려주기
    char Bad[3][4]={{0,0,2,1},{1,2,2,1},{0,1,2,0}}; // 행을 그룹으로 묶어서 2차원 배열로 저장
    int X,Y;
    for (Y=0;Y<3;Y++){ //행
        for (X=0;X<4;X++){ //열
            printf("%d행 %d열에",Y+1,X+1); // +1해주기
            if (Bad[Y][X]==1) printf(" 검은 돌이 놓여 있습니다\n");
            else if (Bad[Y][X]==2) printf(" 흰 돌이 놓여 있습니다\n");
            else printf(" 바둑 돌이 없습니다\n");
        }
    }

    //연습 문제
    //짝수 요소 합 출력
    short datA[9]={4,6,9,8,7,2,5,1,3};
    short hap=0;
    for (i=0;i<9;i+=2) hap=hap+datA[i];
    printf("짝수 요소의 합은 %d\n",hap);
    
    // 요소 중 최대 값 출력
    //int max=0,m;
   
    //for (m=0;m<9;m++) {
        //if (max<data[m]) max=datA[m]; //저장하며 비교
   // }
   // printf("배열에 저장된 요소 중 가장 큰 값은 %d입니다\n",max);
    
    //2차원 배열로 재구성
    char bad2[3][4]={{0,},{0,},{0,},{0,}};
    bad2[1][1]=1;
    bad2[2][3]=2;
    
    //정수 오름차순 정렬-버블 정렬
    int n,m,temp=0;
    int DaTa[7]={6,3,9,7,2,4,1};
    for (n=0;n<6;n++) {
        for (m=0;m<6-n;m++){ //내부 반복문, 인접한것끼리 비교
            if (DaTa[m]>DaTa[m+1]) {
                temp=DaTa[m];
                DaTa[m]=DaTa[m+1];
                DaTa[m+1]=temp; // 자리 바꾸는 명령 수행 과정. 97->77->79
            }
        }
       
    }
   
    for (n=0;n<7;n++) printf("%d,",DaTa[n]);
    printf("\n");
    
    
    // 포인터: 포인터 변수= 메모리 주소. 무조건 4바이트. *: 포인터 변수임을 알려줌. 자료형은 포인터 변수가 아닌 저장된 값의 자료형
    // 변수가 위치한 메모리 주소 출력하기
    short birthday;
    short *ptr=&birthday;// 포인터 선언(*), 포인터 변수에 메모리 주소 저장. &연산자: 변수의 메모리 주소 불러옴
    printf("변수 birthday의 메모리 주소는 %p입니다\n",ptr); //%p형식은 메모리 주소를 16진수 형태로 출력
    
    //다른 변수의 주소를 사용하여 포인터로 값 대입하기
    short birth; //변수 선언
    short *Ptr; // 포인터 변수 선언
    Ptr=&birth; //포인터 변수에 birth변수 메모리 주소 저장
    *Ptr=0x0412; // Ptr포인터가 가리키는 주소의 변수(birth)에 값 대입
    printf("birth=%d (0x%04X)\n",birth,birth); //10진수, 4자리 16진수로 출력
    
    // 간접 주소 지정 방식: 포인터 변수는 같은 함수 내에 없더라도 통용 가능. 메모리 주소로 움직이기 때문
    // 직접: 한계 (같은 함수 내에서만 사용 가능) -> '매개변수' 이용
    // 매개 변수로 다른 함수의 값 받기 (Test 함수)
    short tips=5;
    Test(tips); // Test함수의 DATA 변수 값에 tips 대입-> 함수에서 tips 변수에 저장된 5가 soft 변수에 저장됨. soft=5
    
 // 매개변수로 간접 주소 지정 방식(포인터) 사용하기(Test2함수)
    short Tips=5; //Tips 변수에 5 저장
    Test2(&Tips); // Tips 변수의 메모리 주소가 매개변수 값.
    
// 두변수의 값 서로 바꾸기-> 포인터  이용, swap함수 (직접 방법으로 할 시 지역변수 값은 변경 안되므로 값이 바뀌지않음
    int start=96, end=5;
    printf("before: start=%d, end=%d\n",start,end);
    
    if (start>end) {
        swap(&start, &end); // 변수의 주소를 전달
            }
    printf("after: start=%d, end=%d\n",start,end);

    // * 연산자 사용 주의
    // const 키워드: 주소가 바뀌는 오류 방지
    // 매개변수 선언 시 <int * const pa> 로 선언하면 실수로 * 연산자를 생략하는 경우 오류 발생
    /* const 위치에 따라 다른 사용법
     1. int * const p;
     -> p가 가지고 있는 주소가 변경될 때 오류발생
     2. const int *p;
     -> *p를 사용하여 대상의 값이 변경될 때 오류 발생
     3. const int * const p;
     -> 두 가지 경우 중 하나만 발생해도 오류 발생 */
    
    // 포인터 변수의 주소 연산, 메모리의 시작 주소만 기억하면 됨
    short dt=0;
    short *p=&dt; // 저장된 값의 자료형이 short: 2바이트
    p=p+1; // 포인터  변수에 저장된 주소 값을 1만큼 증가: 포인터가 가리키는 값의 자료형이 2바이트이므로 2바이트 단위로 증가 100번지->102번지에 저장됨
    
    char *p1=(char *)100; // 포인터 변수 p1에 100번지 저장(1바이트 자료형으로 형 변환 )
    char *p2=(short *)100;
    char *p3=(int *)100;
    char *p4=(double *)100;
    p1++; // 1바이트 증가->101번지
    p2++; // 2바이트 증가->102번지
    p3++; // 4바이트 증가->104번지
    p4++; // 8바이트 증가->108번지
    
    // 포인터와 대상의 크기- int형 변수에 저장된 값을 1바이트 단위로 출력하기
    int DT=0x12345678,I; //값 저장
    char *P=(char *)&DT; // p는 char 형이고 DT는 int 형이므로 char형으로 형 변환-> 시작 주소부터 1바이트 크기만 사용
    for(I=0;I<4;I++) { // 1바이트 씩 4번 반복
        printf("%X,",*P);// 1바이트씩 16진수로 출력
        P++; // p가 char * 형이므로 1바이트 뒤에 있는 주소로 값 변경.-> p가 가지고 있는 주소 값을 옮기면서 출력
        
    }
    printf("\n");
    
    // void * 형 포인터: 대상의 크기가 정해져 있지 않을 때, 반드시 형 변환 표현을 사용해 사용할 크기 표기
    int Dt=0;
    void * pp=&Dt;
    * (int *)pp=5; //일시적으로 포인터 변수 pp의 형식이 int* 형이 됨 -> 4바이트 크기로 값 5저장
    
    // (Myfun 함수: main 함수에서 선언한 지역 변수의 주소 값을 매개 변수로 받아 그 주소에 해당하는 메모리에 1대입하는함수)
    short dT=5;
    Myfun(NULL, &dT, NULL); // 매개변수가 되는 것이 short 자료형의 변수이므로 주소 저장 후 나머지는 NULL 대입 -> 매개변수가 많아지면 불편, void 포인터 사용
    
    // void* 형 포인터 사용하기(Myfun2 함수)-> flag에 전달된 값에 따라 형 변환 후 전달된 주소에 1대입
    short DATa=5;
    Myfun2(&DATa,1); // flag==1 이므로 short 형으로 변환 후 1대입
    
    // void * 사용하여 대상 메모리 크기 조절하기 (GetData 함수)
    int p_data=0x12345678;
    printf("%X\n",GetData(&p_data,2)); // type 변수에 2지정-> 2바이트 만큼 저장 후 출력 (리틀 엔디언 시스템)
    
    // 연습문제 1
    int data1=0x12345678;
    short *p_Data=(short *)&data1;
    *p_Data=0x0412;
   
    printf("%0x%x\n",data1);
    
    //연습문제 2
    char a=0x12 ,b=0x34;
    short c=0x5678;
    int t;
    
    char *PP= (char *) &t; // 자료형이 맞지 않으므로 int 형의 변수 t의 주소를  char형으로 casting , 포인터 변수는 1바이트 단위로 증감됨
    *(short*)PP=c; //p가 가리키는 주소(t변수의 시작지점)부터 2바이트 크기 메모리에 c 값 저장
    *(PP+2)=b; // p가 가리키는 주소부터 2바이트 떨어진 주소에 1바이트 크기의 메모리에 b값 저장
    *(PP+3)=a; // p가 가리키는 주소부터 3바이트 떨어진 주소에 1바이트 크기의 메모리에 a값 저장
    printf("t: 0x%x\n",t);
    
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
     

     
    
    
    
    
    
    
    
    
}

 
