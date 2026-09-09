#include <stdint.h>
#include "versions.h"

volatile uint32_t demo_flags = 0;
volatile uint32_t demo_counter = 0;
volatile char demo_probe = 0;

static const char demo_version[] = DFHB_VERSION;
static const char demo_model[] = DEVICE_MODEL;
static const char demo_commit[] = COMMIT_HASH;

static uint32_t get_demo_flags(void)
{
    uint32_t flags = 0;

#ifdef FC22_01
    flags |= (1UL << 0);
#endif

#ifdef FC22_02
    flags |= (1UL << 1);
#endif

#ifdef FC22_02_LL
    flags |= (1UL << 2);
#endif

#ifdef FC22_03
    flags |= (1UL << 3);
#endif

#ifdef FC22R_01
    flags |= (1UL << 4);
#endif

#ifdef FC22R_02
    flags |= (1UL << 5);
#endif

#if RECLOSER
    flags |= (1UL << 8);
#endif

#ifdef CHANGE_OVER
    flags |= (1UL << 9);
#endif

#ifdef DISJONCTEUR
    flags |= (1UL << 10);
#endif

#ifdef MAIN_RELEASE
    flags |= (1UL << 11);
#endif

    return flags;
}

int main(void)
{
    demo_flags = get_demo_flags();

    while (1)
    {
        demo_counter++;

        demo_probe ^= demo_version[
            demo_counter % (sizeof(demo_version) - 1U)
        ];

        demo_probe ^= demo_model[0];
        demo_probe ^= demo_commit[0];
    }
}
