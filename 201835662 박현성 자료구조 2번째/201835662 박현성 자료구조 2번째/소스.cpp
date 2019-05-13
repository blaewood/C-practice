#include <stdio.h> //헤더파일을 포함
#include <stdlib.h>
#define STACK_SIZE 100 //스택의 크기를 100으로 정의


typedef int element;        // 스택 원소(element)의 자료형을 int로 정의 



element stack1[STACK_SIZE]; 
element stack2[STACK_SIZE];// 1차원 배열 스택 선언
int top1 = -1;   
int top2 = -1;  // top 초기화

							// 스택이 공백 상태인지 확인하는 연산
int isEmpty1() {
	if (top1 == -1) return 1; //비어 있으면 1 아니면 0
	else return 0;//비어 있으면 1 아니면 0
}
int isEmpty2() {
	if (top2 == -1) return 1;//비어 있으면 1 아니면 0
	else return 0;//비어 있으면 1 아니면 0
}

// 스택이 포화 상태인지 확인하는 연산
int isFull1() {
	if (top1 == STACK_SIZE - 1) return 1;
	else return 0;
}
int isFull2() {
	if (top2 == STACK_SIZE - 1) return 1;
	else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push1(element item) {
	if (isFull1()) {				// 스택이 포화 상태인 경우
		printf("\n\n Stack1 is FULL! \n");
		return;
	}
	else stack1[++top1] = item;	// top을 증가시킨 후 현재 top에 원소 삽입
}
void push2(element item) {
	if (isFull2()) {				// 스택이 포화 상태인 경우
		printf("\n\n Stack2 is FULL! \n");
		return;
	}
	else stack2[++top2] = item;	// top을 증가시킨 후 현재 top에 원소 삽입
}

// 스택의 top에서 원소를 삭제하는 연산
element pop1() {
	if (isEmpty1()) {			// 스택이 공백 상태인 경우
		printf("\n\n Stack1 is Empty!!\n");
		return 0;
	}
	else return stack1[top1--];	// 현재 top의 원소를 삭제한 후 top 감소
}
element pop2() {
	if (isEmpty2()) {			// 스택이 공백 상태인 경우
		printf("\n\n Stack2 is Empty!!\n");
		return 0;
	}
	else return stack2[top2--];	// 현재 top의 원소를 삭제한 후 top 감소
}

// 스택의 top 원소를 검색하는 연산
element peek1() {
	if (isEmpty1()) {			// 스택이 공백 상태인 경우
		printf("\n\n Stack1 is Empty !\n");
		exit(1);
	}
	else return stack1[top1];		// 현재 top의 원소 확인
}
element peek2() {
	if (isEmpty2()) {			// 스택이 공백 상태인 경우
		printf("\n\n Stack2 is Empty !\n");
		exit(1);
	}
	else return stack2[top2];		// 현재 top의 원소 확인
}

// 스택의 원소를 출력하는 연산
void printStack1() {
	int i;
	printf("\n STACK1 [ ");
	for (i = 0; i <= top1; i++) //원소를 차례로 출력한다
		printf("%d ", stack1[i]);
	printf("] ");
}

void printStack2() {
	int i;
	printf("\n STACK2 [ ");
	for (i = 0; i <= top2; i++)
		printf("%d ", stack2[i]);
	printf("] ");
}


void select()
{
	element item; //밑에서 사용

	int sel = 0;



	printf("\n선택 기능과 데이터 값을 입력하시오."); //선택 기능과 데이터 값을 입력 받는 구문이다
	scanf_s("%d", &sel);
	scanf_s("%d", &item);

	if (sel == 1)
	{
		push1(item); //입력한거를 넣음
		push2((item*item)); //제곱을 스택2에 넣음
	
			printStack1(); //두 스택을 출력
			printStack2();

	}
	else if (sel==2)
	{
		element p1;
		element p2;
		element temp;

		item=pop1(); //뽑아낸거를 저장한다
		p1 = item;
		item= pop2();
		p2 = item;

		temp = p1; //매개 변수를 이용해서 값을 바꿔준다
		p1 = p2;
		p2 = temp;

		push1(p1); //바꾼 값을 다시 밀어 넣음
		push2(p2);
		printStack1(); //두 스택을 출력한다
			printStack2();
	}
	else if (sel == 3)
	{
		element g1;
		element g2;
		element g3;

		item = peek1();
		g1 = item; //뽑아 낸거를 다른 변수에 저장
		item = pop1();
		item = peek1();
		g2 = item; //뽑아 낸거를 다른 변수에 저장
		item = pop1();
		g3 = g1 * g2; //곱한다
		push1(g3); //스택1에 곱한 값을 넣는다


		printStack1(); //두 스택을 출력한다
		printStack2();
	}
	else if (sel == 4)
	{
		element *ad=stack2;
		for (int i = 0; i < STACK_SIZE; i++)
		{
			printf("\n%d %u\n", stack2[i], ad[i]);
		}


	}


	getchar();
}


void main(void) { //반환 값이 없는 메인 함수
	
	printf("\n실행 화면\n"); //위쪽에 분홍색
	while (1) //무한루프를 사용
	{
		select(); //위에 있는 함수 호출
	}

	getchar();
	return;
}