library verilog;
use verilog.vl_types.all;
entity block2 is
    port(
        q               : out    vl_logic_vector(7 downto 0);
        clk             : in     vl_logic;
        b               : in     vl_logic_vector(3 downto 0);
        a               : in     vl_logic_vector(3 downto 0)
    );
end block2;
