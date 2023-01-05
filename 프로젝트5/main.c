//
//  main.c
//  Created by SUNJAE on 2022/01/26.
// 스택, 포인터, 연결리스트 활용 문제

#include <stdio.h>
#include <stdlib.h>
#define MAX_COUNT 5 //최대 등록 가능한 친구의 수
typedef unsigned short int  US; //typedef로 정의한 자료형으로 변수 선언하기
typedef char NAME_TYPE[14];  //2차원 배열로 사람의 이름을 저장하는 배열의 자료형 재정의

typedef struct node{ //연결리스트 구조체 선언 (노드)
    int number;
    struct node *p_next; //다음 노드를 가리킬 포인터
} NODE;

//더하기 프로그램
void AddNumber(NODE **pp_head, NODE **pp_tail,int data){
    //헤드,테일: 1차원 포인터의 주소값을 매개변수로 받으므로 2차원 포인터. data: 더할 숫자
    if (*pp_head!=NULL){// p_head포인터의 주소 값이 NULL이아니면 기존 연결리스트에 노드 있음.
        (*pp_tail)->p_next=(NODE *)malloc(sizeof(NODE)); //테일 포인터에 저장된 마지막 노드의 p_next요소에 동적 메모리 할당
        *pp_tail=(*pp_tail)->p_next;//새 노드 값의 주소 저장
    }
    else{ //노드 없음-> 헤,테 변경
        *pp_head=(NODE*)malloc(sizeof(NODE)); //새 노드 할당, 메모리 주소 저장
        *pp_tail=*pp_head; //새 노드의 주소 값을 p_tail에 저장.
        
    }
    (*pp_tail)->number=data; //새 노드의 number에 data값 저장
    (*pp_tail)->p_next=NULL; //새노드이 포인터가 가리키는 다음 노드가 없음을 명시

}



typedef struct {
    char name[14];
    unsigned short int age;
    float height;
    float weight;
    
}Person;

void push(short *ap_data_list,short *ap_top){ //사용자에게 값을 입력받고 그 값을 배열에 저장
    short data;
    printf("input data:");
    scanf("%hd",&data);
    
    (*ap_top)++; //push 함수가 호출될 때마다 top변수 1씩 증가.
    ap_data_list[*ap_top]=data; //해당 인덱스 배열에 추가
    
    if (*ap_top>=29){ //더 이상 push할 수 없는 경우: 예외처리해줌
        printf("더 이상 push할 공간이 없음.\n");
        return;
}
}
    
void pop(short *ap_data_list,short *ap_top){ //배열에 저장된 인덱스 중 가장 마지막에 추가된 데이터를 뺌
    short data=ap_data_list[*ap_top];
    (*ap_top)--; //하나 pop했기 때문에 마지막에 저장된 인덱스 순서가 변함, top변수 값 1감소
    printf("pop data: %hd\n",data);
    if (*ap_top==-1){//스택이 비어있어서 더이상 뺄게 없는 경우->예외처리
        printf("스택이 비어있어 더 이상 뺄 수 없음.\n");
        return;}
}

void printdata(short *ap_data_list, short ap_top){ //스택에 저장된 데이터들을 보여주는 함수
    printf("-------[stack data]-------\n");
    for (int i=0;i<=ap_top;i++){
        printf("%2d번째: %hd\n",i+1,ap_data_list[i]);
    }
    printf("--------------------------\n");
    
}

int AddFriend(Person *p_friend, int count){ //구조체 자료형의 포인터 변수. main함수에서 선언한 배열의 시작주소를 포인터로 받음 count:현재까지 입력된 친구의 수 기억
    if (count<MAX_COUNT) {
        p_friend+=count; //p_friend배열의  count 위치로 이동
        printf("\n 새로운 친구 정보 입력.\n");
        printf("1. 이름:");
        scanf("%s",p_friend->name); //이름 배열의 count 색인에 이름 저장
        printf("2. 나이:");
        scanf("%hu",&p_friend->age); //(*p_friend).age와같다
        printf("3. 키:");
        scanf("%f",&p_friend->height);
        printf("4. 몸무게:");
        scanf("%f",&p_friend->weight);
        
        printf("\n입력을 완료함\n");
        return 1; //친구 추가 성공시 1반환
        
    }
    else {
        printf("최대 인원을 초과하여 더 이상 입력할 수 없음.\n");
        printf("최대 %d명까지만 관리 가능함.\n\n",MAX_COUNT);
    }

    
    return 0; //실패 시 0반환
}
void ShowFriend(Person *p_friend, int count){
    int i;
    if (count>0){ //등록된 친구가 있으면 출력
        printf("등록된 친구 목록\n");
        printf("======================================\n");
        for (i=0;i<count;i++){
            printf("%-14s, %3d, %6.2f, %6.2f",p_friend->name,p_friend->age,p_friend->height,p_friend->weight);
            p_friend++; //다음 위치에 있는 친구 정보로 주소이동(22바이트 만큼)
        }
        
        printf("\n======================================\n\n");
        
        
    }
    else {
        printf("\n등록된 친구가 없습니다.\n\n");
    }
}

