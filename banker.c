#include<stdio.h>
int main(){
	int n, m, i, j, k;

	n=5;
	m=3;

	int alloc[5][3]={
		{0, 1, 0 },
		{2, 0, 0 },
		{3, 0, 2 },
		{2, 1, 1 },
		{0, 0, 2 },
	};

	int maxn[5][3]={
		{7, 5, 3 },
		{3, 2, 2 },
		{9, 0, 2 },
		{4, 2, 2 },
		{5, 3, 3 },
	};

	int avail[3]={3, 3, 2};

	int f[n], ans[n], ind=0;
	int need[n][m];
	for( i=0;i<n;i++){
		for( j=0;j<m;j++){
			need[i][j]=maxn[i][j]-alloc[i][j];
		}
	}

	for( k=0;k<n;k++){
		f[k]=0;
	}

	int y=0;
	for( k=0;k<n;k++){
		for( i=0;i<n;i++){
			if (f[i]==0){
				int flag=0;
				for( j=0;j<m;j++){
					if(need[i][j]>avail[j]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					ans[ind++]=i;
					for( y=0;y<m;y++){
						avail[y] += alloc[i][y];
					}
					f[i]=1;
				}
			}
		}
}
int flag =1;
for( i=0;i<n;i++ ){
	    	if(f[i]==0){
	      		flag=0;
	      		printf("\nThe following system is not safe\n");
	      		break;
	      	}
	      }



if(flag==1){
	      printf("\nThe safe sequence is : \n");
	    	for( i=0;i<n-1;i++){
	  		printf("p%d -> " ,ans[i]);
			}
			printf("p%d \n\n", ans[n-1]);

		}


	return 0;
}


//in

#include<stdio.h>
#include<stdbool.h>

int main(){
  int n,m;
  printf("Enter the number of processes: \n");
  scanf("%d",&n);
  printf("Enter the number of resources: \n");
  scanf("%d",&m);
  
  int alloc[n][m];
  int max[n][m];
  int avail[m];
  printf("enter the allocation matrix :\n");
  for(int i = 0; i<n ;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&alloc[i][j]);
    }
  }
  printf("enter the maximum matrix :\n");
  for(int i = 0; i<n ;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&max[i][j]);
    }
  }
  printf("enter the available resources : \n");
  for(int i =0;i<m;i++){
    scanf("%d",&avail[i]);
  }
  int need[n][m];
  for(int i = 0; i<n ;i++){
    for(int j=0;j<m;j++){
      need[i][j]=max[i][j]-alloc[i][j];
    }
  }
  int f[n],ans[n],ind = 0;
  for (int k=0;k<n;k++){
    f[k]=0;
  }
  int y = 0;
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      if(f[i] == 0){
        int flag = 0;
        for(int j =0;j<m;j++){
          if(need[i][j]>avail[j]){
            flag = 1;
            break;
          }
        }
        if(flag==0){
          ans[ind++] = i;
          for(y =0;y<m;y++){
            avail[y]+=alloc[i][y];
          }
          f[i] = 1;
        } 
      }
    }
  }
  int flag = 1;
  for(int i=0;i<n;i++){
    if(f[i]==0){
      flag =0 ;
      printf("the system is not safe:\n");
      break;
    }
  }
  if(flag==1){
    printf("the system is safe and sequence is \n");
    for(int i =0;i<n-1;i++){
      printf("P%d --> ",ans[i]);
    }
    printf("P%d \n",ans[n-1]);
  }
  return 0;
  
}