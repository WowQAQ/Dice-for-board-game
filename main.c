#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stddef.h>
#include<time.h>
#include <conio.h>
#include <wchar.h>
#include <locale.h>
int num(int a)
{
    long b=0;
    int i;
    for(i=0;a>0;a/=10,i++)
    {
        b=(b*10)+a%10;
    }
    return i;
}


int main()
{
     // 应用环境Locale设置

  /*  setlocale(LC_CTYPE,setlocale(LC_ALL,""));
      wprintf(L"\u127922\n");*/
	int i,j,a,b,t,sum,bit;
	double history[99],count=1;
	for(i=0;i<=12;i++)
    {
        history[i]=0;
    }
	while(getchar()!=NULL)
    {
        t=clock();
        srand(t);
        //printf("time=%d\n",t);
        a=(rand()%6)+1;
        b=(rand()%6)+1;
        sum=a+b;
        printf("第%.0f次\n",count);
        printf("first one=%d,",a);
        printf("second one=%d\n",b);
        printf("sum=%d\n",sum);
        history[sum]++;

        //system("cls");
        printf("-------------------------------------------------------------\n");
        printf("   大小   |   出现次数   |   概率   \n");
        for(i=2;i<=12;i++)
        {
            printf("      %d    ",i);
            //bit=num(history[i]);
            printf("       %.0f    ",history[i]);
            printf("      %.2f    \n",(history[i]/count)*100);
        }
        count++;
    }


		/*for (i=0; i<n; i++)
			scanf("%d", &a[i]);
        printf("%d",(a[0]+a[n-1]));*/
	return 0;
}
