/*************************************************************************************************\
|*                                                                                               *|
|*   projeto.cpp: Projeto de AED I                                                               *|
|*   Autores: Andrey Gogora dos Santos - 11026411                                                *|
|*		    Gustavo Torres Custódio - 11130311                                                   *|
|*   Versão: 1.0          Data: 27/06/2013                                                       *|
|*                                                                                               *|
\*************************************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>
using namespace std;

//Protótipo de Funções
void bubble_sort(int V[], int n);
void insertion_sort(int V[], int n);
void selection_sort(int V[], int n);
void quick_sort(int V[], int n);
void quick_sort1(int V[], int n);
void merge_sort(int V[], int n);
void heap_sort(int V[], int n);
void exibeVetor(int V[], int n);
void preencherVetor(int V[],int n,int seed);
void testaInvertido();
void preencherVetorInvertido(int V[],int n);

int timeout(int seconds)
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {
    
    }

    return  1;
}

//INICIO DO MAIN
main()
{
	int to=1200;//to -> timeout=1200 segundos;
  	int t[9];
  	/*t[0]=65610000;
	t[1]=30000;
	t[2]=90000;
	t[3]=270000;
	t[4]=810000;
	t[5]=2430000;
	t[6]=7290000;
	t[7]=21870000;
	t[8]=65610000;*/
  	t[0]=656;
	t[1]=300;
	t[2]=900;
	t[3]=2700;
	t[4]=810;
	t[5]=2430;
	t[6]=729;
	t[7]=218;
	t[8]=656;
  	int seed[6];
  	seed[0]=4;
  	seed[1]=81;
  	seed[2]=151;
  	seed[3]=1601;
  	seed[4]=2307;
  	seed[5]=4207;
  	for(int j=0;j<=8;j++)
  	{
		cout << "-----------------------SEQUENCIA DE " << t[j] << " ELEMENTOS -------------------------" << endl;
	  	for(int i=0;i<=5;i++)
	  	{
			int n=t[j];
			int *V=(int *)malloc(n * sizeof(int));
	  		clock_t start_time;
			
			preencherVetor(V,n,seed[i]);
			start_time = clock();
			insertion_sort(V,n);
			double itime_in_seconds = (clock() - start_time) / (double)CLOCKS_PER_SEC;
			printf("INSERTION[%d]Tempo gasto em segundos %.3f\n\n",i+1,itime_in_seconds);
		
	  		preencherVetor(V,n,seed[i]);
			start_time = clock();
			selection_sort(V,n);
			double stime_in_seconds = (clock() - start_time) / (double)CLOCKS_PER_SEC;
			printf("SELECTION[%d]Tempo gasto em segundos %.3f\n\n",i+1,stime_in_seconds);
			
			preencherVetor(V,n,seed[i]);
			start_time = clock();
			bubble_sort(V,n);
			double btime_in_seconds = (clock() - start_time) / (double)CLOCKS_PER_SEC;
			printf("BUBBLE[%d]Tempo gasto em segundos %.3f\n\n",i+1,btime_in_seconds);
	
	  		preencherVetor(V,n,seed[i]);
			start_time = clock();
			quick_sort(V,n);
			double qtime_in_seconds = (clock() - start_time) / (double)CLOCKS_PER_SEC;
			printf("QUICK[%d]Tempo gasto em segundos %.3f\n\n",i+1,qtime_in_seconds);
			
			preencherVetor(V,n,seed[i]);
			start_time = clock();
			heap_sort(V,n);
			double htime_in_seconds = (clock() - start_time) / (double)CLOCKS_PER_SEC;
			printf("HEAP[%d]Tempo gasto em segundos %.3f\n\n",i+1,htime_in_seconds);
			
			preencherVetor(V,n,seed[i]);
			start_time = clock();
			merge_sort(V,n);
			double mtime_in_seconds = (clock() - start_time) / (double)CLOCKS_PER_SEC;
			printf("MERGE[%d]Tempo gasto em segundos %.3f\n\n\n",i+1,mtime_in_seconds);
            
            free(V);			
		}
	}
	cout << "---------------------SEQUENCIA INVERTIDA DE 50000 ELEMENTOS -------------------" << endl;
	testaInvertido();
  	system("PAUSE");
  	system("PAUSE");
  	system("PAUSE");
}
//FIM DO MAIN

