/*
Declare a 2-dimensional array, , of  empty arrays. All arrays are zero indexed.
Declare an integer, , and initialize it to .

There are  types of queries, given as an array of strings for you to parse:

Query: 1 x y
Let .
Append the integer  to .
Query: 2 x y
Let .
Assign the value  to .
Store the new value of  to an answers array.
Note:  is the bitwise XOR operation, which corresponds to the ^ operator in most languages. Learn more about it on Wikipedia.  is the modulo operator.
Finally, size(arr[idx]) is the number of elements in arr[idx]
*/

 int len(int **chary,int idx,int n){
     int i=0;
     while(*(*(chary+idx)+i)!=0){
         i++;
     }
     return i;
     
 }
int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    int i,j,idx,indexj=0,**chary,lastAnswer=0,*ry,z=0;
    chary=(int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++){
        *(chary + i) = malloc(3 * (sizeof(int)));
        for(j=0;j<3;j++){
            *(*(chary+i)+j)=0;
        }
    }
    ry=(int *)malloc(sizeof(int)*n);
    for(i=0;i<queries_rows;i++){
        
        int a[3];
        for(j=0;j<3;j++){
            a[j]=*(*(queries+i)+j);
        }
        if(a[0]==1){
            idx=(a[1]^lastAnswer);
            idx=idx%n;
            indexj=len(chary,idx,n);
            printf("len jj=%d\n",indexj);
            *(*(chary+idx)+indexj)=a[2];
            
        }else{
            idx=(a[1]^lastAnswer);
            idx=idx%n;
            indexj=len(chary,idx,n);
            if(indexj!=0){
                indexj=a[2]%indexj;
            }else{
                indexj=a[2]%(sizeof(*(chary+idx))/sizeof(*(*(chary+idx)+0)));
            }
            printf("len j=%d\n",indexj);
            lastAnswer=*(*(chary+idx)+indexj);//chary[idx][a[2]%indexj];
            *(ry+z)=lastAnswer;
            z++;
  
            
        }
    }
    *result_count=z;
    return ry;
    

}
