#pragma XOD require "https://github.com/PaulStoffregen/TimerOne"

#include <TimerOne.h>

node {
    meta {
        using Type = Timer1*;
    }

    void evaluate(Context ctx) {
        emitValue<output_OUT>(ctx, &Timer1);
    }
}
