#include<stdio.h>
#include<string.h>

char * rePath() {		
	char temp[100];

	printf("���ο� ��θ� �Է��ϼ��� : ex).\\save\\\n");
	scanf("%s", temp);
	getchar();

	printf("������ �Ϸ� �Ǿ����ϴ�.\n");
	printf("����� ��� : %s\n", temp);

	return temp;
}