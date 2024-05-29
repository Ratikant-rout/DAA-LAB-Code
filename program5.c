// Convert infix into Postfix without using pointer
#include <stdio.h>
#include<stdlib.h>

int stack[100];
int top = -1;

void push(int x){
    stack[++top] = x;
}
   
int pop(){
    if(top == -1){
        return -1;
    }
       else{
              return stack[top--];
       }
     
}
 
int priority(char x){
    if(x == '('){
        return 0;
    }
    if(x == '+' || x == '-'){
        return 1;
    }
    if(x == '*' || x == '/'){
        return 2;
    }
    return 0;
}
  //main function 

int main(){
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0'){
        if(isalnum(*e)){
            printf("%c",*e);
        }
        else if(*e == '('){
            push(*e);
        }
        else if(*e == ')'){
            while((x = pop()) != '('){
                printf("%c", x);
            }
        }
        else{
            while(priority(stack[top]) >= priority(*e)){
                printf("%c",pop());
            }
            push(*e);
        }
        e++;
    }
    while(top != -1){
        printf("%c",pop());
    }
    return 0;
}
  