library verilog;
use verilog.vl_types.all;
entity TimingModule_Second_Minute is
    port(
        M               : out    vl_logic_vector(7 downto 0);
        Input           : in     vl_logic;
        S               : out    vl_logic_vector(7 downto 0)
    );
end TimingModule_Second_Minute;
