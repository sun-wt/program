#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <curl/curl.h>
#include <assert.h>
 
typedef struct name
{
    char title[2048];
    char author[20][256];
    char source[1024];
    char source1[1024];//
    char source2[1024];//
    char year[4];
    int32_t count;
}n;

void printer( int32_t i , const n page )//
{
    printf( "Page %d:\n" , i+1 );
    printf( "Title: %s\n" , page.title );
    printf( "Author:" );
    for(int j=0;j<page.count;j++)
    {
        if( j == page.count - 1 )
        {
            printf( " %s\n" , page.author[j] );
        }
        else
        {
            printf( " %s," , page.author[j] );
        }
    }
    printf( "Source: " );
    if( strlen(page.source) )
    {
        printf( "%s" , page.source );
    }
    if( strlen(page.source1) )
    {
        printf( " %s" , page.source1 );
    }
    else
    {
        printf("\n");
    }
    if( strlen(page.source2) )
    {
        printf( " %s\n" , page.source2 );
    }
   
    printf( "Date: %s\n" , page.year );
    printf( "\n\n\n" );    
}//

void func( FILE *pFile , n *page )
{
    fseek( pFile , 0 , SEEK_END );
    int64_t size = 0;
    size = ftell( pFile );
    fseek( pFile , 0 , SEEK_SET );
    char *remain = calloc( size , sizeof(int) );
    fread( remain , size , 1 , pFile );
    
    char *remain1 = strstr( remain , "<span itemprop=\"name\" title=" );
    int32_t count_author = 0;
    while( remain1 != NULL )
    {
        char *remain1 = strstr( remain , "<span itemprop=\"name\" title=" );
        if( remain1 )
        {
            FILE *fp1 = fopen( "o.html" , "w+" );
            fwrite( remain1 , strlen(remain1) , 1 , fp1 );
            fseek( fp1 , 0 , SEEK_END );
            int64_t size_fp1 = ftell( fp1 );
            //printf("%d",size_r1);
            fseek(fp1,0,SEEK_SET);
            char mem1[size_fp1-1];
            char *token1 = strtok( remain1 , ">" );
            int32_t count = 0;
            while( token1 != NULL )
            {
                token1 = strtok( NULL , ">" );
                if( count == 0 )
                {
                    strcpy( remain1 , token1 );
                    break;
                }
                //printf("%s>\n",token1);
                count++;
            }
                
            remain1 = strtok( remain1 , "<" );
            //strcpy( name[i] , remain1 );
            
            strcpy ( page->author[count_author] , remain1 );
            //printf("%s\n",page->author[count_author]);
            fseek( fp1 , 1 , SEEK_SET );
            fread( mem1 , size_fp1 - 1 , 1 , fp1 );
            strcpy( remain , mem1 );
            count_author++;
            //fclose( fp1 );
        }
        else
        {
            break;
        }
    }
    //printf("\n");
    page->count = count_author;
}

void func01( FILE *pFile , n *page )
{
    fseek( pFile , 0 , SEEK_END );
    int64_t size = 0;
    size = ftell( pFile );
    fseek( pFile , 0 , SEEK_SET );
    char *remain = calloc( size , sizeof(int) );
    fread( remain , size , 1 , pFile );
    char *remain1 = strstr( remain , "<span itemprop=\"datePublished\">" );
    char *token = strtok( remain1 , ">" );
    token = strtok( NULL , ">" );
    strncpy( page->year , token , 4 );
    printf( "%s\n" , page->year );
}

void func02( FILE *pFile , n *page )//
{
    fseek( pFile , 0 , SEEK_END );
    int64_t size = 0;
    size = ftell( pFile );
    fseek( pFile , 0 , SEEK_SET );
    char *remain = calloc( size , sizeof(int) );
    fread( remain , size , 1 , pFile );
    char *remain1 = strstr( remain , "<span itemprop=\"name\">" );
    char *token = strtok( remain1 , ">" );
    token = strtok( NULL , "<" );
    strcpy( page->source , token );
    if(strlen(page->source))
    {
        //printf( "%s\n" , page->source );
    }
}//

void func03( FILE *pFile , n *page )//
{
    fseek( pFile , 0 , SEEK_END );
    int64_t size = 0;
    size = ftell( pFile );
    fseek( pFile , 0 , SEEK_SET );
    char *remain = calloc( size , sizeof(int) );
    fread( remain , size , 1 , pFile );
    char *remain1 = strstr( remain , "<span itemprop=\"volumeNumber\">" );
    char *token = strtok( remain1 , ">" );
    token = strtok( NULL , "<" );
    strcpy( page->source1 , token );
    if(strlen(page->source1))
    {
        //printf( "%s\n" , page->source );
    }
}//

void func04( FILE *pFile , n *page )//
{
    fseek( pFile , 0 , SEEK_END );
    int64_t size = 0;
    size = ftell( pFile );
    fseek( pFile , 0 , SEEK_SET );
    char *remain = calloc( size , sizeof(int) );
    fread( remain , size , 1 , pFile );
    char *remain1 = strstr( remain , "<span itemprop=\"pagination\">" );
    char *token = strtok( remain1 , ">" );
    token = strtok( NULL , "<" );
    strcpy( page->source2 , token );
    if(strlen(page->source2))
    {
        //printf( "%s\n" , page->source );
    }
}//

