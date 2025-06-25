#include "doomgeneric.h"
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>

int fb_fd = -1;
void DG_Init() {
    printf("open /dev/fb...\n");
    fb_fd = open("/dev/fb", O_RDONLY, 0);
}

void DG_DrawFrame() {
    write(fb_fd, (void *)DG_ScreenBuffer, DOOMGENERIC_RESX * DOOMGENERIC_RESY * sizeof(pixel_t) );
}

void DG_SleepMs(uint32_t ms) {
    struct timespec ts = {0, ms * 1000000};
    struct timespec rem = {0, 0};
    nanosleep(&ts, &rem);
}

uint32_t DG_GetTicksMs() {
    struct timeval  tp;
    struct timezone tzp;

    gettimeofday(&tp, &tzp);

    return (tp.tv_sec * 1000) + (tp.tv_usec / 1000); /* return milliseconds */
}

int DG_GetKey(int* pressed, unsigned char* key) {
    return 0;
}


void DG_SetWindowTitle(const char * title) {

}


int main(int argc, char **argv)
{
    doomgeneric_Create(argc, argv);

    for (int i = 0; ; i++)
    {
        doomgeneric_Tick();
    }
    

    return 0;
}


