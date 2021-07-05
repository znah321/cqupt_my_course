library verilog;
use verilog.vl_types.all;
entity block1 is
    port(
        q               : out    vl_logic_vector(7 downto 0);
        clk             : in     vl_logic;
        a               : in     vl_logic
    );
end block1;
