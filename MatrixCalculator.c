#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void onNumber(int **matr,int rows,int cols);
void sum(int **matr,int rows,int cols);
void difference(int **matr,int rows,int cols);
void multy(int **matr,int rows,int cols);
void transponovana(int **matr,int rows,int cols);
void determinant(int **matr,int rows,int cols);
void powMatrix(int **matr,int rows,int cols);
char continues();
void inputRowsCols(int *rows,int *cols);
void dinamic(int ***matr,int rows,int cols);
void outputMatrix(int **matr,int rows,int cols);


int main(){
	setlocale(LC_ALL, "Russian");
   // SetConsoleCP(1251);
   // SetConsoleOutputCP(1251);
    int rows,cols;
    int **matr;
    char number;
    	
    do{
    printf("\n########################################################################");	
    printf("\n�������� �������� ��� ���������:\n");
    printf("\n1 : ��������� ������� �� �����\t\t2: �������� ���� ������\n");
    printf("\n3 : ������� ���� ������\t\t\t4: ��������� ���� ������\n");
    printf("\n5 : �������������� �������\t\t6: ������������ �������\n");
    printf("\n7 : ���������� ������� � �������\n");
    printf("########################################################################\n\n");	
    number=getch();
    printf("��� ����� : %c",number);
    getch(); 
    system("cls");

    switch(number){
    case '1': onNumber(matr,rows,cols); break;
    case '2': sum(matr,rows,cols); break;
    case '3': difference(matr,rows,cols);break;
    case '4': multy(matr,rows,cols); break;
    case '5': transponovana(matr,rows,cols); break;
    case '6': determinant(matr,rows,cols); break;
    case '7': powMatrix(matr,rows,cols); break;
    default: printf("������� ��������� ��������!\n");
    }
    }
    while((number<='0' || number>'7') || continues()=='1');
    }

//-------------------------------------------------------
void onNumber(int **matr,int rows,int cols)
    {   
    int i,j,k,l;
    inputRowsCols(&rows,&cols);  
    dinamic(&matr,rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
        	printf("�������:\n");
            for(k=0;k<rows;k++){
        	    for(l=0;l<cols;l++){
        		printf("[%d]  ",matr[k][l]);
			    }
			    printf("\n");
	            }
	            printf("������� ������� �������: ");
                scanf("%d",&matr[i][j]);
                fflush(stdin);
                system("cls");
                }
    }
    outputMatrix(matr,rows,cols);
    int num;
    printf("\n������� �����: ");
    scanf("%d",&num);
    fflush(stdin);
    printf("\n���������: \n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            matr[i][j]=matr[i][j]*num;
            printf("%2i ",matr[i][j]);
            }
            printf("\n");
            }
    getch();
}

//------------------------------------------------------------
void sum(int **matr,int rows,int cols)
	{   
	int i,j,k,l,rows1,cols1;
	int **matr1,**res;
    inputRowsCols(&rows,&cols);
    dinamic(&matr,rows,cols);
 
     for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
        	printf("�������:\n");
            for(k=0;k<rows;k++){
        	    for(l=0;l<cols;l++){
        		printf("[%d]  ",matr[k][l]);
			    }
			    printf("\n");
	            }
	            printf("������� ������� �������: ");
                scanf("%d",&matr[i][j]);
                system("cls");
                }
    } 
    outputMatrix(matr,rows,cols);
	//-------------------------------------------------
	do{
	 printf(" ������� �������� ���������� ����� ������ �������: ");
            scanf("%d",&rows1);
            fflush(stdin);
            printf(" ������� �������� ���������� �������� ������ �������: ");
            scanf("%d",&cols1);
            fflush(stdin);
            	if(cols!=cols1 || rows!=rows1 || rows1<=0 || cols1<=0) {
				printf(" ���������� �������� �����! ��������� �������!\n");
			    }
    }while(cols!=cols1 || rows!=rows1);
    dinamic(&matr1,rows1,cols1);
     for(i=0;i<rows1;i++){
        for(j=0;j<cols1;j++){
        	printf("�������:\n");
            for(k=0;k<rows1;k++){
        	    for(l=0;l<cols1;l++){
        		printf("[%d]  ",matr1[k][l]);
			    }
			    printf("\n");
	            }
	            printf("������� ������� �������: ");
                scanf("%d",&matr1[i][j]);
                system("cls");
                }
    }
    dinamic(&res,rows,cols);
    printf("\n������ �������:\n");
    outputMatrix(matr,rows,cols);
    printf("\n������ �������:\n");
    outputMatrix(matr1,rows1,cols1);
    printf("\n���������: \n");
   	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			res[i][j]=matr[i][j]+matr1[i][j];
				printf("%2d ",res[i][j]);
			    }
				printf("\n");
			    }
}

