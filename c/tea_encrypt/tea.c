#include <stdio.h>
#include <stdint.h>

//加密函数
void encrypt (uint32_t* v, uint32_t* k) {
    uint32_t v0=v[0], v1=v[1], sum=0, i;           /* set up */
    uint32_t delta=0x9e3779b9;                     /* a key schedule constant */
    uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];   /* cache key */
    for (i=0; i < 32; i++) {                       /* basic cycle start */
        sum += delta;
        v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
    }                                              /* end cycle */
    v[0]=v0; v[1]=v1;
}
//解密函数
void decrypt (uint32_t* v, uint32_t* k) {
    uint32_t v0=v[0], v1=v[1], sum=0xC6EF3720, i;  /* set up */
    uint32_t delta=0x9e3779b9;                     /* a key schedule constant */
    uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];   /* cache key */
    for (i=0; i<32; i++) {                         /* basic cycle start */
        v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
        v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        sum -= delta;
    }                                              /* end cycle */
    v[0]=v0; v[1]=v1;
}


int encrypt_block(char * data,int len,char *key)
{
  int i;
  if((len <=0) || (len%8 != 0))
    return -1;

  for(i=0;i<len;i+=8){
    encrypt((unsigned int *)(data+i),key);
  }
  return 0;
}

int decrypt_block(char * data,int len,char *key)
{
  int i;
  if((len <=0) || (len%8 != 0))
    return -1;

  for(i=0;i<len;i+=8){
    decrypt((unsigned int *)(data+i),key);
  }
  return 0;
}

/*int main()
{
    uint32_t v[2]={1,2},k[4]={2,2,3,4};
    // v为要加密的数据是两个32位无符号整数
    // k为加密解密密钥，为4个32位无符号整数，即密钥长度为128位
    printf("加密前原始数据：%u %u\n",v[0],v[1]);
    encrypt(v, k);
    printf("加密后的数据：%u %u\n",v[0],v[1]);
    decrypt(v, k);
    printf("解密后的数据：%u %u\n",v[0],v[1]);
    return 0;
}
*/

int main()
{
	char * data="pengjia912432##";
	char * raw_key="12345678";
	int len;
	int i;
	unsigned int key[4]={0};
	char *p;

	len=strlen(data)/8*8+8;
	char * enc_data=(char*)malloc(len);
	memset(enc_data,0,len);
	memcpy(enc_data,data,strlen(data));
	memcpy((void *)key,raw_key,strlen(raw_key));

	encrypt_block(enc_data,len,key);
	for(i=0;i<len;i++)
	  printf("%c",enc_data[i]);
	printf("\r\n");
	
	key[0]=3;
	decrypt_block(enc_data,len,key);
        for(i=0;i<len;i++)
          printf("%c",enc_data[i]);
        printf("\r\n");

	return 0;
}
