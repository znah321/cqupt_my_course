library verilog;
use verilog.vl_types.all;
entity Second_Count is
    port(
        Carry_Sginal    : out    vl_logic;
        S               : out    vl_logic_vector(7 downto 0);
        CLK             : in     vl_logic
    );
end Second_Count;