//----------------------------------------------------------
void difference(int **matr,int rows,int cols)
	{   
	int i,j,k,l,rows1,cols1;
	int **matr1,**res;
	inputRowsCols(&rows,&cols);
	dinamic(&matr,rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
        	printf("�������:\n");
            for(k=0;k<rows;k++){
        	    for(l=0;l<cols;l++){
        		printf("[%d]  ",matr[k][l]);
			    }
			    printf("\n");
	            }
	            printf("������� ������� �������: ");
                scanf("%d",&matr[i][j]);
                system("cls");
                }
    }
    outputMatrix(matr,rows,cols);
	//--------------------------
    do{
	printf(" ������� �������� ���������� ����� ������ �������: ");
            scanf("%d",&rows1);
            printf(" ������� �������� ���������� �������� ������ �������: ");
            scanf("%d",&cols1);
            	if(cols!=cols1 || rows!=rows1 || rows1<=0 || cols1<=0) {
				printf(" ���������� �������� �����! ��������� �������!\n");
			    }
    }while(cols!=cols1 || rows!=rows1);
    dinamic(&matr1,rows1,cols1);
    for(i=0;i<rows1;i++){
        for(j=0;j<cols1;j++){
        	printf("�������:\n");
            for(k=0;k<rows1;k++){
        	    for(l=0;l<cols1;l++){
        		printf("[%d]  ",matr1[k][l]);
			    }
			    printf("\n");
	            }
	            printf("������� ������� �������: ");
                scanf("%d",&matr1[i][j]);
                system("cls");
                }
    } 
    outputMatrix(matr1,rows1,cols1);
    dinamic(&res,rows,cols);
    printf("\n������ �������:\n");
    outputMatrix(matr,rows,cols);
    printf("\n������ �������:\n");
    outputMatrix(matr1,rows1,cols1);
    printf("\n���������: \n");
   	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			res[i][j]=matr[i][j]-matr1[i][j];
				printf("%2d ",res[i][j]);
			}
				printf("\n");
			}
}

//--------------------------------------------------------------
void multy(int **matr,int rows,int cols){
	int i,j,k,l,rows1,cols1;
	int **matr1,**res;
	inputRowsCols(&rows,&cols);
    dinamic(&matr,rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
        	printf("�������:\n");
            for(k=0;k<rows;k++){
        	    for(l=0;l<cols;l++){
        		printf("[%d]  ",matr[k][l]);
			    }
			    printf("\n");
	            }
	            printf("������� ������� �������: ");
                scanf("%d",&matr[i][j]);
                system("cls");
                }
    } 
    outputMatrix(matr,rows,cols);
	//-------------------------------------------------
    do{
	        printf(" ������� �������� ���������� ����� ������ �������: ");
            scanf("%d",&rows1);
            printf(" ������� �������� ���������� �������� ������ �������: ");
            scanf("%d",&cols1);
            if(cols!=rows1 || rows1<=0 || cols1<=0) {
			printf(" ���������� �������� �����! ��������� �������!\n");
			}
    }while(cols!=rows1);
    dinamic(&matr1,rows1,cols1);
    for(i=0;i<rows1;i++){
        for(j=0;j<cols1;j++){
        	printf("�������:\n");
            for(k=0;k<rows1;k++){
        	    for(l=0;l<cols1;l++){
        		printf("[%d]  ",matr1[k][l]);
			    }
			    printf("\n");
	            }
	            printf("������� ������� �������: ");
                scanf("%d",&matr1[i][j]);
                system("cls");
                }
    }
    outputMatrix(matr1,rows1,cols1);
	dinamic(&res,rows,cols1);
    printf("\n������ �������:\n");
    outputMatrix(matr,rows,cols);
    printf("\n������ �������:\n");
    outputMatrix(matr1,rows1,cols1);
    printf("\n���������: \n");
    for(i=0;i<rows;i++){
		for(j=0;j<cols1;j++){
			res[i][j]=0;
			for(k=0;k<cols;k++)
			res[i][j]+=matr[i][k]*matr1[k][j];
		}
		printf("\n");
		}
		outputMatrix(res,rows,cols1);
}
//--------------------------------------------
void transponovana(int **matr,int rows,int cols)
{
	int i,j,k,l,rows1,cols1;
	int **res;
    inputRowsCols(&rows,&cols);
    dinamic(&matr,rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
        	printf("�������:\n");
            for(k=0;k<rows;k++){
        	    for(l=0;l<cols;l++){
        		printf("[%d]  ",matr[k][l]);
			    }
			    printf("\n");
	            }
	            printf("������� ������� �������: ");
                scanf("%d",&matr[i][j]);
                system("cls");
                }
    }
    outputMatrix(matr,rows,cols);
    dinamic(&res,cols,rows);
	 for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
        	res[j][i]=matr[i][j];
        }
    }
    printf("\n�������:\n");
    outputMatrix(matr,rows,cols);
    printf("\n���������: \n");  
    for(i=0;i<cols;i++){
        for(j=0;j<rows;j++){
        	printf("%2d ",res[i][j]);
        }
        printf("\n");
    }
}
//------------------------------------------------------------
void determinant(int **matr,int rows,int cols){   //������ ��� 2��2 3��3 �������� ����
	int i,j,k,l,det;
    do{
            printf("\n������� �������� ���������� �����: ");
            scanf("%d",&rows);
            fflush(stdin);
            printf("\n������� �������� ���������� ��������: ");
            scanf("%d",&cols);
            fflush(stdin);
            if(cols>=4 || rows >=4){
	            printf("�� ���� ��� �� ����� ������ ��� ������! �� �� �������� ��� ����! �������� ���� ��������� :)");
				getch();
				return;
	        }
    }while((rows!=cols) || rows<=0 || cols<=0);
    
    dinamic(&matr,rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
        	printf("�������:\n");
            for(k=0;k<rows;k++){
        	    for(l=0;l<cols;l++){
        		printf("[%d]  ",matr[k][l]);
			    }
			    printf("\n");
	            }
	            printf("������� ������� �������: ");
                scanf("%d",&matr[i][j]);
                system("cls");
                }
    }
    outputMatrix(matr,rows,cols);
    printf("\n���������: \n");  
	if (rows==1) {
	printf("Determinant = %d ",matr[0][0]);	
	}
	else{
	if(rows==2) {
		det=matr[0][0]*matr[1][1]-matr[0][1]*matr[1][0];
		printf("Determinant = %d ",det);	
			}
	if(rows==3){
		det=matr[0][0]*matr[1][1]*matr[2][2]+
		matr[0][1]*matr[1][2]*matr[2][0]+
		matr[1][0]*matr[2][1]*matr[0][2]-
		matr[2][0]*matr[1][1]*matr[0][2]-
		matr[0][0]*matr[2][1]*matr[1][2]-
		matr[1][0]*matr[0][1]*matr[2][2];
		printf("Determinant = %d ",det);	
	}	
	}
}

