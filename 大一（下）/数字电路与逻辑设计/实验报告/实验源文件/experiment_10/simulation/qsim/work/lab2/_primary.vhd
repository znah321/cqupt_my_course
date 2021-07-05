library verilog;
use verilog.vl_types.all;
entity lab2 is
    port(
        F               : out    vl_logic_vector(3 downto 0);
        Y               : out    vl_logic_vector(3 downto 0);
        clk             : in     vl_logic
    );
end lab2;
