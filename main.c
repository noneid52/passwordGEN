#include <stdio.h>
#include <stdlib.h> //rand(), exit()
#include <string.h> //strlen()
#include <time.h> //time()


//���ڼ� ���� ����
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define NUMBER "0123456789"
#define SPECIAL "!@#$%^&*()-_=+[]{};:,.<>?/"

#define ALL_CHARS UPPERCASE LOWERCASE NUMBER SPECIAL
//���ڼ� ���� ��


void generatePassword(int length)
{
    char password[length + 1]; //������ ��й�ȣ �����
    int charSetLength = strlen(ALL_CHARS); //���ڼ� ���� ���ϱ�
    int i;

    srand(time(NULL)); //���� �Լ� seed ����

    // ���� ��й�ȣ ����
    for (i = 0; i < length; i++) {
        password[i] = ALL_CHARS[rand() % charSetLength];  //������ �������� ������ ã���� ���� �ʰ� �ȵ�
    }
    password[length] = '\0';  //���� ���� ������ null


    printf("������ ��й�ȣ: %s\n", password);
}


void viewPasswordGuideline()
{
    printf("\n\n------------------------------------------------------------\n");

    printf("1. �̷� ��й�ȣ�� ������� ������\n");
    printf("  - Ư�� ������ ���� ��й�ȣ\n");
    printf("  - �����̳� ��ȭ��ȣ �� ���� ������ ���� ������� ������� ��й�ȣ\n");
    printf("  - ID�� ��й�ȣ�� ����ϰ� ������� ��й�ȣ\n");
    printf("  - �θ� �˷��� �̸��̳� �ܾ ������� ������� ��й�ȣ\n\n\n");

    printf("2. ������ ��й�ȣ�� �����ϴ� ���\n");
    printf("  - ���� ��ҹ���, ����, Ư�����ڸ� ȥ���Ͽ� ��й�ȣ�� �����.\n");
    printf("  - �⺻ ��й�ȣ�� ����� ����Ʈ���� Ư�� ��Ģ�� �����Ͽ� ����Ʈ���� �ٸ��� �����.\n");
    printf("  - �뷡 ����, �Ӵ� ���� ������� ��й�ȣ�� �����.\n");
    printf("  - ��й�ȣ ������ ���α׷��� ����ϴ� �͵� ���� ����̴�.\n\n");

    printf("[��ó : �ѱ����ͳ������]\n");
    printf("------------------------------------------------------------\n\n");
}

int main()
{
    int length = 0;
    int userCommand = 0;
    int passwordDigitFlag = 0;

    //���ϴ� �׸� �Է¹ޱ�
    printf("����������� ��й�ȣ ������ �����������\n\n\n");
    printf("���� �׸��� ������ �ּ���.\n");
    printf("1. ��й�ȣ �����ϱ�.\n");
    printf("2. ��й�ȣ�� �����ϰ� ����ϴ� ��� �˾ƺ���.\n");
    printf("3. ���α׷� ����.\n\n\n");


    printf("�۵��ϰ� ���� ����� ��ȣ�� ���ڸ� �Է��� �ּ���.\n");
    printf("---> ");
    scanf("%d", &userCommand);


    //userCommand �Ǵ�
    if (userCommand == 1) { //generatePassword()
        while (passwordDigitFlag == 0) {
            printf("��й�ȣ�� �ڸ����� �������ּ���.\n");
            scanf("%d", &length);

            if (length < 1) {
                printf("��й�ȣ�� ���̴� �ּ� 1�ڸ� �̻��̾�� �մϴ�.\n");
                printf("------------------------------------------------------------\n");
            }
            else {
                generatePassword(length);
                passwordDigitFlag = 1;
            }
        }


    }
    else if (userCommand == 2) { //viewPasswordGuideline()
        viewPasswordGuideline();
    }
    else if (userCommand == 3) { //exit()
        printf("���α׷��� �����մϴ�.\n");
    }
    else {
        printf("�������� �ʴ� ��ɾ� �Դϴ�. ���α׷��� �����մϴ�.\n");
    }


    return 0;
}