int main( int argc , char *argv[] )
{
    CURL *curl;
    CURLcode res;
 	char N[128] = "https://dblp.org/search?q=";
	int32_t time = strlen(N);
    curl = curl_easy_init();
  	if( strcmp(argv[1],"-r") == 0 )
	{
		for(int i=0;i<strlen(argv[2]);i++)
		{
			N[time++] = argv[2][i];
		}
	}
    if(curl) 
    {
        curl_easy_setopt( curl , CURLOPT_URL , N );
        
        FILE *fp = fopen( "0.html" , "w+" );
        assert( fp );
        curl_easy_setopt( curl, CURLOPT_WRITEDATA, fp );
		fseek( fp , 0 , SEEK_END );				
		int32_t size = ftell( fp );
		//printf( "%s\n" , remain );
        /* Perform the request, res will get the return code */ 
        res = curl_easy_perform(curl);
        /* Check for errors */ 
        if( res != CURLE_OK )
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        fseek( fp , 0 , SEEK_END );
        int64_t size_fp = 0;
        size_fp  = ftell ( fp );
        fseek( fp , 0 , SEEK_SET );
        char *store = calloc( size_fp , sizeof(int) );
        char *Store = calloc( size_fp , sizeof(int) );
        fread( store , size_fp , 1 , fp );
        strncpy( Store , store , size_fp );

		char name[10][1024];
        int32_t number = 0;
        int64_t memory[10] = {0};
        for(int i=0;i<10;i++)
        {   
            char *remain1 = NULL;
            if( i == 0 )
            {
                remain1= strstr( Store , "<span class=\"title\" itemprop=\"name\">" );
            }
            else
            {
                FILE *r2 = fopen( "remain2.html" , "r+" );
                int64_t size_r2 = 0;
                fseek( r2 , 0 , SEEK_END );
                size_r2 = ftell( r2 );
                fseek( r2 , 0 , SEEK_SET );
                char *newS = calloc( size_r2 , sizeof(int) );
                fread( newS , size_r2 , 1 , r2 );
                remain1 = strstr( newS , "<span class=\"title\" itemprop=\"name\">" );
                fclose( r2 );
            }
            if( remain1 )
            {
                int64_t size_r1 = 0;
                size_r1 = strlen(remain1);
                memory[i] = size_fp - strlen(remain1);
                char *temp = calloc( size_r1 , sizeof(int) );
                strncpy( temp , remain1 , size_r1 );

                FILE *r1 = fopen( "remain1.html" , "w+" );
                fwrite( remain1 , strlen(remain1) , 1 , r1 );

                char *token1 = strtok( remain1 , ">" );
                if( token1 != NULL )
                {
                    token1 = strtok( NULL , ">" );
                    //printf("%s>\n",token1);
                }

                char *title = calloc( strlen(token1) , sizeof(int) );
                strncpy( title , token1 , strlen(token1) );
                title = strtok( token1 , "<" );
                strncpy( name[i] , title , strlen(token1) );
                //printf("%s\n",name[i]);
                //printf("\n\n\n");

                fseek( r1 , 1 , SEEK_SET );
                char *mem1 = calloc( size_r1-1 , sizeof(int) );
                fread( mem1 , size_r1 - 1 , 1 , r1 );
                FILE *r2 = fopen( "remain2.html" , "w+" );
                fwrite( mem1 , size_r1 - 1 , 1 , r2 );
                fclose( r1 );
                fclose( r2 );
                number++;
            }
            else
            {
                break;
            }
        }

        n page[number];
        int64_t gap[10] = {0};
        gap[0] = memory[0];
        for(int i=0;i<number;i++)
        {
            strncpy( page[i].title , name[i] , strlen(name[i]) );
        }
        for(int i=1;i<number;i++)
        {
            gap[i] = memory[i] - memory[i-1];
            //printf("%d%s\n",i,name[i]);
        }
        fseek( fp , 0 , SEEK_SET ); 
        
        for(int i=0;i<number;i++)
        {
            char *filename = calloc( log10(i+1) + 5 , sizeof(int) );
            char *remain2 = calloc( gap[i] , sizeof(int) ); 
            sprintf( filename , "%d.%s" , i+1 , "html" );
            FILE *r2 = fopen( filename , "w+" );
            if( i== 0 )
            {
                fseek( fp , 0 , SEEK_SET );
                fread( remain2 , memory[i] , 1 , fp );
                fwrite(remain2 , memory[i] , 1 , r2 );
            }
            else
            {
                fseek( fp , memory[i-1] , SEEK_SET );
                fread( remain2 , gap[i] , 1 , fp );
                fwrite( remain2 , gap[i] , 1 , r2 );
            }
            //printf("%d\n",i);
            func( r2 , &page[i] );
            if( i != 0 )
            {
                func01( r2 , &page[i-1] );
				func02( r2 , &page[i-1] );//
            	func03( r2 , &page[i-1] );//
            	func04( r2 , &page[i-1] );//
            }
            fclose( r2  );
        }
        char *l = calloc( 1024 , sizeof(int) ); 
        FILE *little = fopen( "11.html" , "w+" );
        fseek( fp , memory[number-1] , SEEK_SET );
        fread( l , 1024 , 1 , fp );
        fwrite( l , 1024 , 1 , little );
        func01( little , &page[number-1] );
        func01( little , &page[number-1] );
    	func02( little , &page[number-1] );//
    	func03( little , &page[number-1] );//
    	func04( little , &page[number-1] );//
        for(int i=0;i<number;i++)
        {
            printer( i , page[i] );
        }
        
        curl_easy_cleanup(curl);
        fclose( little );
        fclose( fp );
    }
    return 0;
}
