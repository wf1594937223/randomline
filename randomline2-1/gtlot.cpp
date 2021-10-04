# include <stdio.h>
# include <stdlib.h>
# define ull unsigned long long
FILE *fr,*fw;
char lin[110]="rl",s[110];
int pos=1;
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
void comprem(int x)
{
	if(x/10)
		comprem(x/10);
	pos++;
	lin[pos]=x%10+'0';
	return;
}
int main()
{
	int i,j,n,m;
	scanf("%d",&n);
	n--;
	fr=fopen("rem.in","r");
	m=read();
	fclose(fr);
	for(i=m+1;i<=n;i++)
		system("./rand");
	fw=fopen("get.out","w");
	for(i=0;i<=n;i++)
	{
		pos=1;
		comprem(i);
		lin[++pos]='.';
		lin[++pos]='o';
		lin[++pos]='u';
		lin[++pos]='t';
		static const char *ss=lin;
		fr=fopen(ss,"r");
		fscanf(fr,"%s",s);
		fprintf(fw,"%s",s);
		fprintf(fw,"\n");
	}
}
