#include<stdio.h>
#include<string.h>

<<<<<<< HEAD
void rePath(LPCTSTR FileName) {			// ���ϰ�� ����
	char path[100];

	scanf("%s", &path);
=======
char * rePath() {			// ���ϰ�� ����
	char temp[100];
>>>>>>> origin/master

	printf("���ο� ��θ� �Է��ϼ��� : ex).\\save\\\n");
	scanf("%s", temp);
	getchar();

	printf("������ �Ϸ� �Ǿ����ϴ�.\n");
	printf("����� ��� : %s", temp);

	return temp;
}