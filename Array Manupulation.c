/*
Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each the
array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in the array.*/
long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries) {
    long greatest=0,*chary;
    int i=0,j;
    chary=(long *)malloc(sizeof(long)*n+1);
    for(i=0;i<n+1;i++){
        *(chary+i)=0;
    }
    for(i=0;i<queries_rows;i++){//chary[*(*(queries+i)+0)-1]+
        long long a[3];
        a[0]=*(*(queries+i)+0);
        a[1]=*(*(queries+i)+1);
        a[2]=*(*(queries+i)+2);
        *(chary+(a[0]-1))+=a[2];
        if(a[1]<=n){
            *(chary+a[1])-=a[2];
        }
        
        // chary[*(*(queries+i)+0)-1]+=*(*(queries+i)+2);
        // chary[*(*(queries+i)+1)]-=(*(*(queries+i)+2));
        // for(j=*(*(queries+i)+0)-1;j<*(*(queries+i)+1);j++){
        //     chary[j]=chary[j]+ *(*(queries+i)+2);
        // }
    }
    long  sum=0;
    for(i=0;i<n+1;i++){
        sum+=*(chary+i);
        if(greatest<sum){
            greatest=sum;
        }
    }
    return greatest;
}