int main() {
   /*포인터 배열로 연령별 윗몸 횟수 관리하기
    unsigned char *p_limit_table; //사용자에게 입력받은 연령별 인원수 저장
    unsigned char **p; //연령별 윗몸 일으키기 횟수를 저장할 2차원 포인터 (연령층->인원수->인원수만큼 각각 횟수 입력 받아)
    
    int age,age_step,member,temp,sum;
    
    printf("연령층 몇개?"); scanf("%d",&age_step); //연령층 개수 입력받기
    
    p_limit_table=(unsigned char *)malloc(age_step); //입력받은 연령층 수 만큼의 메모리 할당,메모리의 주소 저장
    p=(unsigned char **)malloc(sizeof(unsigned char *)*age_step); //연령층 수마다 인원수 저장할 메모리 할당
    
    for (age=0;age<age_step;age++){
        printf("%d0대 연령의 윗몸일으키기 횟수\n",age+2);
        printf("이 연령대는 몇명입니까? :"); scanf("%d",&temp); //scanf함수는 unsigned char 변수에 정수 입력불가
        //                                                 -> temp에 받음
        *(p_limit_table+age)=(unsigned char)temp; //형변환 후 저장 *(p_limit_+0)=x명..
        *(p+age)=(unsigned char *)malloc(*(p_limit_table+age)); //위에서 입력받은 인원수만큼 크기의 메모리 할당 후 포인터에 주소 저장
        for (member=0;member<*(p_limit_table+age);member++){ //인원수만큼 횟수 입력받음
            printf("%dth: ",member+1);
            scanf("%d",&temp);
            *(*(p+age)+member)=(unsigned char)temp;
            
        }
    }
    printf("\n\n연령별 평균 윗몸 일으키기 횟수\n");
    for (age=0;age<age_step;age++){
        sum=0;
        printf("%d0대:",age+2);
        for (member=0;member<*(p_limit_table+age);member++)
             sum=sum+ *(*(p+age)+member);
    
        printf("%5.2f\n",(double)sum/ *(p_limit_table+age));
        free(*(p+age)); //반복문으로 포인터 메모리 모두 해제
    }
    free(p);
    free(p_limit_table);
    */
    
    
//활용 -스택 구현하기
    short data_list[30];
    short top=-1,menu=0; //push한 데이터의 배열 인덱스를 저장하는 변수. 처음에 -1로 초기화
    while (1){ //무한루프, 사용자가 push/pop/print 하고 스택의 구조를 알기 위해.
        printf("--------Menu-------\n");
        printf(" 1. push data\n");
        printf(" 2. pop data\n");
        printf(" 3. show data\n");
        printf(" 4. Exit\n");
        printf("------------------\n\n ");
        printf("select Menu(1~4):");
        scanf("%hd",&menu); //short signed
        
        if (menu==1) push(data_list,&top);//데이터를 push
        else if (menu==2) pop(data_list,&top);//pop
        else if (menu==3) printdata(data_list,top);//show
        else if (menu==4) break; //종료
        
        
    }
    US Data=5;
    US temp;
    temp=Data;
    printf("%d",temp);
    
    // 구조체를 사용해서 사람의 신체 정보를 입력받고 출력하기
    Person data; //구조체 자료형으로 변수 선언
    printf("이름 입력:");
    scanf("%s",data.name);
    printf("나이 입력:");
    scanf("%hu",&data.age);
    printf("키 입력:");
    scanf("%f",&data.height);
    printf("몸무게 입력:");
    scanf("%f",&data.weight);
    
    printf("\n입력한 정보는 다음과 같습니다.\n");
    printf("%-10.30s: %d세, %.1fcm, %.1fkg\n",data.name,data.age,data.height,data.weight);

    //배열/구조체로 친구 정보 관리 프로그램 만들기
    /*NAME_TYPE name[MAX_COUNT]; //자료형, 배열이름, 요소개수
    unsigned short int age[MAX_COUNT];
    float height[MAX_COUNT];
    float weight[MAX_COUNT]; //이름,나이,키,몸무게를 저장할 배열*/
    
    Person friends[MAX_COUNT]; // 친구 정보를 저장할 배열
    
    int count=0,num; //count: 등록된 친구 수
    while(1){
    
        printf("      [메뉴]       \n");
        printf("===================\n");
        printf("1. 친구 추가\n");
        printf("2. 친구 목록 보기\n");
        printf("3. 종료\n");
        printf("===================\n");
   
        printf("번호 선택:");
        scanf("%d",&num);
    
        if (num==1){
            if (1==AddFriend(friends,count)) count++; //친구 추가에 성공하면 친구 수 하나 증가시킴
    }
        else if (num==2){
            ShowFriend(friends,count);
    }
        else if (num==3) {break;}
        else printf("1-3 중 하나만 선택\n");
    }
    
    
    //연결리스트로 더하기 프로그램 만들기
    
    NODE *p_head=NULL, *p_tail=NULL, *p; //노드의 시작과 끝을 기억할 포인터
    int sum=0,Temp;
    while(1){ //숫자 입력: 무한 반복 루프
        printf("숫자 입력(9999누르면 종료):");
        scanf("%d",&Temp);
        if (Temp==9999)break;
        AddNumber(&p_head, &p_tail, Temp); //else구문
    }
    
    p=p_head; //노드를 탐색할 포인터에 시작 노드의 주소값 보관(헤드포인터가 가리키는 노드의 주소)
    while (NULL!=p) { //마지막 노드가 나타나기전까지 반복
        if (p!=p_head)printf(" + ");
        sum+=p->number; //최초 1회 여기부터 실행
        p=p->p_next;//다음 노드로 이동
    }
    printf(" = %d\n",sum); //더하기 결과 출력
    
    while (NULL!=p_head) { //메모리 해제 헤드포인터가 가리키는 노드의 주소값이 NULL(마지막노드)일때까지 반복
        p=p_head;
        p_head=p_head->p_next; //다음 노드로 이동
        free(p); //메모리 해제
        
    }
    
    p_tail=p_head; //둘다 null값
    
    
    
   
    
    
    
    
    

    

   
    
    
    
    
    return 0;
}
