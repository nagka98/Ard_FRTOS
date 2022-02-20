#include <Arduino_FreeRTOS.h>

void TaskA(void *parameters);
void TaskB(void *parameters);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(500000);
  while(!Serial){}
  Serial.println("tasks created.......");
  xTaskCreate(TaskA, "A" , 100 , NULL, 1, NULL);
  xTaskCreate(TaskB, "B" , 100 , NULL, 1, NULL);
}

void loop() {
  // put your main code here, to run repeatedly:  

}

void TaskA(void *parameters)
{
  Serial.println("Task A started \n");
  while(1)
  {
    Serial.print("Task_A :");
    Serial.print(millis());
    Serial.print("\r\n");
    vTaskDelay(500/ portTICK_PERIOD_MS);
  }
}

void TaskB(void *parameters)
{
  Serial.println("Task B started \n");
    while(1)
  {
    Serial.print("Task_B :");
    Serial.print(millis());
    Serial.print("\r\n");
    vTaskDelay(500/ portTICK_PERIOD_MS);
  }
}
