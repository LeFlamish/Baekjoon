#include <stdio.h>

int arr[10][10];
int arr2[10][10];
int virus[64][2];
int num;
int n,m;

int xx[4]={0,0,-1,1};
int yy[4]={1,-1,0,0};

void dfs(int x, int y){
	for(int i=0;i<4;i++){
		int X = x+xx[i];
		int Y = y+yy[i];
		
		if(X>0 && X<=n && Y>0 && Y<=m && !arr2[X][Y]){
			arr2[X][Y] = 2;
			dfs(X,Y);
		}
	}
	
	return;
}

int main(){
	int x1,x2,x3,y1,y2,y3;
	int ans = 0;
	
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&arr[i][j]);
			arr2[i][j] = arr[i][j];
			
			if(arr[i][j]==2){
				virus[num][0] = i;
				virus[num][1] = j;
				num++;
			}
		}
			
	for(int i=0;i<n*m;i++){
		x1=i/m+1; y1=i%m+1;
		if(!arr2[x1][y1])
		for(int j=i+1;j<n*m;j++){
			x2=j/m+1; y2=j%m+1;
			if(!arr2[x2][y2])
			for(int k=j+1;k<n*m;k++){
				x3=k/m+1; y3=k%m+1;
				if(!arr2[x3][y3]){
					arr2[x1][y1] = 1;
					arr2[x2][y2] = 1;
					arr2[x3][y3] = 1;
					
					for(int p=0;p<num;p++)
						dfs(virus[p][0],virus[p][1]);
					
					int cnt = 0;
					
					for(int p=1;p<=n;p++)
						for(int q=1;q<=m;q++)
							if(!arr2[p][q]) cnt++;
					
					if(ans<cnt)
						ans = cnt;
					
					for(int p=1;p<=n;p++)
						for(int q=1;q<=m;q++)
							arr2[p][q] = arr[p][q];
				}
			}
		}
	}
	
	printf("%d",ans);
	
	return 0;
}