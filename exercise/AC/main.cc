#include "TSTs.h"
#include "Aho-Croasick.h"

int main(int argc, char* argv[])
{
    TSTs aho;
    //AhoCroasick aho;
    char* test[] = { "she", "he", "say", "shr", "her" };
    for (int i = 0, c = sizeof(test) / sizeof(test[0]); i < c; ++i)
        aho.insert(test[i]);
    aho.construct_fail();
    char* str = "yasherhs";
    int c = aho.recognize(str);

    int count = 0;
    for (int i = 0, c = sizeof(test) / sizeof(test[0]); i < c; ++i)
    {
        char* r = str;
        do {
            r = strstr(r, test[i]);
            if (r && r++)
                count++;
        } while (r != nullptr);
    }
    assert(c == count);
    return 0;
}
