library verilog;
use verilog.vl_types.all;
entity Buzzer_Clock_Simulation is
    port(
        Buzzer          : out    vl_logic;
        ST              : in     vl_logic;
        Clock           : in     vl_logic;
        Set_H           : in     vl_logic_vector(7 downto 0);
        Set_M           : in     vl_logic_vector(7 downto 0);
        Set_S           : in     vl_logic_vector(7 downto 0)
    );
end Buzzer_Clock_Simulation;
