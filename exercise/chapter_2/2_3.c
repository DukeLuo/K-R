/* 练习2-3 */

#include <stdio.h>
#include <stdlib.h>

int htoi(char s[]);

/* 测试 */
int main(void)
{
  char *endp = NULL;
  char *test[] =
  {
    "F00",
    "bar",
    "0100",
    "0x1",
    "0XA",
    "0X0C0BE",
    "abcdef",
    "123456",
    "0x123456",
    "deadbeef",
    "zog_c"
  };

  long int result;
  long int check;

  size_t numtests = sizeof test / sizeof test[0];

  size_t thistest;

  for(thistest = 0; thistest < numtests; thistest++)
  {
    result = htoi(test[thistest]);
    check = strtol(test[thistest], &endp, 16);

    if((*endp != '\0' && result == -1) || result == check)
    {
      printf("Testing %s. Correct. %ld\n", test[thistest], result);
    }
    else
    {
      printf("Testing %s. Incorrect. %ld\n", test[thistest], result);
    }
  }

  return 0;
}



int htoi(char s[])
{
    int i, n;
    
    i = 0;
    if(s[i] == '0') {
        ++i;
        if(s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    
    n = 0;
    while(s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9') {
            n = 16 * n + (s[i] - '0');
            ++i;
        }
        else if (s[i] >= 'a' && s[i] <= 'f') {
            n = 16 * n + (s[i] - 'a' + 10);
            ++i;
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            n = 16 * n + (s[i] - 'A' + 10);
            ++i;
        }
        else {
            n = -1;
            break;
        }
    }
    return n;
}

   