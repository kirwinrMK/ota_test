#include <Arduino.h>
#include "BLE.h"
/**Bluetooth**/
BLE BT;

void setup(void) {
  Serial.begin(115200);
  Serial.println("Serial Begin");
  Serial.println();
  
  Serial.print("HW v");
  Serial.print(HARDWARE_VERSION_MAJOR);
  Serial.print(".");
  Serial.println(HARDWARE_VERSION_MINOR);
  
  Serial.print("SW v");
  Serial.print(SOFTWARE_VERSION_MAJOR);
  Serial.print(".");
  Serial.print(SOFTWARE_VERSION_MINOR);
  Serial.print(".");
  Serial.println(SOFTWARE_VERSION_PATCH);
  const esp_partition_t partition = *esp_ota_get_running_partition();
  Serial.println(partition.label);
  
  const esp_partition_t *partition2 = esp_partition_find_first(ESP_PARTITION_TYPE_ANY, ESP_PARTITION_SUBTYPE_ANY, "app0");
  // Serial.println(partition2->label);
  // esp_ota_img_states_t *ota_state;
  // esp_err_t error = esp_ota_get_state_partition(partition2, ota_state);
  // Serial.println(error);
  // Serial.println((int)ota_state);
  esp_ota_set_boot_partition(partition2);
  BT.begin("ESP32 OTA Updates");
}

void loop(void) {
  
}
