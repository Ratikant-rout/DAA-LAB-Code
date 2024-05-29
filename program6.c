//write a program to take input for an expresssion and convert from infix to postfix using pointer and store it in astring and print the string
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
                char postfix[100];
                int i = 0;
                printf("Enter The Expression : ");
                scanf("%s",exp);
                e = exp;
                while(*e != '\0'){
                    if(isalnum(*e)){
                        postfix[i++] = *e;
                    }
                    else if(*e == '('){
                        push(*e);
                    }
                    else if(*e == ')'){
                        while((x = pop()) != '('){
                            postfix[i++] = x;
                        }
                    }
                    else{
                        while(priority(stack[top]) >= priority(*e)){
                            postfix[i++] = pop();
                        }
                        push(*e);
                    }
                    e++;

                }
         }
      
   

