
//단순 배열 리스트
//클래스도 구조체처럼 포인터로 정의 가능 그리고 구조체처럼 -> 로 원소 불러옴
#include <iostream>
#define MAX_LIST_SIZE 100
/*
 * add_last
 * add_first
 * add
 * delete
 * clear
 * replace
 * is_in_list
 * get_entry
 * get_length
 * is_empty
 * is_full
 * display
 */
typedef int element;
class ArrayList{
    public:
        element list[MAX_LIST_SIZE]; //배열의 최대 크기
        int length; //배열에 저장된 자료들의 개수=cnt 가 의미가 더 맞겠네
};
//오류처리함수

void error(char *message){
    fprintf(stderr, "%s\n",message);
}
//리스트 초기화
void init(ArrayList A1) {
    A1.length =0;
};

int is_empty(ArrayList *L){
    return (*L).length==0;
}

int is_full(ArrayList *L){
    return L->length==MAX_LIST_SIZE;
}
void display(ArrayList *L){
    int i;
    for(i=0;i<L->length;i++){
        printf("%d\n",L->list[i]);
    }
}
//프로그램 4.2 더하기(삽입)
void add(ArrayList *L, int pos, element item){
    if(!is_full(L)&& (pos>=0)&& (pos<=L->length)){
        int i;
        for(i=L->length-1;i>=pos;i--){
            L->list[i+1]=L->list[i];
        }
        L->list[pos]=item;//삽입
        L->length++;
    }
}
//프로그램 4.3 뺴기(삭제)
//void remove_node(ArrayList **phead,ArrayList *p, ArrayList *removed){
//    if(p==NULL){
//        *phead = (*phelink;
//    }
//    else
//        p->link =
//}
element remove(ArrayList *L, int pos)
{
    int i;
    element item;
    if(pos<0|| pos>= L->length) error("위치오류");
    //삭제
    item=L->list[pos];
    //i부터 리스트의 번호를 하나씩 당긴다.
    for(i=pos;i<(L->length-1);i++){
        L->list[i] = L->list[i+1];
    }
    L->length--;
    return item;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}