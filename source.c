#include <stdio.h>
#include <string.h>
#include <stdint.h>

int block1(char* ptr){
    int i;
    char number[4] = {'n', 'm', 'b', 'r'};
    for(i=0; i<4; i++){
        if(*(ptr + i) != number[i]){
            return 0;
        }
    }
    return 1;
}

int block2(char* ptr){
    int i;
    for(i=0; i<4; i++){
        if(*(ptr + i) < '0' || *(ptr + i) > '9'){
            return 0;
        }
    }
    return 1;
}

int block3(char* ptr){
    int i, j;
    char smb;
    char code[4] = {'r', 'v', 's', 'g'};
    for(i=0; i<4; i++){
        smb = *(ptr+i);
        smb = smb ^ ((1<<i) + i + 1);
        if(smb != code[i]){
            return 0;
        }
    }
    return 1;
}

int block4(char* ptr){
    unsigned char a = 0x69;
    unsigned char b = 0xa5;
    unsigned char m = 0x7f;
    
    if( *(ptr) != ((((a>>3)<<3) | ((b<<5)>>5)) & m) ){
        return 0;
    }
    if( *(ptr+1) != (((b<<4) | (a>>4)) & m) ){
        return 0;
    }
    if( *(ptr+2) != (((((b>>4)<<5) | (a<<1)>>3)) & m) ){
        return 0;
    }
    if( *(ptr+3) != (((b<<3) | (a>>5)) & m) ){
        return 0;
    }
    return 1;
}


int check(char* password){
    int i, len = strlen(password);
    if(len != 21){
        return 0;
    }

    if(password[0] != '(' || password[20] != ')'){
        return 0;
    }

    for(i=1; i<4; i++){
        if(password[5*i] != '-'){
            return 0;
        }
    }

    char *ptr = password;
    ptr += 1;
    if(block1((ptr)) == 0){
        return 0;
    }

    ptr += 5;
    if(block2((ptr)) == 0){
        return 0;
    }

    ptr += 5;
    if(block3((ptr)) == 0){
        return 0;
    }

    ptr += 5;
    if(block4((ptr)) == 0){
        return 0;
    }

    return 1;
}

int main() {
    char str[22];

	printf("Welcome back, agent. Provide your daily pass:");

	fgets(str, sizeof(str), stdin);


    if(check(str)){
        printf("Access granted\n");
    }
    else{
        printf("Wrong password\n");
    }
    return 0;
}