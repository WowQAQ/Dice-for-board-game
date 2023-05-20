#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stddef.h>
#include<time.h>

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

    /*setlocale(LC_CTYPE,setlocale(LC_ALL,""));
    wprintf(L"\u127922\n");*/
	int i,j,a,b,t,sum,bit,seed,begin=0,dicenum=2;
	double history[999],count=1;
	printf("请输入本局需要的骰子数量(1-100)\n");
    scanf("%d",&dicenum);
	for(i=dicenum;i<=6*dicenum;i++)
    {
        history[i]=0;
    }

    time_t timep;
    time (&timep);
    printf("当前时间为：%s", asctime( gmtime(&timep) ) );
    seed=time(&timep);
    srand(seed%65535);
    printf("本局随机数种子为%d\n",seed%65535);

    /*t=clock();
    srand(t);
    printf("本局随机数种子为%d",t);*/
    while(begin<10000)
    {

        /*t=clock();
        srand(t);*/
        //printf("time=%d\n",t);
        sum=0;
        for(j=0;j<dicenum;j++)
        {
            sum+=(rand()%6)+1;
        }
        //b=(rand()%6)+1;
        //sum=a+b;
        history[sum]++;
        count++;
        begin++;
    }
    printf("运行10000次后的概率分布如下\n");
    printf("-------------------------------------------------------------\n");
        printf("   大小   |   出现次数   |   概率   \n");
        for(i=dicenum;i<=6*dicenum;i++)
        {
            printf("      %d    ",i);
            //bit=num(history[i]);
            printf("       %.0f    ",history[i]);
            printf("      %.2f    \n",(history[i]/count)*100);
        }
    //统计清零
    for(i=dicenum;i<=6*dicenum;i++)
    {
        history[i]=0;
    }
    count=1;
    getchar();
	while(getchar()!=NULL)
    {
        //printf("time=%d\n",t);
        //system("cls");
        sum=0;
        for(j=0;j<dicenum;j++)
        {
            sum+=(rand()%6)+1;
        }
        /*a=(rand()%6)+1;
        b=(rand()%6)+1;
        sum=a+b;*/
        printf("第%.0f次\n",count);
        /*printf("first one=%d,",a);
        printf("second one=%d\n",b);*/
        printf("sum=%d\n",sum);
        history[sum]++;


        printf("-------------------------------------------------------------\n");
        printf("   大小   |   出现次数   |   概率   \n");
        for(i=dicenum;i<=6*dicenum;i++)
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
