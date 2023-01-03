//
//  main.c
//  플젝7
//
//  Created by SUNJAE on 2022/02/07.
//학생의 성적 관리 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <memory.h> //memcpy함수
typedef struct studentdata{
    char name[32];
    int kor,eng,mat;
    int sum;
    float ave;
    int ranking;
}SD;

typedef struct node{
    SD data; //학생들의 데이터를 입력받을 변수
    struct node *p_next; //다음 노드를 가리킬 포인터
}NODE;

void AddNode(NODE **ap_head, NODE **ap_tail,SD *temp){
    if (NULL==*ap_head){ //기존 연결리스트에 노드가 없을때
        *ap_head=(NODE *)malloc(sizeof(NODE)); //새 노드 할당
        *ap_tail=*ap_head; //테일 포인터에 새 노드 주소 저장
    }
    else {//노드가 있을때
        (*ap_tail)->p_next=(NODE *)malloc(sizeof(NODE)); //마지막 노드의 포인터에 새 노드 주소 저장
        *ap_tail=(*ap_tail)->p_next; //테일 포인터에 새 노드 주소 저장
    }
    memcpy(&(*ap_tail)->data,temp,sizeof(SD)); // SD자료형으로 입력된 학생들의 data가 담긴 temp 변수의 내용을 그대로 복사 . data변수는 SD형으로 선언된 일반변수이므로 접근하려면 &붙임.
    (*ap_tail)->p_next=NULL; //다음 노드가 비어있음 명시

    
}
void LoadFile(NODE **ap_head, NODE **ap_tail, unsigned short *count ){ //데이터를 불러오는 함수
    FILE *ap_file=fopen("student_grade.dat", "rb"); //읽기 모드
    if (ap_file!=NULL){
        fread(count, sizeof(unsigned short ),1, ap_file); //학생의 수 읽어와서 count에 저장
        
        for (unsigned short i=0;i<*count;i++){ //학생 수만큼 반복문 진행
            //메모리 동적 할당
            if (NULL==*ap_head){ //기존 연결리스트에 노드가 없을때
                *ap_head=(NODE *)malloc(sizeof(NODE)); //새 노드 할당
                *ap_tail=*ap_head; //테일 포인터에 새 노드 주소 저장
            }
            else {//노드가 있을때
                (*ap_tail)->p_next=(NODE *)malloc(sizeof(NODE)); //마지막 노드의 포인터에 새 노드 주소 저장
                *ap_tail=(*ap_tail)->p_next; //테일 포인터에 새 노드 주소 저장
            }
            fread(*ap_tail, sizeof(NODE), 1, ap_file); //파일에서 학생의 데이터를 읽어와서 동적 할당된 메모리에 저장.
        }
        
        (*ap_tail)->p_next=NULL; //다음 노드에 가리킬 값 없음 명시
        fclose(ap_file); //닫기
    }
}
    
void SaveFile(NODE *ap_head,unsigned short count){//입력 데이터를 파일에 저장하는 함수
    FILE *ap_file=fopen("student_grade.dat", "wb"); //파일 생성(열기)
    if (ap_file!=NULL) { //파일이 성공적으로 열림
        fwrite(&count,sizeof(unsigned short), 1, ap_file); //count변수에 저장된 학생 수를 파일에 저장.
        while (ap_head!=NULL) {//끝날때까지 반복
            fwrite(ap_head, sizeof(NODE),1, ap_file); //노드 구조체 그대로 저장
            ap_head=ap_head->p_next; //다음 노드로 이동
        }
        fclose(ap_file);
    }
    
}


void DeleteNode(NODE *ap_head){ //다 지웠을때 두 포인터에 모두 NULL값 넣어야 함
    NODE *p; //새로운 포인터 변수
    while (ap_head!=NULL) { //끝날때까지 반복
        p=ap_head->p_next; //처음 노드의 포인터 주소 보관
        free(ap_head); //해제
        ap_head=p; //다음 노드로 이동
        }
    }

void PutGrade(SD *ap_data,unsigned short count){
    
    
    printf("%d번째 학생 이름:",count);
    scanf("%s",ap_data->name);
    printf("국어 점수:");
    scanf("%d",&ap_data->kor);
    printf("영어 점수:");
    scanf("%d",&ap_data->eng);
    printf("수학 점수:");
    scanf("%d",&ap_data->mat);
    
   
    ap_data->sum=ap_data->kor+ap_data->eng+ap_data->mat;
    ap_data->ranking=1;
    ap_data->ave=ap_data->sum/3.0;
    
    
}

void UpdateRanking(NODE *ap_head,SD *ap_data){ //새로 추가될 데이터와 기존 데이터를 비교해서 더 작은 값 등수 하락
    NODE *p=ap_head; //새 노드의 주소 값 저장
    while (p!=NULL){ //마지막 노드까지 반복
        if(p->data.sum< ap_data->sum) {
            p->data.ranking++;
    }
        else ap_data->ranking++;
        p=p->p_next; //다음 노드로 이동
    }
    
    
}

