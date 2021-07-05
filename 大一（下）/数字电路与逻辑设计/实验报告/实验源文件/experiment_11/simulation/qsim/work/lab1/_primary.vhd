library verilog;
use verilog.vl_types.all;
entity lab1 is
    port(
        BON             : out    vl_logic;
        clk             : in     vl_logic;
        LDN             : in     vl_logic;
        Q               : out    vl_logic_vector(3 downto 0)
    );
end lab1;
