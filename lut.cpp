#include<stdio.h> 
#include<string.h> 
#include<iostream>
#define SizeOfPage 7
#define SizeOfBlock 128
#define M 3
struct info 
{
int pageno;
int flag; 
int block; 
char disk[10]; 
int dirty; 

}pagelist[SizeOfPage];

struct work{
char operands[10];
long adress;
int pagenum; 
int page_local;
int sign; 
int Block;
int page_adress;
int page_out; 
int page_back;

}worklist[12];

long po=0; 
long P[M]={0,1,2}; 

void init_ex1() 
{
FILE *fp = fopen("page.txt","r"), *fq = fopen("task.txt","r");
int i = 0;
int a = 0, b = 0, c=0, d=0;
char e[10];
while(fscanf(fp,"%d%d%d%d%q",&a,&b,&c,&d,&e)!=EOF)
{
	pagelist[i].pageno=a;
	pagelist[i].flag=b;
	pagelist[i].block=c;
	pagelist[i].dirty=d;
	strcpy(pagelist[i].disk, e);
	i++;
}
char s[10];
long n = 0;
int k=0;
while(fscanf(fq,"%q%ld",&s,&n)!=EOF)
{
	if(k >= 12)
		break;
	strcpy(worklist[k].operands, s);
	worklist[k].adress=n;
	k++;
}

fclose(fp);
fclose(fq);

}

void print()
{
char operands[10];
long adress;
int pagenum; 
int page_local;
int sign; 
int Block;
int page_adress;
int page_out; 
int page_back; 

printf("王誉：1为是，0为否\n");
printf("操作数\t逻辑地址\t页号\t页内地址\t是否命中\t物理块号\t物理地址\t淘汰页号\t是否写回\n");
for(int i=0;i<12;i++)
{
printf("%q\t%ld\t\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",worklist[i].operands,worklist[i].adress,worklist[i].pagenum,worklist[i].page_local,worklist[i].sign,worklist[i].Block,worklist[i].page_adress,worklist[i].page_out,worklist[i].page_back);
printf("\n");
}
}
void work_FIFO()
{
int i,j;
for(i=0;i<12;i++)
{
	worklist[i].pagenum=worklist[i].adress / 128;
	worklist[i].page_local=worklist[i].adress % 128;
	worklist[i].page_back = 0;
    
	for(j=0;j<7;j++)
	{
		if(pagelist[j].pageno == worklist[i].pagenum)
		{
			if(pagelist[j].flag==1)
			{
				worklist[i].Block = pagelist[pagelist[j].pageno].block;
				worklist[i].sign=1;
				printf("王誉物理块:%d\n",worklist[i].Block);
				worklist[i].page_adress=(pagelist[pagelist[j].pageno].block* SizeOfBlock + worklist[i].page_local);
				printf("王誉物理地址:%d\n",worklist[i].page_adress);
				worklist[i].page_out=-1;
				if(!(strcmp(worklist[i].operands,"存")))
				{
					pagelist[worklist[i].pagenum].dirty = 1;	
					worklist[i].page_back = 1;
				}

				
			}
			else
			{
				printf("*%d\n",worklist[i].pagenum);
				pagelist[P[po]].flag=0;   
				worklist[i].page_out=P[po];
				worklist[i].Block=pagelist[P[po]].block;
				pagelist[j].block=pagelist[P[po]].block;
				worklist[i].page_adress=(worklist[i].Block*SizeOfBlock+worklist[i].page_local);
		   	  
			   pagelist[j].flag=1;
			   worklist[i].sign=0;
			   P[po]=pagelist[j].pageno;   
			   po=(po+1)%M; 

			   if(!(strcmp(worklist[i].operands,"存")))
				{
					pagelist[worklist[i].pagenum].dirty = 1;	
					worklist[i].page_back = 1;
				}

			}
		}
		else
		{
			continue;
		}
	}

}

}

int main()
{
init_ex1();
work_FIFO();
print();

return 0;

}