void ShowGrade(NODE *ap_head){ //처음부터 끝날때까지 보여주기
    NODE *p=ap_head;
    printf("----------------------------------------\n");
    printf("이름   국어  영어  수학  총점  평균  등수\n");
    printf("----------------------------------------\n");
    
    while (p!=NULL) {
        printf("%-8s  %3d  %4d  %4d  %4d  %4.0f  %3d등\n",p->data.name,p->data.kor,p->data.eng
               ,p->data.mat,p->data.sum,p->data.ave,p->data.ranking);
        p=p->p_next; //다음 노드로 이동
    }
    printf("\n\n");
    
}


int main() {
  /*fprintf함수 사용해서 파일에 문자열 저장하기
    FILE *p_file=fopen("f1.txt", "wt"); //쓰기 모드. 텍스트 파일 오픈
    if(p_file!=NULL) {
        fprintf(p_file, "Hello\n"); //새로운 파일을 만들고 문자열 저장함
        fclose(p_file);} //파일닫기
    else printf("실패");*/
    
    //fscanf함수로 문자열 형식의 정수값 읽어오기
    int num;
    
    FILE *p_file1=fopen("f1.txt", "rt");
    if(p_file1!=NULL) {
        while(EOF!=fscanf(p_file1,"%d",&num)){ //어떤파일에서 어떤 형식으로 가져와 어떤 변수에 저장할 건지.EOF문자 나올때까지 반복
            printf("%d\n",num);
    }
        fclose(p_file1);} //파일닫기
    else printf("실패\n");
    
    //fgets함수:txt파일에서 한 줄 단위로 문자열 처리 . EOF만나면 NULL값 반환함. \n포함
    char Temp[64]; //파일에서 읽은 문자열을 저장할 배열
    FILE *p_file2=fopen("tips.txt", "rt");
    if (NULL!=p_file2){
        while (NULL!=fgets(Temp, sizeof(Temp), p_file2)) {
            printf("%s\n",Temp); //fgets함수는 한 줄 끝에 \n도 temp배열에 넣어주므로 개행 문자 적지 않음
        }
        fclose(p_file2);
    }
    
//바이너리 파일에 읽고 쓰기
    //fwrite함수: 파일에 바이너리 저장, fread함수: 바이너리 파일에서 데이터 읽기
    int data=0x00000412;
    int rdata; //저장한 데이터 읽어올 변수
    FILE *p_file3=fopen("jin.dat", "wb");
    if (NULL!=p_file3){
        fwrite(&data, sizeof(int), 1, p_file3);
        fclose(p_file3); //바이너리 형태이므로 응용프로그램이 없다면 저장 여부 확인 어려움
    }
    FILE *p_file4=fopen("jin.dat", "rb");
    fread(&rdata, sizeof(int), 4, p_file4);
    printf("%d(0x%04x)\n",rdata,rdata);
    fclose(p_file4);
    
//fseek(포인터,이동거리,기준위치),ftell(파일포인터): 반환 값이 시작 위치를 0으로 계산한 결과.-> 파일 내부 작업  위치 확인 및 탐색
    //바이너리 파일 크기 알아내기
    int file_size=0;
    FILE *p_file5=fopen("jin.dat", "rb");
    if (NULL!=p_file5){
        fseek(p_file5, 0, SEEK_END); //파일의 끝으로 이동
        file_size=ftell(p_file5); //이동한 위치를 값으로 확인
        printf("%d\n",file_size);
        fclose(p_file5);
    }
    
//활용문제-성적 처리 프로그램을 파일 입출력 형태로 변환하기(입력한 성적 데이터를 파일에 저장해야됨)
    int Num;
    unsigned short count=0;
    NODE *ap_head=NULL; NODE *ap_tail=NULL;
    SD temp;
    LoadFile(&ap_head, &ap_tail, &count); //불러오기
    while (1) {
        printf("[Menu]\n");
        printf("1.성적 입력\n");
        printf("2.성적 확인\n");
        printf("3.종료\n");
        
        printf("------------\n");
        printf("(1-3)선택:");
        scanf("%d",&Num);
        
        if (Num==1){
            PutGrade(&temp,count);  count++;
            UpdateRanking(ap_head, &temp);
            AddNode(&ap_head, &ap_tail, &temp);
        }
        else if (Num==2){
            ShowGrade(ap_head);
        }
        else if (Num==3) {
            printf("프로그램이 종료됨\n");
            break;
    }
        SaveFile(ap_head,count); //데이터 파일에 저장
        DeleteNode(ap_head);
    }
    
    
    
    
    
    
    
    
    
    return 0;
}
