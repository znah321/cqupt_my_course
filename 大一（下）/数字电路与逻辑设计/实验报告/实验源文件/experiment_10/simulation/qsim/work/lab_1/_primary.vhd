library verilog;
use verilog.vl_types.all;
entity lab_1 is
    port(
        F               : out    vl_logic_vector(3 downto 0);
        clk             : in     vl_logic;
        Y               : out    vl_logic_vector(3 downto 0)
    );
end lab_1;
