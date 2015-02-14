#ifndef __CWPROTOCOL__
#define __CWPROTOCOL__

#define INTERFACE_VERSION "irmc v0.02"

#define MAX_CHANNEL 10000 // FIXME: from protocol
#define CW_SEND_RETRIES 5 // the lower the more bad the signal

// Structures for the packets: unsigned short command
#define DIS 0x0002 // disconnect
#define DAT 0x0003 
#define CON 0x0004 // connect
#define ACK 0x0005

#define SIZE_COMMAND_PACKET 4
#define SIZE_DATA_PACKET 496
#define SIZE_DATA_PACKET_PAYLOAD 492 // = SIZE_DATA_PACKET - SIZE_COMMAND_PACKET

#define SIZE_ID 128
#define SIZE_STATUS 128
#define SIZE_CODE 51
// This structure will be used to (dis-)connect to KOB servers

struct command_packet_format{
    	unsigned short command; // CON / DIS
    	unsigned short channel; // Channel number
};
// This structure will be used for id, rx and tx packets
struct data_packet_format{
    	unsigned short command;
    	unsigned short length;
    	char id[SIZE_ID];
    	char a1[4];
    	unsigned int sequence;
	unsigned int a21;  
	unsigned int a22;
	unsigned int a23;
    	signed int code[SIZE_CODE];
    	unsigned int n;
    	char status[SIZE_STATUS];  /* This is called version in MorseKob */
    	char a4[8];
    
};

// Define the packets used
#define DEFAULT_CHANNEL 103


int prepare_id (struct data_packet_format *id_packet, char *id);
int prepare_tx (struct data_packet_format *tx_packet, char *id);
void current_utc_time(struct timespec *ts);


#endif