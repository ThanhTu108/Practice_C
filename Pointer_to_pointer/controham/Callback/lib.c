#include "lib.h"
#include <stdio.h>

data_uart_handeler_t data_ptr = NULL;

void Uart_RX_data(char* data_Rx, int data_len)
{
    data_ptr(data_Rx, data_len);
}

void Uart_Rx_data_set_callback(data_uart_handeler_t fptr)
{
    if(fptr)
    {
        data_ptr = fptr;
    }
}