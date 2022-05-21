#include <stdio.h> 
#include <stdint.h>
#include <stdlib.h>

 uint32_t reverseBits(uint32_t n) 
    {        
        //printf("%d \n",n);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = (n >> 16) | (n << 16);
        //printf("%u",n);
        return n;
    }
void main()
{
    uint32_t n=0x12345678,a;
    a=reverseBits(n);
    printf("%x",a);

};
/**
Step 0.
abcd efgh ijkl mnop qrst uvwx yzAB CDEF <-- n

Step 1.
 a c  e g  i k  m o  q s  u w  y A  C E <-- (n & 0xaaaaaaaa) >> 1  
b d  f h  j l  n p  r t  v x  z B  D F  <-- (n & 0x55555555) << 1
badc fehg jilk nmpo rqts vuxw zyBA DCFE <-- after OR

Step 2.
  ba   fe   ji   nm   rq   vu   zy   DC <-- (n & 0xcccccccc) >> 2
dc   hg   lk   po   ts   xw   BA   FE   <-- (n & 0x33333333) << 2
dcba hgfe lkji ponm tsrq xwvu BAzy FEDC <-- after OR

Step 3.
     dcba      lkji      tsrq      BAzy <-- (n & 0xf0f0f0f0) >> 4
hgfe      ponm      xwvu      FEDC      <-- (n & 0x0f0f0f0f) << 4
hgfe dcba ponm lkji xwvu tsrq FEDC BAzy <-- after OR

Step 4.
          hgfe dcba           xwvu tsrq <-- (n & 0xff00ff00) >> 8
ponm lkji           FEDC BAzy           <-- (n & 0x00ff00ff) << 8 
ponm lkji hgfe dcba FEDC BAzy xwvu tsrq <-- after OR

Step 5.
                    ponm lkji hgfe dcba <-- n >> 16, same as (n & 0xffff0000) >> 16 
FEDC BAzy xwvu tsrq                     <-- n << 16, same as (n & 0x0000ffff) << 16
FEDC BAzy xwvu tsrq ponm lkji hgfe dcba <-- after OR
**/