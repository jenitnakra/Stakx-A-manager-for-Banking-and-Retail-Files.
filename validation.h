char c;
    int len,i,flag1=0,flag2=0,flag3=0,flag4=0,j;

int check(char a[])
{
    len=strlen(a);
    if(len<6)
    flag1=1;
    else
    {
        for(i=0;i<len;i++)
        if((a[i]>=48&&a[i]<=58))
        {
            flag2=0;

            break;
        }
        else
        flag2=1;

        for(i=0;i<len;i++)
        if((a[i]>=65&&a[i]<=90))
        {
            flag3=0;

            break;
        }
        else
        flag3=1;

        for(i=0;i<len;i++)
        if(a[i]=='#'||a[i]=='$'||a[i]=='*'||a[i]=='&')
        {
            flag4=0;

            break;
        }
        else
        flag4=1;


    }
    if(flag1==1||flag2==1||flag3==1||flag4==1)
    return 1;
    else
    return 2;
}

 


int check1(char a[])
{
   for(i=0;i<strlen(a);i++)
   {
        if((a[i]>=48&&a[i]<=58))
        {
            flag3=0;

            break;
        }
        else
        {
        flag3=1;
        }
  }
  if(flag3==1)
    return 1;
else 
    return 2;

}





int check2(char a[])
{
       len=strlen(a);
    if(len<6)
    flag1=1;
    else
    {
        for(i=0;i<len;i++)
        if((a[i]>=48&&a[i]<=58))
        {
            flag2=0;

            break;
        }
        else
        flag2=1;

        for(i=0;i<len;i++)
        if((a[i]>=65&&a[i]<=90))
        {
            flag3=0;

            break;
        }
        else
        flag3=1;

     if(flag1==1||flag2==1||flag3==1)
    return 1;
    else
    return 2;
}
}