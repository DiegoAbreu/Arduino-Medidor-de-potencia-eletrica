//Baseado no programa exemplo da biblioteca EmonLib
 
//Carrega as bibliotecas
#include "EmonLib.h" 
#include <LiquidCrystal.h>

//Definindo as variáveis
EnergyMonitor emon1;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int rede = 110; //Tensao da rede eletrica - mudar para 220 se for em uma rede bifásica
int pino_sct = 1; //Pino do sensor SCT

//Inicia o Programa
void setup() 
{
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);   
  
  //Calibração 
  emon1.current(pino_sct, 14.5); // Ajuste esse valor até obter respostas compativéis
  
  //Informacoes iniciais display
  lcd.setCursor(0,0);
  lcd.print("Corr.(A):");
  lcd.setCursor(0,1);
  lcd.print("Pot. (W):");
} 

//Loop de cálculos  
void loop() 
{ 
  //Calcula e mostra o valor da corrente  
  double Irms = emon1.calcIrms(1480);
  Serial.print("Corrente : ");
  Serial.print(Irms)
  lcd.setCursor(10,0);
  lcd.print(Irms);
   
  //Calcula e mostra o valor da potencia
  Serial.print(" Potencia : ");
  Serial.println(Irms*rede);
  lcd.setCursor(10,1);
  lcd.print("      ");
  lcd.setCursor(10,1);
  lcd.print(Irms*rede,1);
   
  delay(1000);
}
