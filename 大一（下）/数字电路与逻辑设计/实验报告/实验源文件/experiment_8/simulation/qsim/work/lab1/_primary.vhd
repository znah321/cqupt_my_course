library verilog;
use verilog.vl_types.all;
entity lab1 is
    port(
        Q               : out    vl_logic_vector(2 downto 0);
        clk             : in     vl_logic
    );
end lab1;
