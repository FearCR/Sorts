#ifndef _CLASE_ORDENADOR
#define _CLASE_ORDENADOR
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <memory>
#include "time.h"
using namespace std;

class Ordenador{
private:

	//Defina aqu� los m�todos auxiliares de los algoritmos de ordenamiento solamente.
	//Puede definir cuantos m�todos quiera.

	void merge(int *arreglo, int primero, int mitad, int ultimo){ //mezcla arreglo[primero...mitad] y arreglo[mitad+1...ultimo]
		int tmp1=0;//controla el primer arreglo auxiliar
		int tmp2=0;//controla el segundo arreglo auxiliar
		int tmp3=primero;//controla el arreglo original


		int tamano1 = mitad - primero + 1;
		int tamano2 =  ultimo - mitad;
		int arr1[tamano1], arr2[tamano2];//areglos auxiliares

		for (int i = 0; i < tamano1; i++){ //se copian los elementos en los arreglos auxiliares
			arr1[i] = arreglo[primero + i];
		}
		for (int i = 0;i < tamano2; i++){
			arr2[i] = arreglo[mitad + 1+ i];
		}


		while (tmp1 < tamano1 && tmp2 < tamano2)//se empieza a mezclar
		{
			if (arr1[tmp1] <= arr2[tmp2])
			{
				arreglo[tmp3] = arr1[tmp1];
				tmp1++;
			}
			else
			{
				arreglo[tmp3] = arr2[tmp2];
				tmp2++;
			}
			tmp3++;
		}

		while (tmp1 < tamano1) //se insertan los elementos restantes del arreglo auxiliar 1
		{
			arreglo[tmp3] = arr1[tmp1];
			tmp1++;
			tmp3++;
		}

		while (tmp2 < tamano2)//se insertan los elementos restantes del arreglo auxiliar 2
		{
			arreglo[tmp3] = arr2[tmp2];
			tmp2++;
			tmp3++;
		}
	};

	void mergesortRecursivo(int * arreglo, int primero, int ultimo){ //llamado recursivo del mergesort
		if(primero<ultimo){
			int mitad=(primero+ultimo)/2;
			mergesortRecursivo(arreglo,primero,mitad);
			mergesortRecursivo(arreglo,mitad+1,ultimo);
			merge(arreglo,primero,mitad,ultimo);
		}
	};

	int particion(int * arreglo, int primero, int ultimo){

		int pivote,policiaMenor,policiaMayor,temp;
		pivote=arreglo[primero];
		policiaMenor=primero;
		policiaMayor=ultimo+1;
		do
		{
			do
			policiaMenor++;
			while(arreglo[policiaMenor]<pivote && policiaMenor<=ultimo);
			do
			policiaMayor--;
			while(pivote<arreglo[policiaMayor]);
			if(policiaMenor<policiaMayor)
			{
				temp=arreglo[policiaMenor];
				arreglo[policiaMenor]=arreglo[policiaMayor];
				arreglo[policiaMayor]=temp;
			}
		}while(policiaMenor<policiaMayor);
		arreglo[primero]=arreglo[policiaMayor];
		arreglo[policiaMayor]=pivote;
		return(policiaMayor);
	};

	void quicksortRecursivo(int * arreglo, int primero, int ultimo){
		if (primero < ultimo)
		{
			int pivote = particion(arreglo, primero, ultimo);
			quicksortRecursivo(arreglo, primero, pivote - 1);
			quicksortRecursivo(arreglo, pivote + 1, ultimo);
		}

	};



	void monticulizar(int * arreglo, int tamano, int i){//monticuliza y arregla cima
		int mayor = i;
		int hIzq = 2*i + 1; // hijo izquierdo
		int hDer = 2*i + 2; // hijo derecho
		// si el hijo izquierdo es mayor que la raiz
		if (hIzq < tamano && arreglo[hIzq] > arreglo[mayor]){
			mayor = hIzq;
		}
		//si el hijo derecho es mayor que mayor(raiz o hijo izquierdo)
		if (hDer < tamano && arreglo[hDer] > arreglo[mayor]){
			mayor = hDer;
		}

		if (mayor != i)
		{
			int tmp;
			tmp=arreglo[i];
			arreglo[i]= arreglo[mayor];
			arreglo[mayor]=tmp;
			monticulizar(arreglo, tamano, mayor);
		}
	};

	int getMayor(int arr[], int n)
	{
		int mx = arr[0];
		for (int i = 1; i < n; i++)
		if (arr[i] > mx)
		mx = arr[i];
		return mx;
	};



public:

	Ordenador(){};
	~Ordenador(){};

	//Si piensa no implementar algunos de los m�todos de ordenamiento, no los borre,
	//simplemente d�jelos con el cuerpo vac�o para evitar errores de compilaci�n, ya
	//que se va a ejecutar el mismo �main� para todas las tareas.
	void seleccion(int * arreglo, int tamano){
		int menor, temp;
		for (int i = 0; i < tamano; i++) {
			menor=i;
			for (int j = i+1; j < tamano; j++){
				if (arreglo[j]<arreglo[menor]){
					menor=j;
				}
			}
			temp=arreglo[i];
			arreglo[i]=arreglo[menor];
			arreglo[menor]=temp;
		}
	};
	void insercion(int * arreglo, int tamano){
		for (int i = 1; i < tamano; i++) {
			int tmp=arreglo[i];
			int j=i-1;
			while(arreglo[j]>tmp && j>=0){
				arreglo[j+1]=arreglo[j];
				j--;
			}
			arreglo[j+1]=tmp;
		}
	};
	void mergesort(int * arreglo, int tamano){
		mergesortRecursivo(arreglo,0,tamano-1);
	}

	void heapsort(int * arreglo, int tamano){
		int tmp;
		for (int i = tamano / 2 - 1; i >= 0; i--){
			monticulizar(arreglo, tamano, i);
		}
		//extaer cima;
		for (int i=tamano-1; i>=0; i--)
		{
			tmp=arreglo[0];
			arreglo[0]=arreglo[i];
			arreglo[i]=tmp;
			monticulizar(arreglo, i, 0);
		}
	};

	void quicksort(int * arreglo, int tamano){
		quicksortRecursivo(arreglo,0,tamano-1);
	};

	void radixsort(int* arreglo, int tamano){
		auto bin = make_unique<int[]>(tamano);
		int* bin_ptr = bin.get();
		auto m_bin = [](int x, int i){
			return (static_cast<unsigned int>(x) >> i*8) & 0xFF;
		};
		for ( int j = 0; j < 4; j++ ) {
			int count[256] = {};
			int inicio;
			//se construye C y el acumulado
			for (int i = 0; i < tamano; i++ ){
				count[m_bin(arreglo[i], j)]++;
			}
			if(j!=3){
				inicio=0;
			}else{
				inicio=128;
			}
			for ( int i = 1+inicio; i < 256+inicio; i++ ){
				count[i % 256] += count[(i-1) % 256];
			}
			//paso magico
			for (int i = tamano; i > 0; i-- ){
				bin_ptr[--count[m_bin(arreglo[i-1], j)]] = arreglo[i-1];
			}
			swap(arreglo, bin_ptr);
		}
	};

};
#endif
