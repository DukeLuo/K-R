/* 练习 2-4 */

#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);

/* 测试程序 */
int main(void)
{
  char *leftstr[] =
  {
    "",
    "a",
    "antidisestablishmentarianism",
    "beautifications",
    "characteristically",
    "deterministically",
    "electroencephalography",
    "familiarisation",
    "gastrointestinal",
    "heterogeneousness",
    "incomprehensibility",
    "justifications",
    "knowledgeable",
    "lexicographically",
    "microarchitectures",
    "nondeterministically",
    "organizationally",
    "phenomenologically",
    "quantifications",
    "representationally",
    "straightforwardness",
    "telecommunications",
    "uncontrollability",
    "vulnerabilities",
    "wholeheartedly",
    "xylophonically", /* if there is such a word :-) */
    "youthfulness",
    "zoologically"
  };
  char *rightstr[] =
  {
    "",
    "a",
    "the",
    "quick",
    "brown",
    "dog",
    "jumps",
    "over",
    "lazy",
    "fox",
    "get",
    "rid",
    "of",
    "windows",
    "and",
    "install",
    "linux"
  };

  char buffer[32];
  size_t numlefts = sizeof leftstr / sizeof leftstr[0];
  size_t numrights = sizeof rightstr / sizeof rightstr[0];
  size_t left = 0;
  size_t right = 0;

  for(left = 0; left < numlefts; left++)
  {
    for(right = 0; right < numrights; right++)
    {
      strcpy(buffer, leftstr[left]);

      squeeze(buffer, rightstr[right]);

      printf("[%s] - [%s] = [%s]\n", leftstr[left], rightstr[right], buffer);
    }
  }
  return 0;
}



void squeeze(char s1[], char s2[])
{
    int i, j, k;
    
    for(j = 0; s2[j] != '\0'; ++j) {
        k = 0;
        for(i = 0; s1[i] != '\0'; ++i)
            if (s1[i] != s2[j])
                s1[k++] = s1[i];
        s1[k] = '\0';
    }
}