void testaInvertido(){
    int n=50000;
    int *V=(int *)malloc(n * sizeof(int));
    clock_t start_time;
			
    preencherVetorInvertido(V,n);
    start_time = clock();
    insertion_sort(V,n);
    double itime_in_seconds = (clock() - start_time) / (double)CLOCKS_PER_SEC;
    printf("INSERTION invertido. Tempo gasto em segundos %.3f\n\n",itime_in_seconds);
    preencherVetorInvertido(V,n);	
	start_time = clock();
	selection_sort(V,n);
	double stime_in_seconds = (clock() - start_time) / (double)CLOCKS_PER_SEC;
	printf("SELECTION invertido. Tempo gasto em segundos %.3f\n\n",stime_in_seconds);
	
	preencherVetorInvertido(V,n);
	start_time = clock();
	bubble_sort(V,n);
	double btime_in_seconds = (clock() - start_time) / (double)CLOCKS_PER_SEC;
	printf("BUBBLE invertido. Tempo gasto em segundos %.3f\n\n",btime_in_seconds);
	
	preencherVetorInvertido(V,n);
	start_time = clock();
	quick_sort(V,n);
	double qtime_in_seconds = (clock() - start_time) / (double)CLOCKS_PER_SEC;
	printf("QUICK invertido. Tempo gasto em segundos %.3f\n\n",qtime_in_seconds);
			
	preencherVetorInvertido(V,n);
	start_time = clock();
	heap_sort(V,n);
	double htime_in_seconds = (clock() - start_time) / (double)CLOCKS_PER_SEC;
	printf("HEAP invertido. Tempo gasto em segundos %.3f\n\n",htime_in_seconds);
			
	preencherVetorInvertido(V,n);
	start_time = clock();
	merge_sort(V,n);
	double mtime_in_seconds = (clock() - start_time) / (double)CLOCKS_PER_SEC;
	printf("MERGE invertido. Tempo gasto em segundos %.3f\n\n\n",mtime_in_seconds);
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//INICIO DO INSERTIONSORT
void insertion_sort(int V[],int n)
{
    int key;
	int i;
	for (int j=1; j < n; j++)
	{
		key = V[j];
		i = j-1;
		while ((i>=0) && (V[i]>key))
		{
			V[i+1] = V[i];
			i=i-1;
		}
		V[i+1] = key;
	}
}
//FIM DO INSERTIONSORT
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//INICIO DO SELECTIONSORT
void selection_sort(int V[], int n)
{
	int key;
	int index;
	for (int i=0; i < n; i++)
	{
		key = V[i];
		index = i;
		for (int j = i+1; j < n; j++)
		{
			if (V[j]<key)
			{
				key = V[j];
				index = j;
			}
		}
		V[index]= V[i];
		V[i] = key;
	}
}
//FIM DO SELECTIONSORT
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//INICIO DO BUBBLESORT
void bubble_sort(int V[], int n)
{
	int key;
	int pass=1;
	bool ordenado=false;
	while ((pass<n) && (ordenado==false))
	{
		ordenado=true;
		for (int i=0; i < n-pass; i++)
		{
			if (V[i]>V[i+1])
			{
				key = V[i];
				V[i] = V[i+1];
				V[i+1] = key;
				ordenado=false;
			}
		}
		pass=pass+1;
	}
}
//FIM DO BUBBLESORT
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//INICIO DO MERGESORT
void merge(int V[], int ini, int meio, int fim)
{
	int p = meio-ini+1;
	int m = fim-meio;
	int L[fim], R[fim];
		for (int i=0; i<p; i++) L[i] = V[ini+i];
		for (int j=1; j<=m; j++) R[j-1] = V[(meio+j)];
		L[p] = INT_MAX;
		R[m] = INT_MAX;
		int i = 0;
		int j = 0;
		for (int k=ini; k<=fim; k++){
		if (L[i]<=R[j]){
		V[k] = L[i];
		i = i+1;
		} 
		else 
		{
			V[k] = R[j];
			j = j+1;
		}
	}
}

void mergesort2(int V[], int ini, int fim)
{
	if (ini<fim)
	{
		int meio = (int)floor((ini+fim)/2);
		mergesort2(V,ini,meio);
		mergesort2(V,meio+1,fim);
		merge(V,ini,meio,fim);
	}
}

void merge_sort(int V[], int n)
{
	mergesort2(V,0,n-1);
}

//FIM DO MERGESORT
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//INICIO DO HEAPSORT
void Heapify(int V[], int i, int NHeap)
{
	int le, ri, maior, aux;
	le = (2*i);
	ri = ((2*i)+1);
	
	if ((le<NHeap) && (V[le]>V[i]))
		maior = le;
	else 
		maior = i;
		
	if ((ri<NHeap) && (V[ri]>V[maior]))
		maior = ri;
		
	if (maior != i)
	{
		aux = V[i];
		V[i] = V[maior];
		V[maior] = aux;
		Heapify(V,maior,NHeap);
	}
}

void HeapBuild(int V[], int n)
{
	for(int i=(int)floor(n/2); i>=0; i--)
		Heapify(V,i,n);
}

void heap_sort(int V[], int n)
{
	int aux;
	int NHeap=n;
	HeapBuild(V,n);
	for(int i=(n-1); i>=0; i--) 
	{
		aux = V[0];
		V[0] = V[i];
		V[i] = aux;
		NHeap = NHeap-1;
		Heapify(V,0,NHeap);
	}
}

//FIM DO HEAPSORT
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//INICIO DO QUICKSORT
int particao(int V[], int p, int r)
{
	int aux;
	int pivo = V[r];
	int i = p-1;
	for (int j=p; j <= r-1; j++)
	{
		if (V[j] <= pivo)
		{
			i=i+1;
			aux = V[i];
			V[i] = V[j];
			V[j] = aux;
		}
	}
	aux = V[i+1];
	V[i+1] = V[r];
	V[r] = aux;
	return (i+1);
}

void quicksort2(int V[], int p, int r)
{
	if (p<r)
	{
		int q = particao(V,p,r);
		quicksort2(V,p,q-1);
		quicksort2(V,q+1,r);
	}
}

void quick_sort1(int V[], int n)
{
	quicksort2(V,0,n-1);
}
//FIM DO QUICKSORT
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//INICIO DO QUICKSORT Aleatorio
int particaoAleatoria(int V[], int p, int r)
{
	int x=p+(rand()%(r-p));
	int aux = V[r];
	V[r]=V[x];
	V[x]=aux;
	return particao(V,p,r);
}

void quicksortAleatorio(int V[], int p, int r)
{
	if(p<r)
	{
		int q = particaoAleatoria(V,p,r);
		quicksortAleatorio(V,p,q-1);
		quicksortAleatorio(V,q+1,r);
	}
}

void quick_sort(int V[], int n)
{
	quicksortAleatorio(V,0,n-1);
}
//FIM DO QUICKSORT ALEATORIO
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//Exibe o Vetor
void exibeVetor(int V[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout << V[i] << endl;
    }
    cout << endl;
}
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//Preenche o Vetor

void preencherVetor(int V[],int n,int seed)
{
  	srand(seed);
  	for(int i=0;i<n;i++)
	{
        V[i]=rand();
	}
}
void preencherVetorInvertido(int V[],int n)
{
  	for(int i=0;i<n;i++)
	{
	    V[i]=50000-i;
	}
}

void escreverVetor(int n, int tempo){
    ofstream myfile;
    myfile.open()
}
