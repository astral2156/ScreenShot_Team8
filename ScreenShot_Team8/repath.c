#include<stdio.h>
char * rePath() {		
	char temp[100];

	printf("���ο� ��θ� �Է��ϼ��� : ex).\\save\\\n");
	scanf("%s", temp);
	getchar();

	printf("������ �Ϸ� �Ǿ����ϴ�.\n");
	printf("����� ��� : %s\n", temp);
	printf("���͸� �����ּ���\n");
	return temp;
}