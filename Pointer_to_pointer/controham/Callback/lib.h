#ifndef LIB_H
#define LIB_H

typedef void (*data_uart_handeler_t)(char* data, int len);

void Uart_Rx_data_set_callback(data_uart_handeler_t fptr);
void Uart_RX_data(char* data_Rx, int data_len);

#endif // LIB_H 
