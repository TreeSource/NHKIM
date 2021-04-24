#include <stdio.h>

struct departure_time
{
    int depart, arrive;
};

struct departure_time dtime_list[] =
{
    {480, 616}, {583, 712}, {679, 811}, {767, 900}, {840, 968}, 
    {945, 1075}, {1140, 1280}, {1305, 1438}
};

int main (void)
{
    int i, inp1, inp2, inp, len = sizeof(dtime_list) / sizeof(dtime_list[0]);
    scanf("%d:%d", &inp1, &inp2);
    inp = inp1*60 + inp2;
    for (i = len - 1; i >= 1; --i)
    {
        if(dtime_list[i].depart <= inp ||
        inp - dtime_list[i-1].depart > dtime_list[i].depart - inp)
        {
            printf("Closest departure time is %d:%d, arriving time at %d:%d\n",
            dtime_list[i].depart / 60, dtime_list[i].depart % 60,
            dtime_list[i].arrive / 60, dtime_list[i].arrive % 60);
            break;
        }
    }
    if (i == 0)
        printf("Closest departure time is %d:%d, arriving time at %d:%d\n",
        dtime_list[i].depart / 60, dtime_list[i].depart % 60,
        dtime_list[i].arrive / 60, dtime_list[i].arrive % 60);
    return 0;
}
