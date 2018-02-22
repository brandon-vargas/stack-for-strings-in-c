#include<stdio.h>
#include<stdlib.h>
#include<string.h>

  int max;
  int top;
  char **stackPATH;

void init_stack(){

  top = 0;
  max = 256;

  stackPATH = (char**) calloc(max, sizeof(char*));
  int i;
  for(i = 0; i < 256; i++){
    stackPATH[i] = (char*) calloc(max, sizeof(char));
  }
}

int stack_empty(){
  if(top == 0){
    return 1;
  }
  return 0;
}

int stack_full(){
  if(top == max){
    return 1;
  }
  return 0;
}

void stack_push(char *p){

  if(!stack_full()){
    stackPATH[top++] = p;
    stackPATH[top] = '\0';
  }
  else{
    printf("ERROR: stack is full\n");
  }
}

char* stack_pop(){

  char *temp;
  if(!stack_empty()){
    temp = stackPATH[top--];
    return temp;
  }
  else{
    printf("ERROR: stack empty\n");
  }
  return '\0';
}

void stack_show(){
  int i;
  for (i = 0; stackPATH[i] != '\0'; i++){
    printf("%s\n",stackPATH[i]);
  }
  printf("\n");

}

int main(){

init_stack();

stack_push("first");
stack_push("second");
stack_pop();
stack_push("third");
stack_show();

}
