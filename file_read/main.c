#include "assert.h"


typedef struct
{
    int a; 
    int b;
}Test_Cfg;


int main()
{    
    char c;
    int i = 0;
    int tmp = 0;
    Test_Cfg config;
    unsigned int data_length = sizeof(Test_Cfg);
    char pbuf[data_length + 1];
    memset(pbuf, 0, data_length+1);

    printf("length = %d\n", data_length);
    FILE *in_file = fopen("./test_data.dat","rt");

    do
    {
        c = fgetc(in_file);
        if(c == ',')
        {
            pbuf[i++] = tmp;       
            tmp = 0;
        }
        else
        {
            tmp = tmp * 10 + (c - '0');
        }
    } while (c != EOF && i < data_length);

    //assert(data_length == i);

    memcpy(&config, pbuf, data_length);

    printf("%d\n", config.a);
    printf("%d\n", config.b);

    fclose(in_file);
}

