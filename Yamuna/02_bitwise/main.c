/* GROUP   : YAMUNA 
   MEMBERS : APURVA MANOZ SS OMKAR ANON
*/


#include<stdio.h>
int main()
{

	int a, b, c, d, e, f,g;
	

	printf("For YES press 1 and for NO press 0\n");
	printf("want admission in nxt grade?\n");
	scanf("%d", &a);

	printf("Did you pass in physics?\n");
	scanf("%d", &b);

	printf("Did you pass in chemistry\n");
	scanf("%d", &c);

	printf("Did you pass in Biology\n");
	scanf("%d", &d);

	printf("Did you pass in Maths\n");
	scanf("%d", &e);

	printf("Did you pass in history\n");
	scanf("%d", &f);

	printf("Did you pass in Arts\n");
	scanf("%d", &g);

 	


if (a&&b&&c&&d&&e&&f&&g == 1)
    {
	printf("u r admited\n ");
    }
else 
   {
	printf("U r not admitted as u dont satisfy the criteria\n");

   }
      return 0;

}
