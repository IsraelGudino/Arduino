/*      DEBER #3 - EJERCICIO 2
 *       
 *       CONTADOR 0-99 MEDIANTE UN PULSADOR OBSERVADO EN DISPLAYS
 * 
 * Este programa es un contador del 0 al 99, consite en que con cada pulsación se debe incrementar el contador, y los números se vizualizarán en 2 displays.
 *  
 * NOMBRE: Israel Gudiño Pabón
 * FECHA DE ENTREGA: 17/11/2016
 */


//Declaración de variables

int A=13;
int B=12;
int C=11;
int D=10;

int decenas=9;
int unidades=8;
int valor_decena;
int valor_unidad;
int contador=0;
//Pulsador
int pulsador=6;

//////////////////////////////

void setup() {

  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(unidades,OUTPUT);
  pinMode(decenas,OUTPUT);
  pinMode(pulsador,INPUT);

}

void loop() {
  
 if(digitalRead(pulsador)==HIGH&&contador<100){
      delay(30);
      contador=contador+1;
      valor_decena=contador/10;//Dígito de las decenas
      valor_unidad=contador-(valor_decena*10);//Dígito de las unidades
      
      digitalWrite(unidades,HIGH);
      digitalWrite(decenas,LOW);
      //imprimir dato
      contador_display(valor_unidad);
      delay(100);
      
      digitalWrite(unidades,LOW);
      digitalWrite(decenas,HIGH);
      //imprimir dato
      contador_display(valor_decena);
      delay(100);
  }
 else{
      if(contador>=100){
        contador=0;    //Reinicio del contador 
        }
  }
//Mantener valores en los display
for(;digitalRead(pulsador)==LOW;){
      delay(50);
      digitalWrite(unidades,HIGH);
      digitalWrite(decenas,LOW);
      //imprimir dato
      contador_display(valor_unidad);
      delay(100);
      
      digitalWrite(unidades,LOW);
      digitalWrite(decenas,HIGH);
      //imprimir dato
      contador_display(valor_decena);
      delay(100);
  }
//////////////////////////////
  
}


void contador_display(int numero){
  
    switch(numero){

   case 0:  
  //0
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
    break;
    case 1:
  //1
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
    break;
    case 2:
  //2
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
    break;
    case 3:
  //3
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
    break;
    case 4:
  
  //4
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
    break;
    case 5:
  //5
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
    break;
    case 6:
  //6
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
    break;
    case 7:
  //7
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
    break;
    case 8:
  //8
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
    break;
    case 9:
  //9
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);

    }
}
