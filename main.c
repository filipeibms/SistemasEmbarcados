#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <termios.h>

int main (int argc, const char *argv[]){

int uart0_filestream = -1; 

uart0_filestream = open("/dev/serial0", O_RDWR | O_NOCTTY | O_NDELAY);

if (uart0_filestream == -1)
{
	printf("Erro na abertura da UART \n");
}

struct termios option;
tcgetattr(uart0_filestream, &options);
options.c_cflag = B115200 | CSB | CLOCAL | CREAD;
options.c_iflag = IGNPAR;
options.c_oflag = 0;
options.c_lflag = 0;

tcflush(uart0_filestream, TCIFLUSH);
tcsetattr(uart0_filestream, TCSANOW, &options);

unsigned char tx_buffer[10];
unsigned char *p_tx_buffer;

p_tx_buffer = &tx_buffer [0];
*p_tx_buffer++='0';
*p_tx_buffer++='l';
*p_tx_buffer++='a';

int count write(uart0_filestream, &tx_buffer[0], (p_tx_buffer-&tx_buffer[0])));

printf("escrevendo na uart... \n");

if (count < 0)
{
	print("Erro no envio de dados - TX \n");
}

sleep(1);

unsigned rx_buffer[100]
int rx_legnth =read (uart0_filestream, (void*)rx_buffer, 100);
if (rx_length < 0)
{
	printf("ERRO NA LEITURA DA UART - RX \n")
}
else if (rx_length == 0)
{
	printf ("Nenhum dado disponivel \n");
}
else
{
 	rx_buffer[rx_length] = '\0';
	printf ("Mensagem de comprimento %d: %s\n", rx_length, rx_buffer);
}	
close (uart0_filestream);
	return 0;
}
