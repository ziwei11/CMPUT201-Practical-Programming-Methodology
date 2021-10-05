/* function strcpy should be out of the for loop,
 * and we should use strncpy
 * because strcpy is insecure as it does not provide bounding of the memory buffer.
 */

#define _POSIX_C_SOURCE 200809L // <-- needed for strdup
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Make a mashup of a poem by Kahlil Gibran


// From Kahlil Gibran's The Prophet
// http://www.gutenberg.org/files/58585/58585-h/58585-h.htm

const char * theComingShip = "Now when he reached the foot of the hill,\
 he turned again towards the sea, and he saw his ship approaching the harbour,\
 and upon her prow the mariners, the men of his own land.\n\
\n\
And his soul cried out to them, and he said:\n\
\n\
Sons of my ancient mother, you riders of the tides,\n\
\n\
How often have you sailed in my dreams. And now you come in my awakening,\
 which is my deeper dream.\n\
\n\
Ready am I to go, and my eagerness with sails full set awaits the wind.\n\
\n\
Only another breath will I breathe in this still air, only another loving look cast backward,\n\
\n\
And then I shall stand among you, a seafarer among seafarers.\n\
\n\
And you, vast sea, sleepless mother,\n\
\n\
Who alone are peace and freedom to the river and the stream,\n\
\n\
Only another winding will this stream make, only another murmur in this glade,\n\
\n\
And then shall I come to you, a boundless drop to a boundless ocean.";

#define OFF 50
int main() {
  // we just want to cut the poem and make some edits
  char * poem = strdup(theComingShip);
  const size_t poemn = strlen(poem);
  for (size_t i = OFF; i <= poemn; i+=OFF) {
    poem[i-1] = '#'; // mark where we are acting
    //strcpy(poem + i, poem + i + OFF);
  }
  char * temp = strdup(poem + OFF + OFF);
  strncpy((poem + OFF), (const char *)temp, strlen(temp));
  char * tempp = malloc(sizeof(char) * (poemn - OFF + 1));
  strncpy(tempp, (const char *)poem, poemn - OFF);
    tempp[poemn - OFF] = '\0';
  puts(tempp);
  free(tempp);
  free(temp);
  free(poem);
}

