/*      2 JUEGOS DE 6 LUCES EMPLEANDO CICLOS FOR 
 * 
 * Este programa consta de 2 juegos de luces con 6 leds.
 * Juego 1: Este juego tiene un for anidado y funciona cuando switch 1=1 y switch 2=0.Inicia  el juego y este se repite el numero de veces que sea igual al número random.
 * Juego 3: Este juego tiene un for anidado y funciona cuando switch 1=0 y switch 2=1.Inicia  el juego y Se van prendiendo desde los extremos en serie hacia el centro, 
 * y al momento de estar encendidos todos, empiezan a apagarse de dos en dos desde el centro hacia los extremos., este se repite el numero de veces que sea igual al número random.
 *  
 * NOMBRE: Israel Gudiño Pabón
 * FECHA DE ENTREGA: 27/10/2016
 */

//Inicializar variables de pines

int sw_1=7; //switch 1
int sw_2=6; //switch 2
int lim=0;
int vector_leds [6]={8,9,10,11,12,13};
/////////////////////////////
//Variables de contadores
int i;
int j;
int cont_1;
int cont_2;

/////////////
void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT); //pin 8 como salida
  pinMode(9,OUTPUT); //pin 9 como salida
  pinMode(10,OUTPUT); //pin 10 como salida
  pinMode(11,OUTPUT); //pin 11 como salida
  pinMode(12,OUTPUT); //pin 12 como salida
  pinMode(13,OUTPUT); //pin 13 como salida
  pinMode(sw_1,INPUT); //pin 7 como entrada
  pinMode(sw_2,INPUT); //pin 6 como entrada

}

void loop() {

  
  //Juego de luces 1 For Anidado
  
    if(digitalRead(sw_1)==HIGH&&digitalRead(sw_2)==LOW){
           delay(200);
           lim=random(5);
           for(j=0;j<lim;j++){//for 1
              for(i=8;i<14;i++){//for 2
                       digitalWrite(i,HIGH);
                       delay(70);
               }//For 2
               for(i=13;i>7;i--){//for 3
                      digitalWrite(i,LOW);
                      delay(70);
                 }//for 3
               i=8;
              }//for 1    
              delay(2000);//Tiempo de espera antes de empezar la siguiente secuencia   
            } //Final juego de luces 1 
            
////////////////////////////////////////////////////////
    //Inicio juego de luces 2 
      else{ 
         if(digitalRead(sw_1)==LOW&&digitalRead(sw_2)==HIGH){
              delay(200);
              lim=random(5);
              for(j=0;j<lim;j++){//For 1
                 for (cont_1 = 8,cont_2=13; cont_1 < 11; cont_1++,cont_2--) { //For 2
                    digitalWrite(cont_1, HIGH);
                    digitalWrite(cont_2, HIGH);
                    delay(125);
                   }//For 2

                 for (cont_1 = 10, cont_2=11; cont_2 < 14; cont_1--,cont_2++) {//For 3
                     digitalWrite(cont_1, LOW);
                     digitalWrite(cont_2, LOW);
                     delay(125);
                    }//For 3
                 }//For 1
       }
        delay(2000);//Tiempo de espera antes de empezar la siguiente secuencia
      }//Final juego de luces 2
     
}
