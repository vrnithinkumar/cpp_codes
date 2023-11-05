#include <cstring>

unsigned int convert_int_to_bcd(unsigned char* destination_buffer, unsigned int bufferlength, unsigned int value){
  if(bufferlength <= 0){
    return 0;
  }
  memset(destination_buffer, 0, bufferlength * sizeof(unsigned char));
  unsigned int size = 0;
  unsigned int buffer_index = 0;
  
  while(value){
    unsigned int buffer_size_sofar = ( size + 1) / 2;
    // if the size of the buffer is more than availabe buffer length return
    if(buffer_size_sofar > bufferlength){
      return 0;
    }
    unsigned char digit = (unsigned char) value % 10;
    value /= 10;
    unsigned char buffer_value = destination_buffer[buffer_index];
    if(size & 1){ // odd case add nibble at right
      buffer_value = buffer_value | digit;
    }else{ // even case add nibble at left by shifting 4 bits
      buffer_value = buffer_value | (digit << 4);
    }
    destination_buffer[buffer_index] = buffer_value;
  }
  
  unsigned int buffer_size_sofar = ( size + 1) / 2;
  return buffer_size_sofar;
}
