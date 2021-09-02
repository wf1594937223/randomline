# include <stdio.h>
# define ull unsigned long long
FILE *fr,*fw;
char s[110],lin[110]="rl",pos=1;
ull transz()
{
	int i,j;
	char c;
	ull now=0;
	for(i=1;i<=10;i++)
	{
		c=fgetc(fr);
		if(c>='0' && c<='9')
			now=(now<<6)+c-'0';
		if(c>='A' && c<='Z')
			now=(now<<6)+(c&31)+9;
		if(c>='a' && c<='z')
			now=(now<<6)+(c&31)+35;
		if(c=='-')
			now=(now<<6)+62;
		if(c=='+')
			now=(now<<6)+63;
	}
	return now;
}
void transf(ull x,int lef)
{
	if(lef)
		transf(x>>6,lef-1);
	ull now=(x&63);
	if(now>=0 && now<=9)
		s[lef]=now+'0';
	if(now>=10 && now<=35)
		s[lef]=now-10+'A';
	if(now>=36 && now<=61)
		s[lef]=now-35+'a';
	if(now==62)
		s[lef]='-';
	if(now==63)
		s[lef]='+';
	return;
}
void comprem(int x)
{
	if(x/10)
		comprem(x/10);
	pos++;
	lin[pos]=x%10+'0';
	return;
}
int read()
{
	ull val=0;
	char ch=fgetc(fr);
	while(ch<'0' || ch>'9')
		ch=fgetc(fr);
	while(ch>='0' && ch<='9')
	{
		val=(val<<1)+(val<<3)+(ch&15);
		ch=fgetc(fr);
	}
	return val;
}
void write(int x)
{
	if(x<10)
		fputc(x+48,fw);
	else
	{
		write(x/10);
		fputc((x%10)+48,fw);
	}
	return;
}
ull qpow(ull x,ull y)
{
	ull now=1,chen=x;
	while(y)
	{
		if(y&1)
			now*=chen;
		chen*=chen;
		y>>=1;
	}
	return now;
}
int main()
{
	int i,j,n,m;
	ull cun;
	fr=fopen("rem.in","r");
	m=read();
	fclose(fr);
	fw=fopen("rem.in","w");
	write(m+1);
	fclose(fw);
	comprem(m);
	lin[++pos]='.';
	lin[++pos]='o';
	lin[++pos]='u';
	lin[++pos]='t';
	const char *zsr=lin;
	fr=fopen(zsr,"r");
	cun=transz();
	fclose(fr);
	m++;
	pos=1;
	comprem(m);
	lin[++pos]='.';
	lin[++pos]='o';
	lin[++pos]='u';
	lin[++pos]='t';
	const char *zsw=lin;
	cun|=19491001;
	cun/=2696059140;
	cun*=1594937223;
	cun<<=1;
	cun^=(ull)((ull)19174956786<<30);
	cun^=(ull)((ull)15874918896);
	cun+=qpow((ull)2544307,cun);
	cun&=(((ull)1<<60)-1);
	fw=fopen(zsw,"w");
	transf(cun,9);
	for(i=0;i<10;i++)
		fputc(s[i],fw);
	fclose(fw);
	return 0;
}