//----------------------- -----------------------------
char continues(){
    char i;
    printf("\n������� 1, ���� ������� ����������:");
    i=getch();
    printf("%c\n",i);
    if(i=='1'){
    	system("cls");
	}
    return i;
  }
//---------------------------------------------------
void inputRowsCols(int *rows,int *cols){
  	int i;
  		do{
    printf(" ������� �������� ���������� �����: ");
    scanf("%d",rows);
    fflush(stdin);
    printf(" ������� �������� ���������� ��������: ");
    scanf("%d",cols);
    fflush(stdin);
    if(*rows<=0 || *cols<=0) {
	printf(" ���������� �������� �����! ��������� �������!");
	}
    }while(*rows<=0 || *cols<=0);
}
//---------------------------------------------------    
void dinamic(int ***matr,int rows,int cols){
	int i;
    *matr=(int**)calloc(rows,sizeof(int*)); 
    for(i=0;i<rows;i++){
        *(*matr+i)=(int*)calloc(cols,sizeof(int)); 
    }
    system("cls");
  }
  
//----------------------------------------
void outputMatrix(int **matr,int rows,int cols){
  	int i,j;
  	for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf(" %2i ",matr[i][j]); 
            }
            printf("\n");
    }
}
//---------------------------------------------------
void powMatrix(int **matr,int rows,int cols){
	int i,j,k,l,pow;
	int **res,**matr1;
    do{
            printf("\n������� �������� ���������� �����: ");
            scanf("%d",&rows);
            fflush(stdin);
            printf("\n������� �������� ���������� ��������: ");
            scanf("%d",&cols);
            fflush(stdin);
    }while((rows!=cols) || rows<=0 || cols<=0);
    dinamic(&matr,rows,cols);
    dinamic(&matr1,rows,cols);
	dinamic(&res,rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
        	printf("�������:\n");
            for(k=0;k<rows;k++){
        	    for(l=0;l<cols;l++){
        		printf("[%d]  ",matr[k][l]);
			    }
			    printf("\n");
	            }
	            printf("������� ������� �������: ");
                scanf("%d",&matr[i][j]);
                res[i][j]=i==j;
                system("cls");
                }
    }
    outputMatrix(matr,rows,cols);
    do{
    printf("������� �������: ");
    scanf("%d",&pow);
    fflush(stdin);
    } while(pow<1);
    printf("\n���������: \n");
    int sum;
    for(i=0;i<pow;i++){
		for(j=0;j<rows;j++){
			for(k=0;k<cols;k++){
				sum=0;
				for(l=0;l<rows;l++){
		        sum+=matr[j][l]*res[l][k];
		}
		matr1[j][k]=sum;
		}
	}
	for(j=0;j<rows;j++){
		for(k=0;k<cols;k++){
			res[j][k]=matr1[j][k];
         	}
        }
    }
    outputMatrix(res,rows,cols);	
	}
