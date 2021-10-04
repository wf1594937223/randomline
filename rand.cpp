# include <stdio.h>
# include <random>
# include <time.h>
# define ull unsigned long long
# define longran() ((ran()<<32)^ran())
FILE *fr,*fw;
char s[110],lin[110]="rl",pos=1;
ull a[6];
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
	int now=(x&63);
	if(now>=0 && now<=9)
		s[lef]=now+'0';
	if(now>=10 && now<=35)
		s[lef]=now-10+'A';
	if(now>=36 && now<=61)
		s[lef]=now-36+'a';
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
	if(ch==EOF)
		return -1;
	while(ch<'0' || ch>'9')
		ch=fgetc(fr);
	while(ch>='0' && ch<='9')
	{
		val=(val<<1)+(val<<3)+(ch&15);
		ch=fgetc(fr);
	}
	return val;
}
void write(ull x)
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
	int i,j,n,m,w;
	ull cun,x;
	fr=fopen("rem.in","r");
	m=read();
	w=m;
	fclose(fr);
	fw=fopen("rem.in","w");
	write(m+1);
	fclose(fw);
	if(m==-1)
	{
		std::mt19937 ran(time(0));
		cun=longran();
		transf(cun,9);
		fw=fopen("rl0.out","w");
		for(i=0;i<10;i++)
			fputc(s[i],fw);
		fclose(fw);
		fw=fopen("ints.in","w");
		for(i=1;i<=6;i++)
		{
			x=ran()&(((ull)1<<32)-1);
			write(x);
			fputc('\n',fw);
		}
		return 0;
	}
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
	fr=fopen("ints.in","r");
	for(i=0;i<=5;i++)
		a[i]=read();
	fclose(fr);
	cun&=(a[0]|a[1]);
	cun|=(a[0]&a[1]);
	cun^=(ull)((ull)a[3]<<(ull)32);
	cun^=(ull)((ull)a[4]);
	std::mt19937 ran(a[2]^a[5]^(cun&2147483647));
	for(i=0;i<=(w&3);i++)
		cun^=longran();
	cun&=(((ull)1<<60)-1);
	fw=fopen(zsw,"w");
	transf(cun,9);
	for(i=0;i<10;i++)
		fputc(s[i],fw);
	fclose(fw);
	return 0;
}
