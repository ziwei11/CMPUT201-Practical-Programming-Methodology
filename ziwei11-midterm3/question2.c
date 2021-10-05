/*

  CMPUT201W20 Midterm 3 Question 2
  
  This program attempts to create a growing list of coolbears.
  Coolbears have names, metadata (junk), and temperatures. We care
  about 1 bear in particular and want to modify that bear's
  temperature. But something is wrong, we don't seem to be changing
  its temperature. Your solution should be less than 5 lines. My
  solution was 2 lines.

  NAME: Vicky Zhao
  CCID: ziwei11
  STUDENT NUMBER: 1593071

  In this comment please describe how you fixed this problem and what
  tools you used:
  We need to delete line 109 "CoolBear ziggy = getCoolbearCBList( cblist, 0)"
  and add this line to line 117, because every time we call addCoolBearCBList,
  it will realloc the memory so the address of cblist->list will change.
  Thus, if we do not delete line 109 and add it to line 117,
  ziggy's address must be different with getCoolbearCBList( cblist, 0)'s address.

 
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define METADATA 60

struct coolbear {
  const char * name;
  long int temperature;
  char metadata[METADATA];
};
typedef struct coolbear * CoolBear;


struct coolbearlist {
  struct coolbear * list;
  size_t ncoolbears;
};
typedef struct coolbearlist * CBList;

// Create a coolbear list that can grow in size.
CBList createCBList() {
  CBList cblist = malloc(sizeof(struct coolbearlist));
  cblist->list = NULL;
  cblist->ncoolbears = 0;
  return cblist;
}
// Free a coolbear list
void freeCBList(CBList cblist) {
  if (cblist->list != NULL) {
    free(cblist->list);
  }
  free(cblist);
}

// get a coolbear from cblist at size_t index
CoolBear getCoolbearCBList(CBList cblist, size_t index) {
  // you can't get any coolbears if cblist is null
  assert(cblist != NULL);
  // you can't get any coolbears if the list is null
  assert(cblist->list != NULL);
  return &cblist->list[index];
}

// Add a struct coolbear to the CBList cblist
// Allocate more memory if necessary
void addCoolBearCBList(CBList cblist, struct coolbear coolbear) {
  assert(cblist != NULL);
  size_t ncoolbears = cblist->ncoolbears;
  cblist->list = realloc(cblist->list, (ncoolbears+1)*sizeof(coolbear));
  assert(cblist->list != NULL);
  cblist->list[ncoolbears] = coolbear;
  cblist->ncoolbears++;
}

// Define test data
// 4 Possible names with 5 possible temperatures
#define NAMES 4
const char * names[] = {
  "Olivia",
  "Daryl",
  "Charmane",
  "Lin"
};
#define TEMPS 5
const long int temps[] = { // DNC
  -10,                     // DNC
  -20,                     // DNC
  -30,                     // DNC
  -40,                     // DNC
  -50,                     // DNC
};

#define NBEARS 16000

int main() {
  CBList cblist = createCBList();
  const long int zigtemp = -32; // DNC
  // Add Ziggy the test bear
  addCoolBearCBList(
    cblist,
    (struct coolbear){.name="Ziggy",.temperature=zigtemp});
  //CoolBear ziggy = getCoolbearCBList( cblist, 0);
  // We'll make lots of coolbears!
  for (int i = 1; i < NBEARS; i++) {
    addCoolBearCBList( cblist, (struct coolbear){
        .name=names[i%NAMES],
        .temperature=temps[i%TEMPS]}
    );    
  }
  CoolBear ziggy = getCoolbearCBList( cblist, 0);
  // ensure that cblist contains NBEARS of coolbears
  assert(cblist->ncoolbears == NBEARS);                                  //DNC
  // GOAL: Change ziggy's temperature!
  // DOUBLE ZIGGY'S TEMPERATURE!
  ziggy->temperature *= 2;
  // Debug print out ziggy's name and temperature
  printf("%s %ld\n", ziggy->name, ziggy->temperature); // DNC
  // We're going to compare ziggy with the first bear in the list
  // Who is also ziggy.
  long int zigtemp2 = ziggy->temperature;
  long int zigtemp3 = getCoolbearCBList( cblist, 0)->temperature;
  // MAKE SURE ZIGGY HAS 2X temperature
  if (zigtemp2 != zigtemp3) {
    printf("Hmmm zigtemp2 %ld != zigtemp3 %ld\n", zigtemp2, zigtemp3);
  }
  // Verify that the first coolbear is ziggy and the temperature is
  // the same
  assert( getCoolbearCBList( cblist, 0)->temperature == zigtemp2 );      //DNC
  assert( strcmp(getCoolbearCBList( cblist, 0)->name, ziggy->name) == 0);//DNC
  freeCBList(cblist);
  return 0;
}
