library verilog;
use verilog.vl_types.all;
entity Buzzer_Hour_Simulation is
    port(
        Buzzer          : out    vl_logic;
        ST              : in     vl_logic;
        Clock           : in     vl_logic
    );
end Buzzer_Hour_Simulation;
