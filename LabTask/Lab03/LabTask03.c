#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
#include&lt;math.h&gt;
#include&lt;stdlib.h&gt;

#define f(x) cos(x)-x*exp(x)

int main()
{
float x0, x1, x2, f0, f1, f2, e;
int step = 1, N;

printf(&quot;\nEnter initial guesses:\n&quot;);
scanf(&quot;%f%f&quot;, &amp;x0, &amp;x1);
printf(&quot;Enter tolerable error:\n&quot;);
scanf(&quot;%f&quot;, &amp;e);
printf(&quot;Enter maximum iteration:\n&quot;);
scanf(&quot;%d&quot;, &amp;N);

printf(&quot;\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n&quot;);
do

{
f0 = f(x0);
f1 = f(x1);
if(f0 == f1)
{
printf(&quot;Mathematical Error.&quot;);
exit(0);
}

x2 = x1 - (x1 - x0) * f1/(f1-f0);
f2 = f(x2);

printf(&quot;%d\t\t%f\t%f\t%f\t%f\n&quot;,step,x0,x1,x2, f2);

x0 = x1;
f0 = f1;
x1 = x2;
f1 = f2;

step = step + 1;

if(step &gt; N)
{
printf(&quot;Not Convergent.&quot;);
exit(0);

}
}while(fabs(f2)&gt;e);

printf(&quot;\nRoot is: %f&quot;, x2);
getch();
return 0;
}