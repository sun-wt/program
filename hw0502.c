#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define CK_TIME 1
 
int main()
{
        FILE *Stat;
        char buf[128];
        char cpu[5];
        long int user , nice , sys , idle , iowait , irq , softirq;
        long int all1 , all2 , idle1 , idle2;
        float usage;
 
        while(1)
        {
                           
                if( ( Stat = fopen( "/proc/stat" , "rb" ) ) == NULL )
                {
                    printf( "File could not be opened!\n" );
                    return 0;
                }

                fgets( buf , sizeof(buf) , Stat );
                sscanf( buf , "%s%ld%ld%ld%ld%ld%ld%ld" , cpu , &user , &nice , &sys , &idle , &iowait , &irq , &softirq );
                all1 = user + nice + sys + idle + iowait + irq + softirq;
                idle1 = idle;
                rewind( Stat );

                sleep( CK_TIME );
                memset( buf , 0 , sizeof(buf) );
                cpu[0] = '\0';
                user = nice = sys = idle = iowait = irq = softirq = 0;

                fgets( buf , sizeof(buf) , Stat );
                sscanf( buf , "%s%ld%ld%ld%ld%ld%ld%ld" , cpu , &user , &nice , &sys , &idle , &iowait , &irq , &softirq );
                all2 = user + nice + sys + idle + iowait + irq + softirq;
                idle2 = idle;
 
                usage = (float)( all2 - all1 - ( idle2 - idle1 ) ) / ( all2 - all1 ) * 100;
                printf( "CPU usage = %.2f%%\n" , usage );
 
                fclose( Stat );
        }
        return 0;
}

