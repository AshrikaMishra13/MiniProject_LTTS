//Contains all the variable declarations,functions declarations,constans definition.

#include <stdio.h> 
#include <conio.h> 
#include <string.h> 
#include <time.h> 
#include <stdlib.h>
#include <ctype.h> //Contains functions used to classify characters by their types or to convert between upper and lower case in a way that is independent of the used character set
#define _WIN32_WINNT 0x0500 //constant for console resizing (redifinition)
#include <windows.h> //contains Windows specific functions that can be used in C.
#include <winsock2.h>   // contains functions for socket programmming
#include <process.h>   
#define DEFAULT_PORT 5000
#define STRLEN 256
#define NUM_CLIENTS 2
#define ESC 27
#define F2 60

FILE *ip;


int port_add ; 
char ipaddr[50];
int customer = 0; 
char recMessage[STRLEN];
char sendMessage[STRLEN];
char *cust_ip_addr;

//variables for the server

int comp_id=5;
int serv_id=0;;
int log_stat=0;
bool is_member=0;   //1=member, 2=admin, 0=guest
char username[20];
char password[20];
int tot_cost=0;
char Name[20];
int fixed_rate;
int tot_service;
int cost_changed=0;
int check_flag = 0;


HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
HANDLE time_thread;


extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow (void);

SOCKET Socket;
struct cust
{
    sockaddr_in c_address;
    int c_addr_len;
    SOCKET c_socket;
    bool connected;
    bool turn;
};
struct cust[NUM_CUST]; //for multiple clients

struct service {
  char name[15];
  int rate;
}items[10];

struct ip_info
{
    char ip_address[50];
    int port_no;
    int client_no;
};
struct ip_info ip1;


COORD coord = {0, 0};
COORD max_buffer_size = GetLargestConsoleWindowSize(hOut);
COORD max_res,cursor_size;



bool SOCKET_START = false;  //TRUE if socket is already initialised
bool login_server = false;  // TRUE if server is alerady logged in
bool done = false;  //if it is true, the communication ends

time_t t; 

int i,j,k;

int flag_menu=0; 
int to_tray = 0;
void main_menu(); 


void gotoxy(int x,int y); 
void delay(unsigned int mseconds); 
void console_resize(int console_id);
void reset_console();
void login_screen();
void admin_page();
void show_menu();
void service_menu();
void settings_menu();
void order(int ord);
void chg_compID();
void chg_password();
void credits();
void log_out();
void help_window();
void console_settings();
void reset_variables();


void start_socket();
void connect_server();
void cust_send_data(char* menu_selected, char* log_status);
int cust_recv_data();
int get_code();
void show_time(void *param);
void update_price(void *param);


void read(int msgExtracted[4],char msg[STRLEN]);
void intToString(int n, char str[]);
void get_password(char* pass);
bool confirm_member();
char* createMessage(char Message[]);
int get_service_info();   


HWND WINAPI GetConsoleWindowNT();
  
