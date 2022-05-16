/*
A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].

Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and ().

A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])} is not balanced because the contents in between { and } are not balanced. The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].

By this logic, we say a sequence of brackets is balanced if the following conditions are met:

It contains no unmatched brackets.
The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
Given  strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, return YES. Otherwise, return NO.

Function Description

Complete the function isBalanced in the editor below.

isBalanced has the following parameter(s):

string s: a string of brackets
Returns

string: either YES or NO
Input Format

The first line contains a single integer , the number of strings.
Each of the next  lines contains a single string , a sequence of brackets.
*/
#define L 1000
 char stack[L];
 int top=-1;
 void push(char a){
     if(top!=L-1){
         stack[++top]=a;
     }
 }
 int isPair(char a,char b){
     switch(a){
         case '[':
            if(b==']'){
                return 1;
            }
            break;
        case '{':
            if(b=='}'){
                return 1;
            }
            break;
        case '(':
            if(b==')'){
                return 1;
            }
            break;
     }
     return 0;
 }
 char pop(){
     if(top>=0){
         return stack[top--];
     }
     return '\0';
 }
char* isBalanced(char* s) {
    printf("called\n");
    char *yes="YES",*no="NO";
    while(*s!='\0'){
        if(*s=='{' || *s=='(' || *s=='['){
            if(*(s+1)=='\0'){
                return no;
            }
            printf("pushed %c\n",*s);
            push(*s);
        }else{
            if(top<0){
                return no;
            }
            printf("%c %c pair\n",stack[top],*s);
            if(isPair(stack[top],*s)){
                pop();
            }else{
                printf("not equal\n");
                return no;
            }
        }
        s++;
    }
    
    return yes;

}
