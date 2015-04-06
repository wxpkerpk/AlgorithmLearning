#include <stdio.h>
#include <stdlib.h>
struct set
{
    double a,b;
};
double d;
struct set sloveset(double a,double b);         /* �� d<=ax+b<360-d �Ľ� */
struct set intersection(struct set a,struct set b);          /* ����������ȡ���� */
int main()
{
    int h,m,i,j,k;
    double a1,b1,a2,b2,a3,b3,time;
    struct set answer[3][2],ensemble;
    while(scanf("%lf",&d)&&d!=-1)
    {
        time=0;
        for(h=0; h<12; h++)
        {
            for(m=0; m<60; m++)
            {
                b1=6.0*m;                a1=-5.9;
                b2=30*h+0.5*m;            a2=1.0/120-6.0;
                b3=30*h+(0.5-6)*m;         a3=(1.0/120)-0.1;
/* ��3������ֵ����ʽ�Ľ⼯ �浽answer��answer[0][0] answer[0][1]Ҫȡ����ʣ������Ҳ��*/
                answer[0][0]=sloveset(a1,b1);              answer[0][1]=sloveset(-a1,-b1);
                answer[1][0]=sloveset(a2,b2);              answer[1][1]=sloveset(-a2,-b2);
                answer[2][0]=sloveset(a3,b3);              answer[2][1]=sloveset(-a3,-b3);
/* ȡ����������Ҫ��3��ʽ�ӵĽ��ȡ���� ���Բ�������ķ���
ѭ������˼���Ǻ�����и�ȡһ���󽻼�����ͼ��ʾ����answer��*/
                for(i=0;i<2;i++)
                {
                    for(j=0;j<2;j++)
                    {
                        for(k=0;k<2;k++)
                        {
                            ensemble=intersection(intersection(answer[0][i],answer[1][j]),answer[2][k]);
                            time+=ensemble.b-ensemble.a; } } }
            }
        }
        time=time*100.0/(12*3600);
        printf("%.3lf\n",time);
    }
    return 0;
}
struct set sloveset(double a,double b)
{
    struct set seta;
    if(a>0)
    {
        seta.a=(d-b)/a;
        seta.b=(360-d-b)/a;
    }
    else
    {
        seta.b=(d-b)/a;
        seta.a=(360-d-b)/a;
    }
    if(seta.a<0) seta.a=0;
    if(seta.b>60) seta.b=60;
    if(seta.a>=seta.b) seta.a=seta.b=0; //֮ǰ���ŵ���if��seta.a<0��if��seta.b>60��ǰ����
    return seta;              //���seta.b����˸��Ļ�����seta.b̫���� ð�� ��֪�Դ�
}
struct set intersection(struct set a,struct set b)
{
    struct set p;
    p.a=a.a>b.a ?a.a:b.a;
    p.b=a.b<b.b ?a.b:b.b;
    if(p.a>p.b) p.a=p.b=0;
    return p;
}
