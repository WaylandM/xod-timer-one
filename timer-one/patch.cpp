#pragma XOD require "https://github.com/PaulStoffregen/TimerOne"

#include <TimerOne.h>

node {
    meta {
        using Type = TimerOne*;
    }

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;
        emitValue<output_Timer1>(ctx, &Timer1);
    }
}
