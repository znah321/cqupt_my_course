library verilog;
use verilog.vl_types.all;
entity Buzzer_Hour_Simulation_vlg_sample_tst is
    port(
        Clock           : in     vl_logic;
        ST              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end Buzzer_Hour_Simulation_vlg_sample_tst;
