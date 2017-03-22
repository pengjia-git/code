#include <stdio.h>
//int is_end(char matrix[10][10],struct point *node );

void display_matrix(char matrix[10][10])
{
  int i,j;
  for(i=0;i<10;i++){
    for(j=0;j<10;j++){
      if(matrix[i][j] == '0'){
	printf("#");
      }
      else{
	printf("-");
      }
      /*if(matrix[i][j] == 'e'){
	printf("\nfind end\n");
	}*/
      //printf("matrix[i][j]=%x",matrix[i][j]);

    }
    printf("\n");
  }
}

void get_matrix(char matrix[10][10])
{
  FILE *fp;
  int row_size;
  int i=0;
  char temp;
  fp=fopen("matrix.txt","r");
  if(fp == NULL){
    printf("open matrix.txt fail\n");
  }

  for(i=0;i<10;i++){
    row_size=fread(matrix[i],1,10,fp);
    if(row_size != 10){
      printf("read file error\n");
      return ;
    }
    fread(&temp,1,1,fp);
  }
}

struct point{
  int x;
  int y;
  int dir_flag;
#define DIR_NONE 0
#define DIR_UP 0x01
#define DIR_RIGHT 0x02
#define DIR_DOWN 0x04
#define DIR_LEFT 0X08
};

/*return val:1,this node is end node*/
int is_end(char matrix[10][10],struct point *node )
{
  if(matrix[node->x][node->y] == 'e'){
    return 1;
  }
  return 0;
}


int main()
{
  char matrix [10][10]={0};
  struct point path[100]={0};
  int top=0;
  
  memset(path,0,sizeof(path[100]));
  get_matrix(matrix);
  display_matrix(matrix);

  return 0;
}
