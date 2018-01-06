#include <stdio.h>

/* take 64 bits of data in v[0] and v[1] and 128 bits of key[0] - key[3] */
typedef  unsigned int uint32_t;
void encipher(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]) {
  unsigned int i;
  uint32_t v0=v[0], v1=v[1], sum=0, delta=0x9E3779B9;
  for (i=0; i < num_rounds; i++) {
    v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]);
    sum += delta;
    v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum>>11) & 3]);
  }
  v[0]=v0; v[1]=v1;
}

void decipher(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]) {
  unsigned int i;
  uint32_t v0=v[0], v1=v[1], delta=0x9E3779B9, sum=delta*num_rounds;
  for (i=0; i < num_rounds; i++) {
    v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum>>11) & 3]);
    sum -= delta;
    v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]);
  }
  v[0]=v0; v[1]=v1;
}

int encipher_block(char * data,int len,char * key)
{
  int i;
  if((len <=0)|| (len%8 !=0))
    return -1;
  for(i=0;i<len;i+=8)
    encipher(32,(uint32_t *)(data+i),(uint32_t *)key);
  return 0;
}

int decipher_block(char * data,int len,char * key)
{
  int i;
  if((len <=0)|| (len%8 !=0))
    return -1;
  for(i=0;i<len;i+=8)
    decipher(32,(uint32_t *)(data+i),(uint32_t *)key);
  return 0;
}

int main()
{
  uint32_t key[4]={1,30,78,9};
  char * raw_data="pengjia912##00";
  char data[10*8]={0};
  memcpy(data,raw_data,strlen(raw_data));
  encipher_block(data,80,(char *)key);
  printf("%s\n",data);
  decipher_block(data,80,(char *)key);
  printf("%s\n",data);
  
  

  return 0;
}
