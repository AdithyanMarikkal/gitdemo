#include<stdio.h>
int main(){
    int n,m,i,j,count=0,counter=0;
    printf("enter the number of process");
    scanf("%d",&n);
    printf("eneter the number of resource type");
    scanf("%d",&m);
    int max[n][m],need[n][m],alloc[n][m],ava[m],f[n],safe[n];
    for(i=0;i<n;i++)
        f[i]=0;
    printf("enter the available resource");
    for(i=0;i<m;i++)
        scanf("%d",&ava[i]);
    printf("enter the max matrix");
    for(i=0;i<n;i++)
    {  
          for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("max matrix recieved");
    printf("enter the allocation matrix");
    for(i=0;i<n;i++)
    {  
          for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    
    printf("allocation matrix recieved");
    for(i=0;i<n;i++)
    {  
          for(j=0;i<m;j++){
           need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    int k=0;
    while(count!=n){
        for(i=0;i<n;i++){
            counter=0;
            for(j=0;j<m;j++){
                if(need[i][j]<ava[j])
                    counter++;
            }
            if(counter==n && !f[i])
            {
                for(i=0;i<m;i++)
                ava[i]+=alloc[i][j];
                safe[k++]=i;
                count++;
                f[i]=1;
            }
        }
    }
    for (i=0;i<n;i++){
        if(!f[i]){
            printf("\n\n-system is not in safe state");
        }
    }
    printf("\n safe sequesce:");
    for(i=0;i<n;i++){
        printf("=>%d",safe[i]);
    }


}
//incomeplete debug it later.