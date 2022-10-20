#if 0
#include <stdio.h>
int a = 100;
int main()
{
	//printf("hello world!\n");
	//printf("hehe\n");
	//printf("%d\n", (int)sizeof(char));
	//printf("%d\n", (int)sizeof(short));
	//printf("%d\n", (int)sizeof(int));
	//printf("%d\n", (int)sizeof(long));
	//printf("%d\n", (int)sizeof(long long));
	//printf("%d\n", (int)sizeof(float));
	//printf("%d\n", (int)sizeof(double));
	//printf("%d\n", (int)sizeof(long double));

  int age = 20;
  double weight = 75.3;
  age++;
  weight = weight - 20.0;
  printf("age = %d\n", age);
  printf("%.2lf\n", weight);

  int a = 10;
  printf("a = %d\n", a);
	return 0;
}
#include <stdio.h>
int main()
{
  int a = 0;
  int b = 0;
  int s = 0;
  scanf("%d%d", &a, &b);
  s = a + b;
  printf("s = %d\n", s);
  return 0;
}
#endif
