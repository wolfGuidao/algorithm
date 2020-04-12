#include "Header.hpp"

#include<stdio.h>  
  
typedef unsigned int uint_32 ;  
typedef unsigned short uint_16 ;  
 
//16位
#define BSWAP_16(x) \
    (uint_16)((((uint_16)(x) & 0x00ff) << 8) | \
              (((uint_16)(x) & 0xff00) >> 8) \
             )
             
//32位               
#define BSWAP_32(x) \
    (uint_32)((((uint_32)(x) & 0xff000000) >> 24) | \
              (((uint_32)(x) & 0x00ff0000) >> 8) | \
              (((uint_32)(x) & 0x0000ff00) << 8) | \
              (((uint_32)(x) & 0x000000ff) << 24) \
             )  
 
//无符号整型16位  
uint_16 bswap_16(uint_16 x)  
{  
    return (((uint_16)(x) & 0x00ff) << 8) | \
           (((uint_16)(x) & 0xff00) >> 8) ;  
}  
 
//无符号整型32位
uint_32 bswap_32(uint_32 x)  
{  
    return (((uint_32)(x) & 0xff000000) >> 24) | \
           (((uint_32)(x) & 0x00ff0000) >> 8) | \
           (((uint_32)(x) & 0x0000ff00) << 8) | \
           (((uint_32)(x) & 0x000000ff) << 24) ;  
}  
 
int main(int argc,char *argv[])  
{  
    printf("------------带参宏-------------\n");  
    printf("%#x\n",BSWAP_16(0x1234)) ;  
    printf("%#x\n",BSWAP_32(0x12345678));  
    printf("------------函数调用-----------\n");  
    printf("%#x\n",bswap_16(0x1234)) ;  
    printf("%#x\n",bswap_32(0x12345678));  
      
    return 0 ;  
}  
