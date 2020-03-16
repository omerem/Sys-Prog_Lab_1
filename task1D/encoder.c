#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "basicEncoder.c"

int main(int argc, char **argv)
{
    int i;   
    
    FILE* filePointer;
    int fromFile=0;
    int fileIndex=0;
    int ch;
    // int fileNameLength=0;
    
    
    
    for(i=1; i<argc; i++)
    {
        if(strncmp(argv[i],"-i",2)==0)
            {
                fromFile=1;
                fileIndex=i;
                
                // fileNameLength  =  strlen(argv[fileIndex])-2;
                
                break;
            }
    }
    
    //char p[fileNameLength];
    if (fromFile==1)
    {
       // for(i=0; i<fileNameLength; i++)
        //{
          //  p[i] = argv[fileIndex][i+2];
            //fprintf( stderr, "p[%d] %c\n",i, p[i] );
       // }
         
        /*
            for (i=0; i<fileNameLength; i++)
        {
            printf(stderr, "AAAAAAAAAAA = %d", p[i]);
            
        }
        */
        
        
        filePointer = fopen(argv[fileIndex]+2, "r");
        if( filePointer == NULL)
        {
            fprintf( stderr, "ERROR: FILE cannot be opened for reading" );
            return -1;
        }
    }
    
    else if(fromFile==0)
    {
        filePointer = fopen("text.txt", "w+");
        ch = fgetc(stdin);
        while(ch!=EOF)
        {
            fputc(ch, filePointer);
            ch=fgetc(stdin);
        }
        printf("\n");
    }
    if(fromFile==0)
    fseek(filePointer, 0, SEEK_SET);
    
    basic(argc,argv, filePointer);
     //if (fromFile==0)
    fclose(filePointer);
    
    
    
    
    return 0;
    
}


