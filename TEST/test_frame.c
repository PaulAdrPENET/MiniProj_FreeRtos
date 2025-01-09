#include "test_frame.h"

/*
const char* strbool(int v){
    static const char* array[2] = {
            "[FAILED]",
            "[PASSED]"};
    return array [v & 1];
}
 */

int test_frames_generation(void){
    Frame frames[NB_CHANNELS + 1];

    for (int i = 1; i <= NB_CHANNELS + 1; i++) {
        create_Frame(&frames[i-1], i);
    }
    for (int i = 0; i < NB_CHANNELS + 1; i++) {
        Frame *frame = &frames[i];
        if (i < NB_CHANNELS) {
            if (frame->data.channel != i + 1) {
                printf("A ");
                return 0;
            }
            if (frame->data.value[0] < 0
                || frame->data.value[0] > 255
                || frame->data.value[1] < 0
                || frame->data.value[1] > 255
                || frame->data.value[2] < 0
                || frame->data.value[2] > 255) {
                printf("B ");
                return 0;
            }
        } else if (i == NB_CHANNELS) {
            if (frame->state.channel != 4) {
                printf("C ");
                return 0;
            }
            if (frame->state.state != 0x00) {
                printf("D ");
                return 0;
            }
        }
    }
    return 1;
}

int test_print_frames(void) {
    printf("test_print_frames [BEGIN]\n");

    Frame frames[NB_CHANNELS + 1];

    for (int i = 1; i <= NB_CHANNELS + 1; i++) {
        create_Frame(&frames[i-1], i);
    }

    for (int i = 0; i < NB_CHANNELS + 1; i++) {
        Frame *frame = &frames[i];
        if (frame->data.channel <= NB_CHANNELS) {
            printf("Frame %d (Channel %d): Data = [%02X %02X %02X]\n",
                   i + 1,
                   frame->data.channel,
                   frame->data.value[0],
                   frame->data.value[1],
                   frame->data.value[2]);

        } else if (frame->state.channel == 4) {
            printf("Frame %d (Channel %d): State = [%02X]\n",
                   i + 1,
                   frame->state.channel,
                   frame->state.state);
        }
    }
    return 1;
}