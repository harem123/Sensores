
const int En_WrRd_RS485 =  2;

const int Led_1 =  7; 
const int Led_2 =  6; 
const int Led_3 =  5;  

char VarChar = ' ';
String BufferIn = "";        
boolean StringCompleta = false; 

void setup() 
{ 
  Serial.begin(9600);

  pinMode(En_WrRd_RS485, OUTPUT);
  
  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(Led_3, OUTPUT);
  
  digitalWrite(En_WrRd_RS485, LOW); 
  digitalWrite(Led_1, LOW);
  digitalWrite(Led_2, LOW);
  digitalWrite(Led_3, LOW); 
} 
 
void loop() 
{  
  digitalWrite(En_WrRd_RS485, HIGH); 
  Serial.print("B1#");
  digitalWrite(Led_1, HIGH);digitalWrite(Led_2, HIGH);digitalWrite(Led_3, HIGH); 
  delay(50);
 

  digitalWrite(En_WrRd_RS485, HIGH); 
  Serial.print("C1#");
  digitalWrite(Led_1, LOW);digitalWrite(Led_2, LOW);digitalWrite(Led_3, LOW); 
  delay(50);

  digitalWrite(En_WrRd_RS485, HIGH); 
  Serial.print("B2#");
  digitalWrite(Led_1, HIGH);digitalWrite(Led_2, HIGH);digitalWrite(Led_3, HIGH); 
  delay(50);
 

  digitalWrite(En_WrRd_RS485, HIGH); 
  Serial.print("C2#");
  digitalWrite(Led_1, LOW);digitalWrite(Led_2, LOW);digitalWrite(Led_3, LOW); 
  delay(50);

  digitalWrite(En_WrRd_RS485, HIGH); 
  Serial.print("B3#");
  digitalWrite(Led_1, HIGH);digitalWrite(Led_2, HIGH);digitalWrite(Led_3, HIGH); 
  delay(50);
 

  digitalWrite(En_WrRd_RS485, HIGH); 
  Serial.print("C3#");
  digitalWrite(Led_1, LOW);digitalWrite(Led_2, LOW);digitalWrite(Led_3, LOW); 
  delay(50);
} 


