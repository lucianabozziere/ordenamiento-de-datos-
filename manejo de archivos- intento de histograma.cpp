#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(){
 	int i,j,n;
	int A=0,B=0;
 	srand(time(NULL));
 	printf("numero de elementos a ordenar\n");
 	scanf("%d", &n);
 	int lista[n];
 	printf("lista sin ordenar\n");
 	for (i=0;i<n;i++)
 	{
 		lista[i]=rand()% (30+1-1)+1;
 		printf(" %d ",lista[i]);
 	}
 	printf("\n");
 	
 	for (i=0;i<n;i++)
 	{
 		B= lista[i];
 		A=i-1;
 		while (A>=0 && lista[A]>B)
 		{
 			lista[A+1]= lista[A];
 			A--;
 		}
 		lista[A+1]=B; 
 	}
 	
 	printf("lista ordenada\n");
 	for(i=0;i<n;i++)
 	printf(" %d ",lista[i]);
 	printf("\n");
 	 
 	int minimo = lista[0];
    int maximo = lista[n - 1];

    printf("\nElemento menor: %d\n", minimo);
    printf("Elemento mayor: %d\n", maximo);
    printf("\n");
    
    int mediana;
    if (n % 2 == 0) 
	{
        mediana = (lista[n / 2 - 1] + lista[n / 2]) / 2;
    } 
	else 
	{
        mediana = lista[n / 2];
    }
    printf("Mediana: %d\n", mediana);
    
    float media= 0;
    for (i = 0; i < n; i++)
	{
        media += lista[i];
    }
    media /= n;
    printf("Media: %f\n", media);
    
    int moda = lista[0];
    int frecuencia = 1;
    int maxF = 1;

    for (i = 1; i < n; i++) {
        if (lista[i] == lista[i - 1]) 
		{
            frecuencia++;
        } 
		else 
		{
            if (frecuencia > maxF) 
			{
                maxF = frecuencia;
                moda = lista[i - 1];
            }
            frecuencia = 1;
        }
    }
    printf("Moda: %d\n", moda);  
    
    printf("Histograma:\n");

    for (i = minimo; i <= maximo; i++)
	 {
        int frec = 0;
        for (j = 0; j < n; j++) {
            if (lista[j] == i) {
                frec++;
            }
        }
        float probabilidad = (float)frec / n * 100;
        printf("%d: ", i);

        for (int k = 0; k < probabilidad; k++) {
            printf("*");
        }
        printf("\n");
    }
 	return 0;
}

