#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto t1 = getValue<input_Timer1>(ctx);
        t1->stop();
        emitValue<output_DONE>(ctx, 1);
    }
}
