#include <stdio.h>
#include <stdlib.h> //rand(), exit()
#include <string.h> //strlen()
#include <time.h> //time()


//문자셋 정의 시작
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define NUMBER "0123456789"
#define SPECIAL "!@#$%^&*()-_=+[]{};:,.<>?/"

#define ALL_CHARS UPPERCASE LOWERCASE NUMBER SPECIAL
//문자셋 정의 끝


void generatePassword(int length)
{
    char password[length + 1]; //생성된 비밀번호 저장용
    int charSetLength = strlen(ALL_CHARS); //문자셋 길이 구하기
    int i;

    srand(time(NULL)); //랜덤 함수 seed 설정

    // 랜덤 비밀번호 생성
    for (i = 0; i < length; i++) {
        password[i] = ALL_CHARS[rand() % charSetLength];  //길이의 나머지로 랜덤을 찾으면 범위 초과 안됨
    }
    password[length] = '\0';  //종료 위해 마지막 null


    printf("생성된 비밀번호: %s\n", password);
}


void viewPasswordGuideline()
{
    printf("\n\n------------------------------------------------------------\n");

    printf("1. 이런 비밀번호는 사용하지 마세요\n");
    printf("  - 특정 패턴을 갖는 비밀번호\n");
    printf("  - 생일이나 전화번호 등 유추 가능한 것을 기반으로 만들어진 비밀번호\n");
    printf("  - ID와 비밀번호가 비슷하게 만들어진 비밀번호\n");
    printf("  - 널리 알려진 이름이나 단어를 기반으로 만들어진 비밀번호\n\n\n");

    printf("2. 안전한 비밀번호를 생성하는 방법\n");
    printf("  - 영문 대소문자, 숫자, 특수문자를 혼합하여 비밀번호를 만든다.\n");
    printf("  - 기본 비밀번호를 만들고 사이트마다 특정 규칙을 적용하여 사이트마다 다르게 만든다.\n");
    printf("  - 노래 구절, 속담 등을 기반으로 비밀번호를 만든다.\n");
    printf("  - 비밀번호 관리자 프로그램을 사용하는 것도 좋은 방법이다.\n\n");

    printf("[출처 : 한국인터넷진흥원]\n");
    printf("------------------------------------------------------------\n\n");
}

int main()
{
    int length = 0;
    int userCommand = 0;
    int passwordDigitFlag = 0;

    //원하는 항목 입력받기
    printf("■■■■■■■■■■ 비밀번호 생성기 ■■■■■■■■■■\n\n\n");
    printf("다음 항목을 선택해 주세요.\n");
    printf("1. 비밀번호 생성하기.\n");
    printf("2. 비밀번호를 안전하게 사용하는 방법 알아보기.\n");
    printf("3. 프로그램 종료.\n\n\n");


    printf("작동하고 싶은 명령의 번호를 숫자만 입력해 주세요.\n");
    printf("---> ");
    scanf("%d", &userCommand);


    //userCommand 판단
    if (userCommand == 1) { //generatePassword()
        while (passwordDigitFlag == 0) {
            printf("비밀번호의 자리수를 설정해주세요.\n");
            scanf("%d", &length);

            if (length < 1) {
                printf("비밀번호의 길이는 최소 1자리 이상이어야 합니다.\n");
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
        printf("프로그램을 종료합니다.\n");
    }
    else {
        printf("존재하지 않는 명령어 입니다. 프로그램을 종료합니다.\n");
    }


    return 0;
}
