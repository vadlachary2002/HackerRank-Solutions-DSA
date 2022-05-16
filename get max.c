/*You have an empty sequence, and you will be given N queries. Each query is one of these three types:

1 x  -Push the element x into the stack.
2    -Delete the element present at the top of the stack.
3    -Print the maximum element in the stack.
Input Format

The first line of input contains an integer, N . The next N lines each contain an above mentioned query. (It is guaranteed that each query is valid.)

Constraints

 1 < = N < = 10 ^5
 1 < = x < =  10^9
1 <=  type <= 3


Output Format

For each type 3 query, print the maximum element in the stack on a new line.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct _node node;
struct _node{
    long long int data;
    node *next;
};
node* getnode(long long int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
node * push(node *top,int long long  data){
    node *newnode=getnode(data);
    if(top == NULL)
        return newnode;
    newnode->next=top;
    return newnode;        
}

node * delete(node *top){
    node  *temp=top;
    top=top->next;
    free(temp);
    return top;
}
void move(node *fromTop,node *toTop) {
    int data=fromTop->data;
    delete(fromTop);
    push(toTop,data);
        
}

void printMax(node *maxtop){
    printf("%lld\n",maxtop->data);
}
int main() {
   
    int choice;
    long long int N;
    long long int data;
    node *top=NULL,*maxtop=NULL;
    scanf("%lld",&N);
    while(N) {
        scanf("%d",&choice);
        if(choice == 1) {
            scanf("%lld",&data);
            if(top == NULL)
                maxtop=push(top,data);
            else if(data >= maxtop->data)
                maxtop=push(maxtop,data);
            top=push(top,data);
            
        }
        else if(choice == 2) {
            if(top->data == maxtop->data)
                maxtop=delete(maxtop);
            top=delete(top);
        }
        else if(choice == 3) {
            printMax(maxtop);
        }
        N--;
    }
    return 0;
}
