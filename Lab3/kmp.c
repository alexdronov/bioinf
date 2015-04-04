#include<stdio.h>
#include<string.h>

int counter=0;
void picalculator(char pattern[],int pi[],int patlen)
{
	int i,j;
	pi[0]=0;
	j=0;
	i=1;
	while(i<patlen){
		if(pattern[i]==pattern[j]){
			pi[i]=j+1;
			i++;
			j++;
                        
		}else if(j>0){
			j=pi[j-1];
		}else {
			pi[i]=0;
			i++;
		}counter++;
	}

}



int kmp_matcher(char text[], char pattern[])
{
	int i,j,F[100];
	int patlen=strlen(pattern);
	int textlen=strlen(text);
	picalculator(pattern,F,patlen);
	i=0;
	j=0;
	while(i<textlen){
		if(text[i]==pattern[j]){
                       
			if(j==patlen-1)
				return i-j;
			else{
				i++;
				j++;
			}
		}else if(j>0){
			j=F[j-1];
		}else{
			i++;
		} counter++;
	}
	return -1;
}


int main()
{
	char T[1000],P[100];
          printf("\nString: \n");
	while(gets(T)){
                printf("\nPattern: \n");
		gets(P);
		int pos=kmp_matcher(T,P);
		if(pos!=-1){
			printf("\nPosition:%d \n",pos+1);
                        printf("Comparisions:%d \n",counter);
		        counter=0; 
                }else{
 			printf("\nNo match found.\n");
                        counter=0; 
                     }
               printf("\nString: \n");
	}

 return 0;
}