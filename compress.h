#include <stdio.h>
#include <string.h>

void Compress(unsigned char *szOut, const char *szMessage) {
	unsigned long long nBuffer = 0; 
	char nBitsInBuffer = 0;
	while (*szMessage != 0) {
		nBuffer |= (unsigned long long)(*szMessage++ & 0x7F) << nBitsInBuffer;
		nBitsInBuffer += 7;
		if (nBitsInBuffer == 7 * 8) {
			while (nBitsInBuffer > 0) {
				*szOut++ = nBuffer & 0xFF;
				nBuffer >>= 8;
				nBitsInBuffer -= 8;
			}
			nBitsInBuffer = 0;
			nBuffer = 0;
		}
	}
	
	while (nBitsInBuffer > 0) {
		*szOut++ = nBuffer & 0xFF;
		nBuffer >>= 8;
		nBitsInBuffer -= 8;
	}
}
 
void Uncompress(char *szOut, const unsigned char *szCompressed, unsigned nCompressedLen) {
	unsigned long long nBuffer = 0; 
	char nBitsInBuffer = 0;
	while (nCompressedLen) {
		while (nCompressedLen && nBitsInBuffer < 7 * 8) {
			nBuffer |= (unsigned long long)*szCompressed++ << nBitsInBuffer;
			nBitsInBuffer += 8;
			--nCompressedLen;
		}
		while (nBitsInBuffer > 0) {
			*szOut++ = nBuffer & 0x7F;
			nBuffer >>= 7;
			nBitsInBuffer -= 7;
		}
		nBitsInBuffer = 0;
		nBuffer = 0;
	}
}
 
void cmp_decmp(int type,FILE *fp) {
	char temp[100];
	char folder [100],folder1[100];
	strcpy(folder,username);
	strcpy(folder1,username);
	strcpy(temp,loc);
	int count = 0;
	for(int i = strlen(temp);i>0;i--){
		if(temp[i]=='/'){
			break;
		}
		count++;
	}
	char filename[count+1];
	int i = 0;
	for(int j = strlen(temp) - (count);j < strlen(temp) ; j++){
		printf("%c",temp[j]);
		filename[i++]=temp[j];
	}
	printf("\n");
	filename[count] = '\0';
	printf("%s\n",filename);
	int size=0;
	// char szUncompressed[10000];
	fp = fopen(loc,"r");
	if (fp == NULL)
	    printf("\nFile unable to open ");
	else 
	    printf("\nFile opened ");
	fseek(fp, 0, 2);
	size = ftell(fp);
	printf("%d",size);
	fclose(fp);
	fp = fopen(loc,"r");
	struct stat st = {0};
	if (stat(username, &st) == -1) {
   		mkdir(username, 0700);
	}
	char szMessage[size];
	fread(szMessage,(size_t)size,1,fp);
	printf("     Message: %s\n", szMessage);	
	if(type==0){
		
		unsigned nCompressedSize = sizeof(szMessage) * 7 / 8;
		unsigned char pCompressedBytes[nCompressedSize];

		printf("     Message: %s\n", szMessage);
		Compress(pCompressedBytes, szMessage);
		strcat(folder,filename);
		strcat(folder,".cmp");
		FILE *out = fopen(folder,"w+");
		fwrite(pCompressedBytes,1,sizeof(pCompressedBytes),out);
		fclose(out);
		printf("  Compressed: ");
		for (int nByte = 0; nByte < nCompressedSize; ++nByte) {
			printf("%02X ", pCompressedBytes[nByte]);
		}
		printf("\n");
		fclose(fp);
	}
	else if(type==1){
		char	szUncompressed[sizeof(szMessage)+100];
		Uncompress(szUncompressed, szMessage, size);
		strcat(folder1,filename);
		strcat(folder1,".txt");
		FILE *uncmp = fopen(folder1,"w+");
		szUncompressed[sizeof(szMessage)+99] = '\0';
		fwrite(szUncompressed,1,sizeof(szUncompressed),uncmp);
		printf("Uncompressed: %s\n", szUncompressed);
        fclose(uncmp);
}
}
