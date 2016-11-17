/*      DEBER #3 - EJERCICIO 3
 *       
 *       MEDIDOR DE VELOCIDAD (0-99) DE UN MOTOR
 * 
 * Este programa es un medidor de velocidad (0-99) de un motor mediante la lectura de un conversor analogo digital,
 * la misma que se visualizará en dos displays.
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
int valor_decena=0;
int valor_unidad=0;
int motor=5;
int valor_cad;
int velocidad;

//////////////////////////////

void setup() {

  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(unidades,OUTPUT);
  pinMode(decenas,OUTPUT);
  pinMode(motor,OUTPUT);

}

void loop() {

      valor_cad=analogRead(3);  
      analogWrite(motor, valor_cad/4);  
      delay(100);        
      velocidad=map (valor_cad, 0, 860, 0, 99);          
       valor_decena=velocidad/10;          
       digitalWrite(unidades,LOW);        
        digitalWrite(decenas,HIGH);         
        contador_display(valor_decena);        
        delay(50);
        valor_unidad=velocidad-(valor_decena*10);      
        digitalWrite(unidades,HIGH);                     
        digitalWrite(decenas,LOW);                      
        contador_display(valor_unidad);                       
        delay(50);
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
