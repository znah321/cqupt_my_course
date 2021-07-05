library verilog;
use verilog.vl_types.all;
entity Timing_Module is
    port(
        H               : out    vl_logic_vector(7 downto 0);
        Input           : in     vl_logic;
        M               : out    vl_logic_vector(7 downto 0);
        S               : out    vl_logic_vector(7 downto 0)
    );
end Timing_Module;
