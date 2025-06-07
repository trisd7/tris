#include<stdio.h>
void main(){
    int i,k,j,n,rs[25],count[25],next=1,pf=0,f,m[25];float pfr;
    printf("\n enter length reference string:");
    scanf("%d",&n);
    printf("\n enter reference string:");
    for(int i=0;i<n;i++){
        scanf("%d",&rs[i]);

    }
    printf("\n enter frame size:");
    scanf("%d",&f);
    for( i=0;i<f;i++){
        m[i]=-1;
        count[i]=0;

    }
    printf("\n the page replacement process:");
    for(int i=0;i<n;i++){
        int found=0;
        //check if already
        for(int j=0;j<f;j++){
            if(m[j]==rs[i]){
                found=1;
                count[j]=next++;//track time
                break;
            }

        }
        if(!found){
            int replaced=0;
            for(int j=0;j<f;j++){
                if(m[j]==-1){
                    m[j]=rs[i];
                    count[j]=next++;
                    pf++;
                    replaced=1;
                    break;
                }

            }
            if(!replaced){
                int min=0;
                for(int j=1;j<f;j++){
                    if(count[j]<count[min]){
                        min=j;

                    }
                }
                    m[min]=rs[i];
                    count[min]=next++;
                    pf++;
                }
            }
                for(int k=0;k<f;k++){
                    if(m[k]!=-1){
                        printf("%d\t",m[k]);
                    }
                    else{
                        printf("-\t");
                           }
                }
                if (!found)
            printf("PF No. -- %d", pf);
        printf("\n");
    }

    // Page Fault Rate Calculation
    pfr = (float)pf / n;

    printf("\nTotal number of page faults using LRU: %d", pf);
    printf("\nPage Fault Rate: %.2f\n", pfr);
}

            

        




