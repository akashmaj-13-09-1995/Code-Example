#include <stdio.h>
using namespace std;
int shared Preferences (int friendA [ ], int friendB[ ]){

int countPreferences = 0;

for (int i=0;i< 5; i++)
 for (int j=0; j<5; j++)

if (friendA[i] ==friendB[j])
countPreferences++;

return countPreferences;
}
 int main ()
{ int friendA[5], friendB[5];

Printf(" Enter friend A's top five preferences:");
 for (int i=0; 1<5; i++)

Scanf("%d",&friendA[i]);

Printf(" Enter friend B's top five preferences:");
for (int i=0; i<5; i++)
 Scanf("%d",&friendB[i])


Printf(" "friend A and friend B shares %d common preferences",Shared Preferences (friendA, friendB));



return 0;
}