#include <iostream>
#include "Aho-Croasick.h"
//5
//she
//he
//say
//shr
//her
//yasherhs
int main(int argc, char* argv[])
{
    char S[20];
    int N = 0;
    scanf_s("%d", &N);
    AhoCroasick aho;
    for (int i = 0; i < N; ++i)
    {
        scanf_s("%s", S, 19);
        aho.insert(S);
    }
	aho.construct_fail();
    scanf_s("%s", S, 19);
    int c =aho.recognize(S);
	return 0;
}
