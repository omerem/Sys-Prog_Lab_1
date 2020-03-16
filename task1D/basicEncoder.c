#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int basic(int argc, char **argv, FILE * filePointer)
{
    
    int debug=0;
    //int sign=0, keyLength;
    //char offset;
    int i;
    int sign=0;
    int keyIndex=0;
    int keyLength;
    int newLine=0;
    
     
    
  
    
    for(i=1; i<argc; i++)
    {
        if(strncmp(argv[i],"-D",2)==0)
            debug=1;
        else if(strncmp(argv[i],"-e",2)==0)
        {
            sign=-1;
            keyIndex=i;
            keyLength=strlen(argv[keyIndex])-2;
        }
        else if(strncmp(argv[i],"+e",2)==0)
        {
            sign=1;
            keyIndex=i;
            keyLength=strlen(argv[keyIndex])-2;
        }
    }
    
    char p[strlen(argv[keyIndex])];
    if (sign!=0)
    {
        
        for (i=0; i<keyLength; i++)
        {
            p[i]=argv[keyIndex][i+2];
        }
    }
    
    /*
    for (i=0; i<keyLength; i++)
    {
        printf("number=%c\n", p[i]);
   }
   */
    i=0;
    
    

    
    int ch = fgetc(filePointer);
    
    
    if (sign==0)
    {
        while (ch!=EOF)
        {
            if (debug==1)
            fprintf( stderr, "%#04x    ", ch );
        
            if ('A'<=ch && ch<= 'Z')
                ch+=32;
        
            if (debug==1)
            fprintf( stderr, "%#04x\n", ch );
        
            putc(ch,stdout);
            ch = fgetc(filePointer);
        }
    }
    else // sign= +-1
    {
        i=0;
        while (ch!=EOF)
        {
            if (debug==1)
            fprintf( stderr, "%#04x    ", ch );
            
            if (ch=='\n')
                newLine=1;
            
            ch=(ch+(sign*p[i]))%128;
            i=(i+1)%keyLength;
            
            if (debug==1)
            fprintf( stderr, "%#04x\n", ch );
            
            putc(ch,stdout);
            
            if (newLine==1)
            {
                printf("\n");
                newLine=0;
                i=0;
            }
            ch = fgetc(filePointer);
            
        }
    }
    
    
    
    //cd Desktop/splab/lab1/task2
    
    
    
    
    
    // printf("\nkeyIndex=%d\nsign=%d\nD=%d\n\n blahhh=%d\n", keyIndex,sign,debug,*p);
    
    return 0;
    
}


