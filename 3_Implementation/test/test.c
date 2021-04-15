#include "cust_declarations.h"
#include "server_declarations.h"
#include "unity.h"
#inlcude "unity_internals.h"

/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown()
{
}

int port_add ; 
char ipaddr[50];
int customer = 0; 
char recMessage[STRLEN];
char sendMessage[STRLEN];
char *cust_ip_addr;

int data_loaded_flag = 0;
int ch;

FILE *ip = NULL;
FILE *r = NULL;
FILE *rt = NULL;

int main(){

     /* Initiate the Unity Test Framework */
    UNITY_BEGIN();
    
    
    /* Run Test functions */
    RUN_TEST(test_calculation);
    RUN_TEST(test_providentfund);

     /* Close the Unity Test Framework */
    return UNITY_END();
    return 0;
	

} 
