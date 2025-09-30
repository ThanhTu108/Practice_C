#include <stdio.h>
#include <string.h>
#include "lib.h"


void uart_handler(char* data, int len)
{
    printf("Data: %s\n", data);
    if(strstr(data, "ON"))
    {
        printf("On led\n");
    }
    else
    {
        printf("Off led\n");
    }
}

int main()
{   
    
    Uart_Rx_data_set_callback(uart_handler);
    Uart_RX_data("Led ON", 10);

    return 0;
}