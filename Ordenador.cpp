#include "Ordenador.h"
int main(int argc, char const *argv[]) {
  Ordenador o;
  double inicio;
  double final;
  double tiempo;
  time_t timer;
  int arreglo1[100000];
  int arreglo2[200000];
  int arreglo3[300000];
  int arreglo4[400000];


  for(int x=1;x<4;x++){
    for (int i = 0; i < 100000; i++) {
      arreglo1[i]=rand();
    }
    for (int i = 0; i < 200000; i++) {
      arreglo2[i]=rand();
    }
    for (int i = 0; i < 300000; i++) {
      arreglo3[i]=rand();
    }
    for (int i = 0; i < 400000; i++) {
      arreglo4[i]=rand();
    }


    //------------------------------Monticulos-----------------------
    cout<<"prueba heapsort 100000"<<endl;
    inicio=clock();
    o.heapsort(arreglo1,100000);
    final=clock();
    tiempo=(final-inicio)/CLOCKS_PER_SEC;
    cout<<"tiempo: "<<tiempo<<endl<<endl;
    for (int i = 1; i < 100000; i++) {
      if(arreglo1[i]<arreglo1[i-1]){
        cout<<"FALLO hs";
      }
    }
    cout<<"prueba heapsort 200000"<<endl;
    inicio=clock();
    o.heapsort(arreglo2,200000);
    final=clock();
    tiempo=(final-inicio)/CLOCKS_PER_SEC;
    cout<<"tiempo: "<<tiempo<<endl<<endl;
    for (int i = 1; i < 200000; i++) {
      if(arreglo2[i]<arreglo2[i-1]){
        cout<<"FALLO hs";
      }
    }
    cout<<"prueba heapsort 300000"<<endl;
    inicio=clock();
    o.heapsort(arreglo3,300000);
    final=clock();
    tiempo=(final-inicio)/CLOCKS_PER_SEC;
    cout<<"tiempo: "<<tiempo<<endl<<endl;
    for (int i = 1; i < 300000; i++) {
      if(arreglo3[i]<arreglo3[i-1]){
        cout<<"FALLO hs";
      }
    }
    cout<<"prueba heapsort 400000"<<endl;
    inicio=clock();
    o.heapsort(arreglo4,400000);
    final=clock();
    tiempo=(final-inicio)/CLOCKS_PER_SEC;
    cout<<"tiempo: "<<tiempo<<endl<<endl;
    for (int i = 1; i < 400000; i++) {
      if(arreglo4[i]<arreglo4[i-1]){
        cout<<"FALLO";
      }
    }
    //------------------------------Monticulos-----------------------

    for (int i = 0; i < 100000; i++) {
      arreglo1[i]=rand();
    }
    for (int i = 0; i < 200000; i++) {
      arreglo2[i]=rand();
    }
    for (int i = 0; i < 300000; i++) {
      arreglo3[i]=rand();
    }
    for (int i = 0; i < 400000; i++) {
      arreglo4[i]=rand();
    }

    //------------------------------Rapido-----------------------
    cout<<"prueba quicksort 100000"<<endl;
    inicio=clock();
    o.quicksort(arreglo1,100000);
    final=clock();
    tiempo=(final-inicio)/CLOCKS_PER_SEC;
    cout<<"tiempo: "<<tiempo<<endl<<endl;
    for (int i = 1; i < 100000; i++) {
      if(arreglo1[i]<arreglo1[i-1]){
        cout<<"FALLO qs en"<<i;
        return 0;
      }
    }
    cout<<"prueba quicksort 200000"<<endl;
    inicio=clock();
    o.quicksort(arreglo2,200000);
    final=clock();
    tiempo=(final-inicio)/CLOCKS_PER_SEC;
    cout<<"tiempo: "<<tiempo<<endl<<endl;
    for (int i = 1; i < 200000; i++) {
      if(arreglo2[i]<arreglo2[i-1]){
        cout<<"FALLO qs en "<< i;
        return 0;
      }
    }
    cout<<"prueba quicksort 300000"<<endl;
    inicio=clock();
    o.quicksort(arreglo3,300000);
    final=clock();
    tiempo=(final-inicio)/CLOCKS_PER_SEC;
    cout<<"tiempo: "<<tiempo<<endl<<endl;
    for (int i = 1; i < 300000; i++) {
      if(arreglo3[i]<arreglo3[i-1]){
        cout<<"FALLO qs en"<< i;
        return 0;
      }
    }
    cout<<"prueba quicksort 400000"<<endl;
    inicio=clock();
    o.quicksort(arreglo4,400000);
    final=clock();
    tiempo=(final-inicio)/CLOCKS_PER_SEC;
    cout<<"tiempo: "<<tiempo<<endl<<endl;
    for (int i = 1; i < 400000; i++) {
      if(arreglo4[i]<arreglo4[i-1]){
        cout<<"FALLO qs";
        return 0;
      }
    }
    //------------------------------Rapido-----------------------

    for (int i = 0; i < 100000; i++) {
      arreglo1[i]=rand();
    }
    for (int i = 0; i < 200000; i++) {
      arreglo2[i]=rand();
    }
    for (int i = 0; i < 300000; i++) {
      arreglo3[i]=rand();
    }
    for (int i = 0; i < 400000; i++) {
      arreglo4[i]=rand();
    }

    //------------------------------Residuos-----------------------
    cout<<"prueba radixsort 100000"<<endl;
    inicio=clock();
    o.radixsort(arreglo1,100000);
    final=clock();
    tiempo=(final-inicio)/CLOCKS_PER_SEC;
    cout<<"tiempo: "<<tiempo<<endl<<endl;
    for (int i = 1; i < 100000; i++) {
      if(arreglo1[i]<arreglo1[i-1]){
        cout<<"FALLO";
      }
    }
    cout<<"prueba radixsort 200000"<<endl;
    inicio=clock();
    o.radixsort(arreglo2,200000);
    final=clock();
    tiempo=(final-inicio)/CLOCKS_PER_SEC;
    cout<<"tiempo: "<<tiempo<<endl<<endl;
    for (int i = 1; i < 200000; i++) {
      if(arreglo2[i]<arreglo2[i-1]){
        cout<<"FALLO";
      }
    }
    cout<<"prueba radixsort 300000"<<endl;
    inicio=clock();
    o.radixsort(arreglo3,300000);
    final=clock();
    tiempo=(final-inicio)/CLOCKS_PER_SEC;
    cout<<"tiempo: "<<tiempo<<endl<<endl;
    for (int i = 1; i < 300000; i++) {
      if(arreglo3[i]<arreglo3[i-1]){
        cout<<"FALLO";
      }
    }
    cout<<"prueba radixsort 400000"<<endl;
    inicio=clock();
    o.radixsort(arreglo4,400000);
    final=clock();
    tiempo=(final-inicio)/CLOCKS_PER_SEC;
    cout<<"tiempo: "<<tiempo<<endl<<endl;
    for (int i = 1; i < 400000; i++) {
      if(arreglo4[i]<arreglo4[i-1]){
        cout<<"FALLO";
      }
    }
    //------------------------------Residuos-----------------------
  }
  return 0;
}
