library verilog;
use verilog.vl_types.all;
entity lab2 is
    port(
        sBON            : out    vl_logic;
        clk             : in     vl_logic;
        Start           : in     vl_logic;
        F               : out    vl_logic_vector(3 downto 0);
        Y               : out    vl_logic_vector(3 downto 0)
    );
end lab2;
