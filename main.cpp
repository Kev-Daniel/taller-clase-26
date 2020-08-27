#include <iostream>
#include <fstream>
using namespace std ;
void arre (int arreglo[100],int A );
 
 
int main() {
 int A,B ;

 int arreglo[100] ;
 arre(arreglo,A);
 
  
}
void arre (int arreglo[100],int A){
  ofstream interpolacion ;
  interpolacion.open("interpolacion.txt") ; 
 int B=0;
  int pri = 0;

  cout << "Ingrese el tamanio del arreglo ";
  cin >> A;
  for (int i = 0 ; i<A; i++){
    cout << "Ingrese elemeto del arreglo"<<"["<<i<<"]\n";
    cin >> arreglo[i];
  }

  interpolacion << "ARREGLO ORIGINAL: " ;
  for (int k =0; k<A; k++){
    interpolacion << arreglo[k]<<" " ;
  }
  interpolacion<< endl;
//ordenamiento
for (int i = 0;i<A;i++){
  int pos,axi;
  pos= i ;
  axi = arreglo [i];
  while((pos>0)&& (arreglo[pos-1]>axi))
  {
    arreglo [pos] = arreglo [pos -1];
    pos -- ;

  }
  arreglo[pos] = axi ;
}
interpolacion<< " ARREGLO ORDENADO ";
  for (int z = 0 ; z < A ;z ++){
    interpolacion << arreglo [z] <<" ";
  }
  int cont ;
  cont = A-1;
  cout <<"\n-----------------------------"<<endl;
  cout << "ingresar elemento a buscar";
  cin >> B;
  int medio ;
  int ultimo ;
  ultimo = A-1;
  int contador = 0;

   while (arreglo[pri]!=B && contador < A)
    {

        medio = pri + ((B-arreglo[pri])*(ultimo -pri))/(arreglo[ultimo]-arreglo[pri]);

        if(arreglo[medio]<B)
            ultimo =medio+1;
        else if (arreglo[medio]>B)
            ultimo = medio -1;
        else
            pri = medio;
        contador++;

        break;
    }
    
    interpolacion << "\nELEMENTO A BUSCAR "<<B<<endl ; 
  
    if (arreglo[pri]==B)
    {
        cout<<"ELEMENTO ENCONTRADO";
        interpolacion << "\nELEMENTO ENCONTRADO : ";
    }
    else
    {
         cout<<"ELEMENTO NO ENCONTRADO";
         interpolacion <<"ELEMENTO NO ENCONTRADO"; 
    }

   

interpolacion.close();

}