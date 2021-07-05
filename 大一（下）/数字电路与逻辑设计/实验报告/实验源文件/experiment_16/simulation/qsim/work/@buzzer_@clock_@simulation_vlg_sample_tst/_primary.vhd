library verilog;
use verilog.vl_types.all;
entity Buzzer_Clock_Simulation_vlg_sample_tst is
    port(
        Clock           : in     vl_logic;
        Set_H           : in     vl_logic_vector(7 downto 0);
        Set_M           : in     vl_logic_vector(7 downto 0);
        Set_S           : in     vl_logic_vector(7 downto 0);
        ST              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end Buzzer_Clock_Simulation_vlg_sample_tst;
