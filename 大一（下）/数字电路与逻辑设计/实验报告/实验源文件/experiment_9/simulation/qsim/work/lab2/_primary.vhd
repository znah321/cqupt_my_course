library verilog;
use verilog.vl_types.all;
entity lab2 is
    port(
        Q               : out    vl_logic_vector(3 downto 0);
        CLK             : in     vl_logic;
        S1              : in     vl_logic;
        S0              : in     vl_logic
    );
end lab2;
