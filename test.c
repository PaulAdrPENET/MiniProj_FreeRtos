#include "test.h"

/*
const char* strbool(int v){
    static const char* array[2] = {
            "[FAILED]",
            "[PASSED]"};
    return array [v & 1];
}
 */

void test_all(test_t * test){
    for (;test->call;test++){
        int ret = test->call(); //0 ou 1
        const char* status = ret ? "[PASSED]" : "[FAILED]";
        printf("%s %s \n",test->name, status);
    }
}

int test_1(void){
    return 1;
};

int test_2(void){
    return 0;
};

int test_frames(void) {
    printf("test_frames [BEGIN]\n");

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