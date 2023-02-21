int PIR = 4;
const int Soil_moisture = 7;
bool Current_Stat = false;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(Soil_moisture, INPUT);

  attachInterrupt(digitalPinToInterrupt(PIR), swap, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Soil_moisture), soil_moist, RISING);
}

void loop()
{
  swap();
  soil_moist();
  delay(3000);
}

void swap()
{
  Current_Stat = !Current_Stat;
  digitalWrite(LED_BUILTIN, Current_Stat);
  Serial.println("Movement Interrupted");
}

void soil_moist()
{
  Serial.println("Soil Moisture Interrupted");
}
