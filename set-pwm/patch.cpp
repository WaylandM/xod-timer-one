#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {

        static_assert(isValidDigitalPort(constant_input_PORT), "must be a valid digital port");
        
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto duty = getValue<input_DUTY>(ctx);
        duty = duty > 1 ? 1 : (duty < 0 ? 0 : duty);
        int val = (int)(duty * 1023);

        pinMode(constant_input_PORT, OUTPUT);
 
        auto t1 = getValue<input_Timer1>(ctx);
        t1->pwm(constant_input_PORT, duty));
        emitValue<output_DONE>(ctx, 1);
    }
}
