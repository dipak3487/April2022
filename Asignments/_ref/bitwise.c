int main()
{
unsigned int a = 60;  /* 60 = 0011 1100 */
unsigned int b = 13;  /* 13 = 0000 1101 */
unsigned int c = 0, d = 0;

c = a | b;            /* 61 = 0011 1101 */
d = a & b;            /* 12 = 0000 1100 */

return 0;
}
