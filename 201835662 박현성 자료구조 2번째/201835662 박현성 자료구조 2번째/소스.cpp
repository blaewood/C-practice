#include <stdio.h> //��������� ����
#include <stdlib.h>
#define STACK_SIZE 100 //������ ũ�⸦ 100���� ����


typedef int element;        // ���� ����(element)�� �ڷ����� int�� ���� 



element stack1[STACK_SIZE]; 
element stack2[STACK_SIZE];// 1���� �迭 ���� ����
int top1 = -1;   
int top2 = -1;  // top �ʱ�ȭ

							// ������ ���� �������� Ȯ���ϴ� ����
int isEmpty1() {
	if (top1 == -1) return 1; //��� ������ 1 �ƴϸ� 0
	else return 0;//��� ������ 1 �ƴϸ� 0
}
int isEmpty2() {
	if (top2 == -1) return 1;//��� ������ 1 �ƴϸ� 0
	else return 0;//��� ������ 1 �ƴϸ� 0
}

// ������ ��ȭ �������� Ȯ���ϴ� ����
int isFull1() {
	if (top1 == STACK_SIZE - 1) return 1;
	else return 0;
}
int isFull2() {
	if (top2 == STACK_SIZE - 1) return 1;
	else return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ����
void push1(element item) {
	if (isFull1()) {				// ������ ��ȭ ������ ���
		printf("\n\n Stack1 is FULL! \n");
		return;
	}
	else stack1[++top1] = item;	// top�� ������Ų �� ���� top�� ���� ����
}
void push2(element item) {
	if (isFull2()) {				// ������ ��ȭ ������ ���
		printf("\n\n Stack2 is FULL! \n");
		return;
	}
	else stack2[++top2] = item;	// top�� ������Ų �� ���� top�� ���� ����
}

// ������ top���� ���Ҹ� �����ϴ� ����
element pop1() {
	if (isEmpty1()) {			// ������ ���� ������ ���
		printf("\n\n Stack1 is Empty!!\n");
		return 0;
	}
	else return stack1[top1--];	// ���� top�� ���Ҹ� ������ �� top ����
}
element pop2() {
	if (isEmpty2()) {			// ������ ���� ������ ���
		printf("\n\n Stack2 is Empty!!\n");
		return 0;
	}
	else return stack2[top2--];	// ���� top�� ���Ҹ� ������ �� top ����
}

// ������ top ���Ҹ� �˻��ϴ� ����
element peek1() {
	if (isEmpty1()) {			// ������ ���� ������ ���
		printf("\n\n Stack1 is Empty !\n");
		exit(1);
	}
	else return stack1[top1];		// ���� top�� ���� Ȯ��
}
element peek2() {
	if (isEmpty2()) {			// ������ ���� ������ ���
		printf("\n\n Stack2 is Empty !\n");
		exit(1);
	}
	else return stack2[top2];		// ���� top�� ���� Ȯ��
}

// ������ ���Ҹ� ����ϴ� ����
void printStack1() {
	int i;
	printf("\n STACK1 [ ");
	for (i = 0; i <= top1; i++) //���Ҹ� ���ʷ� ����Ѵ�
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
	element item; //�ؿ��� ���

	int sel = 0;



	printf("\n���� ��ɰ� ������ ���� �Է��Ͻÿ�."); //���� ��ɰ� ������ ���� �Է� �޴� �����̴�
	scanf_s("%d", &sel);
	scanf_s("%d", &item);

	if (sel == 1)
	{
		push1(item); //�Է��ѰŸ� ����
		push2((item*item)); //������ ����2�� ����
	
			printStack1(); //�� ������ ���
			printStack2();

	}
	else if (sel==2)
	{
		element p1;
		element p2;
		element temp;

		item=pop1(); //�̾Ƴ��Ÿ� �����Ѵ�
		p1 = item;
		item= pop2();
		p2 = item;

		temp = p1; //�Ű� ������ �̿��ؼ� ���� �ٲ��ش�
		p1 = p2;
		p2 = temp;

		push1(p1); //�ٲ� ���� �ٽ� �о� ����
		push2(p2);
		printStack1(); //�� ������ ����Ѵ�
			printStack2();
	}
	else if (sel == 3)
	{
		element g1;
		element g2;
		element g3;

		item = peek1();
		g1 = item; //�̾� ���Ÿ� �ٸ� ������ ����
		item = pop1();
		item = peek1();
		g2 = item; //�̾� ���Ÿ� �ٸ� ������ ����
		item = pop1();
		g3 = g1 * g2; //���Ѵ�
		push1(g3); //����1�� ���� ���� �ִ´�


		printStack1(); //�� ������ ����Ѵ�
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


void main(void) { //��ȯ ���� ���� ���� �Լ�
	
	printf("\n���� ȭ��\n"); //���ʿ� ��ȫ��
	while (1) //���ѷ����� ���
	{
		select(); //���� �ִ� �Լ� ȣ��
	}

	getchar();
	return;
}