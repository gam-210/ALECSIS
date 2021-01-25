void timeStampCharacteristic_notify_callback(BLEClientCharacteristic* chr, uint8_t* data, uint16_t len)
{
  // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.heart_rate_measurement.xml
  // Measurement contains of control byte0 and measurement (8 or 16 bit) + optional field
  // if byte0's bit0 is 0 --> measurement is 8 bit, otherwise 16 bit.

  int distance = data[0];
  Serial.println(distance);
  if (distance < 120 && distance>20){
  analogWrite (vibreur,160- distance);
}else {
  analogWrite (vibreur, 0);
}
}
