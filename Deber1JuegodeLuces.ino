/*      3 JUEGOS DE 14 LUCES EMPLEANDO CICLOS
 * 
 * Este programa consta de 3 juegos de luces con 14 leds.
 * Los 14 leds constan de 2 colores, 7 rojos y 7 verdes y están ubicados alternadamente.
 * Juego 1: Se prenden comenzando desde la parte de abajo los leds rojos, luego desde la parte de arriba se prenden los verdes,
 *  y al final se apagan uno a uno desde abajo.
 * Juego 2: Se prenden de dos en dos (uno de cada extremo) por 1 segundo en linea, saltando uno. y se apagan antes de encender el siguiente, 
 *  y al llegar al centro , siguen prendiendose y apagándose los que faltaban desde el centro hasta los extremos.
 * Juego 3: Se van prendiendo desde los extremos en serie hacia el centro, y al momento de estar encendidos todos, empiezan a apagarse de dos en dos desde el centro 
 *  hacia los extremos.
 *  
 *  
 * NOMBRE: Israel Gudiño Pabón
 * FECHA DE ENTREGA: 20/10/2016
 */
int cont_1;
int cont_2;
void setup() {
  // put your setup code here, to run once:
  pinMode (0, OUTPUT);
  pinMode (1, OUTPUT);
  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);

  }
//Juego de luces 1
  void loop() {
    // put your main code here, to run repeatedly:


    for (cont_1 = 0; cont_1 < 14; cont_1 = cont_1 + 2) {
      digitalWrite(cont_1, HIGH);
      delay(100);
    }

    for (cont_1 = 13; cont_1 >= 0; cont_1 = cont_1 - 2) {
      digitalWrite(cont_1, HIGH);
      delay(100);
    }

    for (cont_1 = 0; cont_1 < 14; cont_1++) {
      digitalWrite(cont_1, LOW);
      delay(100);
    }

  //Juego de luces 2
for (cont_1 = 0, cont_2=13; cont_1 < 14; cont_1 = cont_1 + 2,cont_2 = cont_2 - 2) {
      digitalWrite(cont_1, HIGH);
      digitalWrite(cont_2, HIGH);
      delay(150);
      digitalWrite(cont_1, LOW);
      digitalWrite(cont_2, LOW);
      delay(150);
         }
     

  //Juego de luces 3

      for (cont_1 = 0, cont_2=13; cont_1 < 8; cont_1++,cont_2--) {
      digitalWrite(cont_1, HIGH);
      digitalWrite(cont_2, HIGH);
      delay(100);
    }

   for (cont_1 = 7, cont_2=8; cont_1 < 8; cont_1--,cont_2++) {
      digitalWrite(cont_1, LOW);
      digitalWrite(cont_2, LOW);
      delay(100);
    }

     
  }
