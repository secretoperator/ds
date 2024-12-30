#include<stdio.h>
#include<string.h>
int stkpre(char c) {
  if(c=='+'||c=='-') return 2; if(c=='*'||c=='/') return 4; 
  if(c=='$'||c=='^') return 5; if(c=='(') return 0; if(c=='#') return -1; return 8;
}
int inpre(char c) {
  if(c=='+'||c=='-') return 1; if(c=='*'||c=='/') return 3; 
  if(c=='$'||c=='^') return 6; if(c=='(') return 9; if(c==')') return 0; return 7;
}
void infix_postfix(char infix[], char postfix[]) {
  char s[30]; int top=-1, j=0;
  s[++top]='#'; 
  for(int i=0; i<strlen(infix); i++) {
    while(stkpre(s[top]) > inpre(infix[i])) postfix[j++] = s[top--];
    if(stkpre(s[top]) != inpre(infix[i])) s[++top] = infix[i]; else top--;
  }
  while(s[top] != '#') postfix[j++] = s[top--];
  postfix[j] = '\0';
}
int main() {
  char infix[30], postfix[30];
  printf("\nEnter Infix Expression:"); scanf("%s", infix);
  infix_postfix(infix, postfix);
  printf("\nEquivalent Postfix Expression is: %s", postfix);
  return 0;
}