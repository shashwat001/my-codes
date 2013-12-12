#include<stdio.h>
int scan()
{
int t=0;
char c;
c=getchar_unlocked();
while(c<'0' || c>'9')
c=getchar_unlocked();
while(c>='0' && c<='9')
{
t=(t<<3)+(t<<1)+c-'0';
c=getchar_unlocked();
}
return(t);
}
int decide(int arr[],int a,int b,int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(arr[i]==a)
        return 0;
        else if(arr[i]==b)
        return 1;
    }
    return -1;
    
}
int main()
{
        int i,j,k,cur_m,n,f2prop,mpref[505][505],fpref[505][505],m_engage[505],f_engage[505],m_prop[505]={0};
        n=scan();
        for(i=1;i<=n;i++)
        {
            m_engage[i]=0;
            f_engage[i]=0;
            m_prop[i]=0;
            j=scan();
            for(k=1;k<=n;k++)
            {
                fpref[j][k]=scan();
            }
        }
        for(i=1;i<=n;i++)
        {
            j=scan();
            for(k=1;k<=n;k++)
            {
                mpref[j][k]=scan();
            }
        }
        while(1)
        {
            cur_m=0;
            for(i=1;i<=n;i++)
            {
                if(m_engage[i]==0&&m_prop[i]!=n)
                {
                    cur_m=i;
                    break;
                }
            }
            if(cur_m==0)
            break;
            f2prop=mpref[cur_m][++m_prop[cur_m]];
            if(f_engage[f2prop]==0)
            {
                m_engage[cur_m]=f2prop;
                f_engage[f2prop]=cur_m;
                
            }
            else if(decide(fpref[f2prop],f_engage[f2prop],cur_m,n)==1)
            {
                m_engage[cur_m]=f2prop;
                m_engage[f_engage[f2prop]]=0;
                f_engage[f2prop]=cur_m;
                
            }
        }
        for(i=1;i<=n;i++)
        {
            printf("%d %d\n",i,m_engage[i]);
        }
        
    return 0;
}
